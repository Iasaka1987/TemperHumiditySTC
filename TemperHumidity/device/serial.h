/**
  *******************************************************************************
  * @file    	serial.h
  * @author  	WangHao
  * @version 	1.0.0
  * @date    	2013/07/03
  * @brief		Serial port head file
  *******************************************************************************
  * @attention	
  *	@addtogroup		
  * @COPYRIGHT 2013 JRnet
  *******************************************************************************
  */

#ifndef _SERIAL_H_
#define	_SERIAL_H_

/* Includes -------------------------------------------------------------------*/
#include"public.h"

/* Global define --------------------------------------------------------------*/
#define COM_START			0x3A	//start signal
#define COM_ADDR			0x01	//device id
								//Serial Cmd
#define COM_CMD_TEST  		0x00	//test
#define COM_CMD_RST			0x01	//reset
#define COM_CMD_STANDBY		0x02	//Standby
#define COM_CMD_FORMAT		0x03	//format
#define COM_CMD_W_DAT		0x04	//write EEPROM
#define COM_CMD_READ_ID		0x05	//read ID
								//LCD test Cmd
#define COM_CMD_LCD_ALL		0x06	//all point on
#define COM_CMD_LCD_REVERSE	0x07	//reverse

//Serial communication status
#define COM_STATUS_NO		0x00	//no cmd
#define COM_STATUS_START	0x01	//start
#define COM_STATUS_ADDR		0x02	//address confirm
#define COM_STATUS_CMD		0x03	//read cmd
#define COM_STATUS_RECEIVE	0x04	//receive data from host
#define COM_STATUS_CHECK	0x05	//check sucess

#define COM_TBUFLEN		20		//txd buffer size

#endif

/****************** (C) COPYRIGHT 2013 JRnet *****END OF FILE******************/
