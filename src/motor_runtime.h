
#ifndef MOTOR_RUNTIME_H
#define MOTOR_RUNTIME_H

#include <Arduino.h>

class MotorRuntime {
private:
    unsigned long totalRuntime = 0;
    unsigned long startTime = 0;
    bool running = false;

public:
    void update(bool motorActive) {
        if (motorActive && !running) {
            startTime = millis();
            running = true;
        }

        if (!motorActive && running) {
            totalRuntime += millis() - startTime;
            running = false;
        }
    }

    unsigned long getRuntimeSeconds() const {
        unsigned long runtime = totalRuntime;

        if (running) {
            runtime += millis() - startTime;
        }

        return runtime / 1000;
    }

    void reset() {
        totalRuntime = 0;
        startTime = millis();
    }
};

#endif
