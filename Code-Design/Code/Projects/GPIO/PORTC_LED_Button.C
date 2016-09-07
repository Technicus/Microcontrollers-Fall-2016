/*
	Basic PORTC pin Bo Led Blinker.
	Use for troubleshooting.
*/

#include "../../Library/Library_18f4520.h"

main(int argc, char *argv[]){
   ADCON1 -> PCFGx = 0xF; // ADCON1 |= 0x0F;  Set all to digital
   *TRISC = 0x80;  // 1000 0000 pin C7 as input
   while(1){
   	*PORTC ^= 0x01; // *PORTC = *PORTC ^ 0x01;
   	if (*PORTC & 0x80){  // Read
	   	delay_ms(250);
   	}
   	else{
	   	delay_ms(500);
   	}
   }
}
