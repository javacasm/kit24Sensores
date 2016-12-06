/* Kit Bricogeek
*
* conexion Potenciometro lineal con LED
* 
* by @javacasm 
 */ 
  
#define pinPotenciometro A0
#define pinLed 10

void setup() {
}

void loop() {

  int valorPot=analogRead(pinPotenciometro);
  int brilloLed=map(valorPot,0,1023,0,255);
  analogWrite(pinLed,brilloLed);
  delay(20);
  
}
