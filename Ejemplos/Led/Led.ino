/* Kit Bricogeek
*
* conexion led PWM
* 
* by @javacasm 
 */ 
  
#define pinLedPWM 9

void setup() {
}

void loop() {

  for(int i=0;i<256;i++){
    analogWrite(pinLedPWM,i);
    delay(10);
  }
}
