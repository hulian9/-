#include "modulate.h"

//TIM3��CH2����PWN�����Ĭ�Ͻ���PA7�ϣ���Ȼ����ֱ��ʹ��PA7
//�����ں�����һ���˲��ɼ������Ի���Ҫ���������PB5
//��LED��Ϊ��ʾ
void MOD_Init()
{
	LED_Init();//��ʼ��LED
	//����arr:235
	//Ԥ��Ƶֵpsc:3
	TIM3_PWM_Init(235,3);//��ʼ��TIM3
	
	
}
void MOD_Test()
{
	MOD_Init();
	
}
