
#ifndef EMERGENCY_STOP_CONTROLLER_H
#define EMERGENCY_STOP_CONTROLLER_H

enum class DriveCommand {
    STOP,
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};

class EmergencyStopController {
private:
    bool emergencyActive = false;

public:
    // Activate emergency stop
    void activate() {
        emergencyActive = true;
    }

    // Reset only when motors are stopped
    bool reset(bool motorsStopped) {
        if (!motorsStopped) {
            return false;
        }

        emergencyActive = false;
        return true;
    }

    // Block movement during emergency
    DriveCommand filterCommand(
        DriveCommand command
    ) const {
        if (emergencyActive) {
            return DriveCommand::STOP;
        }

        return command;
    }

    // Return emergency stop status
    bool isActive() const {
        return emergencyActive;
    }
};

#endif


