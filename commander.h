/* 
 * File:   commander.h
 * Author: rodrigo
 *
 * Created on March 20, 2021, 12:10 AM
 */

#ifndef COMMANDER_H
#define	COMMANDER_H

#define COMMAND_LEN 4

char command[COMMAND_LEN + 1] = {0};
unsigned char bytes = 0;

void process_char(unsigned char dat);

#endif	/* COMMANDER_H */

