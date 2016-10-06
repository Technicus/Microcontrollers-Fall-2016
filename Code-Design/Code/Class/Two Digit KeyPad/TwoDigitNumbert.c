#include <18F4520.h>
#use delay (clock = 20000000)
#fuses HS, NOWDT, NOLVP
#include "..\Library\18f4520ptr.h"
#include "..\Library\keypad.h"

main(){
   unsigned int number=0;
   ADCON1->PCFGx=0xF; // All Digital
   INTCON2->RBPU=0;   // Pull Ups Engage
   *TRISB = 0xF0;     // Upper Input
   *TRISC = 0x00;     // Display
   *PORTC = 0x00;
   while(1){
      number=twoDigitNumber(number);
      *PORTC=number;
      delay_ms(200);
   }
}

