#include "headfile.h"

void caibianmaqi(void)
{
	
	bianmaqi_p04=(float)ctimer_count_read(CTIM3_P04);
//	bianmaqi_p06=2*(float)ctimer_count_read(CTIM4_P06);
	ctimer_count_clean(CTIM3_P04);
//	ctimer_count_clean(CTIM4_P06);
//	bianmaqi_p23=P2^3;
//	if(P4^2==0)
//	if(bianmaqi_p23==252)
//		bianmaqi_p06=-bianmaqi_p06;//每读一次都会清零
	
}


//#define p 38
//#define i 0.7
//float sudu_car=0,sudu_new=0,sudu_last=0;
//float sudu_sheding=10,sudu_error=0,sudu_ierror=0;
//float g_fsuducontrolout;
//uint8 sudu_period=1;
//void chuli_bianmaqi(void){

//	sudu_car=(bianmaqi_p04+bianmaqi_p06)/2;
//	sudu_error=(sudu_sheding-sudu_car)*0.01;
//	sudu_ierror+=sudu_error;
//	sudu_last=sudu_new;
//	
//	sudu_new=sudu_error*p+i*sudu_ierror*i;
//	if(sudu_ierror>10)sudu_ierror=10;
//	if(sudu_ierror<-10)sudu_ierror=-10;
//	if(sudu_new>40)sudu_new=40;
//	if(sudu_new<-40)sudu_new=-40;
//	sudu_period=1;//周期比为5： 1在这控制周期
//}


////chuli_sudu 和shuchu_sudu的运行周期不一样。
//void shuchu_bianmaqi(void){

//	float fvalue=0;
//	fvalue=sudu_new-sudu_last;
//	if(g_fsuducontrolout>15)fvalue=0;//shiyan
//	g_fsuducontrolout=sudu_last+sudu_period*fvalue/5;//输出的角度值
//	sudu_period+=1;
//		
//}