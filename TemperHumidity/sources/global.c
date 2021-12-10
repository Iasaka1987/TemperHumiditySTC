/**
  *******************************************************************************
  * @file    	public.c
  * @author  	Iasaka
  * @version 	1.0.0
  * @date    	2012/07/13
  * @brief		public function lib
  *******************************************************************************
  * @attention	
  *	@addtogroup		
  * @COPYRIGHT 2013 JRnet
  *******************************************************************************
  */
/* Includes -------------------------------------------------------------------*/
#include "global.h"
#include "stc15func.h"

/* Private const --------------------------------------------------------------*/
/* Extern Variable -------------------------------------------------------------*/
idata union						//union struct
{
	float  f;
	uint16_t u16;
	uint8_t  ch[4];
	uint32_t u32;
	int32_t  _32;
}F32;
idata uint16_t gTemper;		//温度，扩大十倍
idata uint16_t gHumidity;	//湿度，扩大十倍
idata uint8_t gDispBuf[8];	//显示缓存
/********************************************************************************/
/*            	   Ordinary function                       						*/
/********************************************************************************/
/**
  * @brief  STC-MCU delay 10us@11.0592MHz.
  * @param  None
  * @retval None
  */
void Delay10us(void)
{
	unsigned char i;

	_nop_();
	i = 25;
	while (--i);
}
/**
  * @brief  STC-MCU delay 1ms@11.0592MHz.
  * @param  None
  * @retval None
  */
void Delay1ms(unsigned char n)		
{
	unsigned char i, j;

	while(n--)
	{
		i = 11;
		j = 190;
		do
		{
			while (--j);
		} while (--i);
	}
}
/******************* (C) COPYRIGHT 2013 Iasaka *****END OF FILE*******************/
