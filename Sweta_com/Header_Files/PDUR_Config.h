/* 
 * File:   PDUR_Config.h
 * Author: ma70436
 *
 * Created on October 18, 2022, 3:48 PM
 */

#ifndef PDUR_CONFIG_H
#define	PDUR_CONFIG_H

#include "PDUR_Config.h"
#include "AUTOSAR_COM_Config.h"


#ifdef	__cplusplus
extern "C" {
#endif
    
    /* CAN Message ID's */
    const int PDUR_MSG_ID[4] = {
        0x100,
        0x010,
        0x150,
        0x200
    };
    /* Data Length Code */
     const int PDUR_DLC[4] = {
        5,
        7,
        8,
        4
    };
     
     const char PDUR_Frame[4]={
         1,
         1,
         1,
         1
     };
    
/* Function Definitions */
void Take_CAN_RX_Index(int ID,char DLC,char* Data);
   
#ifdef	__cplusplus
}
#endif

#endif	/* PDUR_CONFIG_H */

