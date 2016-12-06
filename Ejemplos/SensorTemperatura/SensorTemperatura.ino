/* Kit Bricogeek
*
* conexion Sensor de Temperatura (LM35)
* 
* by @javacasm 
 */ 
  
#define pinLM35 A0

void setup() {
  Serial.begin(9600);
}

void loop() {

  int valor = analogRead(pinLM35);
  float mVoltios=(valor/1023.0)*5000;
  float gCelsius = mVoltios / 10; 
  Serial.print(gCelsius);
  Serial.println(" C");
  delay(500);
  
}
