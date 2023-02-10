/*------------ Echo ------------------------------------------------------------------------------------*/
//======================================================================================================//
// FOOTSWITCH ------------------------------ TURN ON/OFF THE EFFECT 
// POT0 ------------------------------------ [DELAY TIME] DEPTH OF THE EFFECT
// POT1 ------------------------------------ FEEDBACK ADJUST
// POT2 ------------------------------------ [MIXER] OUTPUT GAIN
// MIX SWITCH ------------------------------ ALWAYS IN [ON] POSITION
//======================================================================================================//
//
//Based on :[1] www.electrosmash.com/pedalshield configurations,
//          [2] AES Brasil 2011 - article "Filtros e Efeitos de Áudio Analógicos e Digitais"
//          [3] Zolzer, U.; “DAFX: Digital Audio Effects” John Wiley & Sons, Ltd – 2002.
//          [4] Oppenheim, A., V.; “Applications of Digital Signal Processing”, ”, Prentice Hall, 1978.
//          [5] Orfanidis, S. J.; “Introduction to Signal processing”, Prentice Hall, 2009.
//
//
// Developed by Andrew Henrique Pavei, (andrewhpavei@gmail.com), as part of the Final Paper to 
//Electrical Engeneering Graduation of Federal University of Santa Catarina (UFSC), Brazil and AES Brazil 2016 
//LECTURE "Implementações de Efeitos de Áudio utilizando Arduino DUE e PedalSHIELD"
//
//======================================================================================================//
//
// Echo's Function : 
//                  y(n) = x(n) + a.x(n-D)     [137]
//
//======================================================================================================//
 
int in_ADC0, in_ADC1;  //variables for 2 ADCs values (ADC0, ADC1)
int POT0, POT1, POT2, POT3, POT4, out_DAC0, out_DAC1; //variables for 3 pots (ADC8, ADC9, ADC10) 
 
#define MAX_DELAY 44100    // Using sampling in 44.1Khz we have 1s of Delay time.
uint16_t Buffer[MAX_DELAY];
int16_t buffer[44100] = {};
int16_t buffered = 0;
unsigned int Delay_Depth_echo, Delay = 0, a = 0;

uint16_t writepos = 0;
float phAcc = 0;
 
void setup()
{

 //----------------- Funcoes do Atmel Software Framework--------------------------//
 //O Power Management Controller (PMC) optimiza o consumo de energia controlando todo 
 //sistema e os clock perifericos, assim, o PMC pode abilitar ou desabilitar os clocks do
 //Cortex-M ou dos perifericos.
  pmc_set_writeprotect(false); // Disabilita a protecao de escrita do periferico.
  pmc_enable_periph_clk(ID_TC4); //Abilita o Timer 4 


  //------------------------------------- TC------------------------------------//
  // Sao um total de 9 canais de 32 bits
  // 
  //Podemos escolher essas frequencias de amostragem
  //8KHz,  value = 1312 (10500000/8000 = 1312)
  //16KHz, value = 656 (10500000/16000 = 656)
  //32KHz, value = 328 (10500000/32000 = 328)
  //44.1Hz, value = 238 (10500000/44100 = 238) -------------- 44.1KHz (1/44KHz=22.6us)
  //48KHz, value = 218 (10500000/48000 = 218)
  //88.2KHz, value = 119 (10500000/88200 = 119)
  //96KHz, value = 109  (10500000/96000 = 109)
  //
  /* we want wavesel 01 with RC */
  TC_Configure(TC1,1, TC_CMR_WAVE | TC_CMR_WAVSEL_UP_RC | TC_CMR_TCCLKS_TIMER_CLOCK2);
  TC_SetRC(TC1, 1, 238); // sets <> 44.1 Khz interrupt rate
  TC_Start(TC1, 1);
 
  // enable timer interrupts on the timer
  TC1->TC_CHANNEL[1].TC_IER=TC_IER_CPCS;
  TC1->TC_CHANNEL[1].TC_IDR=~TC_IER_CPCS;
 
  /* Enable the interrupt in the nested vector interrupt controller */
  /* TC4_IRQn where 4 is the timer number * timer channels (3) + the channel number 
  (=(1*3)+1) for timer1 channel1 */
  NVIC_EnableIRQ(TC4_IRQn);
 
//--------------Bloco basico de configuracao do ADC para todos os efeitos -------------------------//
// Possui 16 Canais 
// 12 bits Resolucao

  ADC->ADC_MR |= 0x80;   // Mode Register ----------------------  Add[0x400C0004] 
                         // ADC_MR [0x80] 
                         //        [1000 0000] -----------------  Trabalha no modo Freerun 
                               
  ADC->ADC_CR=2;         // ADC Control Register.---------------  Add[0x400C0000]  
                         // ADC_CR [0x02] 
                         //        [0010] ----------------------  Abilita a conversao
                         
  ADC->ADC_CHER=0x1CC0;  // ADC Channel Enable Register --------  Add [0x400C0010]
                         // ADC_CHER [0x1CC0] = [0001 1111 1100 0000]
                         //          [0000 0000 0100 0000] --------------- Abilita o Channel 6
                         //          [0000 0000 1000 0000] --------------- Abilita o Channel 7
                         //          [0000 0100 0000 0000] --------------- Abilita o Channel 10
                         //          [0000 1000 0000 0000] --------------- Abilita o Channel 11
                         //          [0001 0000 0000 0000] --------------- Abilita o Channel 12

//---------------------------------------------------------------------------------------------------//
//--------------Bloco basico de configuracao do DAC para todos os efeitos ---------------------------//
// O DAC possui ate "4" saidas analogicas
// 12 bits resolucao

  analogWrite(DAC0,0);  // analogWrite(pin, value) --------- Ativa o pino DAC0 para escrita analogica
                        // Acredito que a ativacao do DAC0 seja semelhante a DACC_CHER:
                        // DACC_CHER [0x01] ---------------- Abilita o Chennel 0 para a escrita
                        
  analogWrite(DAC1,0);  // analogWrite(pin, value) --------- Ativa o pino DAC1 para escrita analogica
                        // DACC_CHER [0x10] ---------------- Abilita o Chennel 1 para a escrita
//---------------------------------------------------------------------------------------------------//
  
//---------------Configuracao dos pinos da pedalSHIELD ----------------------------------------------//



//---------------------------------------------------------------------------------------------------//
}
 
void loop()
{
 //------------leitura dos ADCs----------------------------------------------------------------------//
  while((ADC->ADC_ISR & 0x1CC0)!=0x1CC0); 
 // ADC Interrupt Status Register  ----------------------  Add[0x400C0030]
 // ADC_ISR [0x1CC0] = [0001 1111 1100 0000]
 //          [0000 0000 0100 0000] --------------- Final da conversao do Channel 6
 //          [0000 0000 1000 0000] --------------- Final da conversao do Channel 7
 //          [0000 0100 0000 0000] --------------- Final da conversao do Channel 10
 //          [0000 1000 0000 0000] --------------- Final da conversao do Channel 11
 //          [0001 0000 0000 0000] --------------- Final da conversao do Channel 12
 // [1] Representa que a conversancao do correspondente Channel foi finalizada
   
  
  // Quando a conversao é concluida, o resultado de 12 bits é armazenado no ADC_CDR[x] correspondente e o 
  // ADC_ISR correspondente é setado
  
  in_ADC0=ADC->ADC_CDR[7];               // Faz a leitura do ADC e armazena na variavel correspondente
  /*POT0=ADC->ADC_CDR[10];                 // Faz a leitura do ADC e armazena na variavel correspondente        
  POT1=ADC->ADC_CDR[11];                 // Faz a leitura do ADC e armazena na variavel correspondente   
  POT2=ADC->ADC_CDR[12];                 // Faz a leitura do ADC e armazena na variavel correspondente 
  POT3=ADC->ADC_CDR[8];
  POT4=ADC->ADC_CDR[9];*/

}
 
void TC4_Handler() 
{
  //Clear status allowing the interrupt to be fired again.
  TC_GetStatus(TC1, 1);

  // mix input and buffered sample
  int32_t in = (in_ADC0 - 2047) + buffered;

  // fold signal to prevent clipping
  if (in > 2047 || in <= -2047) {
    in = abs(abs(in - 2047 % 8191) - 4095) - 2047;
  }

  // write to buffer
  buffer[writepos] = in;
  writepos++;
  if (writepos > 44100) {
    writepos = 0;
  }

  // set phase inceremnts and reset accumulators
  phAcc += (POT0 / 1000.0) + 0.25;
  if (phAcc >= POT1 * 16 + 100) {
    phAcc = 0;
  }

  int outputVal = buffer[(int)phAcc];
  buffered = (outputVal * POT2) / 8192;

  out_DAC0 = outputVal;
 
 
  //----------------------- Funcoes do Atmel Software Framework (ASK)----------
  //Escreve nos DACs
  dacc_set_channel_selection(DACC_INTERFACE, 0);          //select DAC channel 0
  dacc_write_conversion_data(DACC_INTERFACE, out_DAC0);//write on DAC
}
