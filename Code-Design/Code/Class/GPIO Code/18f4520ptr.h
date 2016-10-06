// Here is my 18f4520 Pointer library

// I/O Registers

int *PORTA = 0xF80;
int *PORTB = 0xF81;
int *PORTC = 0xF82;
int *PORTD = 0xF83;
int *PORTE = 0xF84;

int *TRISA = 0xF92;
int *TRISB = 0xF93;
int *TRISC = 0xF94;
int *TRISD = 0xF95;
int *TRISE = 0xF96;

// Interrupts
struct _intcon{
   int RBIF:1;
   int INT0IF:1;
   int TMR0IF:1;
   int RBIE:1;
   int INT0IE:1;
   int TMR0IE:1;
   int PEIE:1;
   int GIE:1;
};
struct _intcon *INTCON = 0xFF2;

struct _intcon2{
   int RBIP:1;
   int notused:1;
   int TMR0IP:1;
   int unused:1;
   int INTEDG2:1;
   int INTEDG1:1;
   int INTEDG0:1;
   int RBPU:1;
};
struct _intcon2 *INTCON2 = 0xFF1;
   
// A/D Circuit
struct _adcon0{
   int ADON:1;
   int GODONE:1;
   int CHSx:4;
   int unused:2;
};
struct _adcon0 *ADCON0 = 0xFC2;

struct _adcon1{
   int PCFGx:4;
   int VCFG0:1;
   int VCFG1:1;
   int unused:2;};
struct _adcon1 *ADCON1 = 0xFC1;

