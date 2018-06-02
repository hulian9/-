#include "receive.h"
extern u8 RmtSta;
extern u8 RmtRec;
extern void delay_ms(u16 nms);
u8 REC_Scan()//和官方程序不同的在于遥控识别码
{
	u8 sta=0;       
    u8 t1,t2;  
	if(RmtSta&(1<<6))//得到一个按键的所有信息了
	{ 
		LCD_Fill(86,170,116+8*8,170+16,WHITE);	//清楚之前的显示
		LCD_ShowNum(86,130,RmtSta,3,16);		//显示键值
	    t1=RmtRec>>24;			//得到地址码
	    t2=(RmtRec>>16)&0xff;	//得到地址反码 
 	    if( /*(*/ t1==(u8)~t2  /*)&&t1==REMOTE_ID*/ )//检验遥控识别码(ID)及地址 
	    { 
	        t1=RmtRec>>8;
	        t2=RmtRec; 	
	        if(t1==(u8)~t2)sta=t1;//键值正确	 
		}   
		if((sta==0)||((RmtSta&0X80)==0))//按键数据错误/遥控已经没有按下了
		{
		 	RmtSta&=~(1<<6);//清除接收到有效按键标识
			RmtCnt=0;		//清除按键次数计数器
		}
	}  
    return sta;
}
void REC_Init()
{
	Remote_Init();			//红外接收初始化	 
}
void REC_Test()
{
	u8 key;
//	u8 *str=0;
	REC_Init();		
	LCD_Init();			   	//初始化LCD
	REC_Init();
	POINT_COLOR=RED;		//设置字体为红色
	LCD_ShowString(30,130,200,16,16,"KEYVAL:");	
   	LCD_ShowString(30,150,200,16,16,"KEYCNT:");	
   	LCD_ShowString(30,170,200,16,16,"SYMBOL:");	 
	while(1)
	{
		key=REC_Scan();
		/*
		if(key)
		{
			
			LCD_ShowNum(86,150,RmtCnt,3,16);	//显示按键次数
			switch(key)
			{
				case 0:str="ERROR";break;			   
				case 162:str="POWER";break;	    
				case 98:str="UP";break;	    
				case 2:str="PLAY";break;		 
				case 226:str="ALIENTEK";break;		  
				case 194:str="RIGHT";break;	   
				case 34:str="LEFT";break;		  
				case 224:str="VOL-";break;		  
				case 168:str="DOWN";break;		   
				case 144:str="VOL+";break;		    
				case 104:str="1";break;		  
				case 152:str="2";break;	   
				case 176:str="3";break;	    
				case 48:str="4";break;		    
				case 24:str="5";break;		    
				case 122:str="6";break;		  
				case 16:str="7";break;			   					
				case 56:str="8";break;	 
				case 90:str="9";break;
				case 66:str="0";break;
				case 82:str="DELETE";break;		 
			}
			
			LCD_ShowString(86,170,200,16,16,str);	//显示SYMBOL
		}
		else 
		*/	delay_ms(10);	 
		
	}
}	

