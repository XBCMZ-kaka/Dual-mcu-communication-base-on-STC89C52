
/*******Ω” ’ œ‘ æ*********/
#include <intrins.h>

#include "reg51.h"

#define uchar unsigned char
#define uint unsigned int
	
sbit P20=P2^0;
sbit P21=P2^1;

unsigned char codeswitch;
uchar code dis_7[] = {
0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 
0x7f, 0x6f, 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71, 0x00};
// 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A, B, C, D, E, F, off 



void delay_ms(unsigned int a)			
{
	unsigned int b;
	for(;a>0;a--)
		for(b=100;b>0;b--);
}


void Uartinit(void)		
{
	PCON &= 0x7F;		//??????
	SCON = 0x50;		//8???,?????
	TMOD &= 0x0F;		//?????1???
	TMOD |= 0x20;		//?????1?8???????
	TL1 = 0xFD;		//??????
	TH1 = 0xFD;		//????????
	ET1 = 0;		//?????1??
	TR1 = 1;		//?????1
	
	ES   = 1;        //?????                  
	EA   = 1;        // ???? 
	

}

void SendData(unsigned char a)
{
	  SBUF =a;
    while(!TI);			
		TI = 0;
	
}


void main()
{
	unsigned char codeswitch;
	unsigned char high=0;
	unsigned char low=0;
 	SCON = 0x50;
	TMOD = 0x20;
	TH1 = 0xfd;
	TL1 = 0xfd;
	PCON = 0x00;
	RI = 0;
	TR1 = 1;
		
	while(1)
	{	
	 	if(RI)
		{
		 	RI = 0;
			codeswitch=SBUF;
			high=((codeswitch&0xf0)>>4);
			low=codeswitch&0x0f;	
			P0=dis_7[high];
			P20=0;
		  P21=1;
		delay_ms(100);
			P0=dis_7[low];
			P20=1;
		  P21=0;
		delay_ms(1);			
		}
	}
		
}






		
