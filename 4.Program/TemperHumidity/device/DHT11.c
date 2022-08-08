/**
  *******************************************************************************
  * @file    	DHT11.c 
  * @author  	Iasaka
  * @version 	1.0.0
  * @date	 	2014.03.04 
  * @brief   	DHT11 drive function
  *******************************************************************************
  * @attention
  *	@addtogroup		
  * @COPYRIGHT	Iasaka
  *******************************************************************************
  */

/* Includes -------------------------------------------------------------------*/
#include "DHT11.h"
/* Private typedef -------------------------------------------------------------*/
/* Private define --------------------------------------------------------------*/
/* Private macro ---------------------------------------------------------------*/
/* Private variables -----------------------------------------------------------*/
/* Private const ---------------------------------------------------------------*/
/* Private function prototypes -------------------------------------------------*/
/* Private functions -----------------------------------------------------------*/

/********************************************************************************/
/*            	   Ordinary function                       						*/
/********************************************************************************/
void Delay8us()		//@11.0592MHz
{
	unsigned char i;

	_nop_();
	_nop_();
	i = 19;
	while (--i);
}

void Delay30us()        //@11.0592MHz
{
    unsigned char i;

    _nop_();
    _nop_();
    i = 80;
    while (--i);
}
void Delay35us()		//@11.0592MHz
{
	unsigned char i;

	_nop_();
	i = 94;
	while (--i);
}
void Delay18ms()		//@11.0592MHz
{
	unsigned char i, j, k;

	i = 1;
	j = 194;
	k = 160;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}
/**
  * @brief  Read one byte from DHT11.
  * @param  None
  * @retval None
  */  
static uint8_t ReadByte(void)
{
	uint8_t i;
    uint8_t temp = 0;
    uint8_t dat;
    for(i = 0;i < 8;i++)
    {
        while(!DHT11_DATA);
        Delay30us();
        temp = 0;
        if(DHT11_DATA == 1)
        {
            temp = 1;
        }
        while(DHT11_DATA);
        dat<<=1;
        dat = dat|temp;
    }
    return dat;
}
/**
  * @brief  Inital DHT11.
  * @param  None
  * @retval None
  */
//void DHT11Init(void)
//{
//
//}
/**
  * @brief  Read temp and rh from DHT11.
  * @param  dat,the buf of data
  *			The length of buf equal 5:RH_high,RH_low,T_high,T_low,Check
  * @retval None
  */
void DHT11Read(uint8_t *dat)
{  
	dat[4] = 'F';

	EA = 0;
    DHT11_DATA = 1;
    Delay8us();
    DHT11_DATA = 0;
    Delay18ms();
    DHT11_DATA = 1;
  	Delay35us();
    if(!DHT11_DATA)
    {
        while(!DHT11_DATA);	//没有添加超时处理
        while(DHT11_DATA); 
        dat[0] = ReadByte();
        dat[1] = ReadByte();
        dat[2] = ReadByte();
        dat[3] = ReadByte();
        dat[4] = ReadByte();
		if(dat[4] == (dat[0] + dat[1] + dat[2] + dat[3]))
		{
			dat[4] = 'T';
		}
		else
		{
			dat[4] = 'F';
		}
    }
	EA = 1;
}

/****************** (C) COPYRIGHT 2014 Iasaka *****END OF FILE******************/
