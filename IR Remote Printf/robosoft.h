/*************************************************************/
/*
Header file Robosofyt Systems Hexapod
//Controller used 	: P89V51RD2
//Crystal Frequency	: 20.000 Mhz X 2

NOTE : Please check wheter file robosoft.lib is pested into your current project directory 

//for more details visit us at http://www.robosoftsystems.co.in/blog/
*/

/*************************************************************/
unsigned char IR_REMOTE(void);
//IR_REMOTE function returns values from 0 to 16 
//if 0 then no key is pressed
//if any other key
//then those keys are defined at end of this file

void Remote_Init(void);
//This function has to be called at begining of program if you want to use IR_REMOTE

void Servo_Init(void);
//This function has to be called at begining of program so that servo motor can work

void Servo_Control(unsigned char Servo_No,unsigned char Angle);
//this function drives servo motors 
//user has to pass servo number and its angle


//here is a defination of each key of remote

#define NUM_1 1
#define NUM_2 2
#define NUM_3 3
#define NUM_4 4
#define NUM_5 5
#define NUM_6 6
#define NUM_7 7
#define NUM_8 8
#define NUM_9 9
#define NUM_0 10

#define NUM_10 11;
#define FWD 12
#define BWD 13
#define RIGHT 14
#define LEFT 15
#define STOP 16
#define PW 17
#define MD 18

