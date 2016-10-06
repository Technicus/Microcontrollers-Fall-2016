/*
	Ananlog to Digital Interrupt
*/

#include "../../Library/Library_18f4520.h"

int16 x = 0;

#INT_AD // Triggered by AD/GODONE = 1
void int_ad_isr(){
  x = *Q; // AD Read
}

//float Vres = 5.0 / 1023.0;  // rail values

main(){
  
  // LCD Setup
  lcd_init();
   
  // Analog - Digital Setup
  ADCON0->CHSx = 0;  // AN0
  ADCON0->ADON = 1;  // Unit is ON

  *TRISA = 0x03;     // A0 Input

  ADCON2->ADFM = 1;  // Right Justified.
  ADCON2->ACQTx = 5; // 12TADs
  ADCON2->ADCSx = 5; // Fosc / 16
  
  // Interrupt Setup
  PIE1->ADIE=1; // #INT_AD on
  INTCON->PEIE = 1; // Preherals on
  INTCON->GIE = 1; // Globals on

  while(1){
    ADCON0->CHSx = 0; // AN0
    ADCON0->GODONE = 1; // Activates A/D
    // printf(lcd_putc,"\f Raw %lu", x);
    printf(lcd_putc,"\f v=%f", x * (5.0 / 1023.0));
    delay_ms(50);
    
    ADCON0->CHSx = 1; // AN1
    ADCON0->GODONE = 1; // Activates A/D
    // printf(lcd_putc,"\f Raw %lu", x);
    printf(lcd_putc,"\n v=%f", x * (5.0 / 1023.0));
    delay_ms(50);
        

  }
}
