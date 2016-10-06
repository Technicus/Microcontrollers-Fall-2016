#include <18f4520.h>
#use delay (clock = 20000000)
#fuses HS, NOWDT, NOLVP
#include "..\Library\18f4520ptr.h"
#include "..\Library\modifiedlcd.h"
int16 x = 0;

#INT_AD   // Triggered by GODONE = 1
void int_ad_isr(){
  x = *Q;  // AD Read
}

main(){
   lcd_init();
   // AD Setup
   ADCON0->CHSx = 0;  // AN0
   ADCON0->ADON = 1;  // Unit is ON
   *TRISA = 0x03;     // A0 Input   0x3  0011
   ADCON2->ADFM = 1;  // Right Justified.
   ADCON2->ACQTx = 5; // 12TADs
   ADCON2->ADCSx = 5; // Fosc / 16
   // Interrupt Setupt
   PIE1->ADIE=1;      // #INT_AD ON
   INTCON->PEIE = 1;  // Peripherals ON
   INTCON->GIE = 1;   // Global ON
   while(1){
       ADCON0->CHSx = 0;
       ADCON0->GODONE = 1;   // Trigger the A/D
       delay_ms(400);
       printf(lcd_putc,"\fV1=%f V",x*(5.0/1023.0));
       ADCON0->CHSx = 1;  
       ADCON0->GODONE = 1;   // Trigger the A/D
       delay_ms(400);
       printf(lcd_putc,"\nV2=%f V",x*(5.0/1023.0));
   }
}
