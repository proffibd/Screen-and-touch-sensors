
#include "touch_settings.h"
#include <util/delay.h>

#define TSC2007_I2CADDR_DEFAULT 0x48  TSC2007 default i2c address


void my_delay_ms(unsigned int delay);
void i2c_start(void);
void i2c_stop(void);
void I2C_write(unsigned char Data);
unsigned char i2c_read(void);

 int SDA = 1;
 int SCL = 1;
 int x;
 int y;


void i2c_start(void)
{
SCL=1;
SDA=1;
_delay_ms(500);
SDA=0;
_delay_ms(500);
SCL=0;
}

void i2c_stop(void)
{
SCL=0;
SDA=0;
my_delay_ms(500);
SCL=1;
my_delay_ms(500);
SDA=1;
}

void i2c_write(unsigned char Data)//0xA0 1010 0000--> 0100 0000
{
	unsigned char i;
	//
	for(i=0;i<8;i++)
	{
		SDA = (Data&0x80)?1:0;
		SCL = 1;
		my_delay_ms(500);
		SCL = 0;
		Data = Data<<1;
	}
	SDA=1;
	SCL=1;
	my_delay_ms(500);
	while(SDA==1); //waiting until SDA=0 this should be set by the slave 
	SCL=0;
	my_delay_ms(500);
}



unsigned char i2c_read(void)///1010 0000     1|0=1...101
{
	int rd_bit;
	unsigned char i,Dat=0;	

	for(i=0;i<8;i++)
	{
		my_delay_ms(500);
		SCL = 1;
		my_delay_ms(500);
		rd_bit = SDA;
		Dat = Dat<<1;
		Dat = Dat|rd_bit;
		SCL = 0;
	}
	//NACK
	SDA = 1;
	SCL = 1;
	my_delay_ms(500);
	SCL = 0;
	return Dat;
}

int x_value() {
	//Send Data
	i2c_start();
	i2c_write(0x60); //1100 0000
	i2c_write(0x48); //register address or memory address
	i2c_write('A'); 
	i2c_stop();
	my_delay_ms(500);

	//Read Data
	i2c_start();
	i2c_write(0x60); //1100 0000
	i2c_write(0x48); //register address or memory address
	i2c_start();
	i2c_write(0x61); //1100 0001 read
	x = i2c_read();
	i2c_stop();

	return x;
}

int y_value() {
	//Send Data
	i2c_start();
	i2c_write(0x68); //1100 0000
	i2c_write(0x48); //register address or memory address
	i2c_write('A'); 
	i2c_stop();
	my_delay_ms(500);

	//Read Data
	i2c_start();
	i2c_write(0x68); //1100 0000
	i2c_write(0x48); //register address or memory address
	i2c_start();
	i2c_write(0x69); //1100 0001 read
	x = i2c_read();
	i2c_stop();

	return x;
}

void my_delay_ms(unsigned int delay) 
{
	unsigned int i;

	for (i=0; i<(delay/10); i++) 
	{
		_delay_ms(10);
	}
	for (i=0; i<(delay % 10); i++) 
	{
		_delay_ms(1);
	}
}