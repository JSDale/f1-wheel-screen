#include "MainView.h"
#include "main.h"
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
	//SD_Init();
	LCD_SCAN_DIR  lcd_scan_dir = SCAN_DIR_DFT;
	LCD_Init(lcd_scan_dir,800);
	//TP_Init(lcd_scan_dir);

	GUI_Show();
	Driver_Delay_ms(1000);
    POINT xStart = 5;
    POINT yStart = 5;
    char content[] = "hello world";
    COLOR purple =  0x680df5;
    COLOR white = 0xffffff;
    GUI_DisString_EN(xStart, yStart, content, &Font12, white, purple);

	//LCD_Show_bmp(lcd_scan_dir);
	//Driver_Delay_ms(2000);

	//TP_GetAdFac();
	//TP_Dialog(lcd_scan_dir);
	// while(1){
	// 	TP_DrawBoard(lcd_scan_dir);
	// }

	return 0;
}
