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
#include "uart.h"
#include "commander.h"
#include "pwm.h"

void toggle_led(){
    RD1 = !RD1;
}

void set_led(unsigned char on_off){
    RD1 = on_off;
}

void setup_led(){
    TRISD1 = 0;
    RD1 = 0;
}

void toggle_dir(){
    RC3 = !RC3;
}

void set_dir(unsigned char fw_bw){
    RC3 = fw_bw;
}

void setup_dir(){
    TRISC3 = 0;
    RC3 = 0;
}

void setup(){
    setup_led();
    setup_dir();
    config_uart(1, 4);
    setup_pwm();
    add_callback("LED", set_led);
    add_callback("DIR", set_dir);
    add_callback("PWM", set_duty_percent);
}

void __interrupt() int_routine(void){
    if(RCIF){
        unsigned char dat = read_uart();
        process_char(dat);
    }
}

void main(void) {
    setup();
    
    while(1){
        continue;
    }
}
