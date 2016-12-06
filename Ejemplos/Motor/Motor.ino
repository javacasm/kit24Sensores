/* Kit Bricogeek
* conexion motor
*
* adaptado by @javacasm
 */
#define pinMotor  10


void setup() {
}

void loop(){
for(int i=0;i<255;i++)
{
  analogWrite(pinMotor,i);
  delay(100);
}
  }
