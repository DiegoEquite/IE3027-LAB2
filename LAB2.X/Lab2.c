/*
 * File:   Lab2.c
 * Author: LAB
 *
 * Created on 3 de febrero de 2020, 11:14 AM
 */


#include <xc.h>
#include <stdlib.h>
#include "ADC.h"
#include "7segmentos.h"
void configIO(void);

void main(void) {
    configIO();
    configADC();
    lecADC(1);
}
void configIO(){
    TRISB=0b00000111;
    TRISC=0;
    TRISD=0;
    PORTB=0;
    PORTC=0;
    PORTD=0;
}