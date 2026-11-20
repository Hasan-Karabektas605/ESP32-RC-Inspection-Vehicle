
#ifndef PARKING_ASSISTANT_H
#define PARKING_ASSISTANT_H

#include <cmath>

class ParkingAssistant {
private:
    bool enabled = true;

public:
    void setEnabled(bool state) {
        enabled = state;
    }

    bool isEnabled() const {
        return enabled;
    }

    int getMaxReverseSpeed(float distance) const {
        if (!enabled)
            return 100;

        if (!std::isfinite(distance) || distance < 2.0f)
            return 0;

        if (distance <= 10.0f)
            return 0;

        if (distance <= 20.0f)
            return 20;

        if (distance <= 40.0f)
            return 40;

        if (distance <= 60.0f)
            return 60;

        return 100;
    }
};

#endif
