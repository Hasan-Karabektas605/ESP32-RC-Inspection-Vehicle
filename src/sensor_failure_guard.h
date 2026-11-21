
#ifndef SENSOR_FAILURE_GUARD_H
#define SENSOR_FAILURE_GUARD_H

#include <stdint.h>

class SensorFailureGuard {
private:
    uint32_t lastValidReading = 0;
    uint32_t timeoutMs;
    bool sensorInitialized = false;
    bool sensorHealthy = false;

public:
    explicit SensorFailureGuard(uint32_t timeout = 2000)
        : timeoutMs(timeout) {}

    void updateDistance(float distanceCm, uint32_t currentTime) {
        if (distanceCm >= 2.0f && distanceCm <= 400.0f) {
            lastValidReading = currentTime;
            sensorInitialized = true;
            sensorHealthy = true;
        } else {
            sensorHealthy = false;
        }
    }

    bool isSensorHealthy(uint32_t currentTime) const {
        if (!sensorInitialized || !sensorHealthy) {
            return false;
        }

        return (uint32_t)(currentTime - lastValidReading) <= timeoutMs;
    }

    bool isMotionAllowed(uint32_t currentTime) const {
        return isSensorHealthy(currentTime);
    }

    void reset() {
        sensorInitialized = false;
        sensorHealthy = false;
        lastValidReading = 0;
    }
};

#endif
