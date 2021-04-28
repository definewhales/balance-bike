/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2020,��ɿƼ�
 * All rights reserved.
 * ��������QQȺ��һȺ��179029047(����)  ��Ⱥ��244861897(����)  ��Ⱥ��824575535
 *
 * �����������ݰ�Ȩ������ɿƼ����У�δ��������������ҵ��;��
 * ��ӭ��λʹ�ò������������޸�����ʱ���뱣����ɿƼ��İ�Ȩ������
 *
 * @file       		main
 * @company	   		�ɶ���ɿƼ����޹�˾
 * @author     		��ɿƼ�(QQ790875685)
 * @version    		�鿴doc��version�ļ� �汾˵��
 * @Software 		MDK FOR C51 V9.60
 * @Target core		STC8H8K64S4
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2020-06-01
 ********************************************************************************************************************/

#include "headfile.h"
#include "oled.h"
float dueeprom(unsigned int addr);

float a1 = 1,b1 = 2,c1 = 3,d1 = 4,e1 = 5,f1 = 6,g1 = 7,h1 = 8,i1 = 9,j1 = 10;
//board.h�ļ���FOSC��ֵ����Ϊ0,������Զ�ʶ��ϵͳƵ��

/*board.h�ļ���FOSC��ֵ���ò�Ϊ0����ϵͳƵ��ΪFOSC��ֵ��
��ʹ��stc-isp�������س����ʱ����Ҫ��IRCƵ������ΪFOSC��ֵ*/

/*��board_init��,�Ѿ���P54��������Ϊ��λ
�����Ҫʹ��P54����,������board.c�ļ��е�board_init()������ɾ��SET_P54_RESRT����*/

void main()
{
	char ab;
	DisableGlobalIRQ();	//�ر����ж�
	board_init();		//�����д���һ�ó�ʼ��
	pwm_init(PWM7_P22,10000,5000);				//��·PWM��ʼ�������
	pwm_init(PWM4N_P27,100,1330);					//���//��ֵ1150
	simiic_init();	//���IIC
	icm20602_init_simiic();	//IIC20602
	adc_init(ADC_P10,ADC_SYSclk_DIV_4);     //��·ADC�����ڲɼ����ֵ
	adc_init(ADC_P15,ADC_SYSclk_DIV_4);			//ʼ��SYM/4
	adc_init(ADC_P11,ADC_SYSclk_DIV_4);
	adc_init(ADC_P14,ADC_SYSclk_DIV_4);
/**
	���100hz����ֵΪ1250
	��ֵ��С��ת��������ת
*/
	ctimer_count_init(CTIM3_P04);					//���ڱ������Ķ�ȡ
	pit_timer_ms(TIM_0,2);							//��ʱ���ж�2ms
	iap_init();			//��ʼ��EEPROM
	oled_init();
	iap_read_bytes(0x49,&ab,1);
	if(ab == '1')
	{
		AngleOffset=dueeprom(0x00);
		AngleControl_D=dueeprom(0x04);
		AngleControl_P=dueeprom(0x08);
		ANgleControl_I=dueeprom(0x0c);
		
		Direction_I=dueeprom(0x10);
		Direction_P=dueeprom(0x14);
		Direction_D=dueeprom(0x18);

		SpeedOffset=dueeprom(0x1c);
		SpeedControl_P=dueeprom(0x20);
		SpeedControl_I=dueeprom(0x24);
		turn_xianfu=dueeprom(0x28);
		gy_p = dueeprom(0x32);
		gy_d = dueeprom(0x36);
		oled_p6x8str(0,6,"du");
	}
	if(ab != '1')
	{
		writedata();
		iap_write_bytes(0x49,"1",1);
		oled_p6x8str(0,5,"write 1");
	}
	EnableGlobalIRQ();	//�������ж�
    while(1)
	{
		TingChe();//ͣ�����	
		if(P16 == 0)//�˵����
		{
			DisableGlobalIRQ();	//�ر����ж�
				while(P16 == 0){
					caidan();
			}
					EnableGlobalIRQ();
		}
		test_c();		//��λ��
    }
}


float dueeprom(unsigned int addr)
{
	float temp;
	char buf[4];
	iap_read_bytes(addr,buf,4);
	temp =*(float*)buf;
	return temp;
}
