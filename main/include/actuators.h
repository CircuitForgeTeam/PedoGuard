#ifndef ACTUATORS_H
#define ACTUATORS_H

#include <stdint.h>
#include "pin_config.h"

struct ActuatorState {
    bool vibrator;
    bool uvLight;
    bool fan;
};

void initActuators(void (*pinModeFunc)(uint8_t pin, uint8_t mode));
void setActuatorState(ActuatorState state, void (*digitalWriteFunc)(uint8_t pin, uint8_t val));

#endif