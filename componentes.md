# General

[Lista de componentes de elecfreaks](http://www.elecfreaks.com/wiki/index.php?title=Catalog_category)

# Potenciómetro lineal

Necesita 4 hilos: V+,GND, Señal y un cuarto que nos permite controlar un led que se include en la placa.

![IMG_20160702_135919.jpg](./images/IMG_20160702_135919.jpg)

# Display 7 segmentos



![7-seg](http://www.elecfreaks.com/wiki/images/4/4f/Segment-1.jpg)

([ejemplo](http://elecfreaks.com/estore/download/EF4056-Paintcode.zip))


    //  Author:Frankie.Chu
    //  This library is free software; you can redistribute it and/or
    //  modify it under the terms of the GNU Lesser General Public
    //  License as published by the Free Software Foundation; either
    //  version 2.1 of the License, or (at your option) any later version.
    //
    //  This library is distributed in the hope that it will be useful,
    //  but WITHOUT ANY WARRANTY; without even the implied warranty of
    //  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    //  Lesser General Public License for more details.
    //
    //  You should have received a copy of the GNU Lesser General Public
    //  License along with this library; if not, write to the Free Software
    //  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
    #include "TM1637.h"
    #define CLK 2 //pueden usarse cualquier pin
    #define DIO 3
    TM1637 tm1637(CLK,DIO);
    void setup()
    {
      tm1637.init();
      tm1637.set(BRIGHT_TYPICAL);//BRIGHT_TYPICAL = 2,BRIGHT_DARKEST = 0,BRIGHTEST = 7;
    }
    void loop()
    {
      int8_t NumTab[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};//0~9,A,b,C,d,E,F
      int8_t ListDisp[4]; // buffer donde guardaremos lo que se muestra
      unsigned char i = 0;
      unsigned char count = 0;
      delay(150);
      while(1)
      {
        i = count;
        count ++;
        if(count == sizeof(NumTab)) count = 0;
        for(unsigned char BitSelect = 0;BitSelect < 4;BitSelect ++)
        {
          ListDisp[BitSelect] = NumTab[i];
          i ++;
          if(i == sizeof(NumTab)) i = 0;
        }
        tm1637.display(0,ListDisp[0]);
        tm1637.display(1,ListDisp[1]);
        tm1637.display(2,ListDisp[2]);
        tm1637.display(3,ListDisp[3]);
        delay(300);
      }
    }

## Motor

![motor](http://www.elecfreaks.com/estore/media/catalog/product/cache/1/image/800x800/9df78eab33525d08d6e5fb8d27136e95/o/c/octopus-motor-brick1-1.png)

Control del motor con un potenciómetro


    //Usaremos un potenciómetro (A0) para controlar la velocidad del motor (PWM10)

    const int potPin = A0;  // Analog input A0 para el potenciómetro
    const int pwmPin = 10; // Analog (PWM) output pin Para el motor

    void setup() {
      // initializamos las communicationes serie a 9600 bps:
      Serial.begin(9600);
    }

    void loop() {

      int potValue = analogRead(potPin);
      int outputValue = map(potValue, 0, 1023, 0, 255);

      analogWrite(pwmPin, outputValue);

      Serial.print("potenciometro = ");
      Serial.print(potValue);
      Serial.print("\t output = ");
      Serial.println(outputValue);

      // esperamos 2 milliseconds
      delay(2);
    }
