// Serial code
#include <lpc17xx_uart.h>		// Central include files
#include <lpc17xx_pinsel.h>
#include <lpc_types.h>
#include <lpc17xx_gpio.h>
#include <lpc17xx_systick.h>
#include <LPC17xx.h>
#include "serial.h"
			// Local functions

// Entry point for the program


int msTicks = 0;
int led = 0;



void SysTick_Handler(void){
	msTicks++;
	int i;
	switch(led){
		case 0:
			if(msTicks < 10 ){
				GPIO_SetDir(1, 0x40000, 1);
				GPIO_SetValue(1, 0x40000);
			}else{
				GPIO_ClearValue(1,0x40000);
				led = 1;
				
			}
			break; //0001
		case 1:
			
			if((msTicks < 20) && (msTicks > 10)){
				GPIO_SetDir(1, 0x100000, 1);
				GPIO_SetValue(1, 0x100000);
			}else{
				GPIO_ClearValue(1,0x100000);
				led = 2;
				
			}
			break; //0010
		case 2:
			if((msTicks < 30) && (msTicks > 20)){
				GPIO_SetDir(1, 0x40000, 1);
				GPIO_SetValue(1, 0x40000);
				GPIO_SetDir(1, 0x100000, 1);
				GPIO_SetValue(1, 0x100000);
			}else{
				GPIO_ClearValue(1, 0x100000);
				GPIO_ClearValue(1, 0x40000);
				led = 3;
				
			}
			break; //0011
		case 3:
			if((msTicks < 40) && (msTicks > 30)){
				GPIO_SetDir(1, 0x200000, 1);
				GPIO_SetValue(1, 0x200000);
			}else{
				GPIO_ClearValue(1, 0x200000);
				led = 4;
				
			}
			break; //0100
		case 4:
			if((msTicks < 50) && (msTicks > 40)){
				GPIO_SetDir(1, 0x200000, 1);
				GPIO_SetValue(1, 0x200000);
				GPIO_SetDir(1, 0x40000, 1);
				GPIO_SetValue(1, 0x40000);
			}else{
				GPIO_ClearValue(1, 0x200000);
				GPIO_ClearValue(1, 0x40000);
				led = 5;
				
			}
			break; //0101
		case 5:
			if((msTicks < 60) && (msTicks > 50)){
				GPIO_SetDir(1, 0x200000, 1);
				GPIO_SetValue(1, 0x200000);
				GPIO_SetDir(1, 0x100000, 1);
				GPIO_SetValue(1, 0x100000);
			}else{
				GPIO_ClearValue(1, 0x200000);
				GPIO_ClearValue(1, 0x100000);
				led = 6;
				
			}
			break; //0110
		case 6:
			if((msTicks < 70) && (msTicks > 60)){
				GPIO_SetDir(1, 0x200000, 1);
				GPIO_SetValue(1, 0x200000);
				GPIO_SetDir(1, 0x100000, 1);
				GPIO_SetValue(1, 0x100000);
				GPIO_SetDir(1, 0x40000, 1);
				GPIO_SetValue(1, 0x40000);
			}else{
				GPIO_ClearValue(1, 0x200000);
				GPIO_ClearValue(1, 0x100000);
				GPIO_ClearValue(1, 0x40000);
				led = 7;
				
			}
			break; //0111
		case 7:
			if((msTicks < 80) && (msTicks > 70)){
				GPIO_SetDir(1, 0x800000, 1);
				GPIO_SetValue(1, 0x800000);
			}else{
				GPIO_ClearValue(1,0x800000);
				led = 8;
				
			}
			break; //1000
		case 8:
			if((msTicks < 90) && (msTicks > 80)){
				GPIO_SetDir(1, 0x800000, 1);
				GPIO_SetValue(1, 0x800000);
				GPIO_SetDir(1, 0x40000, 1);
				GPIO_SetValue(1, 0x40000);
			}else{
				GPIO_ClearValue(1, 0x800000);
				GPIO_ClearValue(1, 0x40000);
				led = 9;
				
			}
			break; //1001
		case 9:
			if((msTicks < 100) && (msTicks > 90)){
				GPIO_SetDir(1, 0x800000, 1);
				GPIO_SetValue(1, 0x800000);
				GPIO_SetDir(1, 0x100000, 1);
				GPIO_SetValue(1, 0x100000);
			}else{
				GPIO_ClearValue(1, 0x800000);
				GPIO_ClearValue(1, 0x100000);	
				led = 10;
				
			}
			break; //1010
		case 10:
			if((msTicks < 110) && (msTicks > 100)){
				GPIO_SetDir(1, 0x800000, 1);
				GPIO_SetValue(1, 0x800000);
				GPIO_SetDir(1, 0x100000, 1);
				GPIO_SetValue(1, 0x100000);
				GPIO_SetDir(1, 0x40000, 1);
				GPIO_SetValue(1, 0x40000);
			}else{
				GPIO_ClearValue(1, 0x800000);
				GPIO_ClearValue(1, 0x100000);	
				GPIO_ClearValue(1, 0x40000);
				led = 11;
				
			}
			break; //1011
		case 11:
			if((msTicks < 120) && (msTicks > 110)){
				GPIO_SetDir(1, 0x800000, 1);
				GPIO_SetValue(1, 0x800000);
				GPIO_SetDir(1, 0x200000, 1);
				GPIO_SetValue(1, 0x200000);
			}else{
				GPIO_ClearValue(1, 0x800000);
				GPIO_ClearValue(1, 0x200000);
				led = 12;
				
			}
			break; //1100
		case 12:
			if((msTicks < 130) && (msTicks > 120)){
				GPIO_SetDir(1, 0x800000, 1);
				GPIO_SetValue(1, 0x800000);
				GPIO_SetDir(1, 0x200000, 1);
				GPIO_SetValue(1, 0x200000);
				GPIO_SetDir(1, 0x40000, 1);
				GPIO_SetValue(1, 0x40000);
			}else{
				GPIO_ClearValue(1, 0x800000);
				GPIO_ClearValue(1, 0x200000);
				GPIO_ClearValue(1, 0x40000);
				led = 13;
				
			}
			break; //1101
		case 13:
			if((msTicks < 140) && (msTicks > 130)){
				GPIO_SetDir(1, 0x800000, 1);
				GPIO_SetValue(1, 0x800000);
				GPIO_SetDir(1, 0x200000, 1);
				GPIO_SetValue(1, 0x200000);
				GPIO_SetDir(1, 0x100000, 1);
				GPIO_SetValue(1, 0x100000);
			}else{
				GPIO_ClearValue(1, 0x800000);
				GPIO_ClearValue(1, 0x200000);
				GPIO_ClearValue(1, 0x100000);
				led = 14;
				
			}
			break; //1110
		case 14:
			if((msTicks < 150) && (msTicks > 140)){
				GPIO_SetDir(1, 0x800000, 1);
				GPIO_SetValue(1, 0x800000);
				GPIO_SetDir(1, 0x200000, 1);
				GPIO_SetValue(1, 0x200000);
				GPIO_SetDir(1, 0x100000, 1);
				GPIO_SetValue(1, 0x100000);
				GPIO_SetDir(1, 0x40000, 1);
				GPIO_SetValue(1, 0x40000);
			}else{
				GPIO_ClearValue(1, 0x800000);
				GPIO_ClearValue(1, 0x200000);
				GPIO_ClearValue(1, 0x100000);
				GPIO_ClearValue(1, 0x40000);
				led = 0;
				
			}
			break; //1111
	}
	
}

			
void main(void)
{	
	serial_init();


	uint32_t bl;
	FunctionalState Time = ENABLE;
	SYSTICK_IntCmd(Time);
	int i;
	bl = SysTick_Config(SystemCoreClock / 10);

	
	
	

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


