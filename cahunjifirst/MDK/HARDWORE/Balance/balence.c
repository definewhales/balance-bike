#include "balence.h"
#include "headfile.h"
uint16 AD[4][5] = {0};
uint16 ADOld[4] = {0};
float DianGanBiLi[4] = {0};
float DianGanGuiYi[2] = {0};
/**
ȡ����ֵ�ķ���
*/
float JueDuiZhi(float canshu){
	if(canshu < 0){
		canshu = -canshu;}
	return canshu;
	}	
//#define AngleOffset -13//+ g_fDirectionControlOut//8.65//-18.5//22�ܵ�ͣ��
//#define AngleControl_P 6.4//4.54 5.73
//#define ANgleControl_I 0.072//.09//0.00285//0.0183
//#define AngleControl_D 0.16//0.043//
/**
λ��ʽPID
�Ƕȿ��ƺ���
��ȫ�ֱ���������� -19 0.13 7.5099 0 
*/
float AngleOffset = -24.82;
float AngleControl_P = 0;
float ANgleControl_I = 0;
float AngleControl_D = 0;
void AngleControl(void){
	float jifen = 0;
	float angleoff = 0;
	float Gyro_new = (mpu_gyro_x-40)*0.088;
	static float Error = 0;//ErrorOld = 0;
	angleoff =AngleOffset - g_fDirectionControlOut;//������������뵽�Ƕ��������
	Error = Angle_z-angleoff;
	jifen +=Error;
	if(jifen > 1000){
		jifen = 1000;}
	else if(jifen < -1000){
		jifen = -1000;}
	if(Gyro_new > 200){
		 Gyro_new = 200;}
	else if(Gyro_new < -200){
		Gyro_new = -200;}
	g_fAngleControlOut = AngleControl_P*Error + ANgleControl_I*jifen + AngleControl_D*Gyro_new;	
	if(g_fAngleControlOut > 250){
		g_fAngleControlOut = 250;}
	if(g_fAngleControlOut < -250){
		g_fAngleControlOut = -250;}
}
/**
�ٶȿ��ƺ���
����ʽPID�㷨
�����ٶȻ᲻����ȶ�
*/
//#define SpeedOffset 250
//#define SpeedControl_P 7
//#define SpeedControl_I 0.5
//#define SpeedControl_D 0
float SpeedOffset = 250;
float SpeedControl_P=0.8;
float SpeedControl_I=7;
float SpeedControl_D = 0;
void SpeedControl(){
	g_fSpeedControlOutOOld = g_fSpeedControlOutOld;
	g_fSpeedControlOutOld = g_fSpeedControlOutNew;
	g_fSpeedControlOutNew = SpeedOffset - bianmaqi_p04;
	g_fSpeedControlOut = SpeedControl_P*(g_fSpeedControlOutNew - g_fSpeedControlOutOld)+SpeedControl_I*g_fSpeedControlOutNew+SpeedControl_D*(g_fSpeedControlOutNew - 2*g_fSpeedControlOutOld+g_fSpeedControlOutOOld);
	if(g_fSpeedControlOut>2000){
		g_fSpeedControlOut = 2000;}
	if(g_fSpeedControlOut<-2000){
		g_fSpeedControlOut = -2000;}
	}
/**
��������������ٶȿ��Ƶ�ʱ��ѽǶȼ���
��ת��ʱ����
*/
#define AngleSpeedHUNHE_P 6
int AngleSpeedHUNHE(float AngleBias){
	if(AngleBias<0){
		AngleBias = -AngleBias;}
	return (int)(AngleBias*AngleSpeedHUNHE_P);
	}
/**
*����һ��ͣ������
*ͨ�����Ƕȣ��鿴���Ƿ���
*/
void TingChe(){
	if(Angle_z >= 130||Angle_z <= -140){
			DisableGlobalIRQ();
			pwm_duty(PWM7_P22,5000);
		}
	}
//#define Direction_P 0
//#define Direction_I 0
//#define Direction_D 0
/**
*@���򷽷�
float DianGanBiLi[4] = {0};
float DianGanGuiYi[2] = {0};
����ƽ������
*/
float Direction_P = 0;
float Direction_I = 0;
float Direction_D = 0;
#define DIRMAX 1000.0
void DirectionControl(){
	//PIDҪ��
	static float Error = 0;
	static float ErrorOld = 0;
	//ƽ��������
	static float DirConError = 0;
	DianGanBiLi[0] = LeftCol_1/DIRMAX;
	DianGanBiLi[1] = LeftCol_2/DIRMAX;
	DianGanBiLi[2] = RightCol_2/DIRMAX;
	DianGanBiLi[3] = RightCol_1/DIRMAX;
	if(DianGanBiLi[0] != 0&&DianGanBiLi[3] != 0){
		DianGanGuiYi[0] = (DianGanBiLi[0]-DianGanBiLi[3])/(DianGanBiLi[0]+DianGanBiLi[3]);}
	ErrorOld = Error;
	Error = DianGanGuiYi[0];
	g_fDirectionControlOutOld = g_fDirectionControlOutNew;
	g_fDirectionControlOutNew = Direction_P*Error + Direction_D*(Error - ErrorOld);
	DirConError = g_fDirectionControlOutNew - g_fDirectionControlOutOld;
//��ÿ�εı仯���޷�
//	if(DirConError>10){
//		DirConError = 10;}
//	if(DirConError<-10){
//		DirConError = -10;}
	g_fDirectionControlOut = DirConError + g_fDirectionControlOutOld;
//����������޷�
	if(g_fDirectionControlOut >turn_xianfu){
		g_fDirectionControlOut = turn_xianfu;}
	if(g_fDirectionControlOut<-turn_xianfu){
		g_fDirectionControlOut = -turn_xianfu;}
}
/**
*����˲�
*ģ����һ�����
*/
void InductanceFilter(){
	int ADMin[4] = {0};
	int ADMax[4] = {0};
	static unsigned long AdOld[4]; 
	uint32 ADSum[4] = {0};
	uint32 DianGan[4] = {0};
	int AdcCount = 0;
	int AdcColleteTimes = 0;
	//�ɼ����ֵ
	for(AdcColleteTimes = 0;AdcColleteTimes<3;AdcColleteTimes++){
		AdOld[AdcColleteTimes] = DianGan[AdcColleteTimes];
	for(AdcColleteTimes = 0;AdcColleteTimes<5;AdcColleteTimes++){
		AD[0][AdcColleteTimes] = adc_once(ADC_P15,ADC_10BIT);
		AD[1][AdcColleteTimes] = adc_once(ADC_P10,ADC_10BIT);
		AD[2][AdcColleteTimes] = adc_once(ADC_P14,ADC_10BIT);
		AD[3][AdcColleteTimes] = adc_once(ADC_P11,ADC_10BIT);
	}
	//�������Сֵ
	for(AdcColleteTimes = 0;AdcColleteTimes<5;AdcColleteTimes++){
		if(AD[0][AdcColleteTimes] < AD[0][ADMin[0]])
    {
      ADMin[0] = AdcColleteTimes;
    }
    if(AD[1][AdcColleteTimes] < AD[1][ADMin[1]])
    {
      ADMin[1] = AdcColleteTimes;
    }
    if(AD[2][AdcColleteTimes] < AD[2][ADMin[2]])
    {
      ADMin[2] = AdcColleteTimes;
    }
    if(AD[3][AdcColleteTimes] < AD[3][ADMin[3]])
    {
      ADMin[3] = AdcColleteTimes;
    }
	}
	for(AdcColleteTimes = 0;AdcColleteTimes<5;AdcColleteTimes++){
		if(AD[0][AdcColleteTimes] > AD[0][ADMax[0]])
    {
      ADMax[0] = AdcColleteTimes;
    }
    if(AD[1][AdcColleteTimes] > AD[1][ADMax[1]])
    {
      ADMax[1] = AdcColleteTimes;
    }
    if(AD[2][AdcColleteTimes] > AD[2][ADMax[2]])
    {
      ADMax[2] = AdcColleteTimes;
    }
    if(AD[3][AdcColleteTimes] > AD[3][ADMax[3]])
    {
      ADMax[3] = AdcColleteTimes;
    }
	}
	for(AdcCount = 0;AdcCount<4;AdcCount++){
		ADOld[AdcCount] = AD[AdcCount][ADMax[AdcCount]];
	}
	//�������Сֵ��0
	for(AdcCount = 0;AdcCount<4;AdcCount++){
		AD[AdcCount][ADMin[AdcCount]] = 0;
		AD[AdcCount][ADMax[AdcCount]] = 0;
}
	//���
for(AdcColleteTimes = 0;AdcColleteTimes<5;AdcColleteTimes++){
	ADSum[0] += (uint32)AD[0][AdcColleteTimes];
	ADSum[1] += (uint32)AD[1][AdcColleteTimes];
	ADSum[2] += (uint32)AD[2][AdcColleteTimes];
	ADSum[3] += (uint32)AD[3][AdcColleteTimes];
}
//ƽ��
DianGan[0] = ADSum[0]/3.0;
DianGan[1] = ADSum[1]/3.0;
DianGan[2] = ADSum[2]/3.0;
DianGan[3] = ADSum[3]/3.0;
if (DianGan[0]>=1024)DianGan[0]=1024;
if (DianGan[1]>=1024)DianGan[1]=1024;
if (DianGan[2]>=1024)DianGan[2]=1024;
if (DianGan[3]>=1024)DianGan[3]=1024;
//if(DianGan[0]<=200)DianGan[0] = 200;
//if(DianGan[1]<=200)DianGan[1] = 200;
//if(DianGan[2]<=200)DianGan[2] = 200;
//if(DianGan[3]<=200)DianGan[3] = 200;
}
LeftCol_1 = DianGan[0];
LeftCol_2 = DianGan[1];
RightCol_2 = DianGan[2];
RightCol_1 = DianGan[3];
}

/**
@���ٶ��������
@���ڻ����
@PD���ڡ���Ӧ�ٶ�
*/
//#define GYROCON_P 0
//#define GYROCON_I 0
//#define GYROCON_D 0
float GyroCon_P = 0;
float GyroCon_I = 0;
float GyroCon_D = 0;
void gyroConOut(){
	static float Error = 0;
	static float ErrorOld = 0;
	static float Integral = 0;
	get_icm20602_gyro_simiic();
	ErrorOld = Error;
	Error = g_fDirectionControlOut - icm_gyro_x*0.0610;//��ʼ��20602gyroΪ2000��4000/2^16 = 0.0610
	Integral += Error;
	GyroConOutput = GyroCon_P * Error + GyroCon_I * Integral + GyroCon_D*(Error - ErrorOld);
	//�Զ��������޷�
	if(GyroConOutput > 300){
		GyroConOutput = 300;
	}
	if(GyroConOutput < -300){
		GyroConOutput = -300;
	}
}