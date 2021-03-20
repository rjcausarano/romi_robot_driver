#include "bt.h"
#include <string.h>
#include "string_macros.h"

void config_bt(unsigned char high_speed, char spbrg){
    // RC6 and RC7 as inputs
    TRISD6 = 1;
    TRISD7 = 1;
    BRGH = high_speed;
    SPBRG = spbrg;
    // enable serial
    SYNC = 0;
    SPEN = 1;
    // interrupts
    GIE = 1;
    PEIE = 1;
    TXIE = 0;
    RCIE = 1;
    // enable reception
    CREN = 1;
    // enable transmission
    TXEN = 1;
}
char data_received_bt(){
    return RCIF;
}

char data_transmited_bt(){
    return TXIF;
}
void write_bt(char* data){
    for(unsigned int i = 0 ; i <= strlen(data) ; i++){
        while(!data_transmited_bt()) continue;
        TXREG = data[i];
    }
}
char read_bt(){
    return RCREG;
}
