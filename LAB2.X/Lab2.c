/*
 * File:   Lab2.c
 * Author: LAB
 *
 * Created on 3 de febrero de 2020, 11:14 AM
 */
// CONFIG1
#pragma config FOSC = INTRC_NOCLKOUT// Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // RE3/MCLR pin function select bit (RE3/MCLR pin function is digital input, MCLR internally tied to VDD)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#include <stdlib.h>  
#include "ADC.h"  
#include "7segmentos.h"  
#define _XTAL_FREQ 4000000
uint8_t vanalog;
uint8_t x=0;
uint8_t unidad;
uint8_t decena;
uint8_t contador=0;
uint8_t contador2=0;
void __interrupt() ISR(){
    if(INTCONbits.RBIF==1){
        if(PORTBbits.RB0==0){contador++;}
        if(PORTBbits.RB1==0){contador--;}
        INTCONbits.RBIF=0;
    }
    if(TMR0IF==1){
        TMR0IF=0;
        TMR0 = 240;
        if(x==1){PORTD=segmentos(unidad);PORTE=1;}
        else if(x==2){PORTD=segmentos(decena);PORTE=2;x=0;};
        x++;
    }
        
}
void configIO(void);


void main(void) {
    configIO();
    configADC();
    while(1){
        PORTA=contador2;
        PORTC=contador;
        vanalog=lecADC(8);
        unidad=vanalog & 15;
        decena=vanalog;
        decena =decena>>4;
        if(vanalog>contador){PORTEbits.RE2=1;}
        else{PORTEbits.RE2=0;}
    }
}


void configIO(){
    TRISA=0;
    TRISB=0b00000111;
    TRISC=0;
    TRISD=0;
    TRISE=0;
    PORTE=0;
    PORTB=0;
    PORTC=0;
    PORTD=0;
    ANSEL=0;
    ANSELH=0;
    OSCCON= 0B01100111;
    INTCONbits.TMR0IE = 1;
    INTCONbits.TMR0IF=0;
    INTCONbits.RBIE=1;
    INTCONbits.RBIF=0;
    IOCBbits.IOCB0=1;
    IOCBbits.IOCB1=1;
    INTCONbits.GIE = 1;
    OPTION_REGbits.T0CS = 0;  // bit 5  TMR0 Clock Source Select bit...0 = Internal Clock (CLKO) 1 = Transition on T0CKI pin
    OPTION_REGbits.T0SE = 0;  // bit 4 TMR0 Source Edge Select bit 0 = low/high 1 = high/low
    OPTION_REGbits.PSA = 0;   // bit 3  Prescaler Assignment bit...0 = Prescaler is assigned to the Timer0
    OPTION_REGbits.PS2 = 1;   // bits 2-0  PS2:PS0: Prescaler Rate Select bits
    OPTION_REGbits.PS1 = 1;
    OPTION_REGbits.PS0 = 1;
    TMR0 = 240;  
    
}