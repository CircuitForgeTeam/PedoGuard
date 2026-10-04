#ifndef PIN_CONFIG_H
#define PIN_CONFIG_H

//nalog Pins for presure sensors
#define PIN_FSR_HALLUX  36
#define PIN_FSR_1ST_MET 39
#define PIN_FSR_3RD_MET 34 
#define PIN_FSR_5TH_MET 35 
#define PIN_FSR_HEEL    32 

// DHT Sensor Pin
#define PIN_DHT_SENSOR  27

// Actuator Pins
#define PIN_VIBRATOR    14 
#define PIN_UV_LIGHT    12 
#define PIN_FAN         13 



// TODO :
// NOT COMPLETED YET
#define OVERPRESSURE_THRESHOLD 2500 // Must be change
#define TEMP_THRESHOLD_HIGH    35.0f // Celsius
#define HUM_THRESHOLD_HIGH     70.0f // Percentage (%)

#endif