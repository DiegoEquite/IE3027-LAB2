#include <xc.h>
#include <stdint.h>

void segmentos(uint8_t PUERTO, uint8_t numero){
    switch(numero){
        case 0: PUERTO=63;
        case 1: PUERTO=6;
        case 2: PUERTO=91;
        case 3: PUERTO=79;
        case 4: PUERTO= 102;
        case 5: PUERTO= 109;
        case 6: PUERTO= 125;
        case 7: PUERTO= 7;
        case 8: PUERTO= 127;
        case 9: PUERTO= 111;
        case 10: PUERTO= 119;
        case 11: PUERTO= 124;
        case 12: PUERTO= 57;
        case 13: PUERTO= 94;
        case 14: PUERTO= 121;
        case 15: PUERTO= 161;
        default: PUERTO=0;
    }
}
