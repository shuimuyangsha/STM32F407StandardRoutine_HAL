#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "key.h"
#include "lcd.h"
#include "usmart.h"
#include "sram.h"
#include "malloc.h" 
#include "sdio_sdcard.h"
#include "w25qxx.h"
#include "ff.h"
#include "exfuns.h"
#include "string.h"
#include "fontupd.h"
#include "text.h"
#include "wm8978.h"	 
#include "audioplay.h"	
#include "videoplayer.h" 
#include "timer.h" 
/************************************************
 ALIENTEK ̽����STM32F407������ ʵ��45
 ��Ƶ������ʵ��-HAL�⺯����
 ����֧�֣�www.openedv.com
 �Ա����̣�http://eboard.taobao.com 
 ��ע΢�Ź���ƽ̨΢�źţ�"����ԭ��"����ѻ�ȡSTM32���ϡ�
 ������������ӿƼ����޹�˾  
 ���ߣ�����ԭ�� @ALIENTEK
************************************************/

int main(void)
{
    HAL_Init();                   	//��ʼ��HAL��    
    Stm32_Clock_Init(336,8,2,7);  	//����ʱ��,168Mhz
	delay_init(168);               	//��ʼ����ʱ����
	uart_init(115200);             	//��ʼ��USART
	usmart_dev.init(84); 		    //��ʼ��USMART
	LED_Init();						//��ʼ��LED	
	KEY_Init();						//��ʼ��KEY
	LCD_Init();                     //��ʼ��LCD
	SRAM_Init();					//��ʼ���ⲿSRAM  
	W25QXX_Init();				    //��ʼ��W25Q128
	WM8978_Init();					//��ʼ��WM8978	
	WM8978_ADDA_Cfg(1,0);			//����DAC
	WM8978_Input_Cfg(0,0,0);		//�ر�����ͨ��
	WM8978_Output_Cfg(1,0);			//����DAC���  
	WM8978_HPvol_Set(40,40);
	WM8978_SPKvol_Set(60);
	TIM3_Init(10000-1,8400-1);		//10Khz����,1�����ж�һ��
	
	my_mem_init(SRAMIN);			//��ʼ���ڲ��ڴ��
	my_mem_init(SRAMCCM);			//��ʼ��CCM�ڴ�� 
	exfuns_init();					//Ϊfatfs��ر��������ڴ�  
 	f_mount(fs[0],"0:",1); 			//����SD��   	
	POINT_COLOR=RED;      
	while(font_init()) 			//����ֿ�
	{	    
		LCD_ShowString(30,50,200,16,16,"Font Error!");
		delay_ms(200);				  
		LCD_Fill(30,50,240,66,WHITE);//�����ʾ	     
		delay_ms(200);	
		LED0=!LED0;
	}  	 
	POINT_COLOR=RED;      
 	Show_Str(60,50,200,16,"Explorer STM32������",16,0);				    	 
	Show_Str(60,70,200,16,"��Ƶ������ʵ��",16,0);				    	 
	Show_Str(60,90,200,16,"����ԭ��@ALIENTEK",16,0);				    	 
	Show_Str(60,110,200,16,"2017��5��5��",16,0);
	Show_Str(60,130,200,16,"KEY0:NEXT   KEY2:PREV",16,0); 
	Show_Str(60,150,200,16,"KEY_UP:FF   KEY1��REW",16,0);
	delay_ms(1500);
	while(1)
	{ 
		video_play();
	} 
}

