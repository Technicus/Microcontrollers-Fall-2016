// Blink Test
#include <18f4520.h>
#use delay (clock = 2000000)
#fuses HS, NOWDT, NOLVP
#include "18F4520ptr.h"

main(){
	*TRISC^=0x00;
	while(1){
		*PORTC^=0x01;
		delay_ms(100);
		}
}

b
