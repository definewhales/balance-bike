/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2020,逐飞科技
 * All rights reserved.
 * 技术讨论QQ群：一群：179029047(已满)  二群：244861897(已满)  三群：824575535
 *
 * 以下所有内容版权均属逐飞科技所有，未经允许不得用于商业用途，
 * 欢迎各位使用并传播本程序，修改内容时必须保留逐飞科技的版权声明。
 *
 * @file       		main
 * @company	   		成都逐飞科技有限公司
 * @author     		逐飞科技(QQ790875685)
 * @version    		查看doc内version文件 版本说明
 * @Software 		MDK FOR C51 V9.60
 * @Target core		STC8H8K64S4
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2020-06-01
 ********************************************************************************************************************/

#include "headfile.h"
#include "oled.h"
float dueeprom(unsigned int addr);

float a1 = 1,b1 = 2,c1 = 3,d1 = 4,e1 = 5,f1 = 6,g1 = 7,h1 = 8,i1 = 9,j1 = 10;
//board.h文件中FOSC的值设置为0,则程序自动识别系统频率

/*board.h文件中FOSC的值设置不为0，则系统频率为FOSC的值，
在使用stc-isp工具下载程序的时候需要将IRC频率设置为FOSC的值*/

/*在board_init中,已经将P54引脚设置为复位
如果需要使用P54引脚,可以在board.c文件中的board_init()函数中删除SET_P54_RESRT即可*/

void main()
{
	char ab;
	DisableGlobalIRQ();	//关闭总中断
	board_init();		//里面有串口一得初始化
	pwm_init(PWM7_P22,10000,5000);				//两路PWM初始化，电机
	pwm_init(PWM4N_P27,100,1330);					//舵机//中值1150
	simiic_init();	//软件IIC
	icm20602_init_simiic();	//IIC20602
	adc_init(ADC_P10,ADC_SYSclk_DIV_4);     //两路ADC，用于采集电感值
	adc_init(ADC_P15,ADC_SYSclk_DIV_4);			//始终SYM/4
	adc_init(ADC_P11,ADC_SYSclk_DIV_4);
	adc_init(ADC_P14,ADC_SYSclk_DIV_4);
/**
	舵机100hz，中值为1250
	数值减小右转，增大左转
*/
	ctimer_count_init(CTIM3_P04);					//用于编码器的读取
	pit_timer_ms(TIM_0,2);							//定时器中断2ms
	iap_init();			//初始化EEPROM
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
	EnableGlobalIRQ();	//开启总中断
    while(1)
	{
		TingChe();//停车检测	
		if(P16 == 0)//菜单入口
		{
			DisableGlobalIRQ();	//关闭总中断
				while(P16 == 0){
					caidan();
			}
					EnableGlobalIRQ();
		}
		test_c();		//上位机
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
