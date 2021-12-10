/**
  *******************************************************************************
  * @file    	stc15func.c 
  * @author  	WangHao
  * @version 	1.0.0
  * @date   	2013/07/02 
  * @brief     	stc15 handle function
  *******************************************************************************
  * @attention	
  *	@addtogroup		
  * @COPYRIGHT 2013 JRnet
  *******************************************************************************
  */

/* Includes --------------------------------------------------------------------*/
#include <intrins.h>
#include <STC\STC15.H>
#include "comdef.h"
#include "stc15func.h"

/* Private typedef -------------------------------------------------------------*/
/* Private define --------------------------------------------------------------*/
/*Power Define*/
#define LVDF_MASK		0x20	//low voltage flag mask

/*IAP Define*/
#define	IAP_CMD_IDLE	0x00	//IAP idle mode
#define	IAP_CMD_READ	0x01	//IAP read mode
#define IAP_CMD_PROGRAM	0x02	//IAP program mode
#define IAP_CMD_ERASE	0x03	//IAP erase mode

//select system clock
//#define	IAP_ENABLE		0x80	//SYSCLK<30MHz
//#define	IAP_ENABLE		0x81	//SYSCLK<24MHz
//#define	IAP_ENABLE		0x82	//SYSCLK<20MHz
#define	IAP_ENABLE		0x83	//SYSCLK<12MHz
//#define	IAP_ENABLE		0x84	//SYSCLK< 6MHz
//#define	IAP_ENABLE		0x85	//SYSCLK< 3MHz
//#define	IAP_ENABLE		0x86	//SYSCLK< 2MHz
//#define	IAP_ENABLE		0x87	//SYSCLK< 1MHz

#define	ENTER_POWERDOWN_MODE()	PCON=PCON|0x02	//enable powerdown mode
/*MCU-ID*/
#define	ID_ADDR_RAM		0xF1	//RAM ID
#define ID_ADDR_ROM		0xEFF9	//ROM ID 7bytes(only stc15x2k60s2)

/*SPI*/
#define SPIF	0x80
#define WCOL	0x40

//sbit	SPISS =	P1^2;
/* Private const ---------------------------------------------------------------*/
//uint8_t code Mcu_ID[7] = {0x41,0x42,0x43,0x44,0x45,0x46,0x47};	//For check ID,defualt value:ABCDEFG

/* Private variables -----------------------------------------------------------*/
/* Private function prototypes -------------------------------------------------*/
/* Private functions -----------------------------------------------------------*/

/********************************************************************************/
/*            	   Ordinary function                       						*/
/********************************************************************************/
/**
  * @brief  This function handles show Instruction.
  * @param  None
  * @retval None
  *	@author	WangHao
  *	@data	2013/07/04
  */
void WDTEnable(void)
{
	WDT_CONTR = 0x35;	//0-11,1.100b
						//clear WDT flag;-;enable WDT;clean count
						//WDT time = (12*Pre-scale*32768)/Osc-frequency
						//no idle;100,Pre-scale:32(12Mhz:1.0485s)
						//no idle;101,Pre-scale:64(12Mhz:2.0971s)
}
/**
  * @brief  This function Clean WDT count.
  * @param  None
  * @retval None
  *	@author	WangHao
  *	@data	2013/07/04
  */
void WDTClean(void)
{
	WDT_CONTR |= 0x10;	//Set 1,clear WDT counter 
}
/**
  * @brief  Uart send information.
  * @param  None
  * @retval None
  *	@author	WangHao
  *	@data	2013/07/15
  */
void UartSend(uint8_t *dat,uint8_t len)
{
	uint8_t i;
	for(i=0;i<len;i++)
	{
		SBUF = dat[i];
		while(!TI);
		TI = 0;
	}
}
/****************** (C) COPYRIGHT 2013 JRnet *****END OF FILE******************/
