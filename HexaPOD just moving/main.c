#include <reg51f.h>
#include <stdio.h>
#include "robosoft.h"

#define R_M 1
#define C_M 2
#define L_M 3

#define RFWD 120
#define RNEU 90
#define RBAK 60

#define LFWD 60
#define LNEU 90
#define LBAK 120

#define CLFT 100
#define CNEU 85
#define CRIT 70

void wait1sec()
{
    unsigned int us, ms;
    for (ms = 0; ms < 1000; ms++)
        for (us = 0; us < 300; us++)
            ;
}

void goforward(void)
{
    Servo_Control(R_M, RBAK);
    Servo_Control(L_M, LFWD);
    Servo_Control(C_M, CRIT);
    wait1sec();

    Servo_Control(R_M, RFWD);
    Servo_Control(L_M, LBAK);
    Servo_Control(C_M, CLFT);
    wait1sec();
}

void gobackward(void)
{
    Servo_Control(R_M, RFWD);
    Servo_Control(L_M, LBAK);
    Servo_Control(C_M, CRIT);
    wait1sec();

    Servo_Control(R_M, RBAK);
    Servo_Control(L_M, LFWD);
    Servo_Control(C_M, CLFT);
    wait1sec();
}

void turnright(void)
{
    Servo_Control(R_M, RNEU);
    Servo_Control(L_M, LFWD);
    Servo_Control(C_M, CLFT);
    wait1sec();

    Servo_Control(R_M, RNEU);
    Servo_Control(L_M, LBAK);
    Servo_Control(C_M, CLFT);
    wait1sec();

    Servo_Control(R_M, RNEU);
    Servo_Control(L_M, LBAK);
    Servo_Control(C_M, CRIT);
    wait1sec();

    Servo_Control(R_M, RNEU);
    Servo_Control(L_M, LFWD);
    Servo_Control(C_M, CRIT);
    wait1sec();
}

void turnleft(void)
{
    Servo_Control(R_M, RBAK);
    Servo_Control(L_M, LNEU);
    Servo_Control(C_M, CLFT);
    wait1sec();

    Servo_Control(R_M, RFWD);
    Servo_Control(L_M, LNEU);
    Servo_Control(C_M, CLFT);
    wait1sec();

    Servo_Control(R_M, RFWD);
    Servo_Control(L_M, LNEU);
    Servo_Control(C_M, CRIT);
    wait1sec();

    Servo_Control(R_M, RBAK);
    Servo_Control(L_M, LNEU);
    Servo_Control(C_M, CRIT);
    wait1sec();
}

void stop1(void)
{
    Servo_Control(R_M, RNEU);
    Servo_Control(L_M, LNEU);
    Servo_Control(C_M, CNEU);
    wait1sec();
}

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
    Servo_Init();
    Remote_Init();
    Serial_Init();
    stop1();

    while (1)
    {
        goforward();
        goforward();
        goforward();
        goforward();
        goforward();
        turnleft();
        turnleft();
        turnleft();
        turnleft();
        turnleft();
        turnright();
        turnright();
        turnright();
        turnright();
        turnright();
        gobackward();
        gobackward();
        gobackward();
        gobackward();
        gobackward();
    }
}
