#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "Airtel_Tapas"; //"YOUR_WIFI_SSID";
const char* password = "wifi@CogLab#1"; //"YOUR_WIFI_PASSWORD";
const char* server = "https://api.thingspeak.com/channels/2901835/feeds.json?api_key=J76W5U4T53DGLEN0&results=2"; //"YOUR_READ_API"
const char* writeApiKey = "7K3G8QQIOP6E5SON";

#define LED_PIN 12
#define BUZZER_PIN 13
#define LDR_PIN 34

void setup() {
    Serial.begin(115200);
    pinMode(LED_PIN, OUTPUT);
    pinMode(BUZZER_PIN, OUTPUT);
    pinMode(LDR_PIN, INPUT);

    WiFi.begin(ssid, password);
    Serial.print("Connecting to WiFi...");
    
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print(".");
    }
    Serial.println("\nConnected to WiFi");
}

void loop() {
    if (WiFi.status() == WL_CONNECTED) {
        HTTPClient http;
        http.begin(server);
        int httpResponseCode = http.GET();

        if (httpResponseCode == 200) {
            String payload = http.getString();
            Serial.println(payload);

            int ledState = getValue(payload, "field1");
            int buzzerState = getValue(payload, "field2");

            digitalWrite(LED_PIN, ledState);
            digitalWrite(BUZZER_PIN, buzzerState);
        }
        http.end();

        int ldrValue = analogRead(LDR_PIN);
        Serial.print("LDR Value: ");
        Serial.println(ldrValue);

        String getURL = "http://api.thingspeak.com/update?api_key=" + String(writeApiKey) + "&field3=" + String(ldrValue);

        http.begin(getURL);
        int httpGetCode = http.GET();
        if (httpGetCode > 0) {
            Serial.println("LDR sent to ThingSpeak (GET): Code " + String(httpGetCode));
        } else {
            Serial.println("Error sending GET: " + http.errorToString(httpGetCode));
        }
        http.end();
    }
    delay(5000);
}

int getValue(String data, String field) {
    int index = data.indexOf(field + "\":\"");
    if (index != -1) {
        return data.charAt(index + field.length() + 3) - '0';
    }
    return 0;
}
