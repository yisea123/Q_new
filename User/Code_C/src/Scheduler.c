#include "Scheduler.h"
void Loop_1000Hz(u16 Time);
void Loop_500Hz(u16 Time);
void Loop_200Hz(u16 Time);
void Loop_50Hz(u16 Time);

struct Scheduler_ Scheduler = 
{
	Loop_1000Hz,
	Loop_500Hz,
	Loop_200Hz,
	Loop_50Hz
};

void Loop_1000Hz(u16 Time)
{
	
}

void Loop_500Hz(u16 Time)
{
  MPU6050.Updata();									//mpu6050数据采集
	Attitude.Updata();								//姿态解算
//Altitude.Updata(Time);						//位置解算
	FlyControl.ATT_InnerLoop(Time);		//姿态控制内环
}

void Loop_200Hz(u16 Time)
{
	HMC5883.Updata();									//磁力计数据采集
	FlyControl.ATT_OuterLoop(Time);		//姿态控制外环
//FlyControl.POS_InnerLoop(Time);	//位置控制内环
}

void Loop_50Hz(u16 Time)
{
	SystemState.Updata(Time);					//系统状态监控
	Communication.UpData();						//调试通信
//FlyControl.POS_OuterLoop(Time);		//位置控制外环
	Power.Updata();										//电压数据采集
	MS5611.Updata();									//气压计数据采集									
	PWM_In.Updata();									//遥控数据采集
	
}



