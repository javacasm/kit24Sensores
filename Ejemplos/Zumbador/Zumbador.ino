/* Kit Bricogeek
*
* conexion zumbador
* 
* by @javacasm 
 */ 
  
#define pinZumbador 8

void setup() {
  pinMode(pinZumbador,OUTPUT);
}

void loop() {

  tone(pinZumbador,440,500);
  delay(500);
  tone(pinZumbador,880,500);
  delay(500);

  
}
