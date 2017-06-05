// ESP8266 DS18B20 ArduinoIDE Thingspeak IoT Example code
// http://vaasa.hacklab.fi
//
// https://github.com/milesburton/Arduino-Temperature-Control-Library
// https://gist.github.com/jeje/57091acf138a92c4176a


#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 5




OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature DS18B20(&oneWire);


char temperatureString[6];

void setup(void){
  Serial.begin(115200);
  Serial.println("START");
  

  DS18B20.begin();
   

}

float getTemperature() {
  float temp;
  do {
    DS18B20.requestTemperatures(); 
    temp = DS18B20.getTempCByIndex(0);
    delay(100);
  } while (temp == 85.0 || temp == (-127.0));
  return temp;
}


void loop() {

  float temperature = getTemperature();

  dtostrf(temperature, 2, 2, temperatureString);
  // send temperature to the serial console
  Serial.println(temperatureString);

  /*WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }*/

  /*client.print(String("GET ") + path + temperatureString + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: keep-alive\r\n\r\n");*/
  delay(500);

}
