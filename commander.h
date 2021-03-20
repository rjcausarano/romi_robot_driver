/* 
 * File:   commander.h
 * Author: rodrigo
 *
 * Created on March 20, 2021, 12:10 AM
 */

#ifndef COMMANDER_H
#define	COMMANDER_H

#define COMMAND_LEN 3

char command_[COMMAND_LEN + 1] = {0};
unsigned char bytes_ = 0;
unsigned char cb_num_ = 0;
void (* callbacks_[10])() = {0};
char commands_[10][COMMAND_LEN + 1] = {0};

void add_callback(char* command, void (* callback)());
void process_char(unsigned char dat);

#endif	/* COMMANDER_H */

