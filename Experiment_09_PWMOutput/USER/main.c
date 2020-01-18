#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "key.h"
#include "timer.h"
/************************************************
 ALIENTEK ̽����STM32F407������ ʵ��9
 PWM���ʵ��-HAL�⺯���� 
 ����֧�֣�www.openedv.com
 �Ա����̣�http://eboard.taobao.com 
 ��ע΢�Ź���ƽ̨΢�źţ�"����ԭ��"����ѻ�ȡSTM32���ϡ�
 ������������ӿƼ����޹�˾  
 ���ߣ�����ԭ�� @ALIENTEK
************************************************/

int main(void)
{
	u8 dir=1;
    u16 led0pwmval=0; 
	
    HAL_Init();                   	//��ʼ��HAL��    
    Stm32_Clock_Init(336,8,2,7);  	//����ʱ��,168Mhz
	delay_init(168);               	//��ʼ����ʱ����
	uart_init(115200);             	//��ʼ��USART
	LED_Init();						//��ʼ��LED	
	TIM3_Init(5000-1,8400-1);       //��ʱ��3��ʼ��������Ϊ500ms
	TIM14_PWM_Init(500-1,84-1);    	//84M/84=1M�ļ���Ƶ�ʣ��Զ���װ��Ϊ500����ôPWMƵ��Ϊ1M/500=2kHZ
	
    while(1)
    {
		delay_ms(10);	 	
		if(dir)led0pwmval++;				//dir==1 led0pwmval����
		else led0pwmval--;					//dir==0 led0pwmval�ݼ� 
		if(led0pwmval>300)dir=0;			//led0pwmval����300�󣬷���Ϊ�ݼ�
		if(led0pwmval==0)dir=1;				//led0pwmval�ݼ���0�󣬷����Ϊ����
		TIM_SetTIM14Compare1(led0pwmval);	//�޸ıȽ�ֵ���޸�ռ�ձ�
    }
}

