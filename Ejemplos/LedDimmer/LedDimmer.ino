
// Encendemos con mayor o menor intensidad un led en función del valor de un potenciómetro lineal

#define pinLed 11


void setup() {
  // No es necesario establecer el modo INPUT/OUTPUT para entradas analógicas o salidas PWM
}

void loop() {
  
  int valorPot=analogRead(A0);
  int valorPWM=map(valorPot,0,1023,0,255);

  analogWrite(pinLed,valorPWM);
}
