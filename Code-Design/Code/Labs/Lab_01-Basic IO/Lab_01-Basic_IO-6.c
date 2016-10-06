/*
 * Lab 01
 *  Basic IO
 * 2016.10.06
*/

#include "../../Library/Library_18f4520.h"

int main(){

   
   *TRISC = 0x00;
   *PORTC = 0x00;
   while(1){
      *PORTC ^= 0x10;
      delay_ms(200);
      
   }
}
