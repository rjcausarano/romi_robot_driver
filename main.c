/*
 * File:   main.c
 * Author: rodrigo
 *
 * Created on March 18, 2021, 6:42 PM
 */

// CONFIG
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#define _XTAL_FREQ 2983056

#include <xc.h>
#include "bt.h"

void toggle_led(){
    __delay_ms(5000);
    RD1 = !RD1;
}

void setup_led(){
    TRISD1 = 0;
}

void setup_uart(){
    // setup transmission 
    BRGH = 1; // high baud rate
    SPBRG = 4;
    SYNC = 0;
    SPEN = 1;
    GIE = 1;
    PEIE = 1;
    TXIE = 0; // interrupt on send
    TXEN = 1;
    
    // setup reception
    RCIE = 1; // interrupt on receive
    CREN = 1;
}

void send_char(unsigned char data){
    TXREG = data;
}

unsigned char get_char(){
    return RCREG;
}

void __interrupt() int_routine(void){
    if(RCIF){
        unsigned char dat = get_char();
        send_char(dat);
    }
}

void main(void) {
    setup_led();
    config_bt(1, 4);
    
    while(1){
        continue;
    }
}
