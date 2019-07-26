/*
 * GSM http request.cpp
 *
 * Created: 7/26/2019 3:28:38 PM
 * Author : Hp
 */ 

#include <avr/io.h>
#include "USART.h"
#include <util/delay.h>

void Send_String(char ar[]){
	int i;
	i=0;
	while(ar[i]!='\0'){
		USART_Transmit(ar[i]);
		i++;
	}
}

int main(void)
{
	
	
	
    /* Replace with your application code */
    while (1) 
    {
		Send_String("AT+HTTPINIT");		//init http service
		_delay_ms(1000);
		
		Send_String("AT+HTTPPARA=”CID”,1");			//set http session
		_delay_ms(1000);
		
		Send_String("AT+HTTPPARA=\”URL\”,\”google.com\”");			//set http url
		_delay_ms(1000);
		
		Send_String("AT+HTTPACTION=0");			//return 200 if successful
		_delay_ms(1000);
		
    }
}

