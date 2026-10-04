#include "../include/actuators.h"

void initActuators(void (*pinModeFunc)(uint8_t pin, uint8_t mode)) {
    // Mode setup for output pins
}

void setActuatorState(ActuatorState state, void (*digitalWriteFunc)(uint8_t pin, uint8_t val)) {
    digitalWriteFunc(PIN_VIBRATOR, state.vibrator ? 1 : 0);
    digitalWriteFunc(PIN_UV_LIGHT, state.uvLight  ? 1 : 0);
    digitalWriteFunc(PIN_FAN,      state.fan      ? 1 : 0);
}