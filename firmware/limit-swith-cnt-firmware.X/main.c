#include "config.h"

#include <xc.h>

#define CHANGE_COUNTER_START    11

void applyRelayOutput()
{
  if((GPIO & 0x03) == 0x03)
  {
      NOP();
      NOP();
      GPIO = 0x00;
  }
  else
  {
      NOP();
      NOP();
      GPIO = 0x04;
  }
}

void main(void) 
{
  unsigned char initalState;
  char changeCounter;
  
  // Initialize system registers and peripherals.
  OPTION = 0x97;
  
  // Initialize GPIO ports. 
  // GP0 - [IN]  - Switch 1 (Lower limit)
  // GP1 - [IN]  - Switch 2 (Upper limit)
  // GP2 - [OUT] - Relay
  TRISGPIO = 0x03;
  GPIO = 0x00;
  
  initalState = (GPIO & 0x03);
  changeCounter = CHANGE_COUNTER_START;
  
  // Main service loop.
  while(1)
  {
    if((GPIO & 0x03) != initalState)
    {
      // Change has detected on limit switches and start counter.        
      changeCounter = CHANGE_COUNTER_START;
    }
    
    if(changeCounter > 0)
    {
      changeCounter--;
      if(changeCounter <= 1)
      {
        // The change counter timeout has reached, apply output changes.
        applyRelayOutput();
        changeCounter = 0;
      }
    }
    
    initalState = (GPIO & 0x03);
    __delay_ms(100);
  }
    
  return;
}
