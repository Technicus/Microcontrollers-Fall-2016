// Interrupt example

// Master, Local, Individual switch to turn on interrupt

#include "../../Library/Library_18f4520.h"

//int x = 255;

#INT_EXT // PIN_B0 external interrupt circuit
void int_ext_isr(){
	INTCON -> INT0IE = 0;  // Software debouncing
	//*PORT^=0X80;
	if (&x == 255){
		&x = 100;
	} else {
		&x = 255;
	}
	INTCON -> INT0IE = 1;  // Software debouncing
}

#INT_EXT1 // PIN_B1 external interrupt circuit
void int_ext_isr(){
}

#INT_EXT2 // PIN_B2 external interrupt circuit
void int_ext_isr(){
}

main//(){
	int x = 255;

	ADCON1 -> PCFGX=0xF; // *ADCON1 = 0x0f; // Select as digital
	*TRISB = 0x01  //TRISB = 0x01; // B0 Input

	INTCON -> GIE = 1; 			// Global Interrupt Enable bit
	INTCON -> PEIE = 1; 		// Peripheral Interrupt Enable bit
	INTCON -> INT0IE = 1;		// INT0 External Interrupt Enable bit
	INTCON2 -> INTEDG0 = 1;		// External Interrupt 0 Edge Select bit

	while(1){
		*PORTB ^= 0x80;
		delay_ms(x);
		}
}
