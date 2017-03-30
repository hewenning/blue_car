#include<reg52.h>
#define uint unsigned int
#define uchar unsigned char
sbit IN1=P2^2;
sbit IN2=P2^4;
sbit IN3=P2^5;
sbit IN4=P2^6;
uint bl;
void delay(uint t)										                   
{
	uint i,j;
	for(i=t;i>0;i--)
		for(j=110;j>0;j--);
}
void qian()
{
	IN1=1;
	IN2=0;
	IN3=0;
	IN4=1;
}
void hou()
{
	IN1=0;
	IN2=1;
	IN3=1;
	IN4=0;
} 
void zuo()
{
	IN1=1;
	IN2=0;
	IN3=1;
	IN4=0;
} 
void you()
{
	IN1=0;
	IN2=1;
	IN3=0;
	IN4=1;
}
void youqian()
{
	IN1=0;
	IN2=0;
	IN3=0;
	IN4=1;
}
void youhou()
{
	IN1=0;
	IN2=0;
	IN3=1;
	IN4=0;
}
void zuoqian()
{
	IN1=1;
	IN2=0;
	IN3=0;
	IN4=0;
}
void zuohou()
{
	IN1=0;
	IN2=1;
	IN3=0;
	IN4=0;
}
void ting()
{
	IN1=0;
	IN2=0;
	IN3=0;
	IN4=0;
}




void bluetooth_init()
{
  TMOD=0x20;
	TH1=0xfd; 
	TL1=0xfd;
	TR1=1;	  
	REN=1;
	SM0=0;
	SM1=1; 
	EA=1;	 
	ES=1;	 
}  
void main()
{
	while(1)
	{
		
		bluetooth_init();

	}	
}
void che() interrupt 4
{		
	RI=0;
	bl=SBUF;
	switch(bl)
	{
	case '2':qian();break;
	case '8':hou();break; 	
	case '4':zuo();break; 
	case '6':you();break;
	case '1':zuoqian();break; 
	case '3':youqian();break;
	case '7':zuohou();break; 
	case '9':youhou();break; 
	case '5':ting();break;
	
	}
}
