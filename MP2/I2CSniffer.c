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
uint8_t buffer[] = {0x00, 0x01};
char output[30];

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

	TransferConfig.tx_data = buffer;
	TransferConfig.tx_length = 1;

	    //for i = 1 to 127
	    //Send a character to address i on the I2C
	    //if TRUE
	    //device counter++
	    //end for

	int numberOfDevices = 0;
	int i = 0;

	for(i=0; i<128; i++)
        {
		
		TransferConfig.sl_addr7bit = i;
		
		if ( I2C_MasterTransferData(I2C, &TransferConfig, I2C_TRANSFER_POLLING) == SUCCESS) 
                {
			
			sprintf(output,"Found a device at Address %d \n\r", i);
			write_usb_serial_blocking(output,strlen(output));
			numberOfDevices++;	
			
		}

	}

	
	    //print on UART the number of devices

	
	sprintf(output,"Number of devices on I2C is %d \n\r", numberOfDevices);
	write_usb_serial_blocking(output, strlen(output));
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
