#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "remote.h"
#include "lcd.h"
#include "receive.h"
#include "modulate.h"
int main(void)
{
	Stm32_Clock_Init(9);	//系统时钟设置
	delay_init(72);//延时函数初始化
	uart_init(72,115200);//串口初始化
	REC_Test();//初始化接收

	//MOD_Init();//初始化调制
	
}

