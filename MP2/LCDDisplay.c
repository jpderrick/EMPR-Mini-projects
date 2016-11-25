#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <lpc17xx_uart.h>
#include <lpc17xx_pinsel.h>
#include <lpc_types.h>
#include <lpc17xx_gpio.h>
#include <lpc17xx_i2c.h>
#include "serial.h"

I2C_M_SETUP_Type TransferConfig;
uint8_t initScreen[12] = {0x00,0x34,0x0c,0x06,0x35,0x04,0x10,0x42,0x9f,0x34,0x02,0x20};


uint8_t writeBlank[33] = {0x40, 'h', 'e', 'l', 'l', 'o', 0xA0, 'w', 'o', 'r', 'l', 'd', 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0,};




void main(void){
	
	serial_init();
	    //DONE Init the ports to act as I2C Settors
	    //DONE Set the Clock Rate
	    //Character buffer with one byte
	    //Send this through each addres (2^7) addresses possible

	    //PIN Configurations for I2C mode
	PINSEL_CFG_Type PinCfg;
	PinCfg.Funcnum = 3;
	PinCfg.OpenDrain = 0;
	PinCfg.Pinmode = 0;
	PinCfg.Portnum = 0;
	PinCfg.Pinnum = 0;

	    //Configure P0.0
	PINSEL_ConfigPin(&PinCfg);

	    //Configure P0.1
	PinCfg.Pinnum = 1;
	PINSEL_ConfigPin(&PinCfg);

	LPC_I2C_TypeDef *I2C = LPC_I2C1;
	I2C_Init(I2C, 100000);
	I2C_Cmd(I2C,ENABLE);

	TransferConfig.tx_length = 12;
	TransferConfig.sl_addr7bit = 59;
	TransferConfig.tx_data = initScreen;

	if(I2C_MasterTransferData(I2C, &TransferConfig, I2C_TRANSFER_POLLING) == SUCCESS){
		
			
			TransferConfig.tx_length = 33;
			TransferConfig.tx_data = writeBlank;
			I2C_MasterTransferData(I2C, &TransferConfig, I2C_TRANSFER_POLLING);
			TransferConfig.tx_length = 2;
			TransferConfig.tx_data = screenOn;
			I2C_MasterTransferData(I2C, &TransferConfig, I2C_TRANSFER_POLLING);
		
		
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
