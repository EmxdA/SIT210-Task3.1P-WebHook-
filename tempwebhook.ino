// This #include statement was automatically added by the Particle IDE.
#include <Adafruit_DHT_Particle.h>

#define DHTPIN D3

DHT dht(DHTPIN, DHT11);
int led1 = D7;

void setup() 
{
    pinMode(led1, OUTPUT);
    digitalWrite(led1, LOW);
    dht.begin();
    Particle.subscribe("hook-response/Temp", myHandler, MY_DEVICES);
}

void myHandler(const char *event, const char *data) {
  digitalWrite(led1, HIGH);
}

void loop() 
{
    float temp_data = dht.getTempCelcius(); 
    Particle.publish("Temp", String(temp_data), PRIVATE);
    delay(10000);
}