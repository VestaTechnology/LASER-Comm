/*
 * File:   main.c
 * Author: Production, James Burnworth
 *
 * Created on August 8, 2014, 11:35 AM
 * This Project controls a transmitter for LASER communication using USART1 for LASER
 * and USART2 to communicate with host computer via USB
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include "../Common/usart.h"
#include "../Common/usart1async.h"

#pragma config FOSC = HS        // Oscillator Selection (HS Oscillator, High-speed crystal/resonator connected between OSC1 and OSC2 pins)
#pragma config WDTE = OFF       // Watchdog Timer Enable (WDT disabled)
#pragma config LVP = OFF        // High-voltage on MCLR/VPP must be used for programming

#define LED PORTCbits.RC3

/*
 *
 */
int main() {
    init_comms();               // Initialize USART2 at 38400 BAUD to talk to computer through USB
    init_usart1();              // Initialize USART1 at 9600 BAUD to communicate with a LASER
    TRISC &= 0xF7;              // Set LED to output

    usart_select = 1;           // Select USB emulated COM port on USART2
    LED = 0;

    printf("%cc",0x1B);         // Reset COM Terminal
    printf("LASER Communication: if misaligned errors will print\n\r");

    char write = 'U', read;
    int error=0;

    usart_select = 0;           // Select LASER comm USART
    while (1) {
#if 1
        printf("%c",write);
        read = getch();

        for (int i = 1000; i > 0; i--);

        if (read == write) {    //Transmition Success! Toggle LED
            LED = !(LED);
        } else {                // Else: Print error mesage to Computer
            error++;
            LED = 0;
            usart_select = 1;
            printf("Laser Comm Error # %4i\r", error);
            usart_select = 0;
        }
        write++;
#else
        printf("%c",0xFF);
#endif
    }
    return (EXIT_SUCCESS);
}
