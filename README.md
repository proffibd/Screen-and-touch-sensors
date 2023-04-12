# Screen-and-touch-sensors

In order to properly hook up the LCD and the Adafruit TSC2007 the correct pins are required

For the LCD setup, the same pin setup was kept from the Arduino Hello World example program for the sake of simplicity. An image of this setup is shown below
![image](https://user-images.githubusercontent.com/123525432/231464135-824529f8-7560-4c6d-8928-f1d041b8f095.png)

For the TSC2007 setup is also simple. The touch screen itself should be plugged into the chip using the middle FPC connector port circled below.
<img width="173" alt="Screenshot 2023-04-12 085932" src="https://user-images.githubusercontent.com/123525432/231465104-8c2f3345-d49d-481d-85e9-d0088bcb56cb.png">

Most touch screens use FPC controlers which mean the TSC2007 should be able to accomadate most any touch screen controler. The SDA and SCL ports found on the opposite side of the chip must be plugged intot the A4 and A5 pins respectivly. These are the SDA and SCL pins of the Arduino Uno and cannot be changed. Note that SDA and SCl pins are different depending on the type or Arduino. The SDA and SDL ports cna be changed in the libTouch/touch_settings.h. Finaly the Vin must be connnected to 5v and the GND must be connected to GND. The TSC2007 does come with small pins that can be sodered into the chip, however that is optional.
