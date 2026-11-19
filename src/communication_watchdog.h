#ifndef COMMUNICATION_WATCHDOG_H
#define COMMUNICATION_WATCHDOG_H

#include <stdint.h>

class CommunicationWatchdog {
private:
    uint32_t lastCommandTime = 0;
    uint32_t timeoutMs;
    bool commandReceived = false;

public:
    explicit CommunicationWatchdog(uint32_t timeout = 2000)
        : timeoutMs(timeout) {}

    void reset(uint32_t currentTime) {
        lastCommandTime = currentTime;
        commandReceived = true;
    }

    bool isConnectionLost(uint32_t currentTime) const {
        return !commandReceived ||
               (currentTime - lastCommandTime >= timeoutMs);
    }

    bool shouldStopVehicle(uint32_t currentTime) const {
        return isConnectionLost(currentTime);
    }

    void setTimeout(uint32_t timeout) {
        timeoutMs = timeout;
    }
};

#endif
