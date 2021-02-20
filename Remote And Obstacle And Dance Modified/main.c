/**************************************************************/
/*
//Sample Code for HexaPOD
//Controller used 	: P89V51RD2
//Crystal Frequency	: 20.000 Mhz X 2

//Project Details	: Obsatcle Avoiding Code

//for more details visit us at http://www.robosoftsystems.co.in/blog/
*/
/**************************************************************/
#include <reg51f.h> //Include registrey files for P89v51RD2
#include <stdio.h>
#include "robosoft.h" //Includes servo control and IR remote functions

#define R_M 1 //defining Servo Channel for Hexabot//Right Servo Motor
#define C_M 2 //defining Servo Channel for Hexabot//Center Servo Motor
#define L_M 3 //defining Servo Channel for Hexabot//Left Servo Motor

#define RFWD 120 // definig servo angle // Right Leg Forward
#define RNEU 90	 // definig servo angle // Right Leg Neutral
#define RBAK 60	 // definig servo angle // Right Leg Backward

#define LFWD 60	 // definig servo angle // Left Leg Forward
#define LNEU 90	 // definig servo angle // Left Leg Neutral
#define LBAK 120 // definig servo angle // Left Leg Backward

#define CLFT 105 // definig servo angle // Middle Leg Left Leg Up
#define CNEU 90	 // definig servo angle // Middle Leg Neutral
#define CRIT 75	 // definig servo angle // Middle Leg Right Leg Up

sbit Lobs = P2 ^ 0; //Defining Obstacle sensors for Left Side
sbit Robs = P2 ^ 1; //Defining Obstacle sensors for Right Side

unsigned char button = 0x00;
unsigned char RDATA;
unsigned char mode;

void wait1sec()
{
	unsigned int us, ms;
	for (ms = 0; ms < 1000; ms++)
		for (us = 0; us < 300; us++)
			;
}

void goforward(void)
{ //Step sequence for going forward
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
{ //Step sequence for going Backward
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
{ //Step sequence for turning Right
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
{ //Step sequence for turning Letf
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
{ //Step sequence for machint to stop in neutral position
	Servo_Control(R_M, RNEU);
	Servo_Control(L_M, LNEU);
	Servo_Control(C_M, CNEU);
	wait1sec();
}

void Navigation(void)
{
	bit esc = 0;

	printf("\n  Navigation Mode");
	printf("\n MODE : ESC\n");

	while (!esc)
	{
		button = IR_REMOTE();
		if (button == FWD)
			goforward();
		if (button == BWD)
			gobackward();
		if (button == LEFT)
			turnleft();
		if (button == RIGHT)
			turnright();
		if (button == STOP)
			stop1();
		if (button == MD)
		{
			stop1();
			esc = 1;
		}
	}
}

void delay(void)
{
	unsigned char a, b, c;
	for (a = 0; a < 255; a++)
		for (b = 0; b < 120; b++)
			for (c = 0; c < 10; c++)
				;
}

void delay1(void)
{
	unsigned char a, b, c;
	for (a = 0; a < 255; a++)
		for (b = 0; b < 120; b++)
			for (c = 0; c < 6; c++)
				;
}

void delay2(void)
{
	unsigned char a, b, c;
	for (a = 0; a < 250; a++)
		for (b = 0; b < 55; b++)
			for (c = 0; c < 6; c++)
				;
}

void Dance_A(void)
{
	int j, k, l;
	//printf("\rDance A");

	Servo_Control(R_M, RFWD);
	Servo_Control(C_M, CNEU);
	Servo_Control(L_M, LBAK);
	delay1();
	Servo_Control(R_M, RNEU);
	Servo_Control(C_M, CNEU);
	Servo_Control(L_M, LNEU);
	delay();
	Servo_Control(R_M, RBAK);
	Servo_Control(C_M, CNEU);
	Servo_Control(L_M, LFWD);
	delay1();
	Servo_Control(R_M, RNEU);
	Servo_Control(C_M, CNEU);
	Servo_Control(L_M, LNEU);
	delay();

	for (j = 0; j < 3; j++)
	{
		Servo_Control(R_M, RNEU);
		Servo_Control(C_M, CRIT);
		Servo_Control(L_M, LBAK);
		delay1();
		Servo_Control(R_M, RNEU);
		Servo_Control(C_M, CRIT);
		Servo_Control(L_M, LFWD);
		delay();
	}

	for (k = 0; k < 3; k++)
	{
		Servo_Control(R_M, RFWD);
		Servo_Control(C_M, CLFT);
		Servo_Control(L_M, LNEU);
		delay1();
		Servo_Control(R_M, RBAK);
		Servo_Control(C_M, CLFT);
		Servo_Control(L_M, LNEU);
		delay();
	}

	for (l = 0; l < 6; l++)
	{
		Servo_Control(R_M, RNEU);
		Servo_Control(C_M, CLFT);
		Servo_Control(L_M, LNEU);
		delay2();
		Servo_Control(R_M, RNEU);
		Servo_Control(C_M, CRIT);
		Servo_Control(L_M, LNEU);
		delay2();
	}

	Servo_Control(R_M, RNEU);
	Servo_Control(C_M, CNEU);
	Servo_Control(L_M, LNEU);
	delay1();
}

void Dance_B(void)
{
	int i, j, k, l;
	//printf("\rDance B");
	for (i = 0; i < 2; i++)
	{
		Servo_Control(R_M, RFWD);
		Servo_Control(C_M, CNEU);
		Servo_Control(L_M, LBAK);
		delay1();
		Servo_Control(R_M, RBAK);
		Servo_Control(C_M, CNEU);
		Servo_Control(L_M, LBAK);
		delay1();
	}

	for (j = 0; j < 2; j++)
	{
		Servo_Control(R_M, RNEU);
		Servo_Control(C_M, CLFT);
		Servo_Control(L_M, LNEU);
		delay1();
		Servo_Control(R_M, RNEU);
		Servo_Control(C_M, CRIT);
		Servo_Control(L_M, LNEU);
		delay1();
	}

	for (k = 0; k < 4; k++)
	{
		Servo_Control(R_M, RFWD);
		Servo_Control(C_M, CLFT);
		Servo_Control(L_M, LFWD);
		delay1();
		Servo_Control(R_M, RFWD);
		Servo_Control(C_M, CRIT);
		Servo_Control(L_M, LFWD);
		delay1();
	}

	for (l = 0; l < 4; l++)
	{
		Servo_Control(R_M, RBAK);
		Servo_Control(C_M, CLFT);
		Servo_Control(L_M, LBAK);
		delay1();
		Servo_Control(R_M, RBAK);
		Servo_Control(C_M, CRIT);
		Servo_Control(L_M, LBAK);
		delay1();
	}

	for (i = 0; i < 2; i++)
	{
		Servo_Control(R_M, RFWD);
		Servo_Control(C_M, CNEU);
		Servo_Control(L_M, LBAK);
		delay1();
		Servo_Control(R_M, RBAK);
		Servo_Control(C_M, CNEU);
		Servo_Control(L_M, LBAK);
	}
	delay1();

	for (i = 0; i < 2; i++)
	{
		Servo_Control(R_M, RBAK);
		Servo_Control(C_M, CNEU);
		Servo_Control(L_M, LFWD);
		delay1();
		Servo_Control(R_M, RBAK);
		Servo_Control(C_M, CNEU);
		Servo_Control(L_M, LBAK);
		delay1();
	}

	Servo_Control(R_M, RNEU);
	Servo_Control(C_M, CNEU);
	Servo_Control(L_M, LNEU);
	delay1();
}

void Dance_C(void)
{
	int i, j, k, l;
	//printf("\rDance C");
	goforward();
	goforward();
	goforward();

	delay();
	delay();
	delay();
	delay();

	for (i = 0; i < 5; i++)
	{
		Servo_Control(R_M, RBAK);
		Servo_Control(C_M, CLFT);
		Servo_Control(L_M, LBAK);
		delay2();
		Servo_Control(R_M, RBAK);
		Servo_Control(C_M, CRIT);
		Servo_Control(L_M, LBAK);
		delay2();
	}

	gobackward();
	gobackward();
	gobackward();
	delay();
	delay();
	delay();
	delay();
	for (j = 0; j < 5; j++)
	{
		Servo_Control(R_M, RFWD);
		Servo_Control(C_M, CLFT);
		Servo_Control(L_M, LFWD);
		delay2();
		Servo_Control(R_M, RFWD);
		Servo_Control(C_M, CRIT);
		Servo_Control(L_M, LFWD);
		delay2();
	}

	turnleft();
	turnleft();
	turnleft();
	turnleft();
	delay();
	delay();
	delay();
	delay();

	for (k = 0; k < 5; k++)
	{
		Servo_Control(R_M, RBAK);
		Servo_Control(C_M, CLFT);
		Servo_Control(L_M, LBAK);
		delay2();
		Servo_Control(R_M, RBAK);
		Servo_Control(C_M, CRIT);
		Servo_Control(L_M, LBAK);
		delay2();
	}

	turnright();
	turnright();
	turnright();
	turnright();
	delay();
	delay();
	delay();
	delay();

	for (l = 0; l < 5; l++)
	{
		Servo_Control(R_M, RFWD);
		Servo_Control(C_M, CLFT);
		Servo_Control(L_M, LFWD);
		delay2();
		Servo_Control(R_M, RFWD);
		Servo_Control(C_M, CRIT);
		Servo_Control(L_M, LFWD);
		delay2();
	}

	Servo_Control(R_M, RNEU);
	Servo_Control(C_M, CNEU);
	Servo_Control(L_M, LNEU);
	delay1();
}

void Dance(void)
{
	bit esc = 0;
	P3 = 0xdf;
	printf("\nDance");
	printf("\n1:A 2:B 3:C");
	printf("\nMODE : ESC\n");

	delay1();
	while (!esc)
	{
		button = IR_REMOTE();
		if (button == NUM_1)
			Dance_A();
		if (button == NUM_2)
			Dance_B();
		if (button == NUM_3)
			Dance_C();
		if (button == MD)
			esc = 1;
	}
}

void obstacle(void)
{
	bit esc = 0;
	P3 = 0x7f;
	printf("\nObstacle");
	printf("\n MODE : ESC\n");
	while (!esc)
	{
		button = IR_REMOTE();
		if (button == MD)
			esc = 1;
		if (Lobs == 1 && Robs == 1)
			goforward();
		if (Lobs == 0 && Robs == 1)
			turnright();
		if (Lobs == 1 && Robs == 0)
			turnleft();
		if (Lobs == 0 && Robs == 0)
		{
			gobackward();
			gobackward();
			gobackward();
			gobackward();
			turnright();
			turnright();
			turnright();
		}
	}
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

void print_string(void)
{
	P3 = 0xff;
	printf("\n1:Dance 2:Navigation 3:Obstacle");
}

void main(void)
{
	P3 = 0x1f;
	delay1();
	P3 = 0xff;
	Serial_Init();
	Lobs = 1;
	Robs = 1;
	Servo_Init();
	Remote_Init();
	stop1();

	printf("\nHexa BOT");

	print_string();
	while (1)
	{
		button = IR_REMOTE();

		if (button == NUM_1)
		{
			Dance();
			print_string();
		}
		else if (button == NUM_2)
		{
			Navigation();
			print_string();
		}
		else if (button == NUM_3)
		{
			obstacle();
			print_string();
		}
	}
}
