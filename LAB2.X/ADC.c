#include <xc.h>
#include <stdint.h>
#define _XTAL_FREQ 4000000

void configADC(){
    ADCON0bits.ADCS=1;
    ADCON1=0;
}
int8_t lecADC(int8_t x){
    switch(x){
        case 0: TRISAbits.TRISA0=1; ANSELbits.ANS0=1; ADCON0bits.CHS=0;
        case 1: TRISAbits.TRISA1=1; ANSELbits.ANS1=1; ADCON0bits.CHS=1;
        case 2: TRISAbits.TRISA2=1; ANSELbits.ANS2=1; ADCON0bits.CHS=2;
        case 3: TRISAbits.TRISA3=1; ANSELbits.ANS3=1; ADCON0bits.CHS=3;
        case 4: TRISAbits.TRISA5=1; ANSELbits.ANS4=1; ADCON0bits.CHS=4;
        case 5: TRISEbits.TRISE0=1; ANSELbits.ANS5=1; ADCON0bits.CHS=5; 
        case 6: TRISEbits.TRISE2=1; ANSELbits.ANS6=1; ADCON0bits.CHS=6;
        case 7: TRISEbits.TRISE3=1; ANSELbits.ANS7=1; ADCON0bits.CHS=7;
        case 8: TRISBbits.TRISB2=1; ANSELHbits.ANS8=1; ADCON0bits.CHS=8;
        case 9: TRISBbits.TRISB3=1; ANSELHbits.ANS9=1; ADCON0bits.CHS=9;
        case 10: TRISBbits.TRISB1=1; ANSELHbits.ANS10=1; ADCON0bits.CHS=10;
        case 11: TRISBbits.TRISB4=1; ANSELHbits.ANS11=1; ADCON0bits.CHS=11;
        case 12: TRISBbits.TRISB0=1; ANSELHbits.ANS12=1; ADCON0bits.CHS=12;
        case 13: TRISBbits.TRISB5=1; ANSELHbits.ANS13=1; ADCON0bits.CHS=13;
    }
    ADCON0bits.ADON=1;
    __delay_ms(2);
    ADCON0bits.GO=1;
    resultado:
    if(ADCON0bits.GO_DONE==1){goto resultado;}
    else {ADCON0bits.ADON=0; return ADRESH;}
}