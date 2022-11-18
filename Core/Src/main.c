/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "u8g2_port.h"
#include "u8g2.h"

// #include "oled.h"
// #include "bmp.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
extern void Main(void);
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
// u8g2_t u8g2;


// u8g2_uint_t offset1;			// current offset for the scrolling text
// u8g2_uint_t width;			// pixel width of the scrolling text (must be lesser than 128 unless U8G2_16BIT is defined
// const char *text = "U8g2 ";	// scroll this text from right to left
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_15, GPIO_PIN_SET);

  // OLED_Init();

  // __HAL_RCC_GPIOB_CLK_ENABLE();
	// GPIO_InitTypeDef GPIO_InitStruct;
	
	// GPIO_InitStruct.Pin = GPIO_PIN_13;
	// GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	// GPIO_InitStruct.Pull = GPIO_NOPULL;
	// GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
	// HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
  // // uint8_t t = ' ';
  // u8g2_Setup_ssd1306_i2c_128x64_noname_f(&u8g2, U8G2_R0, u8x8_byte_stm32_sw_spi, u8x8_gpio_and_delay_stm32);

  // u8g2_InitDisplay(&u8g2); // 初始化显示
  // u8g2_ClearBuffer(&u8g2); // 清除缓存
  // u8g2_SetPowerSave(&u8g2, 0);  // 关闭省电模式（默认开启，屏幕上什么也看不到）   

  // u8g2_SetFont(&u8g2, u8g2_font_inb30_mr);
  // width = u8g2_GetUTF8Width(&u8g2, text);
  // u8g2_SetFontMode(&u8g2, 0);

  Main();
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    // u8g2_uint_t x;
    
    // u8g2_FirstPage(&u8g2);
    // do
    // {    
    //   x = offset1;
    //   u8g2_SetFont(&u8g2, u8g2_font_inb30_mr);
    //   do{
    //     u8g2_DrawUTF8(&u8g2, x, 30, text);
    //     x += width;
    //   }while(x < u8g2_GetDisplayWidth(&u8g2));
      
    //   u8g2_SetFont(&u8g2, u8g2_font_inb16_mr);
    //   u8g2_DrawUTF8(&u8g2, 0, 58, text);
     
    // }while( u8g2_NextPage(&u8g2) );

    // offset1-=1;	// scroll by one pixel
    // if ( (u8g2_uint_t)offset1 < (u8g2_uint_t)-width )	
    //   offset1 = 0; // start over again

    // HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_13);
		// HAL_Delay(100);
		// OLED_ShowPicture(0,0,128,64,BMP1,1);
		// OLED_Refresh();
		// //delay_ms(500);
		// HAL_Delay(500);
		// OLED_Clear();
		// OLED_ShowChinese(0,0,0,16,1);//中
		// OLED_ShowChinese(18,0,1,16,1);//景
		// OLED_ShowChinese(36,0,2,16,1);//园
		// OLED_ShowChinese(54,0,3,16,1);//电
		// OLED_ShowChinese(72,0,4,16,1);//子
		// OLED_ShowChinese(90,0,5,16,1);//技
		// OLED_ShowChinese(108,0,6,16,1);//术
		// OLED_ShowString(8,16,"ZHONGJINGYUAN",16,1);
		// OLED_ShowString(20,32,"2014/05/01",16,1);
		// OLED_ShowString(0,48,"ASCII:",16,1);  
		// OLED_ShowString(63,48,"CODE:",16,1);
		// OLED_ShowChar(48,48,t,16,1);//显示ASCII字符	   
		// t++;
		// if(t>'~')t=' ';
		// OLED_ShowNum(103,48,t,3,16,1);
		// OLED_Refresh();
		// //delay_ms(500);
		// HAL_Delay(500);
		// OLED_Clear();
		// OLED_ShowChinese(0,0,0,16,1);  //16*16 中
	  // OLED_ShowChinese(16,0,0,24,1); //24*24 中
		// OLED_ShowChinese(24,20,0,32,1);//32*32 中
	  // OLED_ShowChinese(64,0,0,64,1); //64*64 中
		// OLED_Refresh();
	  // //delay_ms(500);
		// HAL_Delay(500);
  	// OLED_Clear();
		// OLED_ShowString(0,0,"ABC",8,1);//6*8 “ABC”
		// OLED_ShowString(0,8,"ABC",12,1);//6*12 “ABC”
	  // OLED_ShowString(0,20,"ABC",16,1);//8*16 “ABC”
		// OLED_ShowString(0,36,"ABC",24,1);//12*24 “ABC”
	  // OLED_Refresh();
		//delay_ms(500);
		// HAL_Delay(500);
		// OLED_ScrollDisplay(11,4,1);
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
