/* Kit Bricogeek
* conexion RTC (DS1307)

* adaptado by @javacasm 
 */ 

#include <Wire.h>
#include <Time.h>
#include <DS1307RTC.h>

void setup() {
 Serial.begin(9600);

}

void loop() {
 tmElements_t tm;

 if (RTC.read(tm))
 {
    Serial.print(tm.Hour);
    Serial.print(":");
    Serial.println(tm.Minute);
 }
 else
 {  Serial.print("Error conectando");}
}
