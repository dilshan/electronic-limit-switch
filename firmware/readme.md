This firmware is written for the Microchip PIC10F200 microcontroller.

To compile and flash the firmware, you’ll need:

- [MPLAB X IDE](https://www.microchip.com/en-us/tools-resources/develop/mplab-x-ide) (v6.0 or later recommended)
- [XC8 Compiler](https://www.microchip.com/en-us/tools-resources/develop/mplab-xc-compilers/xc8) (v2.40 or later)

Both are free and cross-platform (Linux, Windows, and macOS).

All MCU configuration bits are defined in `config.h`.

To program the PIC10F200 microcontroller, use MPLAB IPE provided by Microchip. First, connect the programmer (such as PICkit 3 or 4) to the target device and open MPLAB IPE. Select the correct device (PIC10F200) and tool from the dropdown menus. Then, load the generated .hex file from the `dist/` folder, click *Connect* to detect the device, and press *Program* to flash the firmware. 
