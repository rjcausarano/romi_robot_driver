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
#include "commander.h"
#include "pwm.h"


void toggle_led(){
    RD1 = !RD1;
}

void low_pwm(){
    set_duty_percent(0);
}

void med_pwm(){
    set_duty_percent(50);
}

void high_pwm(){
    set_duty_percent(100);
}

void setup(){
    TRISD1 = 0;
    RD1 = 0;
    config_bt(1, 4);
    setup_pwm();
    add_callback("LED", toggle_led);
}

void __interrupt() int_routine(void){
    if(RCIF){
        unsigned char dat = read_bt();
        process_char(dat);
        set_duty_percent(dat);
    }
}

void main(void) {
    setup();
    
    while(1){
        continue;
    }
}
