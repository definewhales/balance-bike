
#ifndef SHANGWEIJI_H
#define SHANGWEIJI_H


#include "headfile.h"


void test_c(void);
void vcan_sendware(UARTN_enum uart_n, void *wareaddr, uint32 waresize);
void uart_putbuff1(UARTN_enum uart_n,uint8 *buff,uint16 len);



#endif


