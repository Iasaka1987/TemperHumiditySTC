/**
  *******************************************************************************
  * @file    	stc15l2kIntProcess.c 
  * @author  	Iasaka
  * @version 	1.0.0
  * @date   	2013/07/13 
  * @brief     	stc15l2k60s2 interrupt handle function
  *******************************************************************************
  * @attention	
  *	@addtogroup		
  * @COPYRIGHT 2013 Iasaka
  *******************************************************************************
  */

/* Includes --------------------------------------------------------------------*/
#include "global.h"
#include "stc15func.h"

/* Interrupt --------------------------------------------------------------------*/
/**
  * @brief  This function handle Int0 interrupt.
  * @param  None
  * @retval None
  */
/*void Int0_Rountine(void)	interrupt 0
{										//wake up mcu
	if(TRUE == powerDownFlag)
	{
		Wakeup();
	}
} */
/**
  * @brief  This function handle Timer0 interrupt.
  			About 3ms
  * @param  None
  * @retval None
  */
void Timer0_Rountine(void)	interrupt 1
{
	static uint8_t index = 0;

	//3ms刷新一下显示
	DPY_PORT = gDispBuf[index];
	switch(index)
	{
		case 0:
			HC138_A0 = 0;
			HC138_A1 = 0;
			HC138_A2 = 0;
			break;
		case 1:
			HC138_A0 = 1;
			HC138_A1 = 0;
			HC138_A2 = 0;
			break;
		case 2:
			HC138_A0 = 0;
			HC138_A1 = 1;
			HC138_A2 = 0;
			break;
		case 3:
			HC138_A0 = 1;
			HC138_A1 = 1;
			HC138_A2 = 0;
			break;
		case 4:
			HC138_A0 = 0;
			HC138_A1 = 0;
			HC138_A2 = 1;
			break;
		case 5:
			HC138_A0 = 0;
			HC138_A1 = 1;
			HC138_A2 = 1;
			break;
		case 6:
			HC138_A0 = 1;
			HC138_A1 = 0;
			HC138_A2 = 1;
			break;
		case 7:
			HC138_A0 = 1;
			HC138_A1 = 1;
			HC138_A2 = 1;
			break;
		default:break;	
	}
	index = (index+1)%8;
}
/**
  * @brief  This function handle Int1 interrupt.
  * @param  None
  * @retval None
  */
/*void Int1_Rountine(void)	interrupt 2
{
}*/

/**
  * @brief  This function handle Timer1 interrupt.
  * @param  None
  * @retval None
  */
//void Timer1_Rountine(void)	interrupt 3
//{
//}
/**
  * @brief  This function handle Uart1 interrupt.
  * @param  None
  * @retval None
  */
void UART1_Rountine(void)	interrupt 4
{
	if(RI)								
	{
//		gUartRxData.timeout = 0;						//超时清零
//	    gUartRxData.isReceiving = TRUE;     			//正在接收数据
//	    
//	    if(gUartRxData.index >= UART_RX_BUF_SIZE)
//	    {
//	     	gUartRxData.index = 0;            			//数据超出范围，清空数据 
//	    }
//	    gUartRxData.buf[gUartRxData.index++] = SBUF; 	//存入缓存
		RI = 0;	
	}
}
/**
  * @brief  This function handle adc interrupt.
  * @param  None
  * @retval None
  */
/*void ADC_Rountine(void)	interrupt 5
{

}*/
/**
  * @brief  This function handle low voltage detect interrupt.
  * @param  None
  * @retval None
  */
  /*
void LVD_Rountine(void)	interrupt 6
{
	batteryLowFlag = BATTERY_STATUS_WARNING;
}
*/
/**
  * @brief  This function handle PCA interrupt.
  * @param  None
  * @retval None
  */
/*void PCA_Rountine(void)	interrupt 7
{

}*/

/**
  * @brief  This function handle Uart2 interrupt.
  * @param  None
  * @retval None
  */
/*void UART2_Rountine(void)	interrupt 8
{

}*/

/**
  * @brief  This function handle SPI interrupt.
  * @param  None
  * @retval None
  */
/*void SPI_Rountine(void)	interrupt 9
{

}*/

/**
  * @brief  This function handle Int2 interrupt.
  * @param  None
  * @retval None
  */
/*void Int2_Rountine(void)	interrupt 10
{

}*/

/**
  * @brief  This function handle Int3 interrupt.
  * @param  None
  * @retval None
  */
/*void Int3_Rountine(void)	interrupt 11
{

}*/

/**
  * @brief  This function handle Timer2 interrupt.
  * @param  None
  * @retval None
  */
/*void Timer2_Rountine(void)	interrupt 12
{

}*/

/**
  * @brief  This function handle Int4 interrupt.
  * @param  None
  * @retval None
  */
/*void Int4_Rountine(void)	interrupt 16
{

}*/

/**
  * @brief  This function handle S3 interrupt.
  * @param  None
  * @retval None
  */
/*void S3_Rountine(void)	interrupt 17
{

}*/

/**
  * @brief  This function handle S4 interrupt.
  * @param  None
  * @retval None
  */
/*void S4_Rountine(void)	interrupt 18
{

}*/

/**
  * @brief  This function handle Timer3 interrupt.
  * @param  None
  * @retval None
  */
/*void Timer3_Rountine(void)	interrupt 19
{

}*/

/**
  * @brief  This function handle Timer4 interrupt.
  * @param  None
  * @retval None
  */
/*void Timer4_Rountine(void)	interrupt 20
{

}*/

/****************** (C) COPYRIGHT 2013 Iasaka *****END OF FILE******************/
