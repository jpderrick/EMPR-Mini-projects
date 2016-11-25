#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <lpc17xx_uart.h>
#include <lpc17xx_pinsel.h>
#include <lpc_types.h>
#include <lpc17xx_gpio.h>
#include <lpc17xx_i2c.h>
#include "serial.h"

uint8_t initScreen[12] = {0x00,0x34,0x0c,0x06,0x35,0x04,0x10,0x42,0x9f,0x34,0x02,0x20};
uint8_t writeBlank[33] = {0x40, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0};
int screenCounter = 1;
char *previousKey;
I2C_M_SETUP_Type TransferConfig;
uint8_t setHigh[] = {0x7F};
char output1[30];
uint8_t buffer1[1] = {};
LPC_I2C_TypeDef *I2C = LPC_I2C1;

void I2C_Our_Setup(void){

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


	I2C_Init(I2C, 100000);
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

char *getCharacter(char buffer){
	
		if(buffer == 0xBF){
			return (void *)"X";
		}else if(buffer == 0xB7){
			return "2";
		}else if(buffer == 0xBB) {
			return "5";
		}else if(buffer == 0xBD){
			return "8";		
		}else if(buffer == 0xBE){
			return "0";		
		}else if(buffer == 0x77){
			return "1";
		}else if(buffer == 0x7B) {
			return "4";
		}else if(buffer == 0x7D){
			return "7";		
		}else if(buffer == 0x7E){
			return "*";
		}else if(buffer == 0xD7){
			return "3";
		}else if(buffer == 0xDB) {
			return "6";
		}else if(buffer == 0xDD){
			return "9";		
		}else if(buffer == 0xDE){
			return "#";
		}else if(buffer == 0xE7){
			return "A";
		}else if(buffer == 0xEB) {
			return "B";
		}else if(buffer == 0xED){
			return "C";		
		}else if(buffer == 0xEE){
			return "D";
		}
		else {
			return "X";
		}

}
void setupScreen(void){
	
	TransferConfig.tx_data = NULL;
	TransferConfig.tx_length = 12;
	TransferConfig.sl_addr7bit = 59;
	TransferConfig.tx_data = initScreen;
	I2C_MasterTransferData(I2C, &TransferConfig, I2C_TRANSFER_POLLING);

}

void sendToScreen(char *keyPressed){
		if(keyPressed == previousKey){
		}	
		else if(keyPressed != "X"){
		
			writeBlank[screenCounter] = (*keyPressed)+128;
			TransferConfig.tx_length = 33;
			TransferConfig.tx_data = writeBlank;
			I2C_MasterTransferData(I2C, &TransferConfig, I2C_TRANSFER_POLLING);
			screenCounter++;
			previousKey = keyPressed;
		}

}

