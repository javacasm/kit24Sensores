/* Kit Bricogeek
*
* conexion sensor de humedad de suelo
* 
* by @javacasm 
 */ 
  
#define pinSensorHumedad A0

void setup() {
  Serial.begin(9600);
}

void loop() {

  int valor=analogRead(pinSensorHumedad);
  Serial.println(valor);
  delay(20);
  
}
