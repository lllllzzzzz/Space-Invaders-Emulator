#include <windows.h>
#include <stdio.h>
#include "cpu.h"

/*
	------------------------------------------------------------------
	8-bit MOV instructions

	Syntax: 			MOV dst, src
	Flags affected: 	N/A
	Operation:			Move 1 byte from src register to dst register.
	------------------------------------------------------------------
*/
void movaa()	// 0x7F MOV A,A 	A <- A
{
	REG_A = REG_A;
	REG_PC++;
}
void movab()	// 0x78 MOV A,B 	A <- B
{
	REG_A = REG_B;
	REG_PC++;
}
void movac() 	// 0x79 MOV A,C 	A <- C
{
	REG_A = REG_C;
	REG_PC++;
}
void movad()	// 0x7A MOV A,D 	A <- D
{
	REG_A = REG_D;
	REG_PC++;
}
void movae()	// 0x7B MOV A,E 	A <- E
{
	REG_A = REG_E;
	REG_PC++;
}
void movah()	// 0x7C MOV A,H 	A <- H
{
	REG_A = REG_H;
	REG_PC++;
}
void moval()	// 0x7D MOV A,L 	A <- L
{
	REG_A = REG_L;
	REG_PC++;
}
void movam()	// 0x7E MOV A,M 	A <- (M)
{
	REG_A = MEM[REG_M];
	REG_PC++;
}
void movba()	// 0x47 MOV B,A 	B <- A
{
	REG_B = REG_A;
	REG_PC++;
}
void movbb()	// 0x40 MOV B,A 	B <- B
{
	REG_B = REG_B;
	REG_PC++;
}
void movbc()	// 0x41 MOV B,B 	B <- C
{
	REG_B = REG_C;
	REG_PC++;
}
void movbd()	// 0x42 MOV B,C 	B <- D
{
	REG_B = REG_D;
	REG_PC++;
}
void movbe()	// 0x43 MOV B,D 	B <- E
{
	REG_B = REG_E;
	REG_PC++;
}
void movbh()	// 0x44 MOV B,E 	B <- H
{
	REG_B = REG_H;
	REG_PC++;
}
void movbl()	// 0x45 MOV B,H 	B <- L
{
	REG_B = REG_L;
	REG_PC++;
}
void movbm()	// 0x46 MOV B,L 	B <- (M)
{
	REG_B = MEM[REG_M];
	REG_PC++;
}
void movca()	// 0x4F MOV C,A 	C <- A
{
	REG_C = REG_A;
	REG_PC++;
}
void movcb()	// 0x48 MOV C,B 	C <- B
{
	REG_C = REG_B;
	REG_PC++;
}
void movcc()	// 0x49 MOV C,C 	C <- C
{
	REG_C = REG_C;
	REG_PC++;
}
void movcd()	// 0x4A MOV C,D 	C <- D
{
	REG_C = REG_D;
	REG_PC++;
}
void movce()	// 0x4B MOV C,E 	C <- E
{
	REG_C = REG_E;
	REG_PC++;
}
void movch()	// 0x4C MOV C,H 	C <- H
{
	REG_C = REG_H;
	REG_PC++;
}
void movcl()	// 0x4D MOV C,L 	C <- L
{
	REG_C = REG_L;
	REG_PC++;
}
void movcm()	// 0x4E MOV C,M 	C <- (M)
{
	REG_C = MEM[REG_M];
	REG_PC++;
}
void movda()	// 0x57 MOV D,A 	D <- A
{
	REG_D = REG_A;
	REG_PC++;
}
void movdb()	// 0x50 MOV D,B 	D <- B
{
	REG_D = REG_B;
	REG_PC++;
}
void movdc()	// 0x51 MOV D,C 	D <- C
{
	REG_D = REG_C;
	REG_PC++;
}
void movdd()	// 0x52 MOV D,D 	D <- D
{
	REG_D = REG_D;
	REG_PC++;
}
void movde()	// 0x53 MOV D,E 	D <- E
{
	REG_D = REG_E;
	REG_PC++;
}
void movdh()	// 0x54 MOV D,H 	D <- H
{
	REG_D = REG_H;
	REG_PC++;
}
void movdl()	// 0x55 MOV D,L 	D <- L
{
	REG_D = REG_L;
	REG_PC++;
}
void movdm()	// 0x56 MOV D,M 	D <- (M)
{
	REG_D = MEM[REG_M];
	REG_PC++;
}
void movea()	// 0x5F MOV E,A 	E <- A
{
	REG_E = REG_A;
	REG_PC++;
}
void moveb()	// 0x58 MOV E,B 	E <- B
{
	REG_E = REG_B;
	REG_PC++;
}
void movec()	// 0x59 MOV E,C 	E <- C
{
	REG_E = REG_C;
	REG_PC++;
}
void moved()	// 0x5A MOV E,D 	E <- D
{
	REG_E = REG_D;
	REG_PC++;
}
void movee()	// 0x5B MOV E,E 	E <- E
{
	REG_E = REG_E;
	REG_PC++;
}
void moveh()	// 0x5C MOV E,H 	E <- H
{
	REG_E = REG_H;
	REG_PC++;
}
void movel()	// 0x5D MOV E,L 	E <- L
{
	REG_E = REG_L;
	REG_PC++;
}
void movem()	// 0x5E MOV E,M 	E <- (M)
{
	REG_E = MEM[REG_M];
	REG_PC++;
}
void movha()	// 0x67 MOV H,A 	H <- A
{
	REG_H = REG_A;
	REG_PC++;
}
void movhb()	// 0x60 MOV H,B 	H <- B
{
	REG_H = REG_B;
	REG_PC++;
}
void movhc()	// 0x61 MOV H,C 	H <- C
{
	REG_H = REG_C;
	REG_PC++;
}
void movhd()	// 0x62 MOV H,D 	H <- D
{
	REG_H = REG_D;
	REG_PC++;
}
void movhe()	// 0x63 MOV H,E 	H <- E
{
	REG_H = REG_E;
	REG_PC++;
}
void movhh()	// 0x64 MOV H,H 	H <- H
{
	REG_H = REG_H;
	REG_PC++;
}
void movhl()	// 0x65 MOV H,L 	H <- L
{
	REG_H = REG_L;
	REG_PC++;
}
void movhm()	// 0x66 MOV H,M 	H <- (M)
{
	REG_H = MEM[REG_M];
	REG_PC++;
}
void movla()	// 0x6F MOV L,A 	L <- A
{
	REG_L = REG_A;
	REG_PC++;
}
void movlb()	// 0x68 MOV L,B 	L <- B
{
	REG_L = REG_B;
	REG_PC++;
}
void movlc()	// 0x69 MOV L,C 	L <- C
{
	REG_L = REG_C;
	REG_PC++;
}
void movld()	// 0x6A MOV L,D 	L <- D
{
	REG_L = REG_D;
	REG_PC++;
}
void movle()	// 0x6B MOV L,E 	L <- E
{
	REG_L = REG_E;
	REG_PC++;
}
void movlh()	// 0x6C MOV L,H 	L <- H
{
	REG_L = REG_H;
	REG_PC++;
}
void movll()	// 0x6D MOV L,L 	L <- L
{
	REG_L = REG_L;
	REG_PC++;
}
void movlm()	// 0x6E MOV L,M 	L <- (M)
{
	REG_L = MEM[REG_M];
	REG_PC++;
}
void movma()	// 0x77 MOV M,A 	(M) <- A
{
	MEM[REG_M] = REG_A;
	REG_PC++;
}
void movmb()	// 0x70 MOV M,B 	(M) <- B
{
	MEM[REG_M] = REG_B;
	REG_PC++;
}
void movmc()	// 0x71 MOV M,C 	(M) <- C
{
	MEM[REG_M] = REG_C;
	REG_PC++;
}
void movmd()	// 0x72 MOV M,D 	(M) <- D
{
	MEM[REG_M] = REG_D;
	REG_PC++;
}
void movme()	// 0x73 MOV M,E 	(M) <- E
{
	MEM[REG_M] = REG_E;
	REG_PC++;
}
void movmh()	// 0x74 MOV M,H 	(M) <- H
{
	MEM[REG_M] = REG_H;
	REG_PC++;
}
void movml()	// 0x75 MOV M,L 	(M) <- L
{
	MEM[REG_M] = REG_L;
	REG_PC++;
}

/*
	----------------------------------------------------------------------
	16-bit Load/Store Immediate instructions

	Syntax: 			LXI dst, src
	Flags affected: 	N/A
	Operation:			Load src word into dst register pair (BC, DE, HL).
	----------------------------------------------------------------------
*/
void lxib()    // 0x01 LD B,word    BC <- word
{
	REG_BC = GET_WORD(REG_PC + 1);
	REG_PC += 3;
}
void lxid()    // 0x11 LD D,word    DE <- word
{
	REG_DE = GET_WORD(REG_PC + 1);
	REG_PC += 3;
}
void lxih()		// 0x21 LD H,word 	HL <- word
{
	REG_HL = GET_WORD(REG_PC + 1);
	REG_PC += 3;
}
void lxisp()	// 0x31 LD SP,word 	SP <- word
{
	REG_SP = GET_WORD(REG_PC + 1);
	REG_PC += 3;
}
void lhld() 	// 0x2A LHLD SP,(word) 	HL <- (word)
{
    REG_HL = (MEM[GET_WORD(REG_PC + 1) + 1] << 8) | MEM[GET_WORD(REG_PC + 1)];
	REG_PC += 3;
}
void shld() 	// 0x22 SHLD (word),SP    (word) <- HL
{
	MEM[GET_WORD(REG_PC + 1)] = REG_L;
	MEM[GET_WORD(REG_PC + 1) + 1] = REG_H;
	REG_PC += 3;
}
void sphl() // 0xF9
{
	REG_SP = REG_HL;
	REG_PC++;
}

/*
	-------------------------------------
	16-bit register exchange instructions
	-------------------------------------
*/
void xchg() // 0xEB
{
	unsigned short temp = REG_HL;

	REG_HL = REG_DE;
	REG_DE = temp;

	REG_PC++;
}
void xthl() // 0xE3
{
	unsigned char temp;

	temp = REG_L;
	REG_L = MEM[REG_SP];
	MEM[REG_SP] = temp;

	temp = REG_H;
	REG_H = MEM[REG_SP + 1];
	MEM[REG_SP + 1] = temp;

	REG_PC++;
}

/*
	------------------------------
	16-bit Load/Store instructions
	------------------------------
*/
void ldaxb() // 0x0A
{
	REG_A = MEM[REG_BC];
	REG_PC++;
}
void ldaxd() // 0x1A
{
	REG_A = MEM[REG_DE];
	REG_PC++;
}
void staxb() // 0x02
{
	MEM[REG_BC] = REG_A;
	REG_PC++;
}
void staxd() // 0x12
{
	MEM[REG_DE] = REG_A;
	REG_PC++;
}
void lda() // 0x3A
{
	REG_A = MEM[GET_WORD(REG_PC + 1)];
	REG_PC += 3;
}
void sta() // 0x32
{
	MEM[GET_WORD(REG_PC + 1)] = REG_A;
	REG_PC += 3;
}

/*
	--------------------------------------------------
	16-bit Move Immediate (MVI) instructions

	Syntax: 			MVI dst, src
	Flags affected: 	N/A
	Operation:			Move src byte to dst register.
	--------------------------------------------------
*/
void mvia() // 0x3E
{
	REG_A = GET_BYTE(REG_PC + 1);
	REG_PC += 2;
}
void mvib() // 0x06
{
	REG_B = GET_BYTE(REG_PC + 1);
	REG_PC += 2;
}
void mvic() // 0x0E
{
	REG_C = GET_BYTE(REG_PC + 1);
	REG_PC += 2;
}
void mvid() // 0x16
{
	REG_D = GET_BYTE(REG_PC + 1);
	REG_PC += 2;
}
void mvie() // 0x1E
{
	REG_E = GET_BYTE(REG_PC + 1);
	REG_PC += 2;
}
void mvih() // 0x26
{
	REG_H = GET_BYTE(REG_PC + 1);
	REG_PC += 2;
}
void mvil() // 0x2E
{
	REG_L = GET_BYTE(REG_PC + 1);
	REG_PC += 2;
}
void mvim() // 0x36
{
	MEM[REG_HL] = GET_BYTE(REG_PC + 1);
	REG_PC += 2;
}

/*
	----------------------------------------------------
	8-bit Add Byte (REG_ADD) instructions

	Syntax: 			ADD src
	Flags affected: 	S, Z, AC, P, C
	Operation:			Add src register to accumulator.
	----------------------------------------------------
*/
void adda()	// 0x87
{
	signed short result = REG_A + REG_A;

	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
	FLAG_CY = (result > 0xFF || result < 0x00);
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_A = result & 0xFF;
	REG_PC++;
}
void addb()	// 0x80
{
	signed short result = REG_A + REG_B;

	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
	FLAG_CY = (result > 0xFF || result < 0x00);
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_A = result & 0xFF;
	REG_PC++;
}
void addc() // 0x81
{
	signed short result = REG_A + REG_C;

	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
	FLAG_CY = (result > 0xFF || result < 0x00);
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_A = result & 0xFF;
	REG_PC++;
}
void addd() // 0x82
{
	signed short result = REG_A + REG_D;

	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
	FLAG_CY = (result > 0xFF || result < 0x00);
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_A = result & 0xFF;
	REG_PC++;
}
void adde() // 0x83
{
	signed short result = REG_A + REG_E;

	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
	FLAG_CY = (result > 0xFF || result < 0x00);
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_A = result & 0xFF;
	REG_PC++;
}
void addh() // 0x84
{
	signed short result = REG_A + REG_H;

	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
	FLAG_CY = (result > 0xFF || result < 0x00);
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_A = result & 0xFF;
	REG_PC++;
}
void addl() // 0x85
{
	signed short result = REG_A + REG_L;

	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
	FLAG_CY = (result > 0xFF || result < 0x00);
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_A = result & 0xFF;
	REG_PC++;
}
void addm() // 0x86
{
	signed short result = REG_A + MEM[REG_M];

	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
	FLAG_CY = (result > 0xFF || result < 0x00);
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_A = result & 0xFF;
	REG_PC++;
}
void adi() // 0xC6
{
	signed short result = REG_A + GET_BYTE(REG_PC + 1);

	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
	FLAG_CY = (result > 0xFF || result < 0x00);
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_A = result & 0xFF;
	REG_PC += 2;
}

/*
	------------------------------------------------------------
	8-bit Add Byte with Carry (REG_ADC) instructions

	Syntax: 			ADD src
	Flags affected: 	S, Z, AC, P, C
	Operation:			Add src register + carry to accumulator.
	------------------------------------------------------------
*/
void adca() // 0x8F
{
	signed short result = REG_A + REG_A + FLAG_CY;

	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
	FLAG_CY = (result > 0xFF || result < 0x00);
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;;
	CALC_P(result);;

	REG_A = result & 0xFF;
	REG_PC++;
}
void adcb() // 0x88
{
	signed short result = REG_A + REG_B + FLAG_CY;

	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
	FLAG_CY = (result > 0xFF || result < 0x00);
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_A = result & 0xFF;
	REG_PC++;
}
void adcc() // 0x89
{
	signed short result = REG_A + REG_C + FLAG_CY;

	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
	FLAG_CY = (result > 0xFF || result < 0x00);
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_A = result & 0xFF;
	REG_PC++;
}
void adcd() // 0x8A
{
	signed short result = REG_A + REG_D + FLAG_CY;

	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
	FLAG_CY = (result > 0xFF || result < 0x00);
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_A = result & 0xFF;
	REG_PC++;
}
void adce() // 0x8B
{
	signed short result = REG_A + REG_E + FLAG_CY;

	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
	FLAG_CY = (result > 0xFF || result < 0x00);
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_A = result & 0xFF;
	REG_PC++;
}
void adch() // 0x8C
{
	signed short result = REG_A + REG_H + FLAG_CY;

	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
	FLAG_CY = (result > 0xFF || result < 0x00);
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_A = result & 0xFF;
	REG_PC++;
}
void adcl() // 0x8D
{
	signed short result = REG_A + REG_L + FLAG_CY;

	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
	FLAG_CY = (result > 0xFF || result < 0x00);
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_A = result & 0xFF;
	REG_PC++;
}
void adcm() // 0x8E
{
	signed short result = REG_A + MEM[REG_M] + FLAG_CY;

	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
	FLAG_CY = (result > 0xFF || result < 0x00);
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_A = result & 0xFF;
	REG_PC++;
}
void aci() // 0xCE
{
	signed short result = REG_A + GET_BYTE(REG_PC + 1) + FLAG_CY;

	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
	FLAG_CY = (result > 0xFF || result < 0x00);
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_A = result & 0xFF;
	REG_PC += 2;
}

/*
	-----------------------------------------------------------
	8-bit Subtract Byte (SUB) instructions

	Syntax: 			ADD src
	Flags affected: 	S, Z, AC, P, C
	Operation:			Subtract src register from accumulator.
	-----------------------------------------------------------
*/
void suba() // 0x97
{
	signed short result = REG_A - REG_A;

	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
	FLAG_CY = (result > 0xFF || result < 0x00);
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_A = result & 0xFF;
	REG_PC++;
}
void subb() // 0x90
{
	signed short result = REG_A - REG_B;

	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
	FLAG_CY = (result > 0xFF || result < 0x00);
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_A = result & 0xFF;
	REG_PC++;
}
void subc() // 0x91
{
	signed short result = REG_A - REG_C;

	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
	FLAG_CY = (result > 0xFF || result < 0x00);
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_A = result & 0xFF;
	REG_PC++;
}
void subd() // 0x92
{
	signed short result = REG_A - REG_D;

	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
	FLAG_CY = (result > 0xFF || result < 0x00);
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_A = result & 0xFF;
	REG_PC++;
}
void sube() // 0x93
{
	signed short result = REG_A - REG_E;

	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
	FLAG_CY = (result > 0xFF || result < 0x00);
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_A = result & 0xFF;
	REG_PC++;
}
void subh() // 0x94
{
	signed short result = REG_A - REG_H;

	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
	FLAG_CY = (result > 0xFF || result < 0x00);
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_A = result & 0xFF;
	REG_PC++;
}
void subl() // 0x95
{
	signed short result = REG_A - REG_L;

	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
	FLAG_CY = (result > 0xFF || result < 0x00);
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_A = result & 0xFF;
	REG_PC++;
}
void subm() // 0x96
{
	signed short result = REG_A - MEM[REG_M];

	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
	FLAG_CY = (result > 0xFF || result < 0x00);
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_A = result & 0xFF;
	REG_PC++;
}
void sui() // 0xD6
{
	signed short result = REG_A - GET_BYTE(REG_PC + 1);

	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
	FLAG_CY = (result > 0xFF || result < 0x00);
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_A = result & 0xFF;
	REG_PC += 2;
}

/*
	-----------------------------------------------------------------------------
	8-bit Subtract Byte with Borrow (SBB) instructions

	Syntax: 			ADD src
	Flags affected: 	S, Z, AC, P, C
	Operation:			Subtract byte from src register - carry from accumulator.
	-----------------------------------------------------------------------------
*/
void sbba() // 0x9F
{
	signed short result = REG_A - REG_A - FLAG_CY;

	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
	FLAG_CY = (result > 0xFF || result < 0x00);
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_A = result & 0xFF;
	REG_PC++;
}
void sbbb() // 0x98
{
    signed short result = REG_A - REG_B - FLAG_CY;

	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
	FLAG_CY = (result > 0xFF || result < 0x00);
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_A = result & 0xFF;
	REG_PC++;
}
void sbbc() // 0x99
{
	signed short result = REG_A - REG_C - FLAG_CY;

	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
	FLAG_CY = (result > 0xFF || result < 0x00);
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_A = result & 0xFF;
	REG_PC++;
}
void sbbd() // 0x9A
{
	signed short result = REG_A - REG_D - FLAG_CY;

	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
	FLAG_CY = (result > 0xFF || result < 0x00);
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_A = result & 0xFF;
	REG_PC++;
}
void sbbe() // 0x9B
{
	signed short result = REG_A - REG_E - FLAG_CY;

	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
	FLAG_CY = (result > 0xFF || result < 0x00);
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_A = result & 0xFF;
	REG_PC++;
}
void sbbh() // 0x9C
{
	signed short result = REG_A - REG_H - FLAG_CY;

	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
	FLAG_CY = (result > 0xFF || result < 0x00);
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_A = result & 0xFF;
	REG_PC++;
}
void sbbl() // 0x9D
{
	signed short result = REG_A - REG_L - FLAG_CY;

	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
	FLAG_CY = (result > 0xFF || result < 0x00);
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_A = result & 0xFF;
	REG_PC++;
}
void sbbm() // 0x9E
{
	signed short result = REG_A - MEM[REG_M] - FLAG_CY;

	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
	FLAG_CY = (result > 0xFF || result < 0x00);
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_A = result & 0xFF;
	REG_PC++;
}
void sbi() // 0xDE
{
    signed short result = REG_A - GET_BYTE(REG_PC + 1) - FLAG_CY;

	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
	FLAG_CY = (result > 0xFF || result < 0x00);
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_A = result & 0xFF;
	REG_PC += 2;
}

/*
	-------------------------------------------------------------------
	16-bit Double Byte Add (DAD) instructions

	Syntax: 			ADD src
	Flags affected: 	C
	Operation:			Add word from src register pair to HL.
	-------------------------------------------------------------------
*/
void dadb() // 0x09
{
	signed int result = REG_HL + REG_BC;

	// Calculate Carry flag
	FLAG_CY = (result > 0xFFFF || result < 0x0000);

	REG_HL = result & 0xFFFF;
	REG_PC++;
}
void dadd() // 0x19
{
	signed int result = REG_HL + REG_DE;

	// Calculate Carry flag
	FLAG_CY = (result > 0xFFFF || result < 0x0000);

	REG_HL = result & 0xFFFF;
	REG_PC++;
}
void dadh() // 0x29
{
	signed int result = REG_HL + REG_HL;

	// Calculate Carry flag
	FLAG_CY = (result > 0xFFFF || result < 0x0000);

	REG_HL = result & 0xFFFF;
	REG_PC++;
}
void dadsp() // 0x39
{
	signed int result = REG_HL + REG_SP;

	// Calculate Carry flag
	FLAG_CY = (result > 0xFFFF || result < 0x0000);

	REG_HL = result & 0xFFFF;
	REG_PC++;
}

/*
	------------------------------------------
	8-bit Control instructions (DI/EI/NOP/HLT)
	------------------------------------------
*/
void di() // 0xF3
{
	INTE = 0;
	REG_PC++;
}
void ei() // 0xFB
{
	INTE = 1;

	if(IPEND & 0x80)
	{
	    generateInterrupt(IPEND & 0x7F);
	}

	REG_PC++;
}
void nop() // 0x00
{
	REG_PC++;
}
void hlt() // 0x76
{
	//REG_PC++;
	//i8080A.stopped = 1;
	printf("\n\nHALT!");
	ExitProcess(0);
}

/*
	---------------------------------------------------------
	8-bit Increment Byte (INR) instructions

	Syntax: 			INR src
	Flags affected: 	S, Z, AC, P
	Operation:			Increment value of src register by 1.
	---------------------------------------------------------
*/
void inra() // 0x3C
{
	signed short result = REG_A + 1;

	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_A = result & 0xFF;
	REG_PC++;
}
void inrb() // 0x04
{
	signed short result = REG_B + 1;

//	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
	FLAG_AC = (REG_B & 0xF) > (result & 0xF);
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_B = result;
	REG_PC++;
}
void inrc() // 0x0C
{
	signed short result = REG_C + 1;

//	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
    FLAG_AC = (REG_C & 0xF) > (result & 0xF);
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_C = result;
	REG_PC++;
}
void inrd() // 0x14
{
	signed short result = REG_D + 1;

//	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
    FLAG_AC = (REG_D & 0xF) > (result & 0xF);
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_D = result;
	REG_PC++;
}
void inre() // 0x1C
{
	signed short result = REG_E + 1;

//	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
    FLAG_AC = (REG_E & 0xF) > (result & 0xF);
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_E = result;
	REG_PC++;
}
void inrh() // 0x24
{
	signed short result = REG_H + 1;

//	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
    FLAG_AC = (REG_H & 0xF) > (result & 0xF);
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_H = result;
	REG_PC++;
}
void inrl() // 0x2C
{
	signed short result = REG_L + 1;

//	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
    FLAG_AC = (REG_L & 0xF) > (result & 0xF);
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_L = result;
	REG_PC++;
}
void inrm() // 0x34
{
	signed short result = MEM[REG_M] + 1;

//	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
    FLAG_AC = (MEM[REG_M] & 0xF) > (result & 0xF);
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	MEM[REG_M] = result;
	REG_PC++;
}

/*
	---------------------------------------------------------
	8-bit Decrement Byte (DCR) instructions

	Syntax: 			DCR src
	Flags affected: 	S, Z, AC, P
	Operation:			Decrement value of src register by 1.
	---------------------------------------------------------
*/
void dcra() // 0x3D
{
	signed short result = REG_A - 1;

	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_A = result & 0xFF;
	REG_PC++;
}
void dcrb() // 0x05
{
	signed short result = REG_B - 1;

	//FLAG_AC = (REG_A & 0xF) > (result & 0xF);
	FLAG_AC = (REG_B & 0xF) > (result & 0xF);
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_B = result;
	REG_PC++;
}
void dcrc() // 0x0D
{
	signed short result = REG_C - 1;

//	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
	FLAG_AC = (REG_C & 0xF) > (result & 0xF);
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_C = result;
	REG_PC++;
}
void dcrd() // 0x15
{
	signed short result = REG_D - 1;

//	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
    FLAG_AC = (REG_D & 0xF) > (result & 0xF);
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_D = result;
	REG_PC++;
}
void dcre() // 0x1D
{
	signed short result = REG_E - 1;

//	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
    FLAG_AC = (REG_E & 0xF) > (result & 0xF);
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_E = result;
	REG_PC++;
}
void dcrh() // 0x25
{
	signed short result = REG_H - 1;

//	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
    FLAG_AC = (REG_H & 0xF) > (result & 0xF);
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_H = result;
	REG_PC++;
}
void dcrl() // 0x2D
{
	signed short result = REG_L - 1;

//	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
	FLAG_AC = (REG_L & 0xF) > (result & 0xF);
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_L = result;
	REG_PC++;
}
void dcrm() // 0x35
{
	signed short result = MEM[REG_M] - 1;

//	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
	FLAG_AC = (MEM[REG_M] & 0xF) > (result & 0xF);
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	MEM[REG_M] = result;
	REG_PC++;
}

/*
	--------------------------------------------------------------
	8-bit Increment Register Pair (INX) instructions

	Syntax: 			INX src
	Flags affected: 	N/A
	Operation:			Increment value of src register pair by 1.
	--------------------------------------------------------------
*/
void inxb() // 0x03
{
	REG_BC++;
	REG_PC++;
}
void inxd() // 0x13
{
	REG_DE++;
	REG_PC++;
}
void inxh() // 0x23
{
	REG_HL++;
	REG_PC++;
}
void inxsp() // 0x33
{
	REG_SP++;
	REG_PC++;
}

/*
	--------------------------------------------------------------
	8-bit Decrement Register Pair (DCX) instructions

	Syntax: 			DCX src
	Flags affected: 	N/A
	Operation:			Decrement value of src register pair by 1.
	--------------------------------------------------------------
*/
void dcxb() // 0x0B
{
	REG_BC--;
	REG_PC++;
}
void dcxd() // 0x1B
{
	REG_DE--;
	REG_PC++;
}
void dcxh() // 0x2B
{
	REG_HL--;
	REG_PC++;
}
void dcxsp() // 0x3B
{
	REG_SP--;
	REG_PC++;
}

/*
	--------------------------------------------------------------
	Special Accumulator and Flag instructions (DAA, CMA, STC, CMC)
	--------------------------------------------------------------
*/
void daa() // 0x27
{
	if((REG_A & 0x0F) > 9 || FLAG_AC)
	{
		signed short result = REG_A + 6;
		FLAG_CY = ((REG_A & 8) > (result & 8));
		REG_A = result & 0xFF;
	}

	if((REG_A >> 4) > 9 || FLAG_AC)
	{
		signed short result = REG_A + (6 << 4);
		FLAG_CY = (REG_A & 0x80) > (result & 0x80);
		REG_A = result & 0xFF;
	}

	REG_PC++;
}
void cma() // 0x2F
{
	REG_A = ~REG_A;
	REG_PC++;
}
void stc() // 0x37
{
	FLAG_CY = 1;
	REG_PC++;
}
void cmc() // 0x3F
{
	FLAG_CY = 0;
	REG_PC++;
}

/*
	------------------------------------------------------
	8-bit Rotate instructions (RLC, RRC, RAL, RAR)

	Syntax: 			RLC src, RRC src, RAL src, RAR src
	Flags affected: 	C
	Operation:			Rotate registers.
	------------------------------------------------------
*/
void rlc() // 0x07
{
    FLAG_CY = REG_A >> 7;
    REG_A = (REG_A << 1) | (REG_A >> 7);
    REG_PC++;
}
void rrc() // 0x0F
{
    signed short result = (REG_A >> 1) | ((REG_A & 0x1) << 7);
    FLAG_CY = (REG_A & 0x1);
    REG_A = result & 0xFF;

//    FLAG_CY = REG_A << 7;
//    REG_A = (REG_A >> 1) | (REG_A << 7);

//    signed short result = (REG_A >> 1) | ((A & 0x1) << 7);
//    FLAG_CY = REG_A & 0x1;
//    REG_A = result & 0xFF;
	REG_PC++;
}
void ral() // 0x17
{
    unsigned short temp = FLAG_CY;
    FLAG_CY = REG_A & 0x80;
	REG_A = (REG_A << 1) | (temp & 0x80);
	REG_PC++;
}
void rar() // 0x1F
{
	signed short result = (REG_A >> 1) | (FLAG_CY << 7);

	FLAG_CY = result & 0x1;

	REG_A = result & 0xFF;
	REG_PC++;
}

/*
	---------------------------------------------------------------------
	8-bit bitwise AND instructions

	Syntax: 			AND src
	Flags affected: 	S, Z, AC, P, C
	Operation:			Bitwise AND accumulator by value of src register.
	---------------------------------------------------------------------
*/
void anaa() // 0xA7
{
	signed short result = REG_A & REG_A;

//	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
//	FLAG_CY = (result > 0xFF || result < 0x00);
    FLAG_AC = 0;
    FLAG_CY = 0;
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_A = result & 0xFF;
	REG_PC++;
}
void anab() // 0xA0
{
	signed short result = REG_A & REG_B;

//	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
//	FLAG_CY = (result > 0xFF || result < 0x00);
    FLAG_AC = 0;
    FLAG_CY = 0;
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_A = result & 0xFF;
	REG_PC++;
}
void anac() // 0xA1
{
	signed short result = REG_A & REG_C;

//	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
//	FLAG_CY = (result > 0xFF || result < 0x00);
    FLAG_AC = 0;
    FLAG_CY = 0;
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_A = result & 0xFF;
	REG_PC++;
}
void anad() // 0xA2
{
	signed short result = REG_A & REG_D;

//	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
//	FLAG_CY = (result > 0xFF || result < 0x00);
    FLAG_AC = 0;
    FLAG_CY = 0;
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_A = result & 0xFF;
	REG_PC++;
}
void anae() // 0xA3
{
	signed short result = REG_A & REG_E;

//	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
//	FLAG_CY = (result > 0xFF || result < 0x00);
    FLAG_AC = 0;
    FLAG_CY = 0;
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_A = result & 0xFF;
	REG_PC++;
}
void anah() // 0xA4
{
	signed short result = REG_A & REG_H;

//	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
//	FLAG_CY = (result > 0xFF || result < 0x00);
    FLAG_AC = 0;
    FLAG_CY = 0;
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_A = result & 0xFF;
	REG_PC++;
}
void anal() // 0xA5
{
	signed short result = REG_A & REG_L;

//	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
//	FLAG_CY = (result > 0xFF || result < 0x00);
    FLAG_AC = 0;
    FLAG_CY = 0;
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_A = result & 0xFF;
	REG_PC++;
}
void anam() // 0xA6
{
	signed short result = REG_A & MEM[REG_M];

//	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
//	FLAG_CY = (result > 0xFF || result < 0x00);
    FLAG_AC = 0;
    FLAG_CY = 0;
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_A = result & 0xFF;
	REG_PC++;
}
void ani() // 0xE6
{
	signed short result = REG_A & GET_BYTE(REG_PC + 1);

//	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
//	FLAG_CY = (result > 0xFF || result < 0x00);
    FLAG_AC = 0;
    FLAG_CY = 0;
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_A = result & 0xFF;
	REG_PC += 2;
}

/*
	---------------------------------------------------------------------
	8-bit bitwise XOR instructions

	Syntax: 			XOR src
	Flags affected: 	S, Z, AC, P, C
	Operation:			Bitwise XOR accumulator by value of src register.
	---------------------------------------------------------------------
*/
void xraa() // 0xAF
{
	signed short result = REG_A ^ REG_A;

//	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
//	FLAG_CY = (result > 0xFF || result < 0x00);
    FLAG_AC = 0;
    FLAG_CY = 0;
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_A = result & 0xFF;
	REG_PC++;
}
void xrab() // 0xA8
{
	signed short result = REG_A ^ REG_B;

//	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
//	FLAG_CY = (result > 0xFF || result < 0x00);
    FLAG_AC = 0;
    FLAG_CY = 0;
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_A = result & 0xFF;
	REG_PC++;
}
void xrac() // 0xA9
{
	signed short result = REG_A ^ REG_C;

//	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
//	FLAG_CY = (result > 0xFF || result < 0x00);
    FLAG_AC = 0;
    FLAG_CY = 0;
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_A = result & 0xFF;
	REG_PC++;
}
void xrad() // 0xAA
{
	signed short result = REG_A ^ REG_D;

//	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
//	FLAG_CY = (result > 0xFF || result < 0x00);
    FLAG_AC = 0;
    FLAG_CY = 0;
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_A = result & 0xFF;
	REG_PC++;
}
void xrae() // 0xAB
{
	signed short result = REG_A ^ REG_E;

//	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
//	FLAG_CY = (result > 0xFF || result < 0x00);
    FLAG_AC = 0;
    FLAG_CY = 0;
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_A = result & 0xFF;
	REG_PC++;
}
void xrah() // 0xAC
{
	signed short result = REG_A ^ REG_H;

//	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
//	FLAG_CY = (result > 0xFF || result < 0x00);
    FLAG_AC = 0;
    FLAG_CY = 0;
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_A = result & 0xFF;
	REG_PC++;
}
void xral() // 0xAD
{
	signed short result = REG_A ^ REG_L;

//	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
//	FLAG_CY = (result > 0xFF || result < 0x00);
    FLAG_AC = 0;
    FLAG_CY = 0;
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_A = result & 0xFF;
	REG_PC++;
}
void xram() // 0xAE
{
	signed short result = REG_A ^ MEM[REG_M];

//	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
//	FLAG_CY = (result > 0xFF || result < 0x00);
    FLAG_AC = 0;
    FLAG_CY = 0;
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_A = result & 0xFF;
	REG_PC++;
}
void xri() // 0xEE
{
	signed short result = REG_A ^ GET_BYTE(REG_PC + 1);

//	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
//	FLAG_CY = (result > 0xFF || result < 0x00);
    FLAG_AC = 0;
    FLAG_CY = 0;
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_A = result & 0xFF;
	REG_PC += 2;
}

/*
	---------------------------------------------------------------------
	8-bit bitwise OR instructions

	Syntax: 			OR src
	Flags affected: 	S, Z, AC, P, C
	Operation:			Bitwise OR accumulator by value of src register.
	---------------------------------------------------------------------
*/
void oraa() // 0xB7
{
	signed short result = REG_A | REG_A;

    FLAG_AC = 0;
    FLAG_CY = 0;
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_A = result & 0xFF;
	REG_PC++;
}
void orab() // 0xB0
{
	signed short result = REG_A | REG_B;

    FLAG_AC = 0;
    FLAG_CY = 0;
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_A = result & 0xFF;
	REG_PC++;
}
void orac() // 0xB1
{
	signed short result = REG_A | REG_C;

    FLAG_AC = 0;
    FLAG_CY = 0;
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_A = result & 0xFF;
	REG_PC++;
}
void orad() // 0xB2
{
	signed short result = REG_A | REG_D;

    FLAG_AC = 0;
    FLAG_CY = 0;
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_A = result & 0xFF;
	REG_PC++;
}
void orae() // 0xB3
{
	signed short result = REG_A | REG_E;

    FLAG_AC = 0;
    FLAG_CY = 0;
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_A = result & 0xFF;
	REG_PC++;
}
void orah() // 0xB4
{
	signed short result = REG_A | REG_H;

    FLAG_AC = 0;
    FLAG_CY = 0;
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_A = result & 0xFF;
	REG_PC++;
}
void oral() // 0xB5
{
	signed short result = REG_A | REG_L;

    FLAG_AC = 0;
    FLAG_CY = 0;
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_A = result & 0xFF;
	REG_PC++;
}
void oram() // 0xB6
{
	signed short result = REG_A | MEM[REG_M];

    FLAG_AC = 0;
    FLAG_CY = 0;
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_A = result & 0xFF;
	REG_PC++;
}
void ori() // 0xF6
{
	signed short result = REG_A | GET_BYTE(REG_PC + 1);

    FLAG_AC = 0;
    FLAG_CY = 0;
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_A = result & 0xFF;
	REG_PC += 2;
}

/*
	-------------------------------------------------------------------
	8-bit logical comparison instructions

	Syntax: 			AND src
	Flags affected: 	S, Z, AC, P, C
	Operation:			Compare accumulator with value of src register.
	-------------------------------------------------------------------
*/
void cmpa() // 0xBF
{
	signed short result = REG_A - REG_A;

	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
	FLAG_CY = (result > 0xFF || result < 0x00);
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_PC++;
}
void cmpb() // 0xB8
{
	signed short result = REG_A - REG_B;

	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
	FLAG_CY = (result > 0xFF || result < 0x00);
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_PC++;
}
void cmpc() // 0xB9
{
	signed short result = REG_A - REG_C;

	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
	FLAG_CY = (result > 0xFF || result < 0x00);
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_PC++;
}
void cmpd() // 0xBA
{
	signed short result = REG_A - REG_D;

	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
	FLAG_CY = (result > 0xFF || result < 0x00);
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_PC++;
}
void cmpe() // 0xBB
{
	signed short result = REG_A - REG_E;

	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
	FLAG_CY = (result > 0xFF || result < 0x00);
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_PC++;
}
void cmph() // 0xBC
{
	signed short result = REG_A - REG_H;

	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
	FLAG_CY = (result > 0xFF || result < 0x00);
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_PC++;
}
void cmpl() // 0xBD
{
	signed short result = REG_A - REG_L;

	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
	FLAG_CY = (result > 0xFF || result < 0x00);
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_PC++;
}
void cmpm() // 0xBE
{
	signed short result = REG_A - MEM[REG_M];

	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
	FLAG_CY = (result > 0xFF || result < 0x00);
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_PC++;
}
void cpi() // 0xFE
{
	signed short result = REG_A - GET_BYTE(REG_PC + 1);

	FLAG_AC = (REG_A & 0xF) > (result & 0xF);
	FLAG_CY = (result > 0xFF || result < 0x00);
	FLAG_S = (result >> 7);
	FLAG_Z = result ? 0 : 1;
	CALC_P(result);

	REG_PC += 2;
}

/*
	-------------------------------------------------------------------
	16-bit Jump instructions

	Syntax: 			JMP src
	Flags affected: 	N/A
	Operation:			Compare accumulator with value of src register.
	-------------------------------------------------------------------
*/
// Jumps
void jmp() // 0xC3
{
	REG_PC = GET_WORD(REG_PC + 1);
}
void jnz() // 0xC2
{
	REG_PC = !FLAG_Z ? GET_WORD(REG_PC + 1) : REG_PC + 3;
}
void jz() // 0xCA
{
	REG_PC = FLAG_Z ? GET_WORD(REG_PC + 1) : REG_PC + 3;
}
void jnc() // 0xD2
{
	REG_PC = !FLAG_CY ? GET_WORD(REG_PC + 1) : REG_PC + 3;
}
void jc() // 0xDA
{
	REG_PC = FLAG_CY ? GET_WORD(REG_PC + 1) : REG_PC + 3;
}
void jpo() // 0xE2
{
	REG_PC = !FLAG_P ? GET_WORD(REG_PC + 1) : REG_PC + 3;
}
void jpe() // 0xEA
{
	REG_PC = FLAG_P ? GET_WORD(REG_PC + 1) : REG_PC + 3;
}
void jp() // 0xF2
{
	REG_PC = !FLAG_S ? GET_WORD(REG_PC + 1) : REG_PC + 3;
}
void jm() // 0xFA
{
	REG_PC = FLAG_S ? GET_WORD(REG_PC + 1) : REG_PC + 3;
}
void pchl() // 0xE9
{
	REG_PC = REG_HL;
}

/*
	--------------------------------------------------------------------
	16-bit Call instructions

	Syntax: 			CALL src
	Flags affected: 	N/A
	Operation:			Push PC onto stack and assign PC to src address.
	--------------------------------------------------------------------
*/
void call() // 0xCD
{
	REG_SP -= 2;
	PUSH_WORD(REG_PC + 3);
	REG_PC = GET_WORD(REG_PC + 1);
}
void cnz() // 0xC4
{
	if(!FLAG_Z)
	{
		REG_SP -= 2;
		PUSH_WORD(REG_PC + 3);
		REG_PC = GET_WORD(REG_PC + 1);
	}
	else
	{
		REG_PC += 3;
	}
}
void cz() // 0xCC
{
	if(FLAG_Z)
	{
		REG_SP -= 2;
		PUSH_WORD(REG_PC + 3);
		REG_PC = GET_WORD(REG_PC + 1);
	}
	else
	{
		REG_PC += 3;
	}
}
void cnc() // 0xD4
{
	if(!FLAG_CY)
	{
		REG_SP -= 2;
		PUSH_WORD(REG_PC + 3);
		REG_PC = GET_WORD(REG_PC + 1);
	}
	else
	{
		REG_PC += 3;
	}
}
void cc() // 0xDC
{
	if(FLAG_CY)
	{
		REG_SP -= 2;
		PUSH_WORD(REG_PC + 3);
		REG_PC = GET_WORD(REG_PC + 1);
	}
	else
	{
		REG_PC += 3;
	}
}
void cpo() // 0xE4
{
	if(!FLAG_P)
	{
		REG_SP -= 2;
		PUSH_WORD(REG_PC + 3);
		REG_PC = GET_WORD(REG_PC + 1);
	}
	else
	{
		REG_PC += 3;
	}
}
void cpe() // 0xEC
{
	if(FLAG_P)
	{
		REG_SP -= 2;
		PUSH_WORD(REG_PC + 3);
		REG_PC = GET_WORD(REG_PC + 1);
	}
	else
	{
		REG_PC += 3;
	}
}
void cp() // 0xF4
{
	if(!FLAG_S)
	{
		REG_SP -= 2;
		PUSH_WORD(REG_PC + 3);
		REG_PC = GET_WORD(REG_PC + 1);
	}
	else
	{
		REG_PC += 3;
	}
}
void cm() // 0xFC
{
	if(FLAG_S)
	{
		REG_SP -= 2;
		PUSH_WORD(REG_PC + 3);
		REG_PC = GET_WORD(REG_PC + 1);
	}
	else
	{
		REG_PC += 3;
	}
}

/*
	-------------------------------------------------------------------
	Return instructions

	Syntax: 			RET, RNZ, RZ, RNC, RC, RPO, RPE, RP, RM
	Flags affected: 	N/A
	Operation:			Pop PC from stack, return from subroutine call.
	-------------------------------------------------------------------
*/
void ret() // 0xC9
{
	REG_PC = POP_WORD()
	REG_SP += 2;
}
void rnz() // 0xC0
{
	if(!FLAG_Z)
	{
		REG_PC = POP_WORD()
		REG_SP += 2;
	}
	else
	{
		REG_PC++;
	}
}
void rz() // 0xC8
{
	if(FLAG_Z)
	{
		#ifdef DEBUG
        if(REG_SP == 0xFFFF)
        {
        fprintf(stderr, "Stack empty, cannot return from subroutine!");
        ExitProcess(0);
        }
		#endif
		REG_PC = POP_WORD()
		REG_SP += 2;
	}
	else
	{
		REG_PC++;
	}
}
void rnc() // 0xD0
{
	if(!FLAG_CY)
	{
		REG_PC = POP_WORD()
		REG_SP += 2;
	}
	else
	{
		REG_PC++;
	}
}
void rc() // 0xD8
{
	if(FLAG_CY)
	{
		REG_PC = POP_WORD()
		REG_SP += 2;
	}
	else
	{
		REG_PC++;
	}
}
void rpo() // 0xE0
{
	if(!FLAG_P)
	{
		REG_PC = POP_WORD()
		REG_SP += 2;
	}
	else
	{
		REG_PC++;
	}
}
void rpe() // 0xE8
{
	if(FLAG_P)
	{
		REG_PC = POP_WORD()
		REG_SP += 2;
	}
	else
	{
		REG_PC++;
	}
}
void rp() // 0xF0
{
	if(!FLAG_S)
	{
		REG_PC = POP_WORD()
		REG_SP += 2;
	}
	else
	{
		REG_PC++;
	}
}
void rm() // 0xF8
{
	if(FLAG_S)
	{
		REG_PC = POP_WORD()
		REG_SP += 2;
	}
	else
	{
		REG_PC++;
	}
}

/*
	------------------------------------------------------------------------
	RST instructions

	Syntax: 			RST_0 - RST_7
	Flags affected: 	N/A
	Operation:			Call subroutine located at lower 64 bytes of memory.
	------------------------------------------------------------------------
*/
void rst0() // 0xC7
{
	STACK[REG_SP] = REG_PC;
	REG_SP -= 2;
	REG_PC = RST_0;
}
void rst1() // 0xCF
{
	STACK[REG_SP] = REG_PC;
	REG_SP -= 2;
	REG_PC = RST_8;
}
void rst2() // 0xD7
{
	STACK[REG_SP] = REG_PC;
	REG_SP -= 2;
	REG_PC = RST_10;
}
void rst3() // 0xDF
{
	STACK[REG_SP] = REG_PC;
	REG_SP -= 2;
	REG_PC = RST_18;
}
void rst4() // 0xE7
{
	STACK[REG_SP] = REG_PC;
	REG_SP -= 2;
	REG_PC = RST_20;
}
void rst5() // 0xEF
{
	STACK[REG_SP] = REG_PC;
	REG_SP -= 2;
	REG_PC = RST_28;
}
void rst6() // 0xF7
{
	STACK[REG_SP] = REG_PC;
	REG_SP -= 2;
	REG_PC = RST_30;
}
void rst7() // 0xFF
{
	STACK[REG_SP] = REG_PC;
	REG_SP -= 2;
	REG_PC = RST_38;
}

/*
	----------------------------
	Stack operation instructions
	----------------------------
*/
void pushb() // 0xC5
{
	REG_SP -= 2;
	PUSH_WORD(REG_BC)
	REG_PC++;
}
void pushd() // 0xD5
{
	REG_SP -= 2;
	PUSH_WORD(REG_DE)
	REG_PC++;
}
void pushh() // 0xE5
{
	REG_SP -= 2;
    PUSH_WORD(REG_HL)
	REG_PC++;
}
void pushpsw() // 0xF5
{
    SET_PSW();
    STACK[REG_SP - 1] = FLAG_PSW;
    STACK[REG_SP - 2] = REG_A;
    REG_SP -= 2;
	REG_PC++;
}
void popb() // 0xC1
{
	REG_BC = POP_WORD()
	REG_SP += 2;
	REG_PC++;
}
void popd() // 0xD1
{
	REG_DE = POP_WORD()
	REG_SP += 2;
	REG_PC++;
}
void poph() // 0xE1
{
	REG_HL = POP_WORD()
	REG_SP += 2;
	REG_PC++;
}
void poppsw() // 0xF1
{
	REG_A = STACK[REG_SP];
	FLAG_PSW = STACK[REG_SP + 1];
	REG_SP += 2;
	GET_PSW();
	REG_PC++;
}

/*
	----------------
	I/O instructions
	----------------
*/
void in() // 0xDB
{
	unsigned char port = GET_BYTE(REG_PC + 1);
//	DWORD dwValue;
//	WORD wValue;

	switch(port)
	{
		case 0x0:               // Inputs (mapped but not used)
			REG_A = 0xF;
		break;
		case 0x01:              // P1 inputs
		    REG_A = INPORT_1;
		break;
		case 0x02:              // P1 inputs
			REG_A = INPORT_2;
		break;
		case 0x03:              // Read bit shift register
//		    dwValue = (i8080A.shift_byte2 << 8) | i8080A.shift_byte1;
//		    wValue = ((dwValue >> (8 - SHIFT_OFFSET)) & 0xFF);
//		    REG_A = wValue;
//		    i8080A.shift_byte1 = i8080A.shift_byte2;
//		    i8080A.shift_byte2 = REG_A;
            //printf("Read: %X -> ", SHIFT_REG);
			REG_A = ((SHIFT_REG << SHIFT_OFFSET) >> 8) & 0xFF;
			//printf("%X\n", A);
			//getchar();
		break;
		default:
        break;
	}

	// if(port == 0)			// Unused port
	// 	REG_A = 0xF;
	// else if(port == 1)		// Player input
	// 	REG_A = INPORT_1;
	// else if(port == 2)		// Player input
	// 	REG_A = INPORT_2;
	// else if(port == 3)		// Read bit shift byte to accumulator
	// 	REG_A = (SHIFT_REG << OUTPORT_2) >> 8;

	REG_PC += 2;
}
void out() // 0xD3
{
	BYTE port = GET_BYTE(REG_PC + 1);

	switch(port)
	{
		case 0x02:              // Shift offset (3 bits)
			SHIFT_OFFSET = REG_A & 0x7;
			//printf("%d\n", SHIFT_OFFSET);
		break;
		case 0x03:              // Sound bits
			//OUTPORT_3 = REG_A;
		break;
		case 0x04:              // Shift data
//		    i8080A.shift_byte1 = i8080A.shift_byte2;
//		    i8080A.shift_byte2 = REG_A;
            //printf("Write: %X -> ", SHIFT_REG);
			SHIFT_REG = (SHIFT_REG >> 8) | (REG_A << 8);

			//printf("%X (%X)\n", SHIFT_REG, A);
			//SHIFT_REG = (SHIFT_REG << 8) | A;
		break;
		case 0x05:              // Sound bits
			//OUTPORT_5 = REG_A;
		break;
		case 0x06:              // Watchdog (debug port)
			OUTPORT_6 = REG_A;
		break;
		default:
        break;
	}

	// if(port == 2)			// Set bit shift offset for writing to port 4
	// 	OUTPORT_2 = REG_A & 0x7;
	// else if(port == 3)		// Sounds bits
	// 	OUTPORT_3 = REG_A;
	// else if(port == 4)		// Bit shift byte
	// 	SHIFT_REG = (SHIFT_REG >> 8) | (REG_A << 8);
	// else if(port == 5)		// Sound bits
	// 	OUTPORT_5 = REG_A;
	// // else if(port == 6)
	// // 	output_6 = REG_A;

	REG_PC += 2;
}

// Illegal instruction
void illegal()
{
	#ifdef DEBUG
		printf("0x%04X %02X: Illegal instruction\n", REG_PC, OPCODE);
		debug();
	#endif
    REG_PC++;
    getchar();
}

