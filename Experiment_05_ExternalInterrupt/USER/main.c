#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "key.h"
#include "exti.h"
/************************************************
 ALIENTEK ̽����STM32F407������ ʵ��5
 �ⲿ�ж�-HAL�⺯����
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
	uart_init(115200);              //��ʼ��USART
	LED_Init();						//��ʼ��LED	
    KEY_Init();                     //��ʼ������
	EXTI_Init();                    //�ⲿ�жϳ�ʼ��
	
    while(1)
    {	
		printf("OK\r\n");           //��ӡOK��ʾ��������
        delay_ms(1000);             //ÿ��1s��ӡһ�� 
    }
}

