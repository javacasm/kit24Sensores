/* Kit Bricogeek
*
* conexion Sensor IR (de proximidad o siguelineas)
* 
* by @javacasm 
 */ 
  
#define pinSensorIR 8

void setup() {
  pinMode(pinSensorIR,INPUT);
  Serial.begin(9600);
}

void loop() {

  int valor=digitalRead(pinSensorIR);
  Serial.println(valor);
   
}
