/*
 * Initial lcd test
 * 2016.09.28
*/

#include "../../Library/Library_18f4520.h"

//float Vres = 5.0 / 1023.0;

main(){
   char press = '@';
   int X = 0;

   lcd_init();
   printf(lcd_putc, "\fHello \n:)");

   while(1){

	//printf(lcd_putc, "\n:) X=%lu",(long)X++);

	press = keyPress();
      if( press != '@'){
         printf(lcd_putc, "\f %c", press);
      }

	delay_ms(10);

   }

}
