//
//used https://github.com/markszabo/IRremoteESP8266/
//

#include <IRrecv.h>
#include <IRutils.h>

#define irPin 5
IRrecv irrecv(irPin);
decode_results results;
 
void setup() {
   Serial.begin(115200);
   irrecv.enableIRIn();
}
 
void loop() {
   if (irrecv.decode(&results)) {
      Serial.print("0x");
      Serial.println( (unsigned long) results.value, HEX);
      if (results.value == 0x3E108)
      {
        Serial.println("ENTER");
      }
      delay(250);
      irrecv.resume();
      }
   
}
