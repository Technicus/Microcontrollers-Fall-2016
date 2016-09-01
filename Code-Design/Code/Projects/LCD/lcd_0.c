/* Initial lcd test
   2015-.09.24
   ../../designs/LCDpanel_1.design
*/

#include <18f4520.h>
#use delay (clock = 200000000)
#fuses HS, NOWDT, NOLvP
#include "../Library/18f4520ptr.h"
#include "../library/modifiedlcd.h"

float Vres = 5.0 / 1023.0;

main(){

   lcd_init();
   //printf(lcd_putc, "\fHello \n:)");

   ADCON0->ADON = 1;
   ADCON0->CHSx = 1;
   ADCON1->PCFGX = 8;

   *TRISA = 0x01;  // set A0 as input

   ADCON2->ADFM = 1; // right justify

   while(1){

      ADCON0->GODONE = 1; // go
      
      while(ADCON0->GODONE){}
      
      printf(lcd_putc, "\f lcd_0");
      printf(lcd_putc, "\n %f", *Q * Vres);
      delay_ms(300);

   };
}
