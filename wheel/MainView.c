#include "MainView.h"
#include "LCD_Driver.h"
#include "LCD_Touch.h"
#include "LCD_GUI.h"
#include "LCD_Bmp.h"
#include "DEV_Config.h"
#include <stdio.h>
#include "hardware/watchdog.h"
#include "pico/stdlib.h"

int Start(void)
{
    uint8_t counter = 0;
   	
	System_Init();
	LCD_SCAN_DIR  lcd_scan_dir = SCAN_DIR_DFT;
	LCD_Init(lcd_scan_dir,800);

	GUI_Clear();
	Driver_Delay_ms(200);
    POINT xStart = 25;
    POINT yStart = 50;
    char content[] = "hello world";
    GUI_DisString_EN(xStart, yStart, content, &Font12, WHITE, BLUE);

	return 0;
}
