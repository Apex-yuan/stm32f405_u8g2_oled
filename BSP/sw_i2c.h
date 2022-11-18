#ifndef __SW_I2C_H
#define __SW_I2C_H

#include "gpio.h"

#define OLED_SCL_Clr() HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET) //GPIO_ResetBits(GPIOG,GPIO_Pin_12)//SCL
#define OLED_SCL_Set() HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET) //GPIO_SetBits(GPIOG,GPIO_Pin_12)

#define OLED_SDA_Clr() HAL_GPIO_WritePin(GPIOC, GPIO_PIN_14, GPIO_PIN_RESET) //GPIO_ResetBits(GPIOD,GPIO_Pin_5)//DIN
#define OLED_SDA_Set() HAL_GPIO_WritePin(GPIOC, GPIO_PIN_14, GPIO_PIN_SET) //GPIO_SetBits(GPIOD,GPIO_Pin_5)

#define OLED_RES_Clr() HAL_GPIO_WritePin(GPIOC, GPIO_PIN_15, GPIO_PIN_RESET)//GPIO_ResetBits(GPIOD,GPIO_Pin_4)//RES
#define OLED_RES_Set() HAL_GPIO_WritePin(GPIOC, GPIO_PIN_15, GPIO_PIN_SET)//GPIO_SetBits(GPIOD,GPIO_Pin_4)


void IIC_Init(void);
void IIC_delay(void);
void I2C_Start(void);
void I2C_Stop(void);
void I2C_WaitAck(void);
void Send_Byte(uint8_t dat);
void SOFT_I2C_Master_Transmit(uint8_t daddr, uint8_t *buff, uint8_t len);
void delay_xus(__IO uint32_t nTime);

#endif 