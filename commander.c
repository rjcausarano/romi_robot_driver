#include "commander.h"
#include "string_macros.h"

#include "bt.h"

void reset_cmd(){
    memset(command, '\0', sizeof(command));
    bytes = 0;
}

void process_char(unsigned char dat){
    command[bytes] = dat;
    bytes++;
    if(bytes == COMMAND_LEN){
        if(strings_eq(command, "Gret\0"))
            write_bt("Hello there!");
        else if(strings_eq(command, "Bark"))
            write_bt("whoof whoof\0");
        else if(strings_eq(command, "Exit"))
            write_bt("Good bye!\0");
        else if(strings_eq(command, "Togl")){
            RD2 = !RD2;
            write_bt("toggled!\0");
        }
        reset_cmd();
    }
}