/* Kit Bricogeek
* conexion Acelerometro (HMC5883L)
* http://www.elecfreaks.com/wiki/index.php?title=Octopus_3-Axis_Digital_Compass_Sensor
* adaptado by @javacasm 
 */ 
  
#include <Wire.h> //I2C Arduino Library

#define address 0x1E //0011110b, I2C 7bit address of HMC5883

void setup(){
  Serial.begin(9600);
  Wire.begin();

  //Ponemos HMC5883 en modo de operacion
  Wire.beginTransmission(address); // abrimos comunicacion
  Wire.write(0x02); //seleccionamos el registro
  Wire.write(0x00); //modo de medida continua
  Wire.endTransmission();
}

void loop(){

  int x,y,z; //triple axis data
  //Enviamos el comando de pedir datos
  Wire.beginTransmission(address);
  Wire.write(0x03); //selecionamos el registro 3
  Wire.endTransmission();

 // Leemos los registros, (2 bytes cada uno)
  Wire.requestFrom(address, 6);
  if(6>=Wire.available()){
    x = Wire.read()<<8; //X msb
    x |= Wire.read(); //X lsb
    z = Wire.read()<<8; //Z msb
    z |= Wire.read(); //Z lsb
    y = Wire.read()<<8; //Y msb
    y |= Wire.read(); //Y lsb
  }

  // Imprimimos los datos
  Serial.print("x: ");
  Serial.print(x);
  Serial.print("  y: ");
  Serial.print(y);
  Serial.print("  z: ");
  Serial.println(z);

  // Imprimimos los datos para representarlos graficamente
//  Serial.print(x);
//  Serial.print(",");
//  Serial.print(y);
//  Serial.print(",");
//  Serial.println(z);

  delay(250);
}
