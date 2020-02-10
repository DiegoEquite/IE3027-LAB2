#include <xc.h> 
#include <stdint.h>
#include "7segmentos.h"
//conversion ingresa el numero y regresa el valor para mostrarlo en el display 7 segmentos
uint8_t segmentos(uint8_t numero){
    switch(numero){
        case 0: return 63; break;
        case 1: return 6; break;
        case 2: return 91; break;
        case 3: return 79; break;
        case 4: return 102; break;
        case 5: return 109; break;
        case 6: return 125; break;
        case 7: return 7; break;
        case 8: return 127; break;
        case 9: return 111; break;
        case 10: return 119; break;
        case 11: return 124; break;
        case 12: return 57; break;
        case 13: return 94; break;
        case 14: return 121; break;
        case 15: return 113; break;
        default: return 0;
    }
}
