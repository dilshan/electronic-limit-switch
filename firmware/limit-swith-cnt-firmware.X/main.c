/*********************************************************************************
 * Copyright (c) 2025 Dilshan R Jayakody [jayakody2000lk@gmail.com].
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *********************************************************************************/

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
