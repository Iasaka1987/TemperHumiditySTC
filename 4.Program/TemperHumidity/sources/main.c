/**
  *******************************************************************************
  * @file    main.c 
  * @author  Iasaka
  * @version 
  * @date	 2012/07/24    
  * @brief   
  *******************************************************************************
  * @attention	
  *	@addtogroup		
  * @COPYRIGHT 2013 Iasaka
  *******************************************************************************
  */

/* Includes -------------------------------------------------------------------*/
#include "global.h"
#include "stc15func.h"
#include "DHT11.h"

/* Private macro ---------------------------------------------------------------*/
#define DPY_CODE_NONE			0x00		//什么都不显示
#define DPY_CODE_NEG			0x40		//负号
#define DPY_CODE_POINT_MASK 	0x80		//显示小数点
code uint8_t DpyCode[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
/* Private variables -----------------------------------------------------------*/
/* Private code variables-------------------------------------------------------*/
/* Private function prototypes -------------------------------------------------*/
/* Private functions -----------------------------------------------------------*/

/********************************************************************************/
/*            	   Ordinary function                       						*/
/********************************************************************************/
/**
  * @brief  This function handles .
  * @param  None
  * @retval None
  */
static void SystemInit(void)
{
	/*MCU Init*/
	EA = 0;
	
	IE		=	0x12;		//Interrupt reg:0001,0010
								//EA =0;ELVD=0;EADC=0;ES=1;
								//ET1=0;EX1=0 ;ET0=1 ;EX0=0
	IE2		=	0x00;	   	//Interrupt reg1:-000,0000
								//-;ET4=0;ET3=0;ES4=0;								
								//ES3=0;ET2=0;ESPI=0;ES2=0
	
	//P0没有
	P1M1	= 0x00;	  	//P1推挽输出
	P1M0	= 0xFF;
	P2M1	= 0x00;		//P2默认准双向口
	P2M0	= 0x00;
	//P3M1	= 0x00;		//P3默认准双向口
	//P3M0	= 0x00;
	//P4没有
	//P5M1	= 0x00; 	//P5默认准双向口  	
	//P5M0	= 0x00;

	/*can check POF bit,find which reset mode*/
	PCON	=	0x00;		//0000,0000
									//SMOD=0;SMOD0=0;LVDF=0;POF
									//GF1=0;GF00;PD=0;IDL=0;
	
	TMOD 	= 	0x00;		//Timer0

	TH0		= 	0x7E;		//Timer0
	TL0		=	0x66;				//about 3ms		
	TF0		=	0;					//clean flag
	
	//串口1
	SCON	=	0x50;		//Uart1	reg:0101,0000
									//SM0=0;SM1=1;SM2=0;REN=1;
									//TB8=0;RB8=0;TI=0;RI=0	
	AUXR	=	0x85;		//1001,0101
									//T0x12=1;T1x12=0;UART_MOX6=0;T2R=1;
									//T2_C/T=0;T2X12=1;EXTRAM=0;S1ST2=1;
									//use timer2 for baudrate
	T2H		=	0xFF;		//baudrate: 9600,FEE0;19200,FF70;38400,FFB8;57600,FFD0;115200,FFE8;
	T2L		=	0xE8;		//baudrate=sysclk/(65536-t2h,t2l)/4

	HC138_EN = 1;
	
	WDTEnable();

	AUXR |= 0x10;			//Start timer2 
	TR0	=	1;				//Start timer0
	EA 	= 1;
}
/**
  * @brief  This function handles main function.
  * @param  None
  * @retval None
  */
void main(void)
{
	idata uint8_t temp;
	idata uint8_t buf[5];
	idata uint8_t uartBuf[10];
	uartBuf[3] = '.'; 		//固定位置小数点
	uartBuf[8] = '.';

	SystemInit();
	
//	gDispBuf[0] = DpyCode[1];
//	gDispBuf[1] = DpyCode[2];
//	gDispBuf[2] = DpyCode[3];
//	gDispBuf[3] = DpyCode[4];
//	gDispBuf[4] = DpyCode[5];
//	gDispBuf[5] = DpyCode[6];
//	gDispBuf[6] = DpyCode[7];
//	gDispBuf[7] = DpyCode[8];

//	DPY_PORT = gDispBuf[7];
//	HC138_A0 = 1;
//	HC138_A1 = 0;
//	HC138_A2 = 0;

	while(TRUE)
	{
		WDTClean();			//Clear watch dog gate counter
		Delay1ms(200);		//延时一段时间再读，注意不要超过等于255
		Delay1ms(200);
		Delay1ms(200);
		Delay1ms(200);
		Delay1ms(200);

		DHT11Read(buf);		//数据读出

		//数据计算，为了方便显示，数值扩大十倍
		gTemper = buf[2]*10 + buf[3];	
		gHumidity = buf[0] * 10;		//湿度不显示小数
		/*数码管显示*/
		if(buf[4] == 'T')
		{
			/*温度显示*/
			if(gTemper < 0)
			{
			 	gDispBuf[0] = DPY_CODE_NEG;
				uartBuf[0] = '-';
			}
			else
			{
				gDispBuf[0] = DPY_CODE_NONE;
				uartBuf[0] = ' ';
			}
			temp=gTemper/100%10; //十位
			if(temp == 0)
			{
				if(gDispBuf[0] == DPY_CODE_NONE)//如果百位不显示，十位也不显示0
				{
					gDispBuf[1] = DPY_CODE_NONE;
					uartBuf[1] = ' ';
				}
				else
				{
					gDispBuf[1] = DpyCode[0];
					uartBuf[1] = '0';
				}
			}
			else
			{
				 gDispBuf[1] = DpyCode[temp];
				 uartBuf[1] = '0' + temp;
			}
			gDispBuf[2] = DpyCode[gTemper/10%10] | DPY_CODE_POINT_MASK;//温度个位，需要显示小数点
			uartBuf[2] = '0' + gTemper/10%10;
			gDispBuf[3] = DpyCode[gTemper % 10];						//温度小数点一位
			uartBuf[4] = '0' + gTemper % 10;

			/*湿度显示*/
			temp = gHumidity/1000;		//百位
			if(temp == 0)
			{
				gDispBuf[4] = DPY_CODE_NONE;
				uartBuf[5] = ' ';
			}
			else
			{
			  	gDispBuf[4] = DpyCode[temp];
				uartBuf[5] = '0' + temp;	
			}

			temp = gHumidity/100%10;	//十位
			if(temp == 0)
			{
				if(gDispBuf[4] == DPY_CODE_NONE)//如果百位不显示，十位也不显示0
				{
					gDispBuf[5] = DPY_CODE_NONE;
					uartBuf[6] = ' ';
				}
				else
				{
					gDispBuf[5] = DpyCode[0];
					uartBuf[6] = '0';
				}
			}
			else
			{
				 gDispBuf[5] = DpyCode[temp];
				 uartBuf[5] = '0' + temp;
			}
			gDispBuf[6] = DpyCode[gHumidity/10%10] | DPY_CODE_POINT_MASK;	//湿度个位，不需要分析前面是否都为0，并且需要显示小数点
			uartBuf[7] = '0' + gHumidity/10%10;
			gDispBuf[7] = DpyCode[gHumidity % 10];					//湿度小数点一位
			uartBuf[9] = '0' + gHumidity % 10;
		}
		else
		{
			//数据读出错误
			gDispBuf[0] = DPY_CODE_NEG;
			gDispBuf[1] = DPY_CODE_NEG;
			gDispBuf[2] = DPY_CODE_NEG;
			gDispBuf[3] = DPY_CODE_NEG;
			gDispBuf[4] = DPY_CODE_NEG;
			gDispBuf[5] = DPY_CODE_NEG;
			gDispBuf[6] = DPY_CODE_NEG;
			gDispBuf[7] = DPY_CODE_NEG;
		}
		
		/*串口发送*/
		UartSend("Temperature=",12);
		UartSend(uartBuf , 5);
		UartSend(";Humidity=",10);
		UartSend(&uartBuf[5] , 5);
		UartSend("\r\n" , 2); 			//回车换行
	}
}
/******************* (C) COPYRIGHT 2013 Iasaka *****END OF FILE*******************/
