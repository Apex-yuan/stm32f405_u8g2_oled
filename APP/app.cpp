#include "main.h"
#include "u8g2.h"
#include "u8x8.h"
#include "u8g2_port.h"
#include "U8g2lib.h"


  SSD1306 oled;


extern "C" void Main(void) {
  


  oled.begin();
  oled.clearBuffer();
  oled.setFont(u8g2_font_5x8_tr);
  oled.setCursor(0, 10);
  oled.printf("hello world");
  oled.drawUTF8(50,50,"U8g2");
  oled.sendBuffer();
  uint8_t x = 0, y = 0;
  while(1) {
    oled.clearBuffer();
    oled.setFont(u8g2_font_5x8_tr);
    oled.setCursor(0, 10);
    oled.printf("IMU:%.3f/%.3f", 0.5f, 0.5f);
    oled.setCursor(85, 10);
    oled.printf("| FPS:%u", 200);
    // t = micros();

    oled.drawBox(0, 15, 128, 3);
    oled.setCursor(0, 30);
    oled.printf(">%3d|%3d|%3d|%3d|%3d|%3d",
                (int) 10, (int) 10,
                (int) 10, (int) 10,
                (int) 10, (int) 10);

    oled.drawBox(40, 35, 128, 24);
    oled.setFont(u8g2_font_6x12_tr);
    oled.setDrawColor(0);
    oled.setCursor(42, 45);
    oled.printf("%4d|%4d|%4d", (int) x++,
                (int) y++, (int) 20);
    oled.setCursor(42, 56);
    oled.printf("%4d|%4d|%4d", (int) 50,
                (int) 60, (int) 70);
    oled.setDrawColor(1);
    oled.setCursor(0, 45);
    oled.printf("[XYZ]:");
    oled.setCursor(0, 56);
    oled.printf("[ABC]:");

    oled.setFont(u8g2_font_10x20_tr);
    oled.setCursor(0, 78);
    // if (dummy.IsEnabled())
    // {
    //     for (int i = 1; i <= 6; i++)
    //         buf[i - 1] = (dummy.jointsStateFlag & (1 << i) ? '*' : '_');
    //     buf[6] = 0;
    //     oled.printf("[%s] %s", cmdModeNames[dummy.commandMode - 1], buf);
    // } else
    // {
    //     oled.printf("[%s] %s", cmdModeNames[dummy.commandMode - 1], "======");
    // }

    oled.sendBuffer();
    HAL_Delay(100);

  }
}





// u8g2_t u8g2;


// u8g2_uint_t offset1;			// current offset for the scrolling text
// u8g2_uint_t width;			// pixel width of the scrolling text (must be lesser than 128 unless U8G2_16BIT is defined
// const char *text = "U8g2 ";	// scroll this text from right to left

// extern "C" void Main(void) {

//       __HAL_RCC_GPIOB_CLK_ENABLE();
// 	GPIO_InitTypeDef GPIO_InitStruct;
	
// 	GPIO_InitStruct.Pin = GPIO_PIN_13;
// 	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
// 	GPIO_InitStruct.Pull = GPIO_NOPULL;
// 	GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
// 	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
//   // uint8_t t = ' ';
//   u8g2_Setup_ssd1306_i2c_128x64_noname_f(&u8g2, U8G2_R0, u8x8_byte_stm32_sw_spi, u8x8_gpio_and_delay_stm32);

//   u8g2_InitDisplay(&u8g2); // 初始化显示
//   u8g2_ClearBuffer(&u8g2); // 清除缓存
//   u8g2_SetPowerSave(&u8g2, 0);  // 关闭省电模式（默认开启，屏幕上什么也看不到）   

//   u8g2_SetFont(&u8g2, u8g2_font_inb30_mr);
//   width = u8g2_GetUTF8Width(&u8g2, text);
//   u8g2_SetFontMode(&u8g2, 0);
//     while (1)
//     {
//          u8g2_uint_t x;
    
//         u8g2_FirstPage(&u8g2);
//         do
//         {    
//         x = offset1;
//         u8g2_SetFont(&u8g2, u8g2_font_inb30_mr);
//         do{
//             u8g2_DrawUTF8(&u8g2, x, 30, text);
//             x += width;
//         }while(x < u8g2_GetDisplayWidth(&u8g2));
        
//         u8g2_SetFont(&u8g2, u8g2_font_inb16_mr);
//         u8g2_DrawUTF8(&u8g2, 0, 58, text);
        
//         }while( u8g2_NextPage(&u8g2) );

//         offset1-=1;	// scroll by one pixel
//         if ( (u8g2_uint_t)offset1 < (u8g2_uint_t)-width )	
//         offset1 = 0; // start over again

//         HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_13);
// 		HAL_Delay(100);
//     }
    
// }