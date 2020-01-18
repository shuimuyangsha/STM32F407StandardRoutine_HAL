#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "beep.h"
/************************************************
 ALIENTEK ̽����STM32F407������ ʵ��2
 ������ʵ��-HAL��汾
 ����֧�֣�www.openedv.com
 �Ա����̣�http://eboard.taobao.com 
 ��ע΢�Ź���ƽ̨΢�źţ�"����ԭ��"����ѻ�ȡSTM32���ϡ�
 ������������ӿƼ����޹�˾  
 ���ߣ�����ԭ�� @ALIENTEK
************************************************/

int main(void)
{ 
    HAL_Init();                    	//��ʼ��HAL��    
    Stm32_Clock_Init(336,8,2,7);  	//����ʱ��,168Mhz
	delay_init(168);               	//��ʼ����ʱ����
	LED_Init();						//��ʼ��LED	
	BEEP_Init();					//��ʼ��������
	
	while(1)
	{
		HAL_GPIO_WritePin(GPIOF,GPIO_PIN_9,GPIO_PIN_RESET);	//DS0���ͣ���   ��ͬLED0=0;
		HAL_GPIO_WritePin(GPIOF,GPIO_PIN_8,GPIO_PIN_RESET);	//BEEP�������ͣ� ��ͬBEEP=0;
		delay_ms(300);										//��ʱ300ms
		HAL_GPIO_WritePin(GPIOF,GPIO_PIN_9,GPIO_PIN_SET);	//DS0���ߣ���   ��ͬLED0=1;
		HAL_GPIO_WritePin(GPIOF,GPIO_PIN_8,GPIO_PIN_SET);	//BEEP�������ߣ� ��ͬBEEP=1;
		delay_ms(300);										//��ʱ300ms
	 }
}




