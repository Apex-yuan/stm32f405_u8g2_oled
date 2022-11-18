#include "sw_i2c.h"
#include"gpio.h"
#include <stdint.h>
#include "stm32f4xx.h"



void IIC_Init(void) {

}

#define CPU_FREQUENCY_MHZ   0 //4
void delay_xus(__IO uint32_t nTime)
{
    int old_val, new_val, val;

    if (nTime > 900)
    {
        for (old_val = 0; old_val < nTime / 900; old_val++)
        {
            delay_xus(900);
        }
        nTime = nTime % 900;
    }

    old_val = SysTick->VAL;
    new_val = old_val - CPU_FREQUENCY_MHZ * nTime;
    if (new_val >= 0)
    {
        do
        {
            val = SysTick->VAL;
        } while ((val < old_val) && (val >= new_val));
    } else
    {
        new_val += CPU_FREQUENCY_MHZ * 1000;
        do
        {
            val = SysTick->VAL;
        } while ((val <= old_val) || (val > new_val));

    }
}

//延时
void IIC_delay(void)
{
	// uint8_t t=10;
	// while(t--);

	// uint8_t t = 10;
	// while (t--)
	// {
	// 	asm volatile(""); //可以防止while循环被优化掉
	// }
	
	delay_xus(4);
}

//起始信号
void I2C_Start(void)
{
	OLED_SDA_Set();
	OLED_SCL_Set();
	IIC_delay();
	OLED_SDA_Clr();
	IIC_delay();
	OLED_SCL_Clr();
	IIC_delay();
}

//结束信号
void I2C_Stop(void)
{
	OLED_SDA_Clr();
	OLED_SCL_Set();
	IIC_delay();
	OLED_SDA_Set();
}

//等待信号响应
void I2C_WaitAck(void) //测数据信号的电平
{
	OLED_SDA_Set();
	IIC_delay();
	OLED_SCL_Set();
	IIC_delay();
	OLED_SCL_Clr();
	IIC_delay();
}

//写入一个字节
void Send_Byte(uint8_t dat)
{
	uint8_t i;
	for(i=0;i<8;i++)
	{
		if(dat&0x80)//将dat的8位从最高位依次写入
		{
			OLED_SDA_Set();
    }
		else
		{
			OLED_SDA_Clr();
    }
		IIC_delay();
		OLED_SCL_Set();
		IIC_delay();
		OLED_SCL_Clr();//将时钟信号设置为低电平
		dat<<=1;
  }
}

void SOFT_I2C_Master_Transmit(uint8_t daddr, uint8_t *buff, uint8_t len)
{
    I2C_Start();
    Send_Byte(daddr);
    I2C_WaitAck();

    for (int i = 0; i < len; i++)
    {
        Send_Byte(*(buff + i));
        I2C_WaitAck();
    }

    I2C_Stop();
}

//发送一个字节
//mode:数据/命令标志 0,表示命令;1,表示数据;
// void OLED_WR_Byte(u8 dat,u8 mode)
// {
// 	I2C_Start();
// 	Send_Byte(0x78);
// 	I2C_WaitAck();
// 	if(mode){Send_Byte(0x40);}
//   else{Send_Byte(0x00);}
// 	I2C_WaitAck();
// 	Send_Byte(dat);
// 	I2C_WaitAck();
// 	I2C_Stop();
// }