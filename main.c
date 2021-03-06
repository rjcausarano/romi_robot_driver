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
#define _SLAVE_ADDRESS 4
#define LED_COMMAND 5

#include <xc.h>
#include "pic_libs/pwm.h"
#include "pic_libs/i2c.h"

char bytes_received[2] = {0};
char byte_index = 0;

void toggle_led(){
    RD1 = !RD1;
}

void set_led(char on_off){
    RD1 = on_off;
}

void setup_led(){
    TRISD1 = 0;
    RD1 = 0;
}

void toggle_dir(){
    RC3 = !RC3;
}

void set_dir(char fw_bw){
    RC3 = fw_bw;
}

void setup_dir(){
    TRISC3 = 0;
    RC3 = 0;
}

void process_data(){
    if(bytes_received[0] == LED_COMMAND){
        set_led(bytes_received[1]);
    }
}

void on_byte_received(char byte){
    bytes_received[byte_index] = byte;
    byte_index++;
    if(byte_index >= 2){
        byte_index = 0;
        process_data();
    }
}

void setup(){
    setup_led();
    //setup_dir();
    setup_i2c(0, _SLAVE_ADDRESS, on_byte_received); // slave on address
}

void __interrupt() int_routine(void){
    if (SSPIF){ // received data through i2c
        process_interrupt_i2c();
    }
}

void main(void) {
    setup();
    
    while(1){
        continue;
    }
}
