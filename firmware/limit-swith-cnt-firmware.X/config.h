#ifndef CONFIG_H
#define	CONFIG_H

// Use 4MHz internal oscillator.
#define _XTAL_FREQ 4000000

// CONFIG
#pragma config WDTE = OFF       // Watchdog Timer (WDT disabled)
#pragma config CP = OFF         // Code Protect (Code protection off)
#pragma config MCLRE = ON       // Master Clear Enable (GP3/MCLR pin function  is MCLR)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>

#endif	/* CONFIG_H */

