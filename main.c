#include <windows.h>
#include <stdio.h>
#include <stdbool.h>
#include "cpu.h"
#include "resource.h"

#define INVADERS_H_ROM_PATH     ""
#define INVADERS_G_ROM_PATH     ""
#define INVADERS_F_ROM_PATH     ""
#define INVADERS_E_ROM_PATH     ""
#define TIMER_INTERVAL          17
#define CYCLES                  33333
#define ORG_WIDTH               224
#define ORG_HEIGHT              256
#define WIN_WIDTH               448
#define WIN_HEIGHT              512
#define DEBUG
#define WINDOW_CLASS_NAME       "Space Invaders Emulator"

/* Globals */
HINSTANCE       g_hInst   = 0;
HWND            g_hWnd    = 0;
HBITMAP         g_hBmp    = 0;
HBITMAP         g_hBmpOld = 0;
HDC             g_hMemDC  = 0;
UINT32*         g_pPixels = 0;
BYTE            g_Screen[ORG_WIDTH * ORG_HEIGHT];
BOOL            isPaused;
HWND            hwnd;
MMRESULT        timerEvent;
const char      szClassName[] = "WindowClass";

/* Callback prototypes */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);
void CALLBACK timerCallback(UINT, UINT, DWORD, DWORD, DWORD);
/* Function prototypes */
static void drawBitmap();
static void checkInput(i8080*);

// -------------------------------------------------------------------------------
// Draw bitmap to the screen, image is rotated 90 degrees to correct aspect ratio.
// -------------------------------------------------------------------------------
static void drawBitmap()
{
    const int GFX_HEIGHT = 224;
    const int GFX_WIDTH  = 32;

    // Pointer to the VRAM block in memory at 0x2400
    BYTE *gfx = &g_SpaceInvaders.mainMemory[VRAM_OFFSET];

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

// --------------------------------------------------------------------------
// Read keyboard input and write to P1/P2 controls ports.
// Each input port is a bitmask that stores the state of the player controls.
// --------------------------------------------------------------------------
static void checkInput(i8080 *myi8080)
{
    INPORT_1 = ((GetAsyncKeyState('3') & 0x8000)) ? INPORT_1 | 0x1  : INPORT_1 & ~0x1;  // Insert coin
    INPORT_1 = ((GetAsyncKeyState('2') & 0x8000)) ? INPORT_1 | 0x2  : INPORT_1 & ~0x2;  // P2 start
    INPORT_1 = ((GetAsyncKeyState('1') & 0x8000)) ? INPORT_1 | 0x4  : INPORT_1 & ~0x4;  // P1 start
    INPORT_1 = ((GetAsyncKeyState('W') & 0x8000)) ? INPORT_1 | 0x10 : INPORT_1 & ~0x10; // P1 shoot
    INPORT_1 = ((GetAsyncKeyState('Q') & 0x8000)) ? INPORT_1 | 0x20 : INPORT_1 & ~0x20; // P1 left
    INPORT_1 = ((GetAsyncKeyState('E') & 0x8000)) ? INPORT_1 | 0x40 : INPORT_1 & ~0x40; // P1 right
    INPORT_2 = ((GetAsyncKeyState('T') & 0x8000)) ? INPORT_2 | 0x10 : INPORT_2 & ~0x10; // P2 shoot
    INPORT_2 = ((GetAsyncKeyState('R') & 0x8000)) ? INPORT_1 | 0x20 : INPORT_2 & ~0x20; // P2 left
    INPORT_2 = ((GetAsyncKeyState('Y') & 0x8000)) ? INPORT_1 | 0x40 : INPORT_2 & ~0x40; // P2 right
}

// --------------------------------------------------------------------
// This is a callback function that is called when the timer overflows.
// The 8080 processor is clocked at 2MHz, so execute ~3400 instructions
// in 1/60 second intervals (~2000000 instructions per second).
// --------------------------------------------------------------------
void CALLBACK timerCallback(UINT uID, UINT uMsg, DWORD dwUser, DWORD dw1, DWORD dw2)
{
    if (isPaused) {
        return;
    }

    // There is a bug where the vertical movement of the enemy ships is too fast,
    // causing enemies to crash into the player so the game is impossible to play.
    // I think that happens because the interrupt timings are inaccurate or
    // the barrel shift register isn't emulated correctly.

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

int WINAPI WinMain (HINSTANCE hThisInstance, HINSTANCE hPrevInstance, LPSTR lpszArgument, int nCmdShow)
{
    //HWND hwnd;
    MSG messages;
    WNDCLASSEX wincl;

    wincl.hInstance     = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc   = WindowProcedure;
    wincl.style         = CS_DBLCLKS;
    wincl.cbSize        = sizeof (WNDCLASSEX);
    wincl.hIcon         = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm       = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor       = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName  = MAKEINTRESOURCE(ID_MENU);
    wincl.cbClsExtra    = 0;
    wincl.cbWndExtra    = 0;
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;

    if (!RegisterClassEx(&wincl)) {
        return EXIT_FAILURE;
    }

    g_hWnd = CreateWindowEx(0, szClassName, WINDOW_CLASS_NAME,
           WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
           464, 570, HWND_DESKTOP, NULL, hThisInstance, NULL);
    ShowWindow (g_hWnd, nCmdShow);

    BITMAPINFO bmi;
    bmi.bmiHeader.biSize            = sizeof (BITMAPINFO);
    bmi.bmiHeader.biWidth           = WIN_WIDTH;
    bmi.bmiHeader.biHeight          = -WIN_HEIGHT;
    bmi.bmiHeader.biPlanes          = 1;
    bmi.bmiHeader.biBitCount        = 32;
    bmi.bmiHeader.biCompression     = BI_RGB;
    bmi.bmiHeader.biSizeImage       = 0;
    bmi.bmiHeader.biXPelsPerMeter   = 0;
    bmi.bmiHeader.biYPelsPerMeter   = 0;
    bmi.bmiHeader.biClrUsed         = 0;
    bmi.bmiHeader.biClrImportant    = 0;
    bmi.bmiColors[0].rgbBlue        = 0;
    bmi.bmiColors[0].rgbGreen       = 0;
    bmi.bmiColors[0].rgbRed         = 0;
    bmi.bmiColors[0].rgbReserved    = 0;

    HDC hdc   = GetDC(hwnd);
    g_hBmp    = CreateDIBSection(hdc, &bmi, DIB_RGB_COLORS, (void**) &g_pPixels, NULL, 0);
    g_hMemDC  = CreateCompatibleDC(hdc);
    g_hBmpOld = (HBITMAP) SelectObject(g_hMemDC, g_hBmp);

    ReleaseDC(hwnd, hdc);

    while (GetMessage(&messages, NULL, 0, 0)) {
        TranslateMessage(&messages);
        DispatchMessage(&messages);
    }

    return messages.wParam;
}

LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HWND hMenu = GetMenu(hwnd);

    PAINTSTRUCT ps;
    HDC hdc;

    switch (message) {
        case WM_CREATE:
            // Initialize the CPU, reset registers/memory
            initializeCpu(&g_SpaceInvaders);

            // The emulator loads 4 roms to run the game.
            // If any of these roms are missing, the program will terminate.

            // Load invaders.h
            if (!loadRom(&g_SpaceInvaders, INVADERS_H_ROM_PATH, INVADERS_H_ROM_ADDRESS)) {
                #ifdef DEBUG
                puts("ERROR: Cannot find invaders.h! Terminating emulator...");
                #endif
                return EXIT_FAILURE;
            }

            // Load invaders.g
            if (!loadRom(&g_SpaceInvaders, INVADERS_G_ROM_PATH, INVADERS_G_ROM_ADDRESS)) {
                #ifdef DEBUG
                puts("ERROR: Cannot find invaders.g! Terminating emulator...");
                #endif
                return EXIT_FAILURE;
            }

            // Load invaders.f
            if (!loadRom(&g_SpaceInvaders, INVADERS_F_ROM_PATH, INVADERS_F_ROM_ADDRESS)) {
                #ifdef DEBUG
                puts("ERROR: Cannot find invaders.f! Terminating emulator...");
                #endif
                return EXIT_FAILURE;
            }

            // Load invaders.e
            if (!loadRom(&g_SpaceInvaders, INVADERS_E_ROM_PATH, INVADERS_E_ROM_ADDRESS)) {
                #ifdef DEBUG
                puts("ERROR: Cannot find invaders.e! Terminating emulator...");
                #endif
                return EXIT_FAILURE;
            }

            // Start the timer
            timerEvent = timeSetEvent(TIMER_INTERVAL, 0, (LPTIMECALLBACK) timerCallback, 0, TIME_PERIODIC);
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
            switch (LOWORD(wParam)) {
                case VK_F1:
                    isPaused = !isPaused;
                    CheckMenuItem(hMenu, IDM_PAUSE, (isPaused) ? MF_CHECKED : MF_UNCHECKED);
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
            switch (LOWORD(wParam)) {
                case IDM_PAUSE:
                    isPaused = !isPaused;
                    CheckMenuItem(hMenu, IDM_PAUSE, (isPaused) ? MF_CHECKED : MF_UNCHECKED);
                    break;
                    
                case IDM_RESET:
                    resetCpu(&g_SpaceInvaders);
                    break;
                    
                case IDM_EXIT:
                    PostQuitMessage(0);
                    break;
                    
                case IDM_ABOUT:
                    MessageBox(hwnd, "Intel 8080 Space Invaders Emulator by Luke Zimmerer", "About", MB_ICONINFORMATION);
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
