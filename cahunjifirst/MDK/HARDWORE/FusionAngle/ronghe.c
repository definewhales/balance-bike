
#include "data.h"
#include "headfile.h"
#include "math.h"
/**
6050融合
mpu_acc_z用z轴数据
mpu_gyro_x用X轴数据
*/
//#define TIME 1
//#define GYRO_INTERAL_P 0.01 //采样时间
//#define GYRO_P  0.65//此数值为gyro的信任度
//float acc_offset_z=-100;
//float gyro_offset_x=40;
//float f_Car_Angle_d = 0;
//float gyro_old = 0;
//float gyro_new = 0;
//float Angle_z_before = 0;
//float Angle_z = 0;
//void Angel_Calculate(){
//	//角速度处理部分
//	gyro_old = gyro_new;
//	gyro_new = mpu_gyro_x-gyro_offset_x;
//	gyro_new = (gyro_new*0.3+gyro_old*0.7)*GYRO_P;
//	//加速度处理部分
//	Angle_z_before = (mpu_acc_z-acc_offset_z)*0.088;//可以增加这个数值增加跟随度
//	Angle_z = g_f_Car_Angle_I;	
//	f_Car_Angle_d = (Angle_z_before-Angle_z)/TIME;
//	g_f_Car_Angle_I += (gyro_new+f_Car_Angle_d)*GYRO_INTERAL_P;
//}

/**
角度融合方法
ICM20602
用z轴数据icm_acc_z
用X轴数据icm_gyro_x
*/
#define TIME 1
#define GYRO_INTERAL_P 0.004 //采样时间
#define GYRO_P  0.65//此数值为gyro的信任度
float acc_offset_z=88;
float gyro_offset_x=30;
float f_Car_Angle_d = 0;
float gyro_old = 0;
float gyro_new = 0;
float Angle_z_before = 0;
float Angle_z = 0;
void Angel_Calculate(){
	//角速度处理部分
	gyro_old = gyro_new;
	gyro_new = icm_gyro_x-gyro_offset_x;
	gyro_new = (gyro_new*0.3+gyro_old*0.7)*GYRO_P;
	//加速度处理部分
	Angle_z_before = (icm_acc_z-acc_offset_z)*0.089;//可以增加这个数值增加跟随度
	Angle_z = g_f_Car_Angle_I;	
	f_Car_Angle_d = (Angle_z_before-Angle_z)/TIME;
	g_f_Car_Angle_I += (gyro_new+f_Car_Angle_d)*GYRO_INTERAL_P;
}

//void Cascade_pid(){
//	static float Stage = 0,StageOld = 0,StageLV = 0;
//	static float gf_Car_Anglespeed_Old = 0,
//								gyro_x = 0,gf_Car_Anglespeed_New = 0;
//	float fvalue;
//	anglecontroloutput();
//	gf_Car_Anglespeed_Old = gf_Car_Anglespeed_New;
//	gyro_x = get_gyro_x()-GyroOffset[0];
//	if(fabs(gyro_x<5)gyro_x = 0;
//	gf_Car_Anglespeed_New = gyro_x*0.377 + gf_Car_Anglespeed_Old*0.623;
//	StageOld = Stage;
//	Stage = gf_Car_Anglespeed_New - gf_Car_Anglespeed_Old;
//	StageLV = 0.623*StageOld  + 0.377*Stage;
//	fValue = -BalanceOut+gf_Car_Anglespeed_New*0.1*S_AGLE_CONTROL_P+StageLV*S_ANGLE_CONTROL_D;
//	KP1 = -BalanceOut;
//	KD1 = gf_Car_Anglespeed_New*S_AGLE_CONTROL_P;
//	Ca_Value = fValue;
//	if(Ca_Value>gf_Car_Anglespeed_New*S_AGLE_CONTRO_OUT_MAX){
//		Ca_Value = S_AGLE_CONTRO_OUT_MAX;
//	}
//	if(Ca_Value<S_AGLE_CONTRO_OUT_MIN){
//		Ca_Value = S_AGLE_CONTRO_OUT_MIN;
//	}
//}



//void balance(void){
//	static float error = 0,errorold = 0;
//	BalanceOutOld = BalanceOutNew;
//	errorold = error;
//	error = Angle_Z - CAR_ANGLE_SET/**0.01*/;
//	if(error<-35)error = -35;
//	if(error>15)error = 15;
//	BalanceOutNew = ANGLE_CONTROL_P*error;
//	BalanceControlPeriod = 0;
//}



//void anglecontroloutput(void)
//{
//	float fValue  = 0;
//	fValue = BalanceOutNew - BalanceOutOld;
//	BalanceOut = fValue*(BalanceControlPeriod + 1)/5+BalanceOutOld;
//	BalanceControlPeriod+=1;
//}

/**
*@获得翻滚角度
*@用于平衡的D
*/
//#define KI 0.05    //对加速度计取值的权重
//#define DT 0.01		//采样时间
//float angle_ax = 0;
//float gyro_gy = 0;
//void fanGunAngle(){
//	angle_ax = atan(mpu_acc_y/mpu_acc_z)*57.3;
//	gyro_gy = mpu_gyro_x/7150.0;
//	roll = KI*angle_ax + (1-KI)*(roll + gyro_gy*DT);
//}

	
	
	
