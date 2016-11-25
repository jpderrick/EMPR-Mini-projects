#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <lpc17xx_uart.h>
#include <lpc17xx_pinsel.h>
#include <lpc_types.h>
#include <lpc17xx_gpio.h>
#include <lpc17xx_i2c.h>
#include <lpc17xx_dac.h>
#include "serial.h"


void main(void){
	
	serial_init();	
	
	   
	PINSEL_CFG_Type PinCfg;
	PinCfg.Funcnum = 2;
	PinCfg.OpenDrain = 0;
	PinCfg.Pinmode = 0;
	PinCfg.Portnum = 0;

	//Configure P0.26
	PinCfg.Pinnum = 26;
	PINSEL_ConfigPin(&PinCfg);

	LPC_DAC_TypeDef *DAC = LPC_DAC;	

	DAC_Init(DAC);
	int i = 500;
	int up = 1;	
	//Sine wave generating;
	while(1){
		if(up == 1){
			if(i<1000){
				if((i>800)||(i<200)){
					if((i>900)||(i<100)){
						i += 1;
					}else{
						i += 3;
					}					
				}else{
					i += 10;
				}
			}
			else {
				up = 0;
			}
		}else {
			if(i>0){
				if((i<200)||(i>800)){
					if((i<100)||(i>900)){
						i -= 1;
					}else{
						i -= 3;
					}
				}else{
					i -= 10;
				}
				
			}else {
				up = 1;
			}
		}
		
		DAC_UpdateValue(DAC, i); 	
	}
		
	
}


// Read options
int read_usb_serial_none_blocking(char *buf,int length)
{
	return(UART_Receive((LPC_UART_TypeDef *)LPC_UART0, (uint8_t *)buf, length, NONE_BLOCKING));
}

// Write options
int write_usb_serial_blocking(char *buf,int length)
{
	return(UART_Send((LPC_UART_TypeDef *)LPC_UART0,(uint8_t *)buf,length, BLOCKING));
}
// init code for the USB serial line
void serial_init(void)
{
	UART_CFG_Type UARTConfigStruct;			// UART Configuration structure variable
	UART_FIFO_CFG_Type UARTFIFOConfigStruct;	// UART FIFO configuration Struct variable
	PINSEL_CFG_Type PinCfg;				// Pin configuration for UART
	/*
	 * Initialize UART pin connect
	 */
	PinCfg.Funcnum = 1;
	PinCfg.OpenDrain = 0;
	PinCfg.Pinmode = 0;
	// USB serial first
	PinCfg.Portnum = 0;
	PinCfg.Pinnum = 2;
	PINSEL_ConfigPin(&PinCfg);
	PinCfg.Pinnum = 3;
	PINSEL_ConfigPin(&PinCfg);
		
	/* Initialize UART Configuration parameter structure to default state:
	 * - Baudrate = 9600bps
	 * - 8 data bit
	 * - 1 Stop bit
	 * - None parity
	 */
	UART_ConfigStructInit(&UARTConfigStruct);
	/* Initialize FIFOConfigStruct to default state:
	 * - FIFO_DMAMode = DISABLE
	 * - FIFO_Level = UART_FIFO_TRGLEV0
	 * - FIFO_ResetRxBuf = ENABLE
	 * - FIFO_ResetTxBuf = ENABLE
	 * - FIFO_State = ENABLE
	 */
	UART_FIFOConfigStructInit(&UARTFIFOConfigStruct);
	// Built the basic structures, lets start the devices/
	// USB serial
	UART_Init((LPC_UART_TypeDef *)LPC_UART0, &UARTConfigStruct);		// Initialize UART0 peripheral with given to corresponding parameter
	UART_FIFOConfig((LPC_UART_TypeDef *)LPC_UART0, &UARTFIFOConfigStruct);	// Initialize FIFO for UART0 peripheral
	UART_TxCmd((LPC_UART_TypeDef *)LPC_UART0, ENABLE);			// Enable UART Transmit
	
}
