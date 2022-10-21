/*
 * File:   main.c
 * Author: su69186
 *
 * Created on October 12, 2022, 5:47 PM
 */


#include<xc.h>
#include "pic_config.h"      //pic configaration header file
#include "can_config.h"
#include "can_read.h"
#include "interrupt.h"
#include "gpio.h"
#define _XTAL_FREQ 20000000

void __interrupt() ISR1()
{
    PORTBbits.RB0=1;
    if(RXB0IF == 1) {
        GIE = 0;
        RXB0IF = 0;
        can_read();
        GIE = 1;
    }
}

void main(void) {
    
    init_inrpt();
    can_sys_init(); // intialize pins for Pic tx and rx
    char strat_bud = set_mode(250); // set baud rate
    masking_filter();
    gpios_init();
    
    while(1)
    {
    char sw_off_data[8] = {'S','W','I','T','C','H',' ', '0'};
    char sw_on_data[8] = {'S','W','I','T','C','H',' ', '1'};  
        
            can_write(8,0x88,sw_off_data);     //call can write function with 3 arguments 1. data length 2.message id 3.data array
            __delay_ms(100);
        
            can_write(8,0xFF,sw_on_data);     //call can write function with 3 arguments 1. data length 2.message id 3.data array
            __delay_ms(100); 
            PORTBbits.RB0=0;
    }
    
    return;
}