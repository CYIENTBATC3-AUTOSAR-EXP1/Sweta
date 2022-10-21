
#include<xc.h>
#include "can_config.h"

void can_sys_init(void)
{
    TRISBbits.RB2 = 0;          //setting RB2 as Tx
    TRISBbits.RB3 = 1;          //setting RB3 as Rx
}

void masking_filter(void)
{
    RXF0SIDH = 0x00;     //masking off
    RXF0SIDL = 0x00;    //filter off
}

char set_mode(int bud)
{
    CANCON = 0x80;  //Can control register configuration mode set
    
    while(CANSTAT!= 0x80);  //if can control reg status is not equals to 0x80 it'll loop inside up until it becomes 0x80 
    if (bud == 250)
    {
        /*setting the bud-rate as 250*/
        BRGCON1 = 0xc1;
        BRGCON2 = 0xae;
        BRGCON3 = 0x45;
        
        if(BRGCON1 == 0xc1 && BRGCON2 == 0xae &&  BRGCON3 == 0x45) //checking if the bud-rate is successfully set or not
        {
            return 'Y';     //return Y if bud-rate successfully set
        }
        else
            return 'N';      //return N if failed
        
    }
    
    CANCON = 0x08;      //transmit buffer 0 configuration in normal mode
}