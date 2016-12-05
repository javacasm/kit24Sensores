/* Kit Bricogeek
*
* conexion sensor PIR
* 
* by @javacasm 
 */ 
  
#define pinPIR 7

void setup() {
  Serial.begin(9600);
}

void loop() {

  int valor=digitalRead(pinPIR);
  Serial.println(valor);
  delay(10);
  
}
