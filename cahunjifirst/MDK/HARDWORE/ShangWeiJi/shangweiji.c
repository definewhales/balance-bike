#include "shangweiji.h"
extern float gyro_new;
extern float jifen;
extern uint16 ADOld[4];
void test_c(void)
{
		float test[6]={0};
		//mpu6050_get_accdata();
		//mpu6050_get_gyro();
		test[0]=GyroConOutput;
		test[1]=bianmaqi_p04;
		test[2]=icm_gyro_x;
		test[3]=icm_acc_z;
		test[4]=Angle_z;
		test[5]=Angle_z_before;
		vcan_sendware(UART_1, test,sizeof(test));
//		pca_delay_ms(10);
		delay_ms(10);
}


void vcan_sendware(UARTN_enum uart_n, void *wareaddr, uint32 waresize)
{	
		#define CMD_WARE 3

		uint8 cmdf[2] = {CMD_WARE, ~CMD_WARE};

		//串口调试使用的前命令

		uint8 cmdr[2] = {~CMD_WARE, CMD_WARE};


		uart_putbuff1(uart_n,cmdr,sizeof(cmdf)); //先发送前命令
		uart_putbuff1(uart_n,(uint8*)wareaddr, waresize); //发送数据
		uart_putbuff1(uart_n,cmdf, sizeof(cmdr));
}


void uart_putbuff1(UARTN_enum uart_n,uint8 *buff,uint16 len)
{
	buff=buff+len-1;
	while(len--)
	{
		uart_putchar(uart_n,*buff);
		buff--;
	}
}
