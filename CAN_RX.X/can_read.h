/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */
#include<xc.h>

void can_read() 
{
    unsigned char data1[20];
    CANCON = 0x0E;
    data1[0]= RXB0D0;    //read from the 1st register in the buffer 0
    data1[1] = RXB0D1;    //read from the 2nd register in the buffer 0
    data1[2] = RXB0D2;    //read from the 3rd register in the buffer 0
    data1[3] = RXB0D3;    //read from the 4th register in the buffer 0
    data1[4] = RXB0D4;    //read from the 5th register in the buffer 0
    data1[5] = RXB0D5;    //read from the 6th register in the buffer 0
    data1[6] = RXB0D6;    //read from the 7th register in the buffer 0
    data1[7]= RXB0D7;    //read from the 8th register in the buffer 0
    data1[8] = RXB0DLC;
    data1[9] = RXB0SIDH;
    data1[10] = RXB0SIDL;
    RXB0CONbits.RXB0FUL = 0;
    CANCON = 0x08;
}

void can_write(unsigned char DLC,int msg_id,char data[])
{
    CANCON = 0x08;      //CAN control configuration in normal mode
    TXB0DLC = DLC;      //put data length code into DLC control register
    
   char LB =  (msg_id<<5)&0xff;     //left shift 5 for getting lower 3 bis + 00000 and bit wise anding with 0xff for making 1 byte
   char HB =  (msg_id>>3)&0xff;     //right shift 3 for higher 8 bits from 11 bit and bit wise anding with 0xff for making 1 byte
   
   TXB0SIDL = LB;       //put lower byte value into lower byte data length register
   TXB0SIDH = HB;       //put higher byte value into higher byte data length register
   
   TXB0D0 = data[0];    //put in the 1st register in the buffer 0
   TXB0D1 = data[1];    //put in the 2nd register in the buffer 0
   TXB0D2 = data[2];    //put in the 3rd register in the buffer 0
   TXB0D3 = data[3];    //put in the 4th register in the buffer 0
   TXB0D4 = data[4];    //put in the 5th register in the buffer 0
   TXB0D5 = data[5];    //put in the 6th register in the buffer 0
   TXB0D6 = data[6];    //put in the 7th register in the buffer 0
   TXB0D7 = data[7];    //put in the 8th register in the buffer 0
   
   TXB0CON = 0x08;      //transmit buffer 0 configuration in normal mode
   
   
}