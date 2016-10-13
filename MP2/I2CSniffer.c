int main(void){

    //DONE Init the ports to act as I2C Settors
    //DONE Set the Clock Rate
    //Character buffer with one byte
    //Send this through each addres (2^7) addresses possible

    //PIN Configurations for I2C mode
    PINSEL_CFG_Type PinCfg;
    PinCfg.Funcnum = 1;
    PinCfg.OpenDrain = 0;
    PinCfg.Pinmode = 0;
    PinCfg.Portnum = 0;
    PinCfg.Pinnum = 0;
    //Configure P0.0
    PINSEL_ConfigPin(&PinCfg);
    //Configure P0.1
    PinCfg.Pinnum = 1;
    PINSEL_ConfigPin(&PinCfg);
    LPC_I2C_TypeDef I2C = LPC_I2C1;
    I2C_Init(I2C,100000);

    I2C_M_SETUP_Type TransferConfig;
    char buffer = 'a';
    TransferConfig.tx_data = buffer;
    TransferConfig.tx_length = 1;



    //for i = 1 to 127
    //Send a character to address i on the I2C
    //if TRUE
    //device counter++
    //end for

    int numberOfDevices = 0;

    for(int i = 0; i<=128;i++){
        TransferConfig.sl_addr7bit = i;
        
        if(I2C_MasterTransferData(I2C,TransferConfig,0) != 0){
            //Send a character to address i on the I2C
             //if TRUE
             //device counter++
            numberofDevices++;
        }


    }

    //print on UART the number of devices

}