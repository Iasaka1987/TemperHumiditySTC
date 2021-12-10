/**
  *******************************************************************************
  * @file    	config.h
  * @author  	Iasaka
  * @version 	1.0.0
  * @date    	2014/06/05
  * @brief		
  *******************************************************************************
  * @attention	
  *	@addtogroup		
  * @COPYRIGHT 2013 Iasaka
  *******************************************************************************
  */
#ifndef _CONFIG_H_
#define _CONFIG_H_

/* Includes -------------------------------------------------------------------*/

/* Pre-Define ---------------------------------------------------------------*/ 
//#define UART_DEBUG_MODE	//Use for uart-debug mode
//plug mode
//#define _AIR_PLUGS_
	
/* Device pin define ----------------------------------------------------------*/
#define DPY_PORT P1	   		//P1

sbit DHT11_DATA = P2^6;

sbit HC138_A0 = P2^0;
sbit HC138_A1 = P2^1;
sbit HC138_A2 = P2^2;
sbit HC138_EN = P2^3;

#endif

/******************* (C) COPYRIGHT 2013 Iasaka *****END OF FILE*******************/
