#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "key.h"
#include "lcd.h"
#include "usmart.h"
#include "adc.h"
/************************************************
 ALIENTEK ̽����STM32F407������ ʵ��18
 ADCģ��ת��ʵ��-HAL�⺯����
 ����֧�֣�www.openedv.com
 �Ա����̣�http://eboard.taobao.com 
 ��ע΢�Ź���ƽ̨΢�źţ�"����ԭ��"����ѻ�ȡSTM32���ϡ�
 �������������ӿƼ����޹�˾  
 ���ߣ�����ԭ�� @ALIENTEK
************************************************/

int main(void)
{
    u16 adcx;
	float temp;
	
    HAL_Init();                   	//��ʼ��HAL��    
    Stm32_Clock_Init(336,8,2,7);  	//����ʱ��,168Mhz
	delay_init(168);               	//��ʼ����ʱ����
	uart_init(115200);             	//��ʼ��USART
	usmart_dev.init(84); 		    //��ʼ��USMART
	LED_Init();						//��ʼ��LED	
	KEY_Init();						//��ʼ��KEY
 	LCD_Init();           			//��ʼ��LCD
    MY_ADC_Init();                  //��ʼ��ADC1ͨ��5
    
	POINT_COLOR=RED; 
	LCD_ShowString(30,50,200,16,16,"Explorer STM32F4");	
	LCD_ShowString(30,70,200,16,16,"ADC TEST");	
	LCD_ShowString(30,90,200,16,16,"ATOM@ALIENTEK");
	LCD_ShowString(30,110,200,16,16,"2017/4/11");	  
	POINT_COLOR=BLUE;//��������Ϊ��ɫ
	LCD_ShowString(30,130,200,16,16,"ADC1_CH5_VAL:");	      
	LCD_ShowString(30,150,200,16,16,"ADC1_CH5_VOL:0.000V");	//���ڹ̶�λ����ʾС����  	
    while(1)
	{
        adcx=Get_Adc_Average(ADC_CHANNEL_5,20);//��ȡͨ��5��ת��ֵ��20��ȡƽ��
		LCD_ShowxNum(134,130,adcx,4,16,0);    //��ʾADCC�������ԭʼֵ
		temp=(float)adcx*(3.3/4096);          //��ȡ�����Ĵ�С����ʵ�ʵ�ѹֵ������3.1111
		adcx=temp;                            //��ֵ�������ָ�adcx��������ΪadcxΪu16����
		LCD_ShowxNum(134,150,adcx,1,16,0);    //��ʾ��ѹֵ���������֣�3.1111�Ļ������������ʾ3
		temp-=adcx;                           //���Ѿ���ʾ����������ȥ��������С�����֣�����3.1111-3=0.1111
		temp*=1000;                           //С�����ֳ���1000�����磺0.1111��ת��Ϊ111.1���൱�ڱ�����λС����
		LCD_ShowxNum(150,150,temp,3,16,0X80); //��ʾС�����֣�ǰ��ת��Ϊ��������ʾ����������ʾ�ľ���111.
		LED0=!LED0;
		delay_ms(250);	
	} 
}
