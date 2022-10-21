#include "gpio.h"

#include <xc.h> // include processor files - each processor file is guarded.  

void gpios_init()
{

    RBPU =0;            //port B pullup register on
    TRISBbits.RB0 = 0;   //making the o/p
    TRISBbits.RB7 = 0;   //making the O/P
}