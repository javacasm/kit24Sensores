/* Kit Bricogeek
*
* conexion inclinometro analogico
* 
* by @javacasm 
 */ 
  
#define pinSensorInc A0

void setup() {
  Serial.begin(9600);
}

void loop() {

  int valor=analogRead(pinSensorInc);
  Serial.println(valor);
  delay(20);
  
}
