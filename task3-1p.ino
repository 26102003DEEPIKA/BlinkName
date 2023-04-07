// This #include statement was automatically added by the Particle IDE.
#include <Adafruit_DHT.h>
#define DHTPIN 2
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup() 
{
  dht.begin();
}

void loop() 
{
  
   float temp = dht.getTempCelcius();
   Particle.publish("temp", String(temp), PRIVATE);
   delay(3000);
}