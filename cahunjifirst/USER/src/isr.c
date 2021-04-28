/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2020,��ɿƼ�
 * All rights reserved.
 * ��������QQȺ��һȺ��179029047(����)  ��Ⱥ��244861897(����)  ��Ⱥ��824575535
 *
 * �����������ݰ�Ȩ������ɿƼ����У�δ��������������ҵ��;��
 * ��ӭ��λʹ�ò������������޸�����ʱ���뱣����ɿƼ��İ�Ȩ������
 *
 * @file       		isr
 * @company	   		�ɶ���ɿƼ����޹�˾
 * @author     		��ɿƼ�(QQ790875685)
 * @version    		�鿴doc��version�ļ� �汾˵��
 * @Software 		MDK FOR C51 V9.60
 * @Target core		STC8H8K64S4
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2020-4-14
 ********************************************************************************************************************/
#include "headfile.h"

//UART1�ж�
void UART1_Isr() interrupt 4
{
    uint8 res;
	static uint8 dwon_count;
    if(UART1_GET_TX_FLAG)
    {
        UART1_CLEAR_TX_FLAG;
        busy[1] = 0;
    }
    if(UART1_GET_RX_FLAG)
    {
        UART1_CLEAR_RX_FLAG;
        res = SBUF;
        //�����Զ�����
        if(res == 0x7F)
        {
            if(dwon_count++ > 20)
                IAP_CONTR = 0x60;
        }
        else
        {
            dwon_count = 0;
        }
    }
}

//UART2�ж�
void UART2_Isr() interrupt 8
{
    if(UART2_GET_TX_FLAG)
	{
        UART2_CLEAR_TX_FLAG;
		busy[2] = 0;
	}
    if(UART2_GET_RX_FLAG)
	{
        UART2_CLEAR_RX_FLAG;
		//�������ݼĴ���Ϊ��S2BUF

	}
}


//UART3�ж�
void UART3_Isr() interrupt 17
{
    if(UART3_GET_TX_FLAG)
	{
        UART3_CLEAR_TX_FLAG;
		busy[3] = 0;
	}
    if(UART3_GET_RX_FLAG)
	{
        UART3_CLEAR_RX_FLAG;
		//�������ݼĴ���Ϊ��S3BUF

	}
}


//UART4�ж�
void UART4_Isr() interrupt 18
{
    if(UART4_GET_TX_FLAG)
	{
        UART4_CLEAR_TX_FLAG;
		busy[4] = 0;
	}
    if(UART4_GET_RX_FLAG)
	{
        UART4_CLEAR_RX_FLAG;
		//S4BUF;

	}
}



void INT0_Isr() interrupt 0
{

}
void INT1_Isr() interrupt 2
{

}
void INT2_Isr() interrupt 10
{
	INT2_CLEAR_FLAG;  //����жϱ�־
}
void INT3_Isr() interrupt 11
{
	INT3_CLEAR_FLAG;  //����жϱ�־
}

void INT4_Isr() interrupt 16
{
	INT4_CLEAR_FLAG;  //����жϱ�־
}

void TM0_Isr() interrupt 1
{
	static int Symbol_6ms = 0;
	static int Symbol_12ms = 0;
	if(Symbol_12ms >= 4){
		Symbol_12ms = 0;
		InductanceFilter();//����˲�
		DirectionControl();//������ƣ���������뵽�Ƕ�����
	}
	if(Symbol_6ms >= 2){
		Symbol_6ms = 0;
		get_icm20602_accdata_simiic();//�ɼ�acc��gyro�ںϽǶ�
		get_icm20602_gyro_simiic();
		Angel_Calculate();//�Ƕ��ں�
		AngleControl();//�Ƕȿ��ƣ���������뵽���ٶ�
	}
	Symbol_6ms ++;
	Symbol_12ms ++;
	//����Ϊ�ٶȿ���
	caibianmaqi();
	SpeedControl();
	pwm_duty(PWM7_P22,5000 + g_fSpeedControlOut);
	//����Ϊ���ٶȿ���
	gyroConOut();
	pwm_duty(PWM4N_P27,1330 + GyroConOutput);
}
void TM1_Isr() interrupt 3
{

}
/**
���Է����ֽ�200/s
	static int biaozhi = 0;
	if(biaozhi == 0){
		mpu6050_get_accdata();
		mpu6050_get_gyro();
	  Angel_Calculate();}
	if(biaozhi == 1){
	}
	if(biaozhi == 2){
	}
	if(biaozhi == 3){
	}
	biaozhi += 1;
	if(biaozhi == 3){
		biaozhi = 0;}
*/
void TM2_Isr() interrupt 12
{
//	static int biaozhi = 0;
//	TIM2_CLEAR_FLAG;  //����жϱ�־
//	switch(biaozhi){
//		case 0:
//			biaozhi += 1;
//		  mpu6050_get_accdata();
//			mpu6050_get_gyro();
////			caibianmaqi();
//			Angel_Calculate();
////		  test_c();
//			uart_putchar(UART_1,0xA5);
//			break;
//		case 1:
//			biaozhi += 1;
//			break;
//		case 2:
//			biaozhi += 1;
//			break;
//		case 3:
//			biaozhi = 0;
//			break;
//	}
}
void TM3_Isr() interrupt 19
{
	TIM3_CLEAR_FLAG; //����жϱ�־
	
}

void TM4_Isr() interrupt 20
{
//	static int biaozhi = 0;
//	switch(biaozhi){
//		case 0:
//			biaozhi += 1;
//			mpu6050_get_accdata();
//			mpu6050_get_gyro();
////			caibianmaqi();
//			Angel_Calculate();
//			break;
//		case 1:
//			biaozhi += 1;
//			break;
//		case 2:
//			biaozhi += 1;
//			break;
//		case 3:
//			biaozhi = 0;
//			break;
//	}
	TIM4_CLEAR_FLAG; //����жϱ�־
	ccd_collect();

}

//void  INT0_Isr()  interrupt 0;
//void  TM0_Isr()   interrupt 1;
//void  INT1_Isr()  interrupt 2;
//void  TM1_Isr()   interrupt 3;
//void  UART1_Isr() interrupt 4;
//void  ADC_Isr()   interrupt 5;
//void  LVD_Isr()   interrupt 6;
//void  PCA_Isr()   interrupt 7;
//void  UART2_Isr() interrupt 8;
//void  SPI_Isr()   interrupt 9;
//void  INT2_Isr()  interrupt 10;
//void  INT3_Isr()  interrupt 11;
//void  TM2_Isr()   interrupt 12;
//void  INT4_Isr()  interrupt 16;
//void  UART3_Isr() interrupt 17;
//void  UART4_Isr() interrupt 18;
//void  TM3_Isr()   interrupt 19;
//void  TM4_Isr()   interrupt 20;
//void  CMP_Isr()   interrupt 21;
//void  I2C_Isr()   interrupt 24;
//void  USB_Isr()   interrupt 25;
//void  PWM1_Isr()  interrupt 26;
//void  PWM2_Isr()  interrupt 27;