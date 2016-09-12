/*
Usaremos un potenciómetro (A0) para controlar la velocidad del motor (PWM10)
 */

const int potPin = A0;  // Analog input A0 para el potenciómetro 
const int pwmPin = 10; // Analog (PWM) output pin Para el motor

void setup() {
  // initializamos las communicationes serie a 9600 bps:
  Serial.begin(9600);
}

void loop() {
 
  int potValue = analogRead(potPin);
  int outputValue = map(potValue, 0, 1023, 0, 255);
  
  analogWrite(pwmPin, outputValue);

  Serial.print("potenciometro = ");
  Serial.print(potValue);
  Serial.print("\t output = ");
  Serial.println(outputValue);

  // esperamos 2 milliseconds 
  delay(2);
}
