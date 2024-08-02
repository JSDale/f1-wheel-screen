#include "MainView.h"
#include "LCD_Driver.h"
#include "LCD_Touch.h"
#include "LCD_GUI.h"
#include "LCD_Bmp.h"
#include "DEV_Config.h"
#include <stdio.h>
#include "hardware/watchdog.h"
#include "pico/stdlib.h"
#include <stdint.h>
#include <stdio.h>

uint8_t iterationCount = 0;
uint8_t numbers[] = {1,2,3,4,5,6,7,8};

void DisplayRandomNumbers(void)
{
	uint8_t number = GetNumber();

	POINT xStart = 250;
    POINT yStart = 50;
    char content[] = (char)number;
    GUI_DisString_EN(xStart, yStart, content, &Font24, BLACK, WHITE);
}

uint8_t GetNumber(void)
{
	if (iterationCount == 7)
	{
		iterationCount = 0;
	}

	return numbers[iterationCount];
}

int Start(void)
{
	System_Init();
	LCD_SCAN_DIR  lcd_scan_dir = SCAN_DIR_DFT;
	LCD_Init(lcd_scan_dir,800);

	GUI_Clear(BLACK);
	Driver_Delay_ms(200);
    POINT xStart = 25;
    POINT yStart = 50;
    char content[] = "hello world";
    GUI_DisString_EN(xStart, yStart, content, &Font12, BLACK, BLUE);

	while(1)
	{
		DisplayRandomNumbers();
		Driver_Delay_ms(1000);
	}

	return 0;
}

