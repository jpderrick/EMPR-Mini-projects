// Serial code
#include <lpc17xx_uart.h>		// Central include files
#include <lpc17xx_pinsel.h>
#include <lpc_types.h>
#include <lpc17xx_gpio.h>
#include "serial.h"
			// Local functions

// Entry point for the program


			
void main(void)
{	
	serial_init();
	int i;
	int j;

	for(j=0; j<1; j++){
		for(i=0; i<100000; i++){
			GPIO_SetDir(1, 0x40000, 1);
			GPIO_SetValue(1, 0x40000);
			GPIO_ClearValue(1, 0x40000);
		} // 0001

		i = 0;

		for(i=0; i<100000; i++){
			GPIO_SetDir(1, 0x100000, 1);
			GPIO_SetValue(1, 0x100000);
			GPIO_ClearValue(1, 0x100000);
		} // 0010

		i = 0;

		for(i=0; i<100000; i++){
			GPIO_SetDir(1, 0x40000, 1);
			GPIO_SetValue(1, 0x40000);
			GPIO_SetDir(1, 0x100000, 1);
			GPIO_SetValue(1, 0x100000);
			GPIO_ClearValue(1, 0x100000);
			GPIO_ClearValue(1, 0x40000);
		} // 0011

		i = 0;

		for(i=0; i<100000; i++){
			GPIO_SetDir(1, 0x200000, 1);
			GPIO_SetValue(1, 0x200000);
			GPIO_ClearValue(1, 0x200000);
		} // 0100

		i = 0;

		for(i=0; i<100000; i++){
			GPIO_SetDir(1, 0x200000, 1);
			GPIO_SetValue(1, 0x200000);
			GPIO_SetDir(1, 0x40000, 1);
			GPIO_SetValue(1, 0x40000);
			GPIO_ClearValue(1, 0x200000);
			GPIO_ClearValue(1, 0x40000);
		} // 0101
	
		i = 0;

		for(i=0; i<100000; i++){
			GPIO_SetDir(1, 0x200000, 1);
			GPIO_SetValue(1, 0x200000);
			GPIO_SetDir(1, 0x100000, 1);
			GPIO_SetValue(1, 0x100000);
			GPIO_ClearValue(1, 0x200000);
			GPIO_ClearValue(1, 0x100000);
		} // 0110

		i = 0;

		for(i=0; i<100000; i++){
			GPIO_SetDir(1, 0x200000, 1);
			GPIO_SetValue(1, 0x200000);
			GPIO_SetDir(1, 0x100000, 1);
			GPIO_SetValue(1, 0x100000);
			GPIO_SetDir(1, 0x40000, 1);
			GPIO_SetValue(1, 0x40000);
			GPIO_ClearValue(1, 0x200000);
			GPIO_ClearValue(1, 0x100000);
			GPIO_ClearValue(1, 0x40000);
		} // 0111

		i = 0;

		for(i=0; i<100000; i++){
			GPIO_SetDir(1, 0x800000, 1);
			GPIO_SetValue(1, 0x800000);
			GPIO_ClearValue(1, 0x800000);
		} // 1000


		i = 0;

		for(i=0; i<100000; i++){
			GPIO_SetDir(1, 0x800000, 1);
			GPIO_SetValue(1, 0x800000);
			GPIO_SetDir(1, 0x40000, 1);
			GPIO_SetValue(1, 0x40000);
			GPIO_ClearValue(1, 0x800000);
			GPIO_ClearValue(1, 0x40000);
		} // 1001

		i = 0;

		for(i=0; i<100000; i++){
			GPIO_SetDir(1, 0x800000, 1);
			GPIO_SetValue(1, 0x800000);
			GPIO_SetDir(1, 0x100000, 1);
			GPIO_SetValue(1, 0x100000);
			GPIO_ClearValue(1, 0x800000);
			GPIO_ClearValue(1, 0x100000);			
		} // 1010

		i = 0;

		for(i=0; i<100000; i++){
			GPIO_SetDir(1, 0x800000, 1);
			GPIO_SetValue(1, 0x800000);
			GPIO_SetDir(1, 0x100000, 1);
			GPIO_SetValue(1, 0x100000);
			GPIO_SetDir(1, 0x40000, 1);
			GPIO_SetValue(1, 0x40000);
			GPIO_ClearValue(1, 0x800000);
			GPIO_ClearValue(1, 0x100000);	
			GPIO_ClearValue(1, 0x40000);		
		} // 1011

		i = 0;

		for(i=0; i<100000; i++){
			GPIO_SetDir(1, 0x800000, 1);
			GPIO_SetValue(1, 0x800000);
			GPIO_SetDir(1, 0x200000, 1);
			GPIO_SetValue(1, 0x200000);
			GPIO_ClearValue(1, 0x800000);
			GPIO_ClearValue(1, 0x200000);
		} // 1100

		i = 0;

		for(i=0; i<100000; i++){
			GPIO_SetDir(1, 0x800000, 1);
			GPIO_SetValue(1, 0x800000);
			GPIO_SetDir(1, 0x200000, 1);
			GPIO_SetValue(1, 0x200000);
			GPIO_SetDir(1, 0x40000, 1);
			GPIO_SetValue(1, 0x40000);
			GPIO_ClearValue(1, 0x800000);
			GPIO_ClearValue(1, 0x200000);
			GPIO_ClearValue(1, 0x40000);
		} // 1101

		i = 0;

		for(i=0; i<100000; i++){
			GPIO_SetDir(1, 0x800000, 1);
			GPIO_SetValue(1, 0x800000);
			GPIO_SetDir(1, 0x200000, 1);
			GPIO_SetValue(1, 0x200000);
			GPIO_SetDir(1, 0x100000, 1);
			GPIO_SetValue(1, 0x100000);
			GPIO_ClearValue(1, 0x800000);
			GPIO_ClearValue(1, 0x200000);
			GPIO_ClearValue(1, 0x100000);
		} // 1110

		i = 0;

		for(i=0; i<100000; i++){
			GPIO_SetDir(1, 0x800000, 1);
			GPIO_SetValue(1, 0x800000);
			GPIO_SetDir(1, 0x200000, 1);
			GPIO_SetValue(1, 0x200000);
			GPIO_SetDir(1, 0x100000, 1);
			GPIO_SetValue(1, 0x100000);
			GPIO_SetDir(1, 0x40000, 1);
			GPIO_SetValue(1, 0x40000);
			GPIO_ClearValue(1, 0x800000);
			GPIO_ClearValue(1, 0x200000);
			GPIO_ClearValue(1, 0x100000);
			GPIO_ClearValue(1, 0x40000);
		} // 1111

	
	}
		
	
	
	  	
	write_usb_serial_blocking("USB test code\n\r",16);
	while(1);
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


