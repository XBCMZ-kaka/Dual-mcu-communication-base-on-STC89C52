
/*******∂¡»° ∑¢ÀÕ*********/
#include <intrins.h>

#include "reg51.h"

#define uchar unsigned char
#define uint unsigned int
uchar Rbuf = 0;
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
void ReceiveData(unsigned char a)
{
	a=SBUF;
	while(!TI);			
	TI = 0;
}


void main()
{
	unsigned char codeswitch;
	SCON = 0x40;
	TMOD = 0x20;
	PCON = 0x00;
	TH1 = 0xfd;
	TL1 = 0xfd;
	TI = 0;
	TR1 = 1;
		
	while(1)
	{	
		
	delay_ms(500);
	codeswitch=P2;	
	SendData(codeswitch);
		
	}

}
