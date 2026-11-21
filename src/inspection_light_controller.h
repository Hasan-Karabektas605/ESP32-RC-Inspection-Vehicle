
#ifndef INSPECTION_LIGHT_CONTROLLER_H
#define INSPECTION_LIGHT_CONTROLLER_H

#include <stdint.h>

enum class LightMode {
    AUTO,
    ON,
    OFF
};

class InspectionLightController {
private:
    LightMode mode = LightMode::AUTO;

    bool lightsOn = false;
    bool sensorValid = false;

    int darkThreshold = 1400;
    int brightThreshold = 2300;

    // Default: lower ADC values indicate darkness
    bool darkWhenLow = true;

public:
    void setMode(LightMode newMode) {
        mode = newMode;

        if (mode == LightMode::ON)
            lightsOn = true;

        if (mode == LightMode::OFF)
            lightsOn = false;
    }

    bool setThresholds(int dark, int bright) {
        if (dark < 0 || bright > 4095 ||
            dark >= bright) {
            return false;
        }

        darkThreshold = dark;
        brightThreshold = bright;
        return true;
    }

    void setSensorPolarity(bool lowMeansDark) {
        darkWhenLow = lowMeansDark;
    }

    bool update(int lightLevel) {
        if (mode == LightMode::ON)
            return lightsOn = true;

        if (mode == LightMode::OFF)
            return lightsOn = false;

        if (lightLevel < 0 || lightLevel > 4095) {
            sensorValid = false;
            return lightsOn;
        }

        sensorValid = true;

        if (darkWhenLow) {
            if (lightLevel <= darkThreshold)
                lightsOn = true;
            else if (lightLevel >= brightThreshold)
                lightsOn = false;
        } else {
            if (lightLevel >= brightThreshold)
                lightsOn = true;
            else if (lightLevel <= darkThreshold)
                lightsOn = false;
        }

        return lightsOn;
    }

    bool areLightsOn() const {
        return lightsOn;
    }

    bool isSensorValid() const {
        return sensorValid;
    }

    LightMode getMode() const {
        return mode;
    }
};

#endif
