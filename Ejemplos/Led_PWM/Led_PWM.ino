/* Kit Bricogeek
*
* conexion sensor de luz LDR
* 
* by @javacasm 
 */ 
  
#define pinLDR A0

void setup() {
  Serial.begin(9600);
}

void loop() {

  int valor=analogRead(pinLDR);
  Serial.println(valor);
  delay(20);
  
}
