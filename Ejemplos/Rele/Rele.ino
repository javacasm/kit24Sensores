/* Kit Bricogeek
*
* conexion rele
* 
* by @javacasm 
 */ 
  
#define pinRele 7

void setup() {
  pinMode(pinRele,OUTPUT);


}

void loop() {

  digitalWrite(pinRele,HIGH);
  delay(1000);
  digitalWrite(pinRele,LOW);
  delay(1000);
}
