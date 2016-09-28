/*
 * Initial lcd test
 * 2016.09.28
*/

#include "../../Library/Library_18f4520.h"

//float Vres = 5.0 / 1023.0;

main(){

   lcd_init();
   printf(lcd_putc, "\fHello \n:)");

   //  ADCON0->ADON = 1;
   //  ADCON0->CHSx = 1;
   //  ADCON1->PCFGX = 8;

   //  *TRISA = 0x02;  // set A0 as input

   //ADCON2->ADFM = 1; // right justify

   

   while(1){
int X = 0;
   //      ADCON0->GODONE = 1; // go
   //      while(ADCON0->GODONE){}
   //
   //      printf(lcd_putc, "\f lcd");
   //      printf(lcd_putc, "\n %f", *Q * Vres);

   //      delay_ms(300);

	printf(lcd_putc, "\n:) X=%lu",(long)X++);

	delay_ms(300);

   }

}
