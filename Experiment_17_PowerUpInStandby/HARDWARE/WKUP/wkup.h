#ifndef __WKUP_H
#define __WKUP_H
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK STM32F407������
//�������� ��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//��������:2017/4/11
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2014-2024
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	

#define WKUP_KD HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0)  //PA0 ����Ƿ��ⲿWK_UP��������

u8 Check_WKUP(void);  			//���WKUP�ŵ��ź�
void WKUP_Init(void); 			//PA0 WKUP���ѳ�ʼ��
void Sys_Enter_Standby(void);	//ϵͳ�������ģʽ
#endif

