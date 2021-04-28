#ifndef _OLED_H_
#define _OLED_H_

	#define shang P13
	#define xia   P41
	#define zuo   P21
	#define you   P40
extern float 	GyroCon_P;
extern float 	GyroCon_D;
extern float a1,b1,c1,d1,e1,f1,g1,h1,i1,j1;
	#define  angle_offset   AngleOffset
	#define  bal_d          AngleControl_D
	#define  bal_p          AngleControl_P
	#define  bal_i          ANgleControl_I

	#define tu_i            Direction_I
	#define tu_p            Direction_P
	#define tu_d            Direction_D
	#define tu_xianfu       turn_xianfu
	
	#define spe_set         SpeedOffset
	#define spe_p           SpeedControl_P
	#define spe_i           SpeedControl_I
 
	#define gy_p	GyroCon_P
	#define gy_d  GyroCon_D

	void delay(int i);
	void caidan();
	
	void balance();
	void turn();
	void speed();
	
	void balance_a();
	void balance_g();
	void balance_p();
	void balance_i();
	
	void turn_off();
	void turn_p();
	void turn_d();
	
	void speed_set();
	void speed_p();
	void speed_i();
	
	void fun1();
	void fun2();
	void fun3();
	void fun4();
	void fun5();
	void fun6();
	void fun7();
	void fun8();
	void fun9();
	void fun10();
	void fun11();
	
void writedata();

#endif