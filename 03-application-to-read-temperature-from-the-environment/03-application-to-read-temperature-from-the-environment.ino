#include <DHT.h>

#define DHTPIN 2   
#define DHTTYPE DHT11
#define BUZZER_PIN 8
#define THRESHOLD_TEMP 30

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  pinMode(BUZZER_PIN, OUTPUT);
  dht.begin();
}

void loop() {
  float temperature = dht.readTemperature();

  if (isnan(temperature)) {
    Serial.println("Failed to read temperature.");
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  if (temperature > THRESHOLD_TEMP) {
    digitalWrite(BUZZER_PIN, HIGH);  
    Serial.println("Temperature crossed threshold! Buzzer ON.");
  } else {
    digitalWrite(BUZZER_PIN, LOW);  
  }

  delay(2000); 
}
