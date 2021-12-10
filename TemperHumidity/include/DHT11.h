/**
  *******************************************************************************
  * @file    	DHT11.h
  * @author  	Iasaka
  * @version 	1.0.0
  * @date    	2014/03/04
  * @brief		DHT11 drive function
  *******************************************************************************
  * @attention	
  *	@addtogroup		
  * @COPYRIGHT	Iasaka
  *******************************************************************************
  */
#ifndef _DHT11_H_
#define _DHT11_H_

/* Includes -------------------------------------------------------------------*/
#include "global.h"

/* Extern define --------------------------------------------------------------*/
/* Extern variables -----------------------------------------------------------*/
/* Extern Fuction -------------------------------------------------------------*/
/**
  * @brief  This function handles System inital.
  */
//extern void DHT11Init(void);
/**
  * @brief  This function handles System inital.
  */
extern void DHT11Read(uint8_t *dat);

#endif

/****************** (C) COPYRIGHT 2014 Iasaka *****END OF FILE******************/

	 