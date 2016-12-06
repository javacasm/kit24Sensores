/* Kit Bricogeek
*
* conexion Sensor de Lluvia
* 
* by @javacasm 
 */ 
  
#define pinSensorLluvia A0

void setup() {
  Serial.begin(9600);
}

void loop() {

  int valor=analogRead(pinSensorLluvia);
  Serial.println(valor);
  delay(20);
  
}
