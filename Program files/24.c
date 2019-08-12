#include <reg51.h>
#define SEGMENT P2
 
sbit switch1=P1^0;
sbit switch2=P1^1;
sbit digit1=P3^0;
sbit digit2=P3^1;

void delay (int);

int x=0,y,z;
unsigned char ch[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

void delay (int d)
{
	unsigned char i;
	for(;d>0;d--)
	{
		for(i=250;i>0;i--);
		for(i=248;i>0;i--);
	}
}

void main()
{
	switch1=1;
	switch2=1;
	digit1=1;
	digit2=1;

while(1)
{
	if(switch1==0)
	{
		x++;
		delay(200);
	}
	else if(switch2==0)
	{
		x--;
		delay(200);
	}
	y=x/10;
	SEGMENT=ch[y];
	digit1=0;
	delay(10);
	digit1=1;
	
	z=x%10;
	SEGMENT=ch[z];
	digit2=0;
	delay(10);
	digit2=1;
}
}