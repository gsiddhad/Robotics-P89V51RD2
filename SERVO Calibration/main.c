/**************************************************************/
/*
//Sample Code for HexaPOD
//Controller used 	: P89V51RD2
//Crystal Frequency	: 20.000 Mhz X 2

//Project Details	: Servo Motor Interface

//for more details visit us at http://www.robosoftsystems.co.in/blog/
*/
/**************************************************************/
#include <reg51f.h>				//Include registrey files for P89v51RD2
#include <stdio.h>				//Include Standard input output
#include "robosoft.h"			//Includes servo control and IR remote functions

//Define channel number to each servo
#define R_M 1					//Right Servo Motor is on channel 1 that is pin number P1.4
#define C_M 2					//Center Servo Motor is on channel 2 that is pin number P1.5
#define L_M 3					//Left Servo Motor is on channel 3 that is pin number P1.6

sbit KEY1 = P3^2;			   //key 1 to selct servo motor      //KEY defination
sbit KEY2 = P3^3;			   //key 2 is to decrese the angle
sbit KEY3 = P3^4;			   //key 3 is to increse the angel

sbit LED1 = P3^5;			   //LED defination
sbit LED2 = P3^6;
sbit LED3 = P3^7;

unsigned char LED=0;
unsigned char LFT,RGHT,CNTR;

void Serial_Init(void) {
    SCON |= 0x50;
    TMOD |= 0x20;
    TH1=0xF5;
    TL1=0xF5;
    TR1=1;
    TI=1;
}

void Delay(void) {
    unsigned int i=0;
    for(i=0;i<32000;i++);
}

void main(void) {
    Servo_Init();
    Serial_Init();

    KEY1 = 1;
    KEY2 = 1;
    KEY3 = 1;

    LFT=90;
    RGHT=90;
    CNTR=90;

    LED1=0;
    LED2=1;
    LED3=1;

    printf("\n  Robosoft Systems");
    printf("\nServo Values for ARC");
    printf("\nACTIVE  L_M   C_M   R_M");
    printf("\n  L_M   %03d   %03d   %03d",(unsigned int)LFT,(unsigned int)CNTR,(unsigned int)RGHT);
    printf("\n");

    while(1) {
	    if(!KEY1) {
            LED++;
		    if(LED>2)
		        LED=0;
		    if(LED==0) {
                LED1=0;
                LED2=1;
                LED3=1;
			}
            if(LED==1) {
                LED1=1;
                LED2=0;
                LED3=1;
			}
            if(LED==2) {
                LED1=1;
                LED2=1;
                LED3=0;
			}
			Delay();
            Delay();
		}
	    if(!KEY2) {
            if(LED==0) {
                if(LFT > 0)
                    LFT--;
                Servo_Control(L_M,LFT);
            }
            if(LED==1) {
                if(CNTR > 0)
                    CNTR--;
                Servo_Control(C_M,CNTR);
			}
            if(LED==2) {
                if(RGHT>0)
                    RGHT--;
                Servo_Control(R_M,RGHT);
			}
            Delay();
        }
        if(!KEY3) {
            if(LED==0) {
                if(LFT < 180)
                    LFT++;
                Servo_Control(L_M,LFT);
			}
            if(LED==1) {
                if(CNTR < 180)
                    CNTR++;
                Servo_Control(C_M,CNTR);
			}
            if(LED==2) {
                if(RGHT < 180)
                    RGHT++;
                Servo_Control(R_M,RGHT);
			}
			Delay();
		}
        if(LED==0)
            printf("\r  L_M");
        if(LED==1)
            printf("\r  C_M");
        if(LED==2)
            printf("\r  R_M");
        printf("  %03d   %03d   %03d",(unsigned int)LFT,(unsigned int)CNTR,(unsigned int)RGHT);
	}
}
