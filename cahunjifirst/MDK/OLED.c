#include "headfile.h"
#include "OLED.h"


	
//balance gyrooffset
//turn turn p
//speed speed set
int value = 1;

struct xulie{
	
	char bianhao1;
	char up;
	char down;
	char left;
	char right;
	void (*fun)();
};


void delay(int i)
{
	while(i--);
}	

void balance()//显示  balance o   /   turn   /    speed
{
	
	oled_p6x8str(0,0,"balance  o");//显示字符串
	oled_p6x8str(0,1,"turn");
	oled_p6x8str(0,2,"speed");
	oled_p6x8str(0,3,"gyro");
//	oled_uint16(uint8 x, uint8 y, uint16 num);//显示 数字最高到94
}

void turn()//显示  balance    /   turn  o /    speed
{
	oled_p6x8str(0,0,"balance");//显示字符串
	oled_p6x8str(0,1,"turn     o");
	oled_p6x8str(0,2,"speed");
	oled_p6x8str(0,3,"gyro");
}

void speed()//显示  balance    /   turn   /    speed o
{
	oled_p6x8str(0,0,"balance");//显示字符串
	oled_p6x8str(0,1,"turn");
	oled_p6x8str(0,2,"speed    o");
	oled_p6x8str(0,3,"gyro");
}


void gyro(){
	oled_p6x8str(0,0,"balance");//显示字符串
	oled_p6x8str(0,1,"turn");
	oled_p6x8str(0,2,"speed");
	oled_p6x8str(0,3,"gyro   o");
}

void gyro_p(){
	oled_p6x8str(0,0,"gyro_p  o");
	oled_p6x8str(0,1,"gyro_d");
}

void gyro_d(){
	oled_p6x8str(0,0,"gyro_p");
	oled_p6x8str(0,1,"gyro_d   o");
}


void balance_a()
{
	oled_p6x8str(0,0,"angle offset  o");//显示字符串
	oled_p6x8str(0,1,"balance_d");
	oled_p6x8str(0,2,"balance_p"); 
  oled_p6x8str(0,3,"balance_i"); 
}

void balance_g()
{
	oled_p6x8str(0,0,"angle offset");//显示字符串
	oled_p6x8str(0,1,"balance_d    o");
	oled_p6x8str(0,2,"balance_p"); 
  oled_p6x8str(0,3,"balance_i"); 
}

void balance_p()
{
	oled_p6x8str(0,0,"angle offset");//显示字符串
	oled_p6x8str(0,1,"balance_d");
	oled_p6x8str(0,2,"balance_p     o"); 
  oled_p6x8str(0,3,"balance_i"); 
}

void balance_i()
{
	oled_p6x8str(0,0,"angle offset");//显示字符串
	oled_p6x8str(0,1,"balance_d");
	oled_p6x8str(0,2,"balance_p"); 
  oled_p6x8str(0,3,"balance_i     o");  
}


void turn_off()
{
	oled_p6x8str(0,0,"turn_i        o");//显示字符串
	oled_p6x8str(0,1,"turn_p");
	oled_p6x8str(0,2,"turn_d"); 
	oled_p6x8str(0,3,"tu_xianfu"); 
}

void turn_p()
{
	oled_p6x8str(0,0,"turn_i");//显示字符串
	oled_p6x8str(0,1,"turn_p        o");
	oled_p6x8str(0,2,"turn_d"); 
	oled_p6x8str(0,3,"tu_xianfu"); 
}

void turn_d()
{
	oled_p6x8str(0,0,"turn_i");//显示字符串
	oled_p6x8str(0,1,"turn_p");
	oled_p6x8str(0,2,"turn_d        o"); 
	oled_p6x8str(0,3,"tu_xianfu"); 
}

void xianfu(){
	oled_p6x8str(0,0,"turn_i");//显示字符串
	oled_p6x8str(0,1,"turn_p");
	oled_p6x8str(0,2,"turn_d"); 
	oled_p6x8str(0,3,"tu_xianfu     o");


}



void speed_set()
{
	oled_p6x8str(0,0,"speed set   o");//显示字符串
	oled_p6x8str(0,1,"speed_p");
	oled_p6x8str(0,2,"speed_i"); 
}	

void speed_p()
{
	oled_p6x8str(0,0,"speed set");//显示字符串
	oled_p6x8str(0,1,"speed_p     o");
	oled_p6x8str(0,2,"speed_i"); 
}

void speed_i()
{
	oled_p6x8str(0,0,"speed set");//显示字符串
	oled_p6x8str(0,1,"speed_p");
	oled_p6x8str(0,2,"speed_i     o"); 
}





void fun1()
{
	oled_fill(0x00);//清屏
	oled_printf_float(0,0,angle_offset,5,4);
	while(1)
	{
		if( (shang == 0)||(xia == 0)||(zuo == 0)||(you == 0) )
		{
			delay(1000);
			if(shang == 0) 
			{
				angle_offset += 0.1;
			}
			if(xia == 0)
			{
				angle_offset -= 0.1;
			}
			if(you == 0)
			{
				angle_offset += 0.01;
			}
			if(zuo == 0)
			{
				while(zuo == 0);
				break;
			}
		}
		oled_printf_float(0,0,angle_offset,5,4);
		delay(65535);delay(65535);
	}
	writedata();
	value = 4;
	balance_a();
}




void fun2()
{
	oled_fill(0x00);
	oled_printf_float(0,0,AngleControl_D,5,4);
	
	while(1)
	{
	
		if( (shang == 0)||(xia == 0)||(zuo == 0)||(you == 0) )
		{
			delay(1000);
			if(shang == 0) 
			{
				AngleControl_D += 0.1;
			}
			if(xia == 0)
			{
				AngleControl_D -= 0.01;
			}
			if(you == 0)
			{
				AngleControl_D += 0.001;
			}
			if(zuo == 0)
			{
				while(zuo == 0);
				break;
			}
			
		}
		oled_printf_float(0,0,AngleControl_D,5,4);
		delay(65535);delay(65535);
		
	}
	
	writedata();
	
	value = 4;
	balance_a();
}

void fun3()
{
	oled_fill(0x00);
	oled_printf_float(0,0,bal_p,5,4);
	
	while(1)
	{
	
		if( (shang == 0)||(xia == 0)||(zuo == 0)||(you == 0) )
		{
			delay(1000);
			if(shang == 0) 
			{
				bal_p += 0.1;
			}
			if(xia == 0)
			{
				bal_p -= 0.1;
			}
			if(you == 0)
			{
				bal_p += 0.01;
			}
			if(zuo == 0)
			{
				while(zuo == 0);
				break;
			}
		}
		oled_printf_float(0,0,bal_p,5,4);
		delay(65535);delay(65535);
	}
	
		writedata();
	
	value = 4;
	balance_a();
}

void fun4()
{
	oled_fill(0x00);
	oled_printf_float(0,0,bal_i,5,4);
	
	while(1)
	{
	
		if( (shang == 0)||(xia == 0)||(zuo == 0)||(you == 0) )
		{
			delay(1000);
			if(shang == 0) 
			{
				bal_i += 0.01;
			}
			if(xia == 0)
			{
				bal_i -= 0.01;
			}
			if(you == 0)
			{
				bal_i += 0.001;
			}
			if(zuo == 0)
			{
				while(zuo == 0);
				break;
			}
			
		}
		oled_printf_float(0,0,bal_i,5,4);
		delay(65535);
		delay(65535);
	}
	
		writedata();
	
	value = 4;
	balance_a();
}

void fun5()
{
	oled_fill(0x00);
	oled_printf_float(0,0,tu_i,5,4);
	
	while(1)
	{
	
		if( (shang == 0)||(xia == 0)||(zuo == 0)||(you == 0) )
		{
			delay(1000);
			if(shang == 0) 
			{
				tu_i += 0.1;
			}
			if(xia == 0)
			{
				tu_i -= 0.1;
			}
			if(you == 0)
			{
				tu_i += 0.01;
			}
			if(zuo == 0)
			{
				while(zuo == 0);
				break;
			}
			oled_printf_float(0,0,tu_i,5,4);
			delay(65535);delay(65535);
		}
		
	}
	
	value = 8;
	turn_off();
}

void fun6()
{
	oled_fill(0x00);
	oled_printf_float(0,0,tu_p,5,4);
	
	while(1)
	{
	
		if( (shang == 0)||(xia == 0)||(zuo == 0)||(you == 0) )
		{
			delay(1000);
			if(shang == 0) 
			{
				tu_p += 0.1;
			}
			if(xia == 0)
			{
				tu_p -= 0.1;
			}
			if(you == 0)
			{
				tu_p += 0.01;
			}
			if(zuo == 0)
			{
				while(zuo == 0);
				break;
			}
			oled_printf_float(0,0,tu_p,5,4);
			delay(65535);delay(65535);
		}
		
	}
	
		writedata();
	
	value = 8;
	turn_off();
}

void fun7()
{
	oled_fill(0x00);
	oled_printf_float(0,0,tu_d,5,4);
	
	while(1)
	{
	
		if( (shang == 0)||(xia == 0)||(zuo == 0)||(you == 0) )
		{
			delay(1000);
			if(shang == 0) 
			{
				tu_d += 0.1;
			}
			if(xia == 0)
			{
				tu_d -= 0.01;
			}
			if(you == 0)
			{
				tu_d += 0.001;
			}
			if(zuo == 0)
			{
				while(zuo == 0);
				break;
			}
			
		}
		oled_printf_float(0,0,tu_d,5,4);
			delay(65535);delay(65535);
	}
	
		writedata();
	
	value = 8;
	turn_off();
}

void fun8()
{
	oled_fill(0x00);
	oled_printf_float(0,0,spe_set,5,4);
	
	while(1)
	{
	
		if( (shang == 0)||(xia == 0)||(zuo == 0)||(you == 0) )
		{
			delay(1000);
			if(shang == 0) 
			{
				spe_set += 1;
			}
			if(xia == 0)
			{
				spe_set -= 1;
			}
			if(you == 0)
			{
				spe_set += 10;
			}
			if(zuo == 0)
			{
				while(zuo == 0);
				break;
			}
		}
		oled_printf_float(0,0,spe_set,5,4);
		delay(65535);delay(65535);
	}
	
		writedata();
	
	value = 11;
	speed_set();
}

void fun9()
{
	oled_fill(0x00);
	oled_printf_float(0,0,spe_p,5,4);
	
	while(1)
	{
	
		if( (shang == 0)||(xia == 0)||(zuo == 0)||(you == 0) )
		{
			delay(1000);
			if(shang == 0) 
			{
				spe_p += 0.1;
			}
			if(xia == 0)
			{
				spe_p -= 0.1;
			}
			if(you == 0)
			{
				spe_p += 0.01;
			}
			if(zuo == 0)
			{
				while(zuo == 0);
				break;
			}
		}
		oled_printf_float(0,0,spe_p,5,4);
		delay(65535);delay(65535);
	}
	
		writedata();
	
	value = 11;
	speed_set();
}

void fun10()
{
	oled_fill(0x00);
	oled_printf_float(0,0,spe_i,5,4);
	
	while(1)
	{
	
		if( (shang == 0)||(xia == 0)||(zuo == 0)||(you == 0) )
		{
			delay(1000);
			if(shang == 0) 
			{
				spe_i += 0.1;
			}
			if(xia == 0)
			{
				spe_i -= 0.1;
			}
			if(you == 0)
			{
				spe_i += 0.01;
			}
			if(zuo == 0)
			{
				while(zuo == 0);
				break;
			}
		}
		oled_printf_float(0,0,spe_i,5,4);
		delay(65535);delay(65535);
	}
	
		writedata();
	
	value = 11;
	speed_set();
}

void fun11()
{
	oled_fill(0x00);
	oled_printf_float(0,0,tu_xianfu,5,4);
	
	while(1)
	{
	
		if( (shang == 0)||(xia == 0)||(zuo == 0)||(you == 0) )
		{
			delay(1000);
			if(shang == 0) 
			{
				tu_xianfu += 0.1;
			}
			if(xia == 0)
			{
				tu_xianfu -= 0.1;
			}
			if(you == 0)
			{
				tu_xianfu += 0.01;
			}
			if(zuo == 0)
			{
				while(zuo == 0);
				break;
			}
		}
		oled_printf_float(0,0,tu_xianfu,5,4);
		delay(65535);delay(65535);
	}
	
		writedata();
	
  value = 8;
	turn_off();
}

void fun12(){
	oled_fill(0x00);
	oled_printf_float(0,0,gy_p,5,4);
	
	while(1)
	{
	
		if( (shang == 0)||(xia == 0)||(zuo == 0)||(you == 0) )
		{
			delay(1000);
			if(shang == 0) 
			{
				gy_p += 0.1;
			}
			if(xia == 0)
			{
				gy_p -= 0.1;
			}
			if(you == 0)
			{
				gy_p += 0.01;
			}
			if(zuo == 0)
			{
				while(zuo == 0);
				break;
			}
		}
		oled_printf_float(0,0,gy_p,5,4);
		delay(65535);delay(65535);
	}
	
		writedata();
	
  value = 27;
	gyro_p();
}

void fun13(){
	oled_fill(0x00);
	oled_printf_float(0,0,gy_d,5,4);
	
	while(1)
	{
	
		if( (shang == 0)||(xia == 0)||(zuo == 0)||(you == 0) )
		{
			delay(1000);
			if(shang == 0) 
			{
				gy_d += 0.1;
			}
			if(xia == 0)
			{
				gy_d -= 0.1;
			}
			if(you == 0)
			{
				gy_d += 0.01;
			}
			if(zuo == 0)
			{
				while(zuo == 0);
				break;
			}
		}
		oled_printf_float(0,0,gy_d,5,4);
		delay(65535);delay(65535);
	}
	
		writedata();
	
  value = 28;
	gyro_d();
}
struct xulie menu[]  = { 
												 {0,0,0,0,0,0},
												 {1,26,2,1,4,&balance},						 //balance            0
												 {2,1,3,2,8,&turn},								 //turn               1
												 {3,2,26,3,11,&speed},							 // speed             2
						 
												 {4,7,5,1,14,&balance_a},          //angle offset     3 
												 {5,4,6,1,15,&balance_g},           //gyro offset      4 
												 {6,5,7,1,16,&balance_p},  				 //参数 p           5
												 {7,6,4,1,17,&balance_i},  				 //参数 i           6
												
												 {8,25,9,2,18,&turn_off}, 				   //duoji offset       7
												 {9,8,10,2,19,&turn_p},   				   //参数 p             8
											 	 {10,9,25,2,20,&turn_d},   				   //参数 d             9
												
												 {11,13,12,3,21,&speed_set}, 			 //speed set       10
												 {12,11,13,3,22,&speed_p},   			 //参数 p          11
												 {13,12,11,3,23,&speed_i},   			 //参数 i          12 
												 
												 {14,0,0,0,0,&fun1},//直立相关参数调节
												 {15,0,0,0,0,&fun2},
												 {16,0,0,0,0,&fun3},	
												 {17,0,0,0,0,&fun4},
												 
												 {18,0,0,0,0,&fun5},//转向相关参数调节
												 {19,0,0,0,0,&fun6},
												 {20,0,0,0,0,&fun7},
												 
												 {21,0,0,0,0,&fun8},//速度相关参数调节
												 {22,0,0,0,0,&fun9},
												 {23,0,0,0,0,&fun10},
												 {24,0,0,0,0,&fun11},
												 {25,10,8,3,24,&xianfu},
												 
												 
												 {26,3,1,26,27,&gyro},//gyro角速度调节相关
												 {27,28,28,26,29,&gyro_p},
												 {28,27,27,26,30,&gyro_d},
												 {29,0,0,0,0,&fun12},
												 {30,0,0,0,0,&fun13},
																																						};
																																																




void caidan()
{
	void (*p)();// = menu[1].fun;
	if( (shang == 0)||(xia == 0)||(zuo == 0)||(you == 0))
	{
		delay(1000);
		if(shang == 0) 
		{
			value = menu[value].up;
			while(!shang);
		}
		if(xia == 0)
		{
			value = menu[value].down;
			while(!xia);
		}
		if(zuo == 0)
		{
			value = menu[value].left;
			while(!zuo);
		}
		if(you == 0)
		{
			value = menu[value].right;
			while(!you);
		}
	
		oled_fill(0x00);
		p=menu[value].fun;
		(*p)();
	}
}


void writedata()
{
	iap_erase_page(0x50);
	iap_write_bytes(0x00,(char*)&angle_offset,4);
	iap_write_bytes(0x04,(char*)&AngleControl_D,4);
	iap_write_bytes(0x08,(char*)&bal_p,4);
	iap_write_bytes(0x0c,(char*)&bal_i,4);
	iap_write_bytes(0x10,(char*)&tu_i,4);
	iap_write_bytes(0x14,(char*)&tu_p,4);
	iap_write_bytes(0x18,(char*)&tu_d,4);
	iap_write_bytes(0x1c,(char*)&spe_set,4);
	iap_write_bytes(0x20,(char*)&spe_p,4);
	iap_write_bytes(0x24,(char*)&spe_i,4);
	iap_write_bytes(0x28,(char*)&tu_xianfu,4);
	iap_write_bytes(0x32,(char*)&gy_p,4);
	iap_write_bytes(0x36,(char*)&gy_d,4);
	iap_write_bytes(0x49,"1",1);
	oled_p6x8str(0,7,"xie ru");
}



