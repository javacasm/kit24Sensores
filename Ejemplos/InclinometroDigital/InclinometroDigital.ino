/* Kit Bricogeek
*
* conexion inclinometro
* 
* by @javacasm 
 */ 
  
#define pinSensor 7

void setup() {
  Serial.begin(9600);
  pinMode(pinSensor,INPUT_PULLUP);
}

void loop() {

  int valor=digitalRead(pinSensor);
  Serial.println(valor);
  delay(20);
  
}
