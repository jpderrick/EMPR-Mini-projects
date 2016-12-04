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
uint8_t setHigh[] = {0x7F};
char output[30];
uint8_t buffer[1] = {};
LPC_I2C_TypeDef *I2C = LPC_I2C1;

void I2C_Our_Setup(void){

	PINSEL_CFG_Type PinCfg;
	PinCfg.Funcnum = 3;
	PinCfg.OpenDrain = 0;
	PinCfg.Pinmode = 0;
	PinCfg.Portnum = 0;
	PinCfg.Pinnum = 0;
	PINSEL_ConfigPin(&PinCfg);
	PinCfg.Pinnum = 1;
	PINSEL_ConfigPin(&PinCfg);

	I2C_Init(I2C,100000);
	I2C_Cmd(I2C,ENABLE);


}
void enableColumn(int column){
	
	switch(column){
		case 1:
			setHigh[0] = 0x7F;
			break;
		case 2:
			setHigh[0] = 0xBF;
			break;
		case 3:
			setHigh[0] = 0xDF;
			break;
		case 4:
			setHigh[0] = 0xEF;
			break;
	}
	TransferConfig.tx_length = 1;
	TransferConfig.sl_addr7bit = 33;
	TransferConfig.tx_data = setHigh;
	I2C_MasterTransferData(I2C, &TransferConfig, I2C_TRANSFER_POLLING);
}
int keypadUsed(void){

	for(int i = 1;i<=4;i++){

		enableColumn(i);
		//Poll the keypad
		TransferConfig.rx_length = 1;
		TransferConfig.rx_data = buffer;
		I2C_MasterTransferData(I2C, &TransferConfig, I2C_TRANSFER_POLLING);
		

		if(buffer[0] != setHigh[0]){
			return 1;
		}

	}

}
void main(void){

	serial_init();
	I2C_Our_Setup();

	//Do Stage 2
	while(keypadUsed() == 0){
		//STAGE 2 CODE HERE
		write_usb_serial_blocking("Doing Stage 2",12);
	}
	//Some sort of delay, so that we don't register a hold as another key press
	for(int j = 0;j<=1000;j++){
		write_usb_serial_blocking("Doing Stage 0",12)
	}
	//Do Stage 3 
	while(keypadUsed() == 0){
		write_usb_serial_blocking("Doing Stage 3",12)
	}
	//Do stage 4
	write_usb_serial_blocking("Doing Stage 4",12)

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

	CHAR CONVERT_CHARACTER(UINT8_T BUFFER[]){
	CHAR RETVAL = {};
	
}
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