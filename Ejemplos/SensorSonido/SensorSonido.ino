/* Kit Bricogeek
*
* conexion Sensor de sonido
* 
* by @javacasm 
 */ 
  
#define pinSensorSonido 8

void setup() {
  pinMode(pinSensorSonido,INPUT);
  Serial.begin(9600);
}

void loop() {

  int valor=digitalRead(pinSensorSonido);
  Serial.println(valor);
   
}
