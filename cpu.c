#include <windows.h>
//#include <stdbool.h>
#include <stdio.h>
#include "cpu.h"
#include "instructions.h"

size_t fileSize;

// FPT for i8080A subroutines
opcodes i8080A_opcodes[0x100] =
{/*   0        1        2        3        4        5        6        7        8        9        A        B        C        D        E        F   */
 /*0*/nop,     lxib,    staxb,   inxb,    inrb,    dcrb,    mvib,    rlc,     illegal, dadb,    ldaxb,   dcxb,    inrc,    dcrc,    mvic,    rrc,
 /*1*/illegal, lxid,    staxd,   inxd,    inrd,    dcrd,    mvid,    ral,     illegal, dadd,    ldaxd,   dcxd,    inre,    dcre,    mvie,    rar,
 /*2*/illegal, lxih,    shld,    inxh,    inrh,    dcrh,    mvih,    daa,     illegal, dadh,    lhld,    dcxh,    inrl,    dcrl,    mvil,    cma,
 /*3*/illegal, lxisp,   sta,     illegal, inrm,    dcrm,    mvim,    stc,     illegal, dadsp,   lda,     dcxsp,   inra,    dcra,    mvia,    cmc,
 /*4*/movbb,   movbc,   movbd,   movbe,   movbh,   movbl,   movbm,   movba,   movcb,   movcc,   movcd,   movce,   movch,   movcl,   movcm,   movca,
 /*5*/movdb,   movdc,   movdd,   movde,   movdh,   movdl,   movdm,   movda,   moveb,   movec,   moved,   movee,   moveh,   movel,   movem,   movea,
 /*6*/movhb,   movhc,   movhd,   movhe,   movhh,   movhl,   movhm,   movha,   movlb,   movlc,   movld,   movle,   movlh,   movll,   movlm,   movla,
 /*7*/movmb,   movmc,   movmd,   movme,   movmh,   movml,   hlt,     movma,   movab,   movac,   movad,   movae,   movah,   moval,   movam,   movaa,
 /*8*/addb,    addc,    addd,    adde,    addh,    addl,    addm,    adda,    adcb,    adcc,    adcd,    adce,    adch,    adcl,    adcm,    adca,
 /*9*/subb,    subc,    subd,    sube,    subh,    subl,    subm,    sbba,    sbbb,    sbbc,    sbbd,    sbbe,    sbbh,    sbbl,    sbbm,    sbba,
 /*A*/anab,    anac,    anad,    anae,    anah,    anal,    anam,    anaa,    xrab,    xrac,    xrad,    xrae,    xrah,    xral,    xram,    xraa,
 /*B*/orab,    orac,    orad,    orae,    orah,    oral,    oram,    oraa,    cmpb,    cmpc,    cmpd,    cmpe,    cmph,    cmpl,    cmpm,    cmpa,
 /*C*/rnz,     popb,    jnz,     jmp,     cnz,     pushb,   adi,     rst0,    rz,      ret,     jz,      illegal, cz,      call,    aci,     rst1,
 /*D*/rnc,     popd,    jnc,     out,     cnc,     pushd,   sui,     rst2,    rc,      illegal, jc,      in,      cc,      illegal, sbi,     rst3,
 /*E*/rpo,     poph,    jpo,     xthl,    cpo,     pushh,   ani,     rst4,    cpe,     pchl,    jpe,     xchg,    cpe,     illegal, xri,     rst5,
 /*F*/cp,      poppsw,  jp,      di,      cp,      pushpsw, ori,     rst6,    rm,      sphl,    jm,      ei,      cm,      illegal, cpi,     rst7
};

// Opcode mnemonics
const char *i8080A_mnemonics[0x100] =
{/*   0          1          2          3          4          5           6          7          8          9          A          B          C          D          E          F       */
 /*0*/"NOP",     "LXI B",   "STAX B",  "INX B",   "INR B",   "DCR B",    "MVI B",   "RLC",     "Illegal", "DAD B",   "LDAX B",  "DCX B",   "INR C",   "DCR C",   "MVI C",   "RRC",
 /*1*/"Illegal", "LXI D",   "STAX D",  "INX D",   "INR D",   "DCR D",    "MVI D",   "RAL",     "Illegal", "DAD D",   "LDAX D",  "DCX D",   "INR E",   "DCR E",   "MVI E",   "RAR",
 /*2*/"Illegal", "LXI H",   "SHLD",    "INX H",   "INR H",   "DCR H",    "MVI H",   "DAA",     "Illegal", "DAD H",   "LHLD",    "DCX H",   "INR L",   "DCR L",   "MVI L",   "CMA",
 /*3*/"Illegal", "LXI SP",  "STA",     "Illegal", "INR M",   "DCR M",    "MVI M",   "STC",     "Illegal", "DAD SP",  "LDA",     "DCX SP",  "INR A",   "DCR A",   "MVI A",   "CMC",
 /*4*/"MOV B,B", "MOV B,C", "MOV B,D", "MOV B,E", "MOV B,H", "MOV B,L",  "MOV B,M", "MOV B,A", "MOV C,B", "MOV C,C", "MOV C,D", "MOV C,E", "MOV C,H", "MOV C,L", "MOV C,M", "MOV C,A",
 /*5*/"MOV D,B", "MOV D,C", "MOV D,D", "MOV D,E", "MOV D,H", "MOV D,L",  "MOV D,M", "MOV D,A", "MOV E,B", "MOV E,C", "MOV E,D", "MOV E,E", "MOV E,H", "MOV E,L", "MOV E,M", "MOV E,A",
 /*6*/"MOV H,B", "MOV H,C", "MOV H,D", "MOV H,E", "MOV H,H", "MOV H,L",  "MOV H,M", "MOV H,A", "MOV L,B", "MOV L,C", "MOV L,D", "MOV L,E", "MOV L,H", "MOV L,L", "MOV L,M", "MOV L,A",
 /*7*/"MOV M,B", "MOV M,C", "MOV M,D", "MOV M,E", "MOV M,H", "MOV M,L",  "HLT",     "MOV M,A", "MOV A,B", "MOV A,C", "MOV A,D", "MOV A,E", "MOV A,H", "MOV A,L", "MOV A,M", "MOV A,A",
 /*8*/"ADD B",   "ADD C",   "ADD D",   "ADD E",   "ADD H",   "ADD L",    "ADD M",   "ADD A",   "ADC B",   "ADC C",   "ADC D",   "ADC E",   "ADC H",   "ADC L",   "ADC M",   "ADC A",
 /*9*/"SUB B",   "SUB C",   "SUB D",   "SUB E",   "SUB H",   "SUB L",    "SUB M",   "SBB A",   "SBB B",   "SBB C",   "SBB D",   "SBB E",   "SBB H",   "SBB L",   "SBB M",   "SBB A",
 /*A*/"ANA B",   "ANA C",   "ANA D",   "ANA E",   "ANA H",   "ANA L",    "ANA M",   "ANA A",   "XRA B",   "XRA C",   "XRA D",   "XRA E",   "XRA H",   "XRA L",   "XRA M",   "XRA A",
 /*B*/"ORA B",   "ORA C",   "ORA D",   "ORA E",   "ORA H",   "ORA L",    "ORA M",   "ORA A",   "CMP B",   "CMP C",   "CMP D",   "CMP E",   "CMP H",   "CMP L",   "CMP M",   "CMP A",
 /*C*/"RNZ",     "POP B",   "JNZ",     "JMP",     "CNZ",     "PUSHB",    "ADI",     "RST 0",   "RZ",      "RET",     "JZ",      "Illegal", "CZ",      "CALL",    "ACI",     "RST 1",
 /*D*/"RNC",     "POP D",   "JNC",     "OUT",     "CNC",     "PUSH D",   "SUI",     "RST 2",   "RC",      "Illegal", "JC",      "IN",      "CC",      "Illegal", "SBI",     "RST 3",
 /*E*/"CPO",     "POP H",   "JPO",     "XTHL",    "CPO",     "PUSH H",   "ANI",     "RST 4",   "RPE",     "PCHL",    "JPE",     "XCHG",    "CPE",     "Illegal", "XRI",     "RST 5",
 /*F*/"RP",      "POPPSW",  "JP",      "DI",      "CP",      "PUSH PSW", "ORI",     "RST 6",   "CM",      "SPHL",    "JM",      "EI",      "CM",      "Illegal", "CPI",     "RST 7"
};

// Z80 mnemonics, not complete yet
const char *Z80_mnemonics[0x100] =
{/*   0          1          2          3             4          5           6          7          8          9           A          B           C          D          E          F       */
 /*0*/"NOP",     "LD BC",   "STAX B",  "INX B",      "INC B",   "DEC B",    "MVI B",   "RLCA",    "Illegal", "ADD HL,BC", "LDAX B",  "DCX B",    "INC C",   "DEC C",   "MVI C",   "RRCA",
 /*1*/"Illegal", "LD DE",   "STAX D",  "INX D",      "INC D",   "DEC D",    "MVI D",   "RLA",     "Illegal", "ADD HL,DE", "LDAX D",  "DCX D",    "INC E",   "DEC E",   "MVI E",   "RRA",
 /*2*/"Illegal", "LD HL",   "LD HL",   "INX H",      "INC H",   "DEC H",    "MVI H",   "DAA",     "Illegal", "ADD HL,HL", "LD HL",   "DCX H",    "INC L",   "DEC L",   "MVI L",   "CPL",
 /*3*/"Illegal", "LD SP",   "STA",     "Illegal",    "INC M",   "DEC M",    "MVI M",   "SCF",     "Illegal", "ADD HL,SP", "LDA",     "DCX SP",   "INC A",   "DEC A",   "MVI A",   "CCF",
 /*4*/"LD B,B",  "LD B,C",  "LD B,D",  "LD B,E",     "LD B,H",  "LD B,L",   "LD B,M",  "LD B,A",  "LD C,B",  "LD C,C",    "LD C,D",  "LD C,E",   "LD C,H",  "LD C,L",  "LD C,M",  "LD C,A",
 /*5*/"LD D,B",  "LD D,C",  "LD D,D",  "LD D,E",     "LD D,H",  "LD D,L",   "LD D,M",  "LD D,A",  "LD E,B",  "LD E,C",    "LD E,D",  "LD E,E",   "LD E,H",  "LD E,L",  "LD E,M",  "LD E,A",
 /*6*/"LD H,B",  "LD H,C",  "LD H,D",  "LD H,E",     "LD H,H",  "LD H,L",   "LD H,M",  "LD H,A",  "LD L,B",  "LD L,C",    "LD L,D",  "LD L,E",   "LD L,H",  "LD L,L",  "LD L,M",  "LD L,A",
 /*7*/"LD M,B",  "LD M,C",  "LD M,D",  "LD M,E",     "LD M,H",  "LD M,L",   "HLT",     "LD M,A",  "LD A,B",  "LD A,C",    "LD A,D",  "LD A,E",   "LD A,H",  "LD A,L",  "LD A,M",  "LD A,A",
 /*8*/"ADD A,B", "ADD A,C", "ADD A,D", "ADD A,E",    "ADD A,H", "ADD A,L",  "ADD A,M", "ADD A,A", "ADC A,B", "ADC A,C",   "ADC A,D", "ADC A,E",  "ADC A,H", "ADC A,L", "ADC A,M", "ADC A",
 /*9*/"SUB B",   "SUB C",   "SUB D",   "SUB E",      "SUB H",   "SUB L",    "SUB M",   "SBB A",   "SBB B",   "SBB C",     "SBB D",   "SBB E",    "SBB H",   "SBB L",   "SBB M",   "SBB A",
 /*A*/"AND B",   "AND C",   "AND D",   "AND E",      "AND H",   "AND L",    "AND M",   "AND A",   "XOR B",   "XOR C",     "XOR D",   "XOR E",    "XOR H",   "XOR L",   "XOR M",   "XOR A",
 /*B*/"OR B",    "OR C",    "OR D",    "OR E",       "OR H",    "OR L",     "OR M",    "OR A",    "CP B",    "CP C",      "CP D",    "CP E",     "CP H",    "CP L",    "CP M",    "CP A",
 /*C*/"RNZ",     "POP B",   "JP NZ",   "JP",         "CALL NZ", "PUSHB",    "ADI",     "RST 0",   "RZ",      "RET",       "JP Z",    "Illegal",  "CALL Z",  "CALL",    "ACI",     "RST 1",
 /*D*/"RNC",     "POP D",   "JP NC",   "OUT",        "CALL NC", "PUSH D",   "SUI",     "RST 2",   "RC",      "Illegal",   "JP C",    "IN",       "CALL C",  "Illegal", "SBI",     "RST 3",
 /*E*/"CPO",     "POP H",   "JP PO",   "EX (SP),HL", "CALL PO", "PUSH H",   "AND",     "RST 4",   "CPE",     "JP (HL)",   "JP PE",   "EX DE,HL", "CALL PE", "Illegal", "XRI",     "RST 5",
 /*F*/"CP",      "POPPSW",  "JP P",    "DI",         "CALL P",  "PUSH PSW", "OR",      "RST 6",   "CM",      "LD SP,HL",  "JP M",    "EI",       "CALL M",  "Illegal", "CP",      "RST 7"
};

// Opcode cycles
const BYTE i8080A_cycles[0x100] =
{/*   0   1   2   3   4   5   6   7   8   9   A   B   C   D   E   F*/
 /*0*/4,  10, 7,  5,  5,  5,  7,  4,  0,  10, 7,  5,  5,  5,  7,  4,
 /*1*/0,  10, 7,  5,  5,  5,  7,  4,  0,  10, 7,  5,  5,  5,  7,  4,
 /*2*/0,  10, 16, 5,  5,  5,  7,  4,  0,  10, 7,  5,  5,  5,  7,  11,
 /*3*/0,  10, 13, 0,  5,  5,  7,  0,  0,  10, 13, 5,  5,  5,  7,  0,
 /*4*/5,  5,  5,  5,  5,  5,  5,  4,  5,  5,  5,  5,  5,  5,  5,  11,
 /*5*/5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,
 /*6*/5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,
 /*7*/5,  5,  5,  5,  5,  5,  7,  5,  5,  5,  5,  5,  5,  5,  5,  5,
 /*8*/4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,
 /*9*/4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,
 /*A*/4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,
 /*B*/4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,
 /*C*/5,  10, 10, 10, 11, 11, 0,  11, 11, 10, 0,  10, 11, 17, 7,  11,
 /*D*/5,  10, 10, 10, 11, 11, 7,  11, 11, 0,  10, 10, 11, 0,  7,  11,
 /*E*/11, 10, 10, 18, 11, 11, 7,  11, 11, 5,  10, 4,  11, 0,  7,  11,
 /*F*/11, 10, 10, 4,  11, 11, 7,  11, 11, 5,  10, 4,  11, 0,  7,  11
};

/*
    ----------------------------------------
    initializeCpu()
        Initialize CPU state.
    ----------------------------------------
*/
void initializeCpu(i8080 *myi8080)
{
    if (!myi8080) {
        return;
    }
    
    myi8080->pc.w = 0x0000;
    myi8080->sp.w = 0xFFFF;

    myi8080->a    = 0;
    myi8080->bc.w = 0;
    myi8080->de.w = 0;
    myi8080->hl.w = 0;

    myi8080->psw  = 0;
    myi8080->s    = 0;
    myi8080->z    = 0;
    myi8080->ac   = 0;
    myi8080->p    = 0;
    myi8080->cy   = 0;

    myi8080->intEnabled = 0;
    myi8080->intPending = 0;
    myi8080->cycleCount = 0;

    ZeroMemory(myi8080->ports, 18);
    ZeroMemory(myi8080->mainMemory, MEM_BYTES);

    myi8080->shift_byte1  = 0;
    myi8080->shift_byte2  = 0;
    myi8080->shift_offset = 0;
}

/*
    -----------------------------
    resetCpu()
        Send reset signal to CPU.
    -----------------------------
*/
void resetCpu(i8080 *myi8080)
{
    if (!myi8080) {
        return;
    }

    myi8080->pc.w = 0x0000;
    myi8080->sp.w = 0xFFFF;

    myi8080->a    = 0;
    myi8080->bc.w = 0;
    myi8080->de.w = 0;
    myi8080->hl.w = 0;

    myi8080->psw  = 0;
    myi8080->s    = 0;
    myi8080->z    = 0;
    myi8080->ac   = 0;
    myi8080->p    = 0;
    myi8080->cy   = 0;

    myi8080->intEnabled = 0;
    myi8080->intPending = 0;
    myi8080->cycleCount = 0;

    ZeroMemory(myi8080->ports, 18);
    //ZeroMemory(myi8080->mainMemory, MEM_BYTES);

    myi8080->shift_byte1  = 0;
    myi8080->shift_byte2  = 0;
    myi8080->shift_offset = 0;
}

/*
    ---------------------------------
    loadRom()
        Load the Space Invaders roms.
        invaders.h  0x0000 - 0x07FF
        invaders.g  0x0800 - 0x0FFF
        invaders.f  0x1000 - 0x17FF
        invaders.e  0x1800 - 0x1FFF
    ---------------------------------
*/
bool loadRom(i8080 *myi8080, const char *romPath, unsigned short address)
{
    if (!myi8080 || !romPath) {
        return FALSE;
    }

    FILE *pFile = fopen(romPath, "rb");

    if (!pFile) {
        return FALSE;
    }

    fseek(pFile, 0, SEEK_END);
    unsigned short fileSize = ftell(pFile);
    rewind(pFile);

    if (fileSize != SPACEINVADERS_ROM_SIZE) {
        fclose(pFile);
        return FALSE;
    }

    fread(&myi8080->mainMemory[address], sizeof(unsigned char), fileSize, pFile);
    fclose(pFile);
    return TRUE;
}

/*
    --------------------------------------------------------
    executeCycles()
        Execute opcodes until a number of CPU cycles equal
        to nCycles have elapsed. Called 60 times per seceond.
    --------------------------------------------------------
*/
void executeCycles(i8080 *myi8080, unsigned int nCycles)
{
    if (!myi8080 || nCycles == 0) {
        return;
    }

    myi8080->cycleCount = nCycles;

    while (myi8080->cycleCount > 0) {
        // Fetch opcode
        myi8080->opcode = myi8080->mainMemory[myi8080->pc.w];
        // Call opcode function from FPT
        i8080A_opcodes[myi8080->opcode]();
        // Decrement cycle count by cycles required for this instruction
        myi8080->cycleCount -= i8080A_cycles[myi8080->opcode];
    }
}

/*
    ---------------------------------
    generateInterrupt()
        Send interrupt signal to CPU.
    ---------------------------------
*/
void generateInterrupt(BYTE interruptNo)
{
    if (INTE) {
        g_SpaceInvaders.intEnabled = 0;
        g_SpaceInvaders.intPending = 0;
        g_SpaceInvaders.sp.w -= 2;
        PUSH_WORD(g_SpaceInvaders.pc.w);
        g_SpaceInvaders.pc.w = interruptNo * 8;
        g_SpaceInvaders.cycleCount -= 11;
    } else {
        g_SpaceInvaders.intPending = 0x80 | interruptNo;
    }
}

void debug(int cycles)
{
    printf("PC: 0x%04X  ", REG_PC);
    printf("SP: 0x%04X  ", REG_SP);
    printf("Opcode: %02X (%s)  ", OPCODE, i8080A_mnemonics[OPCODE]);
    printf("Address: 0x%04X  ", GET_WORD(REG_PC + 1));

    printf("Stack: 0x%04X\n", (MEM[REG_SP + 1] << 8) | MEM[REG_SP]);

    printf("Cycles remaining: %d\n", cycles);

    printf("REG_A: %02X BC: %04X DE: %04X HL: %04X M: %02X\n\n", REG_A, REG_BC, REG_DE, REG_HL, REG_M);
}
