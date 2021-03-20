/* 
 * File:   bt.h
 * Author: kria
 *
 * Created on October 9, 2019, 1:31 PM
 */

#ifndef BT_H
#define	BT_H

#ifdef	__cplusplus
extern "C" {
#endif

#include<xc.h>
void config_bt(char high_speed, char spbrg);
char data_received_bt();
char data_transmited_bt();
void write_bt(char*);
char read_bt();

#ifdef	__cplusplus
}
#endif

#endif	/* BT_H */

