#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "remote.h"
#include "lcd.h"
#include "receive.h"
#include "modulate.h"
int main(void)
{
	Stm32_Clock_Init(9);	//ϵͳʱ������
	delay_init(72);//��ʱ������ʼ��
	uart_init(72,115200);//���ڳ�ʼ��
	REC_Test();//��ʼ������

	//MOD_Init();//��ʼ������
	
}

