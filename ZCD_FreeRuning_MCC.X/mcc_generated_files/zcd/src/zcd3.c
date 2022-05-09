/**
  ZCD3 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    zcd3.c

  @Summary
    This is the generated driver implementation file for the ZCD3

  @Description
    This source file provides APIs for ZCD3.
    Generation Information :
        Driver Version    :  1.0.0
    The generated drivers are tested against the following:
        Compiler          :  XC8 v2.20
        MPLAB             :  MPLABX v5.40
*/
/*
© [2022] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/


#include "../zcd3.h"

int8_t ZCD3_Initialize(void)
{   
    //INTMODE No interrupt; 
    ZCD3.INTCTRL = 0x0;

    //ENABLE enabled; INVERT disabled; RUNSTDBY disabled; OUTEN enabled; 
    ZCD3.CTRLA = 0x41;
    
    return 0;
}

ISR(ZCD3_ZCD_vect)
{
    /* Insert your ZCD interrupt handling code here */

    /* The interrupt flag has to be cleared manually */
    ZCD3.STATUS = ZCD_CROSSIF_bm;
}
