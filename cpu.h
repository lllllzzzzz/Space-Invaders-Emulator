#ifndef CPU8080_H_INCLUDED
#define CPU8080_H_INCLUDED

#include <stdbool.h>

#define DEBUG

#define I8080_ADDRESS_SPACE         65535
#define I8080_NUM_IO_PORTS          256
#define SPACEINVADERS_ROM_SIZE      2048

#define INVADERS_H_ROM_ADDRESS      0x0000
#define INVADERS_G_ROM_ADDRESS      0x0800
#define INVADERS_F_ROM_ADDRESS      0x1000
#define INVADERS_E_ROM_ADDRESS      0x1800

#define NUM_PORTS                   9
#define PORTS_BYTES                 18
#define MEM_BYTES                   0xFFFF
#define ROM_BYTES                   0x2000
#define RAM_BYTES                   0x0400
#define VRAM_BYTES                  0x1C00
#define ROM_OFFSET                  0x0000
#define RAM_OFFSET                  0x2000
#define VRAM_OFFSET                 0x2400
#define MIRROR_OFFSET               0x4000

#define MEM                         g_SpaceInvaders.mainMemory
#define STACK                       g_SpaceInvaders.mainMemory
#define REG_PC                      g_SpaceInvaders.pc.w
#define REG_SP                      g_SpaceInvaders.sp.w
#define OPCODE                      g_SpaceInvaders.opcode
#define RESULT                      g_SpaceInvaders.result
#define INTE                        g_SpaceInvaders.intEnabled
#define IPEND                       g_SpaceInvaders.intPending

#define REG_A                       g_SpaceInvaders.a
#define REG_B                       g_SpaceInvaders.bc.b.h
#define REG_C                       g_SpaceInvaders.bc.b.l
#define REG_D                       g_SpaceInvaders.de.b.h
#define REG_E                       g_SpaceInvaders.de.b.l
#define REG_H                       g_SpaceInvaders.hl.b.h
#define REG_L                       g_SpaceInvaders.hl.b.l
#define REG_M                       g_SpaceInvaders.hl.w
#define REG_BC                      g_SpaceInvaders.bc.w
#define REG_DE                      g_SpaceInvaders.de.w
#define REG_HL                      g_SpaceInvaders.hl.w

#define INPORT_0                    g_SpaceInvaders.ports[0]
#define INPORT_1                    g_SpaceInvaders.ports[1]
#define INPORT_2                    g_SpaceInvaders.ports[2]
#define INPORT_3                    g_SpaceInvaders.ports[3]
#define OUTPORT_2                   g_SpaceInvaders.ports[4]
#define OUTPORT_3                   g_SpaceInvaders.ports[5]
#define OUTPORT_4                   g_SpaceInvaders.ports[6]
#define OUTPORT_5                   g_SpaceInvaders.ports[7]
#define OUTPORT_6                   g_SpaceInvaders.ports[8]

#define SHIFT_REG                   g_SpaceInvaders.ports[3]
#define SHIFT_OFFSET                g_SpaceInvaders.ports[4]

#define GET_WORD(addr)              (g_SpaceInvaders.mainMemory[addr + 1] << 8) | g_SpaceInvaders.mainMemory[addr]
#define GET_BYTE(addr)              g_SpaceInvaders.mainMemory[addr]

// FLAG_PSW status bits
#define FLAG_PSW                    g_SpaceInvaders.psw     /*Processor status word  */
#define FLAG_S                      g_SpaceInvaders.s       /*Sign flag         bit 7*/
#define FLAG_Z                      g_SpaceInvaders.z       /*Zero flag         bit 6*/
#define FLAG_AC                     g_SpaceInvaders.ac      /*Auxilliary Carry  bit 4*/
#define FLAG_P                      g_SpaceInvaders.p       /*Parity            bit 2*/
#define FLAG_CY                     g_SpaceInvaders.cy      /*Carry             bit 0*/

#define BIT_S                       0x80
#define BIT_Z                       0x40
#define BIT_AC                      0x10
#define BIT_P                       0x04
#define BIT_CY                      0x01

#define RST_0                       0x0000
#define RST_8                       0x0008
#define RST_10                      0x0010
#define RST_18                      0x0018
#define RST_20                      0x0020
#define RST_28                      0x0028
#define RST_30                      0x0030
#define RST_38                      0x0038

/* Calculate Parity flag */
#define CALC_P(x)                   BYTE bits = 0;                      \
                                    for(int i = 0; i < 8; i++)          \
                                        bits += ((0x80 >> i) & (x));    \
                                    FLAG_P = !(bits % 2)
/* Calculate Carry flag */
#define CALC_C(value)               FLAG_CY = ((value) > 0xFF || (value) < 0x00)
/* Calculate Auxiliary Carry flag */
#define CALC_AC(value)              FLAG_AC = (A & 0xF) > (value & 0xF)
/* Calculate Sign flag */
#define CALC_S(value)               FLAG_S = ((value) >> 7)
/* Calculate Zero flag */
#define CALC_Z(value)               FLAG_Z = value ? 0 : 1;

/* Set Processor Status Word */
#define SET_PSW()                   FLAG_PSW = FLAG_S ? FLAG_PSW | BIT_S : FLAG_PSW & ~BIT_S;      \
                                    FLAG_PSW = FLAG_Z ? FLAG_PSW | BIT_Z : FLAG_PSW & ~BIT_Z;      \
                                    FLAG_PSW = FLAG_AC ? FLAG_PSW | BIT_AC : FLAG_PSW & ~BIT_AC;   \
                                    FLAG_PSW = FLAG_P ? FLAG_PSW | BIT_P : FLAG_PSW & ~BIT_P;      \
                                    FLAG_PSW = FLAG_CY ? FLAG_PSW | BIT_CY : FLAG_PSW & ~BIT_CY;

/* Retrieve FLAG_PSW into flags */
#define GET_PSW()                   FLAG_S = FLAG_PSW & BIT_S;       \
                                    FLAG_Z = FLAG_PSW & BIT_Z;       \
                                    FLAG_AC = FLAG_PSW & BIT_AC;     \
                                    FLAG_P = FLAG_PSW & BIT_P;       \
                                    FLAG_CY = FLAG_PSW & BIT_CY;

#define PUSH_WORD(value)            g_SpaceInvaders.mainMemory[g_SpaceInvaders.sp.w] = value & 0x00FF;    \
                                    g_SpaceInvaders.mainMemory[g_SpaceInvaders.sp.w + 1] = (value >> 8) & 0xFF;
#define POP_WORD()                  (g_SpaceInvaders.mainMemory[g_SpaceInvaders.sp.w + 1] << 8) | g_SpaceInvaders.mainMemory[g_SpaceInvaders.sp.w];

// FPT for opcode subroutines
typedef void (*opcodes)();
opcodes i8080A_opcodes[0x100];
const BYTE i8080A_cycles[0x100];

typedef union
{
    WORD w;
    struct
    {
        BYTE l, h;
    } b;
} i8080Reg;

typedef struct i8080
{
    i8080Reg bc, de, hl, pc, sp;            /* 16-bit register pairs */
    unsigned char a, psw, s, z, ac, p, cy;  /* Processor Status Word - S Z 0 AC 0 P 0 CY */

//  signed int result;                      /* Result of arithmetic operations */
    signed int cycleCount;                  /* Count cycles for instructions */

    BYTE opcode;
    BYTE mainMemory[MEM_BYTES];

    BYTE stopped;
    BYTE intEnabled;                        /* Interrupt Enable flip/flop */
    BYTE intPending;

    WORD ports[NUM_PORTS];

    BYTE shift_byte1;
    BYTE shift_byte2;
    BYTE shift_offset;
} i8080;
i8080 g_SpaceInvaders;

// 8080 CPU function declarations
void initializeCpu(i8080 *myi8080);
void resetCpu(i8080 *myi8080);
void executeCycles(i8080 *myi8080, unsigned nCycles);
void generateInterrupt(BYTE interruptNo);
void debug();
bool loadRom(i8080 *myi8080, const char *romPath, unsigned short address);

#endif // CPU8080_H_INCLUDED
