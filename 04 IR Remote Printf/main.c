/**************************************************************/
/*
//Sample Code for HexaPOD
//Controller used 	: P89V51RD2
//Crystal Frequency	: 20.000 Mhz X 2

//Project Details	: IR remote switch sensing

//for more details visit us at http://www.robosoftsystems.co.in/blog/
*/
/**************************************************************/
#include <reg51f.h> //Include registrey files for P89v51RD2
#include <stdio.h>
#include "robosoft.h" //Includes servo control and IR remote functions

void Serial_Init(void)
{
    SCON |= 0x50;
    TMOD |= 0x20;
    TH1 = 0xF5;
    TL1 = 0xF5;
    TR1 = 1;
    TI = 1;
}

void main(void)
{
    unsigned char button;
    Remote_Init(); // initialise IR remote
    Serial_Init();
    while (1)
    {                         //while 1 to repeat code again and again :-)
        button = IR_REMOTE(); // scan and check for any remote key is pressed
        if (button)
            printf("%d", (unsigned int)button);
    }
}
