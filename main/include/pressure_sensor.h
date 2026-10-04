#ifndef PRESSURE_SENSOR_H
#define PRESSURE_SENSOR_H

#include <stdint.h>

#define NUM_SENSORS 5

// Pin Definitions for 5 FSR Sensors
#define PIN_FSR_HALLUX  36 // VP
#define PIN_FSR_1ST_MET 39 // VN
#define PIN_FSR_3RD_MET 34
#define PIN_FSR_5TH_MET 35
#define PIN_FSR_HEEL    32



// MUST CHANGE IN LATER
#define OVERPRESSURE_THRESHOLD 2500 

struct PressureData {
    uint16_t hallux;
    uint16_t met1;
    uint16_t met3;
    uint16_t met5;
    uint16_t heel;
    bool isOverPressure;
};

// Functions for Pressure Module
void initPressureSensors();
struct PressureData readPressureSensors(uint16_t (*analogReadFunc)(uint8_t pin));
bool checkOverPressure(const struct PressureData data, uint16_t threshold);

#endif