#ifndef MICROCLIMATE_H
#define MICROCLIMATE_H

#include "pin_config.h"

struct MicroclimateData {
    float temperature;
    float humidity;
    bool needsCooling;
};

struct MicroclimateData processMicroclimate(float temp, float humidity);

#endif