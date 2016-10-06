#include <18F4520.h>
#use delay (clock = 20000000)
#fuses HS, NOWDT, NOLVP
#include "..\Library\18f4520ptr.h"


#define C0  0x6
#define C1  0x5
#define C2  0x3

#define R0  0xE
#define R1  0xD
#define R2  0xB
#define R3  0x7

struct myKeyPad{
   int COLS:3;
   int unused:1;
   int ROWS:4;
};
struct myKeyPad *KEYPAD = 0xF81;

char keyPadRead(void);  // Declaration

main(){ 
   char x;
   ADCON1->PCFGx=0xF; // All Digital
   INTCON2->RBPU=0;   // Pull Ups Engage
   *TRISB = 0xF0;     // Upper Input
   *TRISC = 0x00;     // Display
   *PORTC = 0x00;
   while(1){
      x = keyPadRead();  // Call
      if(x!='~')
        *PORTC=x;
      delay_ms(200);
   }
}


char keyPadRead(void){   // Definition
  char x = '~';
  KEYPAD->COLS = C0;     // Write
  switch(KEYPAD->ROWS){  // Read
     case R0: x='1'; break;
     case R1: x='4'; break;
     case R2: x='7'; break;
     case R3: x='*'; break;
     default:
  }
  KEYPAD->COLS = C1;     // Write
  switch(KEYPAD->ROWS){  // Read
     case R0: x='2'; break;
     case R1: x='5'; break;
     case R2: x='8'; break;
     case R3: x='0'; break;
     default:
  }
  KEYPAD->COLS = C2;     // Write
  switch(KEYPAD->ROWS){  // Read
     case R0: x='3'; break;
     case R1: x='6'; break;
     case R2: x='9'; break;
     case R3: x='#'; break;
     default:
  }
  return(x);
}
