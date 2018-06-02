#include "modulate.h"

//TIM3与CH2产出PWN输出，默认接在PA7上，虽然可以直接使用PA7
//但由于红外线一般人不可见，所以还是要调整输出到PB5
//让LED作为显示
void MOD_Init()
{
	LED_Init();//初始化LED
	//周期arr:235
	//预分频值psc:3
	TIM3_PWM_Init(235,3);//初始化TIM3
	
	
}
void MOD_Test()
{
	MOD_Init();
	
}
