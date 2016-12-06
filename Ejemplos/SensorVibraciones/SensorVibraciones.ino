/* Kit Bricogeek
*
* conexion Sensor de vibraciones
* 
* by @javacasm 
 */ 
  
#define pinSensorVibra 8

void setup() {
  pinMode(pinSensorVibra,INPUT);
  Serial.begin(9600);
}

void loop() {

  int valor=digitalRead(pinSensorVibra);
  Serial.println(valor);
   
}
