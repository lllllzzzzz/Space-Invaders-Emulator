#ifndef OPCODES_H_INCLUDED
#define OPCODES_H_INCLUDED

/*
	----------------
	8080 Subroutines
	----------------
*/
// Illegal/unknown instruction
void illegal();

// 8-bit MOV instructions
void movaa();	void movba();	void movca();	void movda();	void movea();	void movha();	void movla();	void movma();
void movab();	void movbb();	void movcb();	void movdb();	void moveb();	void movhb();	void movlb();	void movmb();
void movac();	void movbc();	void movcc();	void movdc();	void movec();	void movhc();	void movlc();	void movmc();
void movad();	void movbd();	void movcd();	void movdd();	void moved();	void movhd();	void movld();	void movmd();
void movae();	void movbe();	void movce();	void movde();	void movee();	void movhe();	void movle();	void movme();
void movah();	void movbh();	void movch();	void movdh();	void moveh();	void movhh();	void movlh();	void movmh();
void moval();	void movbl();	void movcl();	void movdl();	void movel();	void movhl();	void movll();	void movml();
void movam();	void movbm();	void movcm();	void movdm();	void movem();	void movhm();	void movlm();	

// 16-bit Load/Store Immediate instructions
void ldaxb();	void staxb();
void ldaxd();	void staxd();
void lda();		void sta();

// 16-bit Load/Store instructions
void lxib();	void lxid();	void lxih();	void lxisp();	void lhld();	void shld();	void sphl();

// Register exchange instructions
void xchg();	void xthl();

// 16-bit Move Immediate (MVI) instructions
void mvia();	void mvib();	void mvic();	void mvid();	void mvie();	void mvih();	void mvil();	void mvim();

// 8-bit Add Byte (ADD) instructions
void adda();	void addb();	void addc();	void addd();	void adde();	void addh();	void addl();	void addm();
void adi();

// 8-bit Add Byte with Carry (ADC) instructions
void adca();	void adcb();	void adcc();	void adcd();	void adce();	void adch();	void adcl();	void adcm();
void aci();

// 8-bit Subtract Byte (SUB) instructions
void suba();	void subb();	void subc();	void subd();	void sube();	void subh();	void subl();	void subm();
void sui();

// 16-bit Subtract Byte with Borrow (SBB) instructions
void sbba();	void sbbb();	void sbbc();	void sbbd();	void sbbe();	void sbbh();	void sbbl();	void sbbm();
void sbi();

// 16-bit Double Byte Add (DAD) instructions
void dadb();	void dadd();	void dadh();	void dadsp();

// 8-bit Control instructions (DI/EI/NOP/HLT)
void di();		void ei();		void nop();		void hlt();

// 8-bit Increment Byte (INR) instructions
void inra();	void inrb();	void inrc();	void inrd();	void inre();	void inrh();	void inrl();	void inrm();

// 8-bit Decrement Byte (DCR) instructions
void dcra();	void dcrb();	void dcrc();	void dcrd();	void dcre();	void dcrh();	void dcrl();	void dcrm();

// 8-bit Increment Register Pair (INX) instructions
void inxb();	void inxd();	void inxh();	void inxsp();

// 8-bit Decrement Register Pair (DCX) instructions
void dcxb();	void dcxd();	void dcxh();	void dcxsp();

// Special Accumulator and Flag instructions (DAA, CMA, STC, CMC)
void daa();		void cma();		void stc();		void cmc();

// 8-bit Rotate instructions (RLC, RRC, RAL, RAR)
void rlc();		void rrc();		void ral();		void rar();

// 8-bit logical byte instructions
// AND
void anaa();	void anab();	void anac();	void anad();	void anae();	void anah();	void anal();	void anam();
void ani();
// XOR
void xraa();	void xrab();	void xrac();	void xrad();	void xrae();	void xrah();	void xral();	void xram();
void xri();
// OR
void oraa();	void orab();	void orac();	void orad();	void orae();	void orah();	void oral();	void oram();
void ori();
// Compares
void cmpa();	void cmpb();	void cmpc();	void cmpd();	void cmpe();	void cmph();	void cmpl();	void cmpm();
void cpi();

// Branch control instructions
// Jumps
void jmp();		void jnz();		void jz();		void jnc();		void jc();		void jpo();		void jpe();		void jp(); 		void jm();
void pchl();
// Calls
void call();	void cnz();		void cz();		void cnc();		void cc();		void cpo();		void cpe();		void cp(); 		void cm();
// Returns
void ret();		void rnz();		void rz();		void rnc();		void rc();		void rpo();		void rpe();		void rp(); 		void rm();
// RSTs
void rst0();	void rst1();	void rst2();	void rst3();	void rst4();	void rst5();	void rst6();	void rst7();

// Stack operation instructions
void pushb();	void pushd();	void pushh();	void pushpsw();	void popb();	void popd();	void poph();	void poppsw();

// I/O instructions
void in();		void out();

#endif // OPCODES_H_INCLUDED
