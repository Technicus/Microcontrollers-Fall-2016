/*
   This code is just for testing purposes. 
*/
#include <18f4520.h>
#use delay (clock = 20000000)
#fuses HS, NOWDT, NOLVP
#include "../Library/18f4520library.h"

#INT_EXT      // Interrupt 0
void int_ext_isr(){
    *PORTC ^= 0x01;   // 
}


main(){
   ADCON1->PCFGx = 0xF;  // All digital
   *TRISB = 0x01;        // B0 Input
   *TRISC = 0x00;        // All C output
   INTCON->GIE = 1;
   INTCON->PEIE = 1;
   INTCON->INT0IE = 1;
   while(1){
   }
}
