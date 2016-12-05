/* Kit Bricogeek
*
* conexion potenciometro
* 
* by @javacasm 
 */ 
  
#define pinPotenciometro A0

void setup() {
  Serial.begin(9600);
}

void loop() {

  int valor=analogRead(pinPotenciometro);
  Serial.println(valor);
  delay(20);
  
}
