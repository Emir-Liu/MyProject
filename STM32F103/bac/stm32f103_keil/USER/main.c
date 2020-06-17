#include "stm32f10x.h"
#include "usart.h"

int main(){
	uart_init(9600);
	while(1){
		printf("11111\n");
	}
}

