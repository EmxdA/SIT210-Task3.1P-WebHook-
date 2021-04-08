# SIT210-Task3.1P-WebHook-
#include <Adafruit_DHT_Particle.h>

#define DHTPIN D3

DHT dht(DHTPIN, 22);
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
    double temp_data = dht.getTempCelcius(); 
    if (temp_data > 0)
        Particle.publish("Temp", String(temp_data), PRIVATE);
    delay(30000);
}
