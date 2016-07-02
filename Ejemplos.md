# Sensores

## Controlar la intensidad de brillo de un led con un potencimetro (Led Dimmer)

![IMG_20160702_133714.jpg](./images/IMG_20160702_133714.jpg)

Conectamos el potenciómetro en A0 (El potenciómetro lineal usa un cable de 4 hilos, de los que sólo usaremos 3, el cuarto es un led que podemos controlar, pero usaremos un led externo) y el led en el pin 11


    // Encendemos con mayor o menor intensidad un led en función del valor de un potenciómetro lineal

    #define pinLed 11


    void setup() {
      // No es necesario establecer el modo INPUT/OUTPUT para entradas analógicas o salidas PWM
    }

    void loop() {

      int valorPot=analogRead(A0);
      int valorPWM=map(valorPot,0,1023,0,255);

      analogWrite(pinLed,valorPWM);
    }

[Ejemplo](./Ejemplos/LedDimmer/LedDimmer.ino)

## Sensor de inclinación

Es analógico

## Sensor de humo (OBMQ05)

[DataSheet](http://elecfreaks.com/estore/download/EF04029-MQ5.pdf)
[Schematic](http://elecfreaks.com/estore/download/EF04029-GAS.pdf)
[wiki](http://www.elecfreaks.com/wiki/index.php?title=Octopus_Smoke_Sensor_MQ-2/MQ-5_Brick)

Es analógico

## Compás

    // From http://www.elecfreaks.com/wiki/index.php?title=Octopus_3-Axis_Digital_Compass_Sensor
    #include <Wire.h> //I2C Arduino Library

    #define address 0x1E //0011110b, I2C 7bit address of HMC5883

    void setup(){
      //Initialize Serial and I2C communications
      Serial.begin(9600);
      Wire.begin();

      //Put the HMC5883 IC into the correct operating mode
      Wire.beginTransmission(address); //open communication with HMC5883
      Wire.send(0x02); //select mode register
      Wire.send(0x00); //continuous measurement mode
      Wire.endTransmission();
    }

    void loop(){

      int x,y,z; //triple axis data

      //Tell the HMC5883 where to begin reading data
      Wire.beginTransmission(address);
      Wire.send(0x03); //select register 3, X MSB register
      Wire.endTransmission();


     //Read data from each axis, 2 registers per axis
      Wire.requestFrom(address, 6);
      if(6<=Wire.available()){
        x = Wire.receive()<<8; //X msb
        x |= Wire.receive(); //X lsb
        z = Wire.receive()<<8; //Z msb
        z |= Wire.receive(); //Z lsb
        y = Wire.receive()<<8; //Y msb
        y |= Wire.receive(); //Y lsb
      }

      //Print out values of each axis
      Serial.print("x: ");
      Serial.print(x);
      Serial.print("  y: ");
      Serial.print(y);
      Serial.print("  z: ");
      Serial.println(z);

      delay(250);
    }

# Temperatura

Es un sensor analógico, y parece que es un LM35

# Encoder

[Tutorial](http://bildr.org/2012/08/rotary-encoder-arduino/)
[About rotary-encoders](http://playground.arduino.cc/Main/RotaryEncoders)

    //(C)2011 ElecFreaks
    // web: http://www.elecfreaks.com
    //
    // This program is a demo of how to use Octopus Rotary Encoder Brick.
    /
    #include <avr/io.h>

    void  Encoder_san();
    //==============================================
    //Set Encoder pin
    //==============================================
    const int Encoder_A =  19;            // Incremental Encoder singal A is PD3
    const int Encoder_B =  16;            // Incremental Encoder singal B is PD2
    const int ledPin    =  13;
    int Encoder_number=0;
    int state=0;
    //==============================================

    void setup()
    {
    //=============================================  
      PORTD |=((1<<Encoder_A)|(1<<Encoder_B));          //Pull up Encoder singal A and Bsignals
      attachInterrupt(1, Encoder_san, FALLING);        //interrupts: numbers 0 (on digital pin 2) and 1 (on digital pin 3).
    //============================================
      pinMode(ledPin, OUTPUT);      
      // initialize the pushbutton pin as an input:
      pinMode(Encoder_A, INPUT);
      pinMode(Encoder_B, INPUT);
    //============================================    
    }

    void loop()
    {
      if(state==1)
      {  
        for(int i=0;i<Encoder_number;i++)
        {
          digitalWrite(ledPin,HIGH);
          delay(500);
          digitalWrite(ledPin,LOW);
          delay(500);
        }
        state=0;
      }
    }
    void Encoder_san()
    {  

            if(digitalRead(Encoder_B))
              {
                 Encoder_number++;
              }
            else
              {  
                Encoder_number--;
              }     
              state=1;
    }
