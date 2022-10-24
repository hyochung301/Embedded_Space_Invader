// DAC.c
// This software configures DAC output
// Lab 6 requires 6 bits for the DAC
// Runs on TM4C123
// Program written by: Hyokwon Chung and Daniel Davis
// Date Created: 3/6/17 
// Last Modified: 10/16/22 
// Lab number: 6
// Hardware connections
// TO STUDENTS "REMOVE THIS LINE AND SPECIFY YOUR HARDWARE********

#include <stdint.h>
#include "../inc/tm4c123gh6pm.h"
// Code files contain the actual implemenation for public functions
// this file also contains an private functions and private data



// **************DAC_Init*********************
// Initialize 6-bit DAC, called once 
// Input: none
// Output: none
void DAC_Init(void){uint32_t delay;
  //set your keys to outputs, set system clock
	SYSCTL_RCGCGPIO_R |= 0x02; // activate port B

  delay = SYSCTL_RCGCGPIO_R; // allow time to finish PortB clock activating

  GPIO_PORTB_DIR_R |= 0x3F;  // make PB5-0 out

  GPIO_PORTB_DEN_R |= 0x3F;  // enable digital I/O on PB5-0
	
	GPIO_PORTB_PCTL_R &= ~0x00FFFFFF; //shut off alternate func
	
	GPIO_PORTB_DR8R_R |= 0x3F;
}

// **************DAC_Out*********************
// output to DAC
// Input: 6-bit data, 0 to 63 
// Input=n is converted to n*3.3V/63
// Output: none
void DAC_Out(uint32_t data){
	GPIO_PORTB_DATA_R  = data;
}
