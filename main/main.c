#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>
#include <DHT.h>

#include "include/pin_config.h"
#include "include/pressure_sensor.h"
#include "include/microclimate.h"
#include "include/actuators.h"

DHT dht(PIN_DHT_SENSOR, DHT22);
WebServer server(80);

ActuatorState systemActuators = {false, false, false};
bool autoFanMode = true;

uint16_t arduinoAnalogRead(uint8_t pin) {
    return analogRead(pin);
}

void arduinoDigitalWrite(uint8_t pin, uint8_t val) {
    digitalWrite(pin, val);
}

void arduinoPinMode(uint8_t pin, uint8_t mode) {
    pinMode(pin, mode);
}

void setup() {
    Serial.begin(115200);

    initActuators(arduinoPinMode);
    pinMode(PIN_VIBRATOR, OUTPUT);
    pinMode(PIN_UV_LIGHT, OUTPUT);
    pinMode(PIN_FAN, OUTPUT);

    dht.begin();
    initPressureSensors(arduinoPinMode);

    WiFi.softAP("PedoGuard_AP", "123456789");
    Serial.println("PedoGuard AP Started: 192.168.4.1");

    server.on("/", []() {
        server.send(200, "text/plain", "PedoGuard");
    });
    server.begin();
}

void loop() {
    server.handleClient();

    static unsigned long lastSample = 0;
    if (millis() - lastSample > 200) {
        lastSample = millis();

        PressureData pData = readPressureSensors(arduinoAnalogRead);

        float temp = dht.readTemperature();
        float hum = dht.readHumidity();
        if (isnan(temp)) temp = 25.0f;
        if (isnan(hum)) hum = 50.0f;

        MicroclimateData mData = processMicroclimate(temp, hum);

        systemActuators.vibrator = pData.isOverPressure;
        if (autoFanMode) {
            systemActuators.fan = mData.needsCooling;
        }

        setActuatorState(systemActuators, arduinoDigitalWrite);
    }
}