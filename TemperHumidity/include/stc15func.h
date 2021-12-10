/**
  *******************************************************************************
  * @file    	stc15func.h
  * @author  	Iasaka
  * @version 	1.0.0
  * @date 		2013/07/03   
  * @brief   	stc15 function head file
  *******************************************************************************
  * @attention	
  *	@addtogroup		
  * @COPYRIGHT 2013 Iasaka
  *******************************************************************************
  */

#ifndef	_STC15_FUNC_H_
#define	_STC15_FUNC_H_

/* Includes -------------------------------------------------------------------*/

/* Extern Define -------------------------------------------------------------*/															
/* Extern Fuction -------------------------------------------------------------*/
/**
  * @brief  This function handles show Instruction.
  */
extern void WDTEnable(void);
/**
  * @brief  This function handles show Instruction.
  */
extern void WDTClean(void);
/**
  * @brief  Uart send information.
  */
extern void UartSend(uint8_t *dat,uint8_t len);


#endif

/****************** (C) COPYRIGHT 2013 Iasaka *****END OF FILE******************/
