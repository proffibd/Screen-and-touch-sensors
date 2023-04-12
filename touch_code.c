#include "IO_Macros.h"
#include "libLCD/hd44780.h"
#include "libLCD/hd44780.c"
#include "libTouch/touch.h"
#include <stdint.h>
#include <string.h>
#include <avr/io.h>
#include <avr/interrupt.h>


int main(void)
{

	int x;
	int y;


	//Setup
	LCD_Setup();
	uint8_t line;
	for (line = 0; line < 2; line++)
	{
		LCD_GotoXY(0, line);
		if (line == 0)
		{
			LCD_PrintString("ECE 387 line: ");
			LCD_PrintInteger(LCD_GetY());
		}
		else 
		{
			LCD_PrintString("LCD[");
			LCD_PrintInteger(LCD_GetY());
			LCD_PrintString("] working!!!");
		}
	}
	my_delay_ms(1000);
	LCD_Clear();
	return 0;

	while (1) {
		
		x = x_value();
		y = y_value();
		LCD_GotoXY(0 , 0);
		LCD_PrintString("X: ");
		LCD_PrintInteger(x);
		LCD_GotoXY(0 , 0);
		LCD_PrintString("Y: ");
		LCD_PrintInteger(y);
		my_delay_ms(1000);
		LCD_Clear();
 
	}
	
}



