#ifndef MOTOR_SPEED_CONTROLLER_H
#define MOTOR_SPEED_CONTROLLER_H

class MotorSpeedController {
private:
    int currentSpeed = 0;
    int targetSpeed = 0;
    int accelerationStep = 5;

public:
    void setTargetSpeed(int speed) {
        if (speed > 255) speed = 255;
        if (speed < -255) speed = -255;

        targetSpeed = speed;
    }

    int update() {
        if (currentSpeed < targetSpeed) {
            currentSpeed += accelerationStep;

            if (currentSpeed > targetSpeed)
                currentSpeed = targetSpeed;
        }
        else if (currentSpeed > targetSpeed) {
            currentSpeed -= accelerationStep;

            if (currentSpeed < targetSpeed)
                currentSpeed = targetSpeed;
        }

        return currentSpeed;
    }

    int getCurrentSpeed() const {
        return currentSpeed;
    }

    void emergencyStop() {
        currentSpeed = 0;
        targetSpeed = 0;
    }
};

#endif
