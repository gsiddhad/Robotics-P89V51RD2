#include<reg51f.h>
#include<stdio.h>
#include"robosoft.h"

void Serial_Init(void) {
	SCON = 0x50;
	TMOD = 0x20;
	TH1=0xF5;
	TL1=0xF5;
	TR1=1;
	TI=1;
}

void main(void) {
	Serial_Init();

	while(1)
		printf("\nHello World\n");
}
