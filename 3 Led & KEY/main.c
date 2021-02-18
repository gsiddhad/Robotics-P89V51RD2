/**************************************************************/
/*
//Sample Code for HexaPOD
//Controller used 	: P89V51RD2
//Crystal Frequency	: 20.000 Mhz X 2

//Project Details	: Simple LED and KEY interface

//for more details visit us at http://www.robosoftsystems.co.in/blog/
*/
/**************************************************************/

#include <reg51f.h>		 //Include registrey files for P89v51RD2
#include "robosoft.h"	 //Includes servo control and IR remote functions

sbit KEY1 = P3^2;		 //defination of KEY1
sbit KEY2 = P3^3;		 //defination of KEY2
sbit KEY3 = P3^4;		 //defination of KEY3

sbit LED1 = P3^5;		 //defination of LED1
sbit LED2 = P3^6;		 //defination of LED2
sbit LED3 = P3^7;		 //defination of LED3

void main(void) {
    KEY1 = 1;				 //Writing 1 to KEY's will set KEY as input pin
    KEY2 = 1;				 //Generally KEY status is high = 1
    KEY3 = 1;				 //when key is pressed it will become low = 0
    while(1) {
        if(KEY1==0)			 //if KEY1 is pressed then its value will be 0
            LED1=0;				 //LED is connected between Vcc and port pin so drivng it zero will turn on LED
        else
            LED1=1;				 //else LED is off

        if(KEY2==0)			//if KEY2 is pressed
            LED2=0;				//LED2 is on
        else
            LED2=1;			    //else LED2 is off

        if(KEY3==0)			//if KEY3 is pressed
            LED3=0;				//LED3 is on
        else
            LED3=1;				//else LED3 is off
    }
}
