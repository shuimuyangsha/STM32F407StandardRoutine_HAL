#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "key.h"
#include "lcd.h"
#include "usmart.h"
#include "sram.h"
#include "malloc.h" 
#include "w25qxx.h"
#include "sdio_sdcard.h"
#include "ff.h"  
#include "exfuns.h"  
#include "text.h"
#include "usbh_usr.h" 
/************************************************
 ALIENTEK ̽����STM32F407������ ʵ��53
 USB U��(Host)ʵ��-HAL�⺯����
 ����֧�֣�www.openedv.com
 �Ա����̣�http://eboard.taobao.com 
 ��ע΢�Ź���ƽ̨΢�źţ�"����ԭ��"����ѻ�ȡSTM32���ϡ�
 ������������ӿƼ����޹�˾  
 ���ߣ�����ԭ�� @ALIENTEK
************************************************/

USBH_HOST  USB_Host;
USB_OTG_CORE_HANDLE  USB_OTG_Core;

//�û�����������
//����ֵ:0,����
//       1,������
u8 USH_User_App(void)
{  
	u32 total,free;
	u8 res=0;
	Show_Str(30,140,200,16,"�豸���ӳɹ�!.",16,0);	 
  	f_mount(fs[2],"2:",1); 	//���¹���U��
	res=exf_getfree("2:",&total,&free);
	printf("res= %d\r\n",res);
	if(res==0)
	{
		POINT_COLOR=BLUE;//��������Ϊ��ɫ	   
		LCD_ShowString(30,160,200,16,16,"FATFS OK!");	
		LCD_ShowString(30,180,200,16,16,"U Disk Total Size:     MB");	 
		LCD_ShowString(30,200,200,16,16,"U Disk  Free Size:     MB"); 	    
		LCD_ShowNum(174,180,total>>10,5,16);//��ʾU�������� MB
		LCD_ShowNum(174,200,free>>10,5,16);	
	} 
	while(HCD_IsDeviceConnected(&USB_OTG_Core))//�豸���ӳɹ�
	{	
		LED1=!LED1;
		delay_ms(200);
	}
	LED1=1;				//�ر�LED1 
 	f_mount(0,"2:",1); 	//ж��U��
	POINT_COLOR=RED;//��������Ϊ��ɫ	   
	Show_Str(30,140,200,16,"�豸������...",16,0);
	LCD_Fill(30,160,239,220,WHITE); 
	return res;
} 

int main(void)
{
	u8 t;
	
    HAL_Init();                   	//��ʼ��HAL��    
    Stm32_Clock_Init(336,8,2,7);  	//����ʱ��,168Mhz
	delay_init(168);               	//��ʼ����ʱ����
	uart_init(115200);             	//��ʼ��USART
	usmart_dev.init(84); 		    //��ʼ��USMART
	LED_Init();						//��ʼ��LED	
	KEY_Init();						//��ʼ��KEY
	LCD_Init();                     //��ʼ��LCD
	SRAM_Init();					//��ʼ���ⲿSRAM  
	W25QXX_Init();					//��ʼ��W25Q128 
	
	my_mem_init(SRAMIN);			//��ʼ���ڲ��ڴ��
	my_mem_init(SRAMEX);			//��ʼ���ⲿ�ڴ��
	my_mem_init(SRAMCCM);			//��ʼ��CCM�ڴ�� 
	exfuns_init();					//Ϊfatfs��ر��������ڴ�  
 	f_mount(fs[0],"0:",1); 			//����SD�� 
 	f_mount(fs[1],"1:",1); 			//����SPI FLASH. 
	f_mount(fs[2],"2:",1); 			//���¹���U��
	POINT_COLOR=RED;      
 	while(font_init()) 				//����ֿ�
	{	    
		LCD_ShowString(60,50,200,16,16,"Font Error!");
		delay_ms(200);				  
		LCD_Fill(60,50,240,66,WHITE);//�����ʾ	     
		delay_ms(200);				  
	}
	Show_Str(30,50,200,16,"̽����STM32F407������",16,0);				    	 
	Show_Str(30,70,200,16,"USB U��ʵ��",16,0);					    	 
	Show_Str(30,90,200,16,"2017��5��16��",16,0);	    	 
	Show_Str(30,110,200,16,"����ԭ��@ALIENTEK",16,0); 
	Show_Str(30,140,200,16,"�豸������...",16,0);			 		
	//��ʼ��USB����
  	USBH_Init(&USB_OTG_Core,USB_OTG_FS_CORE_ID,&USB_Host,&USBH_MSC_cb,&USR_cb);  
	while(1)
	{
		USBH_Process(&USB_OTG_Core, &USB_Host);
		delay_ms(1);
		t++;
		if(t==200)
		{
			LED0=!LED0;
			t=0;
		} 
	}		
}

