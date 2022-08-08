/**
  *******************************************************************************
  * @file    	global.h
  * @author  	Iasaka
  * @version 	1.0.0
  * @date    	2012/07/12
  * @brief		public function head file
  *******************************************************************************
  * @attention	
  *	@addtogroup		
  * @COPYRIGHT 2013 JRnet
  *******************************************************************************
  */
#ifndef _GLOBAL_H_
#define _GLOBAL_H_

/* Includes -------------------------------------------------------------------*/
#include <intrins.h>
#include <STC\STC15.H>
#include "comdef.h"
#include "config.h"

/* Pre-Define ---------------------------------------------------------------*/ 
/* Global Define -------------------------------------------------------------*/
/* Extern Variable -----------------------------------------------------------*/
extern idata union						//union struct
{
	float  f;
	uint16_t u16;
	uint8_t  ch[4];
	uint32_t u32;
	int32_t  _32;
}F32;
extern idata uint16_t gTemper;		//温度，扩大十倍
extern idata uint16_t gHumidity;	//湿度，扩大十倍
extern idata uint8_t gDispBuf[8];	//显示缓存
/* Extern Fuction -------------------------------------------------------------*/	
/**				  
  * @brief  STC-MCU delay 10us@11.0592MHz.
  */
void Delay10us(void);	
/**				  
  * @brief  STC-MCU delay 1ms@11.0592MHz.
  */
void Delay1ms(unsigned char n);	
//extern void SettingWrite(void);
//extern uint16_t CRC16(uint8_t *buf, uint8_t len);

#endif

/******************* (C) COPYRIGHT 2013 Iasaka *****END OF FILE*******************/
