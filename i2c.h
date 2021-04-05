/* 
 * File:   i2c.h
 * Author: rodrigo
 *
 * Created on April 4, 2021, 7:58 PM
 */

#ifndef I2C_H
#define	I2C_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include<xc.h>
    
void setup_i2c(char master, char address);
void write_byte_i2c(char data);
char read_byte_i2c();
char is_byte_data();
char is_read_instruction();


#ifdef	__cplusplus
}
#endif

#endif	/* I2C_H */

