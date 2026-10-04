# PedoGuard: Smart Diabetic Footwear Monitoring System

## 🛠 Pin Configuration Table

| Subsystem | Component Name | Pin Name / Number | Interface / Type |
| :--- | :--- | :--- | :--- |
| Pressure | Sensor 1 (Hallux) | `PIN_FSR_HALLUX` (36 / VP) | ADC Input[cite: 1, 3] |
| Pressure | Sensor 2 (1st Metatarsal) | `PIN_FSR_1ST_MET` (39 / VN) | ADC Input[cite: 1, 3] |
| Pressure | Sensor 3 (3rd Metatarsal) | `PIN_FSR_3RD_MET` (34) | ADC Input[cite: 1, 3] |
| Pressure | Sensor 4 (5th Metatarsal) | `PIN_FSR_5TH_MET` (35) | ADC Input[cite: 1, 3] |
| Pressure | Sensor 5 (Heel) | `PIN_FSR_HEEL` (32) | ADC Input[cite: 1, 3] |
| Microclimate | DHT22 Temp & Humidity | `PIN_DHT_SENSOR` (27) | One-Wire Digital[cite: 1, 3] |
| Actuators | Haptic Vibrator | `PIN_VIBRATOR` (14) | Digital Output[cite: 1, 3, 13] |
| Actuators | UV-C Sterilization LED | `PIN_UV_LIGHT` (12) | Digital Output[cite: 1, 3, 13] |
| Actuators | Microclimate Cooling Fan | `PIN_FAN` (13) | Digital Output[cite: 1, 3, 13] |

---

## 📂 Project Architecture & Functions

### 1. `include/pin_config.h`
Centralized hardware configuration file containing pin maps and threshold settings[cite: 1, 3].

### 2. `src/pressure_sensor.cpp`
* `initPressureSensors()`: Initializes input registers.
* `readPressureSensors()`: Reads raw ADC values across all 5 FSR sensors[cite: 1, 3].
* `checkOverPressure()`: Returns `true` if any sensor exceeds `OVERPRESSURE_THRESHOLD`[cite: 3].

### 3. `src/microclimate.cpp`
* `processMicroclimate()`: Evaluates temperature and humidity against predefined thresholds ($35^\circ\text{C}$ / $70\%$) to control active cooling[cite: 3].

### 4. `src/actuators.cpp`
* `initActuators()`: Configures output driver pins.
* `setActuatorState()`: Controls vibrator, UV-C light, and cooling fan outputs[cite: 1, 3, 13].