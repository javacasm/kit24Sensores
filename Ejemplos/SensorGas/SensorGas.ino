/* Kit Bricogeek
*
* conexion sensor Gas
* 
* by @javacasm 
 */ 
  
#define pinSensorGas A0

void setup() {
  Serial.begin(9600);
}

void loop() {

  int valor=analogRead(pinSensorGas);
  Serial.println(valor);
  delay(20);
  
}
