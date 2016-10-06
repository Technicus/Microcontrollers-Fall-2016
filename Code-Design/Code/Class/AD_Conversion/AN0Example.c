#include <18f4520.h>
#use delay (clock = 20000000)
#fuses HS,NOWDT,NOLVP
#include "../Library/18f4520ptr.h"
#include "../Library/modifiedlcd.h"
float Vres = 5.0 / 1023.0;  // rail values
main(){
    lcd_init();
    ADCON0->CHSx = 0;  // AN0
    ADCON0->ADON = 1;  // Unit is ON
    *TRISA = 0x01;     // A0 Input
    ADCON2->ADFM = 1;  // Right Justified.
    ADCON2->ACQTx = 5; // 12TADs
    ADCON2->ADCSx = 5; // Fosc / 16
    while(1){
       ADCON0->GODONE=1;       // Activates A/D
       while(ADCON0->GODONE){} // wait till its done
       printf(lcd_putc,"\f Raw %lu",(long)*Q);
       printf(lcd_putc,"\n v=%f", (long)*Q * Vres);
       delay_ms(500);
    }
}
 
        
