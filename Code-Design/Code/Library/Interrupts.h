/*
 * Interrupts.h
 *
 * External interrupt control
 *
 */
#define INTERRUPT_0 #INT_EXT0 // PIN_B0 external interrupt circuit
#define INTERRUPT_1 #INT_EXT1 // PIN_B0 external interrupt circuit
#define INTERRUPT_2 #INT_EXT2 // PIN_B0 external interrupt circuit

struct INTCON_{
	int RBIF:1;
	int INT0IF:1;
	int TMR0IF:1;
	int RBIE:1;
	int INT0IE:1;
	int TMR0IE:1;
	int PEIE:1;
	int GIE:1;
	};
struct INTCON_ *INTCON = REGISTER_INTCON;

struct INTCON_2{
	int RBIP:1;
	int UNIMPLEMENTED_0:1;
	int TMROIP:1;
	int UNIMPLEMENTED_1:1;
	int INTEDG2:1;
	int INTEDG1:1;
	int INTEDG0:1;
	int RBPU:1;
	};
struct INTCON_2 *INTCON2 = REGISTER_INTCON2;

struct INTCON_3{
	int INT1F:1;
	int INT2F:1;
	int UNIMPLEMENTED_0:1;
	int INT1E:1;
	int INT2E:1;
	int UNIMPLEMENTED_1:1;
	int INT1P:1;
	int INT2P:1;
	};
struct INTCON_3 *INTCON3 = REGISTER_INTCON3;

/*
 *
 * Peripheral Interrupts Control Registers
 *
 */

struct PIE_1{
	int TMR1IE:1;
	int TMR2IE:1;
	int CCP1IE:1;
	int SSPIE:1;
	int TXIE:1;
	int RCIE:1;
	int ADIE:1;
	int PSPIE:1;
	};
struct PIE_1 *PIE1 = REGISTER_PIE1;
