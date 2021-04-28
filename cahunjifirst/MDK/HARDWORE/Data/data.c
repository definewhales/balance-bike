#include "data.h"
/**
数据存储
*/

	

	float g_fSpeedControlNow = 5000;    //改变的占空比，已用
	float g_fSpeedControlOutNew = 0;	
	float g_fSpeedControlOutOld = 0;
	float g_fSpeedControlOutOOld = 0;
	float g_fSpeedControlIntegral = 0;
	float g_fSpeedControlOut = 0;


	float g_fDirectionControlNow = 0;
	float g_fDirectionControlOutNew = 0;
	float g_fDirectionControlOutOld = 0;
	float g_fDirectionControlOutOOld = 0;
	float g_fDirectionControlOut = 0;
	unsigned long LeftCol_1 = 0;
	unsigned long LeftCol_2 = 0;
	unsigned long RightCol_1 = 0;
	unsigned long RightCol_2 = 0;

	float g_fAngleControlNow = 0;
	float g_fAngleControlOutNew = 0;
	float g_fAngleControlOutOld = 0;
	float g_fAngleControlOutOOld = 0;
	float g_fAngleControlOut = 0;
	float g_fLeftMotorOut = 0;
	float g_f_Car_Angle_I = 0;
	float g_fRightMotorOut = 0;
	float g_fCarAngle = 0;
	float g_fGyroscopeAngleIntegral = 0;
	float mpu_acc_xdeal = 0;
	float mpu_gyro_xdeal = 0;
  float bianmaqi_p04 = 0;
	float turn_xianfu = 19;
	
	
	float roll  = 0;
	
	float GyroConOutput = 0;