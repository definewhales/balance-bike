#include "headfile.h"


float left_1,left_2,right_3,right_4;
float shuchu;
void diangan(void){
//  left_11[0]=adc_once(ADC_P10,ADC_10BIT);
//	left_11[1]=adc_once(ADC_P10,ADC_10BIT);
//	left_11[2]=adc_once(ADC_P10,ADC_10BIT);
//	left_11[3]=adc_once(ADC_P10,ADC_10BIT);
//	left_1=(left_11[0]+left_11[1]+left_11[2]+left_11[3])/4;
//	left_22[0]=adc_once(ADC_P11,ADC_10BIT);
//	left_22[1]=adc_once(ADC_P11,ADC_10BIT);
//	left_22[2]=adc_once(ADC_P11,ADC_10BIT);
//	left_22[3]=adc_once(ADC_P11,ADC_10BIT);
//	left_2=(left_22[0]+left_22[1]+left_22[2]+left_22[3])/4;
//	right_33[0]=adc_once(ADC_P14,ADC_10BIT);
//	right_33[1]=adc_once(ADC_P14,ADC_10BIT);
//	right_33[2]=adc_once(ADC_P14,ADC_10BIT);
//	right_33[3]=adc_once(ADC_P14,ADC_10BIT);
//	right_3=(right_33[0]+right_33[1]+right_33[2]+right_33[3])/4;
//	right_44[0]=adc_once(ADC_P15,ADC_10BIT);
//	right_44[1]=adc_once(ADC_P15,ADC_10BIT);
//	right_44[2]=adc_once(ADC_P15,ADC_10BIT);
//	right_44[3]=adc_once(ADC_P15,ADC_10BIT);
//	right_4=(right_44[0]+right_44[1]+right_44[2]+right_44[3])/4;
	
	
//	if(left_1+right_4!=0)
//		shuchu=(left_1-right_4)/(left_1+right_4);
	
	left_1=adc_once(ADC_P10,ADC_10BIT);
	right_4=adc_once(ADC_P15,ADC_10BIT);
	
}



#define left_1_max 1024
#define right_4_max 1024
#define p 960//960
#define d 0
//pd控制35
float shuchu_diangan=0;
uint8 diangan_period=1;
float diangan_guiyi,diangan_new=0,diangan_last=0;

void chuli_diangan(){

	left_1=left_1/left_1_max;
	right_4=right_4/right_4_max;
	if((left_1!=0)&&(right_4!=0)) diangan_guiyi=(left_1-right_4)/(left_1+right_4);
	diangan_last=diangan_new;
	mpu6050_get_gyro();
	diangan_new=p*diangan_guiyi-d*(mpu_gyro_x+485)*0.00305;
	diangan_period=1;//周期比2： 1
	}

void diangan_shuchu(void){
	
	float fvalue=0;
	fvalue=diangan_new-diangan_last;
	shuchu_diangan=diangan_last+diangan_period*diangan_period*fvalue/2;
	
	diangan_period+=1;
}