#include <reg51f.h>
#include "robosoft.h"

sbit KEY1 = P3 ^ 2;
sbit KEY2 = P3 ^ 3;
sbit KEY3 = P3 ^ 4;

sbit LED1 = P3 ^ 5;
sbit LED2 = P3 ^ 6;
sbit LED3 = P3 ^ 7;

void wait1sec()
{
  unsigned int us, ms;
  for (ms = 0; ms < 1000; ms++) // delay loop
    for (us = 0; us < 300; us++)
      ; // for 1000ms	i.e., 1sec
}

void main(void)
{
  while (1)
  {
    //ON OFF OFF
    LED1 = 0;
    LED2 = 1;
    LED3 = 1;
    wait1sec();

    //OFF ON OFF
    LED1 = 1;
    LED2 = 0;
    LED3 = 1;
    wait1sec();

    //OFF OFF ON
    LED1 = 1;
    LED2 = 1;
    LED3 = 0;
    wait1sec();
  }
}
