#include "../include/microclimate.h"

MicroclimateData processMicroclimate(float temp, float humidity) {
    MicroclimateData data;
    data.temperature = temp;
    data.humidity = humidity;
    
    if (temp >= TEMP_THRESHOLD_HIGH || humidity >= HUM_THRESHOLD_HIGH) {
        data.needsCooling = true;
    } else {
        data.needsCooling = false;
    }
    return data;
}