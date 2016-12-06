/* Kit Bricogeek
* conexion Encoder
* http://playground.arduino.cc/Main/RotaryEncoders#Example2
* adaptado by @javacasm 
 */ 
#define encoder_PinA  2
#define encoder_PinB  4
volatile int contador= 0;

void setup() { 
  pinMode(encoder_PinA, INPUT); 
  pinMode(encoder_PinB, INPUT); 
  attachInterrupt(0, doEncoder, CHANGE);  // encoder pin on interrupt 0 - pin 2
  Serial.begin (9600);
} 
// Podriamos estar haciendo cualquier cosa aqui
void loop(){    }
void doEncoder() {
  // Si tienen el mismo valor van hacia adelante, si no hacia atras
  if (digitalRead(encoder_PinA) == digitalRead(encoder_PinB)) {
    contador++;
  } else {
    contador--;
  }
  Serial.println (contador);
}
