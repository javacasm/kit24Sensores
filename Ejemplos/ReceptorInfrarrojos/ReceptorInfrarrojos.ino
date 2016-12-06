/* Kit Bricogeek
*
* conexion Receptor de Infrarrojos
* 
* by @javacasm 
 */ 
 
#include <IRremote.h>

#define pinReceptor 7
IRrecv irrecv(pinReceptor);
decode_results results;
void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
  }
  delay(100);
}
