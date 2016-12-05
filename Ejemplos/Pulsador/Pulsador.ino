/* Kit Bricogeek
*
* conexion pulsador
* 
* by @javacasm 
 */ 
  
#define pinPulsador 8

void setup() {
  Serial.begin(9600);
  pinMode(pinPulsador,INPUT_PULLUP);
}

void loop() {

  int valor=digitalRead(pinPulsador);
  if(valor==HIGH){
    Serial.println("¡Pulsado!");
    delay(50);
  }
  
}
