#include <windows.h>
#include <stdio.h>
#include <stdbool.h>
#include "cpu8080.h"
#include "resource.h"

#define INVADERS_H_ROM_PATH     "C:\\Users\\Luke\\Programming\\C\\8080SIEmulator\\bin\\Debug\\invaders.h"
#define INVADERS_G_ROM_PATH     "C:\\Users\\Luke\\Programming\\C\\8080SIEmulator\\bin\\Debug\\invaders.g"
#define INVADERS_F_ROM_PATH     "C:\\Users\\Luke\\Programming\\C\\8080SIEmulator\\bin\\Debug\\invaders.f"
#define INVADERS_E_ROM_PATH     "C:\\Users\\Luke\\Programming\\C\\8080SIEmulator\\bin\\Debug\\invaders.e"

#define TIMER_INTERVAL          17

#define CYCLES                  33333
#define ORG_WIDTH               224
#define ORG_HEIGHT              256
#define WIN_WIDTH               448
#define WIN_HEIGHT              512

#define DEBUG

int x = 0;

HWND g_hwndDebugger;

HINSTANCE			g_hInst   = 0;
HWND				g_hWnd    = 0;
HBITMAP				g_hBmp    = 0;
HBITMAP				g_hBmpOld = 0;
HDC					g_hMemDC  = 0;
BYTE				g_Screen[ORG_WIDTH * ORG_HEIGHT];
UINT32*				g_pPixels = 0;

BOOL isPaused;


/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

/*  Make the class name into a global variable  */
char szClassName[] = "WindowClass";
char binFilename[MAX_PATH];
char filename[MAX_PATH];

HWND hwnd;
MMRESULT timerEvent;

void drawBitmap()
{
	const int GFX_HEIGHT = 224;
	const int GFX_WIDTH  = 32;

	BYTE *gfx = &g_SpaceInvaders.mainMemory[0x2400];

	int x1, y1;
	int u, v;
	unsigned char dbColor;

	// Convert 32x224 ==> 224x256 (rotate 90 degrees)
	for (int y = 0; y < GFX_HEIGHT; y++) {
		x1 = 0;
		y1 = y;

		for (int x = 0; x < GFX_WIDTH; x++) {
			BYTE pixels = gfx[y * GFX_WIDTH + x];
			for (int i = 0; i < 8; i++) {
				u = y1;
				v = 255 - x1;

				if (v < 32) {
					dbColor = 'W';  // WHITE
				} else if (v >= 32 && v < 64) {
					dbColor = 'R';  // RED
				} else if (v >= 64 && v < 184) {
					dbColor = 'W';  // WHITE
				} else if (v >= 184 && v < 240) {
					dbColor = 'G';  // GREEN
				} else {
					if (u >= 16 && u < 134) {
                        dbColor = 'G';
					} else {
                        dbColor = 'W';
					}
				}

				g_Screen[(v * ORG_WIDTH) + u] = ((pixels >> i) & 0x1) ? dbColor : 0;
				x1++;
			}
		}
	}

	// Convert 256x224 gfx to 448x512 bitmap
	DWORD dwColor;

	for (int y = 0; y < WIN_HEIGHT; ++y) {
		for (int x = 0; x < WIN_WIDTH; ++x) {
			x1 = x * ORG_WIDTH / WIN_WIDTH;
			y1 = y * ORG_HEIGHT / WIN_HEIGHT;

			dbColor = g_Screen[y1 * ORG_WIDTH + x1];

			if (dbColor == 'W') {
                dwColor = 0xFFFFFFFF;
			} else if (dbColor == 'R') {
                dwColor = 0xFFFF0000;
			} else if (dbColor == 'G') {
                dwColor = 0xFF00FF00;
			} else if (dbColor == 'B') {
                dwColor = 0xFF0000FF;
			} else {
                dwColor = 0x00000000;
			}

			g_pPixels[y * WIN_WIDTH + x] = dwColor;
		}
	}

	InvalidateRect(g_hWnd, 0, false);
}

void checkInput(i8080 *myi8080)
{
    // Player 1/2 start, insert coin
    INPORT_1 = ((GetAsyncKeyState('3') & 0x8000)) ? INPORT_1 | 0x1 : INPORT_1 & ~0x1;
    INPORT_1 = ((GetAsyncKeyState('2') & 0x8000)) ? INPORT_1 | 0x2 : INPORT_1 & ~0x2;
    INPORT_1 = ((GetAsyncKeyState('1') & 0x8000)) ? INPORT_1 | 0x4 : INPORT_1 & ~0x4;

    // Player 1 controls
    INPORT_1 = ((GetAsyncKeyState('W') & 0x8000)) ? INPORT_1 | 0x10 : INPORT_1 & ~0x10;
    INPORT_1 = ((GetAsyncKeyState('Q') & 0x8000)) ? INPORT_1 | 0x20 : INPORT_1 & ~0x20;
    INPORT_1 = ((GetAsyncKeyState('E') & 0x8000)) ? INPORT_1 | 0x40 : INPORT_1 & ~0x40;

    // Player 2 controls
    INPORT_2 = ((GetAsyncKeyState('T') & 0x8000)) ? INPORT_2 | 0x10 : INPORT_2 & ~0x10;
    INPORT_2 = ((GetAsyncKeyState('R') & 0x8000)) ? INPORT_1 | 0x20 : INPORT_2 & ~0x20;
    INPORT_2 = ((GetAsyncKeyState('Y') & 0x8000)) ? INPORT_1 | 0x40 : INPORT_2 & ~0x40;
}

void CALLBACK timerCallback(UINT uID, UINT uMsg, DWORD dwUser, DWORD dw1, DWORD dw2)
{
    if(isPaused) {
        return;
    }

    executeCycles(&g_SpaceInvaders, 17000);
    //executeCycles(&g_SpaceInvaders, CYCLES/2);

    generateInterrupt(1);

    drawBitmap();

    executeCycles(&g_SpaceInvaders, 17000);
    //executeCycles(&g_SpaceInvaders, CYCLES/2);

    generateInterrupt(2);

    //PostMessage(g_hWnd, WM_PAINT, 0, 0);
    checkInput(&g_SpaceInvaders);
}

bool selectBinFilename()
{
    OPENFILENAME ofn;

    ZeroMemory(&ofn, sizeof (OPENFILENAME));
    ofn.lStructSize = sizeof (OPENFILENAME);
    ofn.hwndOwner = hwnd;
    ofn.lpstrFilter = "All files (*.*)\0*.*\0";
    ofn.lpstrFile = binFilename;
    ofn.lpstrTitle = "Open Bin";
    ofn.nMaxFile = MAX_PATH;
    ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST;

    memset(filename, 0, MAX_PATH);
    GetOpenFileName(&ofn);

    if(binFilename[0] == '\0') {
        return false;
    }

    return true;
}

void updateMenu(HMENU hMenu)
{
    CheckMenuItem(hMenu, IDM_PAUSE, (isPaused) ? MF_CHECKED : MF_UNCHECKED);
}

int WINAPI WinMain (HINSTANCE hThisInstance, HINSTANCE hPrevInstance, LPSTR lpszArgument, int nCmdShow)
{
    //HWND hwnd;
    MSG messages;
    WNDCLASSEX wincl;

    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;
    wincl.style = CS_DBLCLKS;
    wincl.cbSize = sizeof (WNDCLASSEX);

    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = MAKEINTRESOURCE(ID_MENU);
    wincl.cbClsExtra = 0;
    wincl.cbWndExtra = 0;

    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;

    if (!RegisterClassEx(&wincl)) {
        return -1;
    }

    g_hWnd = CreateWindowEx(
           0,
           szClassName,
           "Space Invaders Emulator",
           WS_OVERLAPPEDWINDOW,
           CW_USEDEFAULT,
           CW_USEDEFAULT,
           464,
           570,
           HWND_DESKTOP,
           NULL,
           hThisInstance,
           NULL
           );

    ShowWindow (g_hWnd, nCmdShow);

    BITMAPINFO bmi;
    bmi.bmiHeader.biSize = sizeof (BITMAPINFO);
    bmi.bmiHeader.biWidth = WIN_WIDTH;
    bmi.bmiHeader.biHeight = -WIN_HEIGHT;
    bmi.bmiHeader.biPlanes = 1;
    bmi.bmiHeader.biBitCount = 32;
    bmi.bmiHeader.biCompression = BI_RGB;
    bmi.bmiHeader.biSizeImage = 0;
    bmi.bmiHeader.biXPelsPerMeter = 0;
    bmi.bmiHeader.biYPelsPerMeter = 0;
    bmi.bmiHeader.biClrUsed = 0;
    bmi.bmiHeader.biClrImportant = 0;
    bmi.bmiColors[0].rgbBlue = 0;
    bmi.bmiColors[0].rgbGreen = 0;
    bmi.bmiColors[0].rgbRed = 0;
    bmi.bmiColors[0].rgbReserved = 0;

    HDC hdc = GetDC(hwnd);

    g_hBmp = CreateDIBSection(hdc, &bmi, DIB_RGB_COLORS, (void**) &g_pPixels, NULL, 0);

    g_hMemDC = CreateCompatibleDC(hdc);
    g_hBmpOld = (HBITMAP) SelectObject(g_hMemDC, g_hBmp);

    ReleaseDC(hwnd, hdc);

    while (GetMessage(&messages, NULL, 0, 0)) {
        TranslateMessage(&messages);
        DispatchMessage(&messages);
    }

    return messages.wParam;
}

LRESULT CALLBACK DebuggerProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch(message)
    {
        case ID_BTN_DEBUGGERCLOSE:
            ShowWindow(g_hwndDebugger, false);
            break;

        case WM_CLOSE:
            PostQuitMessage(0);
            break;

        case WM_DESTROY:
            PostQuitMessage(0);
            break;
    }

    return 0;
}

LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HWND hMenu = GetMenu(hwnd);

    PAINTSTRUCT ps;
    HDC hdc;

    switch (message)
    {
        case WM_CREATE:
            initializeCpu(&g_SpaceInvaders);
//            if(loadRom(&g_SpaceInvaders))
//            {
//                timerEvent = timeSetEvent(1000/60, 0, (LPTIMECALLBACK)timerCallback, 0, TIME_PERIODIC);
//            }

            if(!loadRom(&g_SpaceInvaders, INVADERS_H_ROM_PATH, INVADERS_H_ROM_ADDRESS)) {
                #ifdef DEBUG
                puts("ERROR: Cannot find invaders.h! Terminating emulator...");
                #endif
                return -1;
            }

            if(!loadRom(&g_SpaceInvaders, INVADERS_G_ROM_PATH, INVADERS_G_ROM_ADDRESS)) {
                #ifdef DEBUG
                puts("ERROR: Cannot find invaders.g! Terminating emulator...");
                #endif
                return -1;
            }

            if(!loadRom(&g_SpaceInvaders, INVADERS_F_ROM_PATH, INVADERS_F_ROM_ADDRESS)) {
                #ifdef DEBUG
                puts("ERROR: Cannot find invaders.f! Terminating emulator...");
                #endif
                return -1;
            }

            if(!loadRom(&g_SpaceInvaders, INVADERS_E_ROM_PATH, INVADERS_E_ROM_ADDRESS)) {
                #ifdef DEBUG
                puts("ERROR: Cannot find invaders.e! Terminating emulator...");
                #endif
                return -1;
            }

            timerEvent = timeSetEvent(TIMER_INTERVAL, 0, (LPTIMECALLBACK)timerCallback, 0, TIME_PERIODIC);

            // g_hwndDebugger = CreateDialog(GetModuleHandle(NULL), MAKEINTRESOURCE(ID_DIALOGDEBUGGER), NULL, (DLGPROC)DebuggerProc);
            // ShowWindow(g_hwndDebugger, true);
        break;

        case WM_PAINT:
            hdc = BeginPaint(hwnd, &ps);

            // Draw pixels to window when window needs repainting
            if (g_hMemDC) {
                BitBlt(hdc, 0, 0, WIN_WIDTH, WIN_HEIGHT, g_hMemDC, 0, 0, SRCCOPY);
            }

            EndPaint(hwnd, &ps);
            break;

        case WM_KEYDOWN:
            switch (LOWORD(wParam))
            {
                case VK_F1:
                    isPaused = !isPaused;
                    updateMenu(hMenu);
                    break;

                case VK_F2:
                    resetCpu(&g_SpaceInvaders);
                    break;

                case VK_ESCAPE:
                    ExitProcess(0);
                    break;
            }
            break;

        case WM_COMMAND:
            switch  (LOWORD(wParam))
            {
//                case ID_MENU_FILEOPEN:
//                    if(!selectBinFilename())
//                    {
//                        MessageBox(hwnd, "Error selecting filename!", "Error", MB_ICONERROR);
//                        #ifdef DEBUG
//                            puts("Error selecting filename");
//                        #endif // DEBUG
//                        break;
//                    }
//
//                    if(!loadRom(binFilename))
//                    {
//                        MessageBox(hwnd, "Error loading file!", "Error", MB_ICONERROR);
//                        #ifdef DEBUG
//                            puts("Error loading file");
//                        #endif // DEBUG
//                        break;
//                    }
//                    break;

                case IDM_PAUSE:
                    isPaused = !isPaused;
                    updateMenu(hMenu);
                    break;

                case IDM_RESET:
                    resetCpu(&g_SpaceInvaders);
                    break;

                case IDM_EXIT:
                    PostQuitMessage(0);
                    break;

//                case IDM_EXIT:
//                    PostQuitMessage(0);
//                    break;

                case IDM_ABOUT:
                    MessageBox(hwnd, "8080 Emulator by Luke Zimmerer", "About", MB_ICONINFORMATION);
                    break;
            }
            break;

        case WM_DESTROY:
            PostQuitMessage(0);
            break;

        default:
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}
