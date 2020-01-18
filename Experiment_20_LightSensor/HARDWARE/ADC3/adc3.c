#include "adc3.h"
#include "delay.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK STM32F407������
//ADC3��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//��������:2017/4/11
//�汾��V1.1
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2014-2024
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	
//20160113 	V1.1
//1,����Get_Temprate����,���ڻ�ȡ�ڲ��¶ȴ������ɼ������¶�ֵ
////////////////////////////////////////////////////////////////////////////////// 

ADC_HandleTypeDef ADC3_Handler;//ADC���

//��ʼ��ADC
//ch: ADC_channels 
//ͨ��ֵ 0~16ȡֵ��ΧΪ��ADC_CHANNEL_0~ADC_CHANNEL_16
void Adc3_Init(void)
{   
    ADC3_Handler.Instance=ADC3;
    ADC3_Handler.Init.ClockPrescaler=ADC_CLOCK_SYNC_PCLK_DIV4;  //4��Ƶ��ADCCLK=PCLK2/4=84/4=21MHZ
    ADC3_Handler.Init.Resolution=ADC_RESOLUTION_12B;            //12λģʽ
    ADC3_Handler.Init.DataAlign=ADC_DATAALIGN_RIGHT;            //�Ҷ���
    ADC3_Handler.Init.ScanConvMode=DISABLE;                     //��ɨ��ģʽ
    ADC3_Handler.Init.EOCSelection=DISABLE;                     //�ر�EOC�ж�
    ADC3_Handler.Init.ContinuousConvMode=DISABLE;               //�ر�����ת��
    ADC3_Handler.Init.NbrOfConversion=1;                        //1��ת���ڹ��������� Ҳ����ֻת����������1 
    ADC3_Handler.Init.DiscontinuousConvMode=DISABLE;            //��ֹ����������ģʽ
    ADC3_Handler.Init.NbrOfDiscConversion=0;                    //����������ͨ����Ϊ0
    ADC3_Handler.Init.ExternalTrigConv=ADC_SOFTWARE_START;      //�������
    ADC3_Handler.Init.ExternalTrigConvEdge=ADC_EXTERNALTRIGCONVEDGE_NONE;//ʹ���������
    ADC3_Handler.Init.DMAContinuousRequests=DISABLE;            //�ر�DMA����
    HAL_ADC_Init(&ADC3_Handler);                                //��ʼ��     
}

//ADC�ײ��������������ã�ʱ��ʹ��
//�˺����ᱻHAL_ADC_Init()����
//hadc:ADC���
void HAL_ADC_MspInit(ADC_HandleTypeDef* hadc)
{
    __HAL_RCC_ADC3_CLK_ENABLE();            //ʹ��ADC3ʱ��
}

//���ADCֵ
//ch: ͨ��ֵ 0~16��ȡֵ��ΧΪ��ADC_CHANNEL_0~ADC_CHANNEL_16
//����ֵ:ת�����
u16 Get_Adc3(u32 ch)   
{
    ADC_ChannelConfTypeDef ADC1_ChanConf;
    
    ADC1_ChanConf.Channel=ch;                                   //ͨ��
    ADC1_ChanConf.Rank=1;                                       //1������
    ADC1_ChanConf.SamplingTime=ADC_SAMPLETIME_480CYCLES;        //����ʱ��
    ADC1_ChanConf.Offset=0;                 
    HAL_ADC_ConfigChannel(&ADC3_Handler,&ADC1_ChanConf);        //ͨ������
	
    HAL_ADC_Start(&ADC3_Handler);                               //����ADC
	
    HAL_ADC_PollForConversion(&ADC3_Handler,10);                //��ѯת��
   
	return (u16)HAL_ADC_GetValue(&ADC3_Handler);	            //�������һ��ADC1�������ת�����
}
