// This #include statement was automatically added by the Spark IDE.
#include "Adafruit_HTU21DF.h"

Adafruit_HTU21DF htu = Adafruit_HTU21DF();
char resultstr[64];

void setup() {
    htu.begin();
    Spark.variable("result", &resultstr, STRING);
}

void loop() {
  float humd = htu.readHumidity();
  float temp = htu.readTemperature() * 9 / 5 + 32; // Convert to F
  sprintf(resultstr, "{\"data1\":%f,\"data2\":%f}", humd, temp);
  delay(30000);
}
