/*
	Basic PORTC pin Bo Led Blinker.
	Use for troubleshooting.
*/

#include "../../Library/Library_18f4520.h"

main(){
   ADCON1 -> PCFGx = 0xF; // ADCON1 |= 0x0F;  Set all to digital
   *TRISC = 0x00;
   while(1){
   	*PORTC ^= 0x01;
   	delay_ms(500);
   }
}
