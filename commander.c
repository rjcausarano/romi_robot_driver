#include "commander.h"
#include "string_macros.h"

void reset_cmd(){
    memset(command_, '\0', sizeof(command_));
    bytes_ = 0;
}

void add_callback(char* command, void (* callback)()){
    strcpy(commands_[cb_num_], command);
    callbacks_[cb_num_] = callback;
    cb_num_++;
}

void process_char(unsigned char dat){
    command_[bytes_] = dat;
    bytes_++;
    if(bytes_ == COMMAND_LEN){
        // find the command and call its callback function
        for(unsigned char i = 0 ; i < cb_num_ ; i++){
            if(strings_eq(command_, commands_[i])){
                callbacks_[i]();
                break;
            }
        }
        
        reset_cmd();
    }
}