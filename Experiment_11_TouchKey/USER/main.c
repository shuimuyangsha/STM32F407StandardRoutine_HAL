#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "key.h"
#include "tpad.h"
/************************************************
 ALIENTEK ̽����STM32F407������ ʵ��11
 ���ݴ�������ʵ��-HAL�⺯����
 ����֧�֣�www.openedv.com
 �Ա����̣�http://eboard.taobao.com 
 ��ע΢�Ź���ƽ̨΢�źţ�"����ԭ��"����ѻ�ȡSTM32���ϡ�
 ������������ӿƼ����޹�˾  
 ���ߣ�����ԭ�� @ALIENTEK
************************************************/

int main(void)
{
	u8 t=0; 
    HAL_Init();                   	//��ʼ��HAL��    
    Stm32_Clock_Init(336,8,2,7);  	//����ʱ��,168Mhz
	delay_init(168);               	//��ʼ����ʱ����
	uart_init(115200);             	//��ʼ��USART
	LED_Init();						//��ʼ��LED	
	TPAD_Init(8);                   //��ʼ����������
	
   	while(1)
	{					  						  		 
 		if(TPAD_Scan(0))	//�ɹ�������һ��������(�˺���ִ��ʱ������15ms)
		{
			LED1=!LED1;		//LED1ȡ��
		}
		t++;
		if(t==15)		 
		{
			t=0;
			LED0=!LED0;		//LED0ȡ��,��ʾ������������
		}
		delay_ms(10);
	}
}

