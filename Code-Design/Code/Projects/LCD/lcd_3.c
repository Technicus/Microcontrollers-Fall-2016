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
float Voltage;

#INT_AD
void int_ad_isr(){
   Voltage = (*ADRESL * Vres) - 3;
}

main(){

   lcd_init();
   //printf(lcd_putc, "\fHello \n:)");

   ADCON0->ADON = 1;
   ADCON0->CHSx = 0;
   ADCON1->PCFGX = 8;

   *TRISA = 0x01;  // set A0 as input

   ADCON2->ADFM = 1; // right justify

   // enable references
   ADCON1->VCFG0 = 1;
   ADCON1->VCFG1 = 1;


   // interrupt setup
   PIE1->ADIE = 1;
   INTCON1->GIE = 1;
   INTCON1->PEIE = 1;

   while(1){

      printf(lcd_putc, "\f %fV", Voltage);
      //printf(lcd_putc, "\n %f", *Q );
      ADCON0->GODONE = 1;
      delay_ms(300);

   };
}
