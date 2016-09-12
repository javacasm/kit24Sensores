# General

[Lista de componentes de elecfreaks](http://www.elecfreaks.com/wiki/index.php?title=Catalog_category)

# Potenciómetro lineal

Necesita 4 hilos: V+,GND, Señal y un cuarto que nos permite controlar un led que se include en la placa.

![IMG_20160702_135919.jpg](./images/IMG_20160702_135919.jpg)

# Display 7 segmentos



![7-seg](http://www.elecfreaks.com/wiki/images/4/4f/Segment-1.jpg)

([ejemplo](http://elecfreaks.com/estore/download/EF4056-Paintcode.zip))


    #include "TM1637.h"
    #define CLK 2//pins definitions for TM1637 and can be changed to other ports       
    #define DIO 3
    TM1637 tm1637(CLK,DIO);
    #define ON 1
    #define OFF 0
    unsigned char ClockPoint = 1;
    void setup()
    {
      tm1637.init();
      tm1637.set(BRIGHT_TYPICAL);//BRIGHT_TYPICAL = 2,BRIGHT_DARKEST = 0,BRIGHTEST = 7;
    }
    void loop()
    {
      int8_t NumTab[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};//0~9,A,b,C,d,E,F
      int8_t ListDisp[0];
      tm1637.display(0,8);
      tm1637.display(1,8);
      tm1637.display(2,8);
      tm1637.display(3,8);
      tm1637.point(POINT_ON);
      delay(300);
      tm1637.clearDisplay();
      tm1637.point(POINT_OFF);
      delay(300);
    }

## Motor

![motor](http://www.elecfreaks.com/estore/media/catalog/product/cache/1/image/800x800/9df78eab33525d08d6e5fb8d27136e95/o/c/octopus-motor-brick1-1.png)

Control del motor con un potentiometer

    /*
      Analog input, analog output, serial output

     Reads an analog input pin, maps the result to a range from 0 to 255
     and uses the result to set the pulsewidth modulation (PWM) of an output pin.
     Also prints the results to the serial monitor.

     The circuit:
     * potentiometer connected to analog pin 0.
       Center pin of the potentiometer goes to the analog pin.
       side pins of the potentiometer go to +5V and ground
     * LED connected from digital pin 9 to ground
     
     created 29 Dec. 2008
     modified 9 Apr 2012
     by Tom Igoe

     This example code is in the public domain.

     */

    // These constants won't change.  They're used to give names
    // to the pins used:
    const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
    const int analogOutPin = 9; // Analog output pin that the LED is attached to

    int sensorValue = 0;        // value read from the pot
    int outputValue = 0;        // value output to the PWM (analog out)

    void setup() {
      // initialize serial communications at 9600 bps:
      Serial.begin(9600);
    }

    void loop() {
      // read the analog in value:
      sensorValue = analogRead(analogInPin);            
      // map it to the range of the analog out:
      outputValue = map(sensorValue, 0, 1023, 0, 255);  
      // change the analog out value:
      analogWrite(analogOutPin, outputValue);           

      // print the results to the serial monitor:
      Serial.print("sensor = " );                       
      Serial.print(sensorValue);      
      Serial.print("\t output = ");      
      Serial.println(outputValue);   

      // wait 2 milliseconds before the next loop
      // for the analog-to-digital converter to settle
      // after the last reading:
      delay(2);                     
    }
