/**************************************************************/
/*
//Sample Code for HexaPOD
//Controller used 	: P89V51RD2
//Crystal Frequency	: 20.000 Mhz X 2

//Project Details	: Obsatcle Avoiding Code
//for more details visit us at http://www.robosoftsystems.co.in/blog/
*/
/**************************************************************/
#include <reg51f.h>	//Include registrey files for P89v51RD2
#include"robosoft.h" //Includes servo control and IR remote functions

#define R_M 1	   //defining Servo Channel for Hexabot//Right Servo Motor
#define C_M 2	   //defining Servo Channel for Hexabot//Center Servo Motor
#define L_M 3	   //defining Servo Channel for Hexabot//Left Servo Motor

#define RFWD 120   // definig servo angle // Right Leg Forward
#define RNEU 90	   // definig servo angle // Right Leg Neutral
#define RBAK 60	   // definig servo angle // Right Leg Backward

#define LFWD 60	   // definig servo angle // Left Leg Forward
#define LNEU 90	   // definig servo angle // Left Leg Neutral
#define LBAK 120   // definig servo angle // Left Leg Backward

#define CLFT 100   // definig servo angle // Middle Leg Left Leg Up
#define CNEU 85	   // definig servo angle // Middle Leg Neutral
#define CRIT 70	   // definig servo angle // Middle Leg Right Leg Up


sbit Lobs=P2^0;	//Defining Obstacle sensors for Left Side
sbit Robs=P2^1;	//Defining Obstacle sensors for Right Side

void wait1sec() {
	unsigned int us,ms;
	for(ms=0;ms<1000;ms++)
		for(us=0;us<300;us++);
}

void goforward(void) {			//Step sequence for going forward
	Servo_Control(R_M,RBAK);
	Servo_Control(L_M,LFWD);
	Servo_Control(C_M,CRIT);
	wait1sec();

	Servo_Control(R_M,RFWD);
	Servo_Control(L_M,LBAK);
	Servo_Control(C_M,CLFT);
	wait1sec();
}

void gobackward(void) {			 //Step sequence for going Backward
	Servo_Control(R_M,RFWD);
	Servo_Control(L_M,LBAK);
	Servo_Control(C_M,CRIT);
	wait1sec();

	Servo_Control(R_M,RBAK);
	Servo_Control(L_M,LFWD);
	Servo_Control(C_M,CLFT);
	wait1sec();
}

void turnright(void) {			//Step sequence for turning Right
	Servo_Control(R_M,RNEU);
	Servo_Control(L_M,LFWD);
	Servo_Control(C_M,CLFT);
	wait1sec();

	Servo_Control(R_M,RNEU);
	Servo_Control(L_M,LBAK);
	Servo_Control(C_M,CLFT);
	wait1sec();

	Servo_Control(R_M,RNEU);
	Servo_Control(L_M,LBAK);
	Servo_Control(C_M,CRIT);
	wait1sec();

	Servo_Control(R_M,RNEU);
	Servo_Control(L_M,LFWD);
	Servo_Control(C_M,CRIT);
	wait1sec();
}

void turnleft(void) {			 //Step sequence for turning Left
	Servo_Control(R_M,RBAK);
	Servo_Control(L_M,LNEU);
	Servo_Control(C_M,CLFT);
	wait1sec();

	Servo_Control(R_M,RFWD);
	Servo_Control(L_M,LNEU);
	Servo_Control(C_M,CLFT);
	wait1sec();

	Servo_Control(R_M,RFWD);
	Servo_Control(L_M,LNEU);
	Servo_Control(C_M,CRIT);
	wait1sec();

	Servo_Control(R_M,RBAK);
	Servo_Control(L_M,LNEU);
	Servo_Control(C_M,CRIT);
	wait1sec();
}

void stop1(void) {		 //Step sequence for machint to stop in neutral position
	Servo_Control(R_M,RNEU);
	Servo_Control(L_M,LNEU);
	Servo_Control(C_M,CNEU);
	wait1sec();
}

void main(void) {
	Lobs=1;			   // set sensor as input channel
	Robs=1;			   // set sensor as input channel
	Servo_Init();	   // Initalise Servo Motors
	stop1();		   // All legs in neutral position

	while(1) {
		if(Lobs==1 && Robs==1)	  //if no obstacle go forward
			goforward();

		if(Lobs==0 && Robs==1)	  //if obstacle at left turn right
			turnright();

		if(Lobs==1 && Robs==0)	  //if obstacle at right turn left
			turnleft();

		if(Lobs==0 && Robs==0) {	   //if obstacle at both side then walk back 4 steps and take a right turn
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
