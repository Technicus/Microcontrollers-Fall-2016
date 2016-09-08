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
	int RBIF:1;     // RBIF: RB Port Change Interrupt Flag bit
					//   1 = At least one of the RB<7:4> pins changed state (must be cleared in software)
					//	 0 = None of the RB<7:4> pins have changed state
	int INT0IF:1;   // INT0IF: INT0 External Interrupt Flag bit
					//   1 = The INT0 external interrupt occurred (must be cleared in software)
					//	 0 = The INT0 external interrupt did not occur 
	int TMR0IF:1;   // TMR0IF: TMR0 Overflow Interrupt Flag bit
					//   1 = TMR0 register has overflowed (must be cleared in software)
					//	 0 = TMR0 register did not overflow
	int RBIE:1;     // RBIE: RB Port Change Interrupt Enable bit
					//   1 = Enables the RB port change interrupt
					//	 0 = Disables the RB port change interrupt
	int INT0IE:1;   // INT0IE: INT0 External Interrupt Enable bit *** needed to have interrupt 
					//   1 = Enables the INT0 external interrupt
					//   0 = Disables the INT0 external interrupt                            
	int TMR0IE:1;   // TMR0IE: TMR0 Overflow Interrupt Enable bit
					//   1 = Enables the TMR0 overflow interrupt
					//	 0 = Disables the TMR0 overflow interrupt
	int PEIE:1;     // PEIE/GIEL: Peripheral Interrupt Enable bit.  Localized enable bit for INT0. *** needed to have interrupt
					//	 When IPEN = 0:
					//	   1 = Enables all unmasked peripheral interrupts
					//	   0 = Disables all peripheral interrupts
					//	 When IPEN = 1:
					//	   1 = Enables all low-priority peripheral interrupts
					//	   0 = Disables all low-priority peripheral interrupts
	int GIE:1;      // GIE/GIEH:: Global Interrupt Enable bit.  Master switch for all interrupts.  *** needed to have interrupt
					//   When IPEN = 0:
					//	   1 = Enables all unmasked interrupts
					//	   0 = Disables all interrupts
					//	 When IPEN = 1:
					//	   1 = Enables all high-priority interrupts
					//	   0 = Disables all interrupts
	};
struct INTCON_ *INTCON = REGISTER_INTCON;

struct INTCON_2{
	int RBIP:1;             // RBIP: RB Port Change Interrupt Priority bit
							//	 1 = High priority
							//	 0 = Low priority
	int UNIMPLEMENTED_0:1;	// Read as ‘0’
	int TMROIP:1;           // TMR0 Overflow Interrupt Priority bit
							//	 1 = High priority
							//	 0 = Low priority
	int UNIMPLEMENTED_1:1;	// Read as ‘0’
	int INTEDG2:1;          // External Interrupt 2 Edge Select bit
							//   1 = Interrupt on rising edge
							//   0 = Interrupt on falling edge 
	int INTEDG1:1;          // External Interrupt 1 Edge Select bit
							//   1 = Interrupt on rising edge
							//   0 = Interrupt on falling edge
	int INTEDG0:1;          // External Interrupt 0 Edge Select bit
							//   1 = Interrupt on rising edge
							//   0 = Interrupt on falling edge
	int RBPU:1;             // PORTB Pull-up Enable bit
							//	 1 = All PORTB pull-ups are disabled
							//	 0 = PORTB pull-ups are enabled by individual port latch values
	};
struct INTCON_2 *INTCON2 = REGISTER_INTCON2;

struct INTCON_3{
	int INT1F:1;             // INT1IF: INT1 External Interrupt Flag bit
							 //	  1 = The INT1 external interrupt occurred (must be cleared in software)
							 //	  0 = The INT1 external interrupt did not occur
	int INT2F:1;			 // INT2IF: INT2 External Interrupt Flag bit
							 //	  1 = The INT2 external interrupt occurred (must be cleared in software)
							 //	  0 = The INT2 external interrupt did not occur
	int UNIMPLEMENTED_0:1;   // Read as ‘0’
	int INT1E:1;             // INT1IE: INT1 External Interrupt Enable bit
							 //	  1 = Enables the INT1 external interrupt
							 //	  0 = Disables the INT1 external interrupt
	int INT2E:1;             // INT2IE: INT2 External Interrupt Enable bit
							 //	  1 = Enables the INT2 external interrupt
							 //	  0 = Disables the INT2 external interrupt
	int UNIMPLEMENTED_1:1;   // Read as ‘0’
	int INT1P:1;			 // INT1IP: INT1 External Interrupt Priority bit
							 //	  1 = High priority
							 //	  0 = Low priority
	int INT2P:1;			 // INT2IP: INT2 External Interrupt Priority bit
							 //	  1 = High priority
							 //	  0 = Low priority
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
