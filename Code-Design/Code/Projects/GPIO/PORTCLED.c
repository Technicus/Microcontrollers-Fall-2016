/*
 *  Basic PORTC Pin C0 LED blinker.
 *  Used for troubleshooting.
 * 
 */
#include <18f4520.h>
#use delay (clock = 20000000)
#fuses HS, NOWDT, NOLVP
#include "../Library/18f4520ptr.h"

main(){
   ADCON1->PCFGx = 0xF;  // All digital
   *TRISC = 0x00;        // All Output on C
   *TRISC = 0xF0;  // 
   
   while(1){
      *PORTC ^= 0x01;
      delay_ms(500);
   }
}
