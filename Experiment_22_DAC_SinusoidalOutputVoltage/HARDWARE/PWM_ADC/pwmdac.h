#ifndef __PWMDAC_H
#define __PWMDAC_H
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK STM32F407������
//PWM DAC��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//��������:2017/4/13
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2014-2024
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	

extern TIM_HandleTypeDef TIM9_Handler;         //��ʱ��9 PWM��� 

void TIM9_CH2_PWM_Init(u16 arr,u16 psc);	
void TIM_SetTIM9Compare2(u32 compare);
#endif
