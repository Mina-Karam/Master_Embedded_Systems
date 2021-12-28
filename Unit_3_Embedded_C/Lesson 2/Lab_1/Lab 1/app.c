/****************************************************/
/*** Auther : Bassam
/** Date    : 15-Dec 2021
/****************************************************/


#include "uart.h"
unsigned char string_buffer[100]= "learn-in-depth:<Mina>";
//unsigned const char string_buffer_2[100];
void main()
{
Uart_Send_string(string_buffer);	
}
