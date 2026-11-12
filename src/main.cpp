
#include <iostream>
#include <limits>

int main() {
    char command;
    int pwmValue = 128;  // Default PWM value (0-255)

    std::cout << "====================================\n";
    std::cout << "   ESP32 RC INSPECTION VEHICLE\n";
    std::cout << "   Movement & PWM Control Simulation\n";
    std::cout << "====================================\n";

    while (true) {
        std::cout << "\n--- CONTROL MENU ---\n";
        std::cout << "W - Move Forward\n";
        std::cout << "S - Move Backward\n";
        std::cout << "A - Turn Left\n";
        std::cout << "D - Turn Right\n";
        std::cout << "X - Stop Vehicle\n";
        std::cout << "P - Set PWM Speed\n";
        std::cout << "V - View Current Speed\n";
        std::cout << "Q - Quit Simulation\n";
        std::cout << "Enter command: ";

        if (!(std::cin >> command)) {
            break;
        }

        if (command == 'Q' || command == 'q') {
            std::cout << "Exiting simulation...\n";
            break;
        }

        switch (command) {

            case 'W':
            case 'w':
                std::cout << "Moving Forward | PWM: "
                          << pwmValue << "/255\n";
                break;

            case 'S':
            case 's':
                std::cout << "Moving Backward | PWM: "
                          << pwmValue << "/255\n";
                break;

            case 'A':
            case 'a':
                std::cout << "Turning Left | PWM: "
                          << pwmValue << "/255\n";
                break;

            case 'D':
            case 'd':
                std::cout << "Turning Right | PWM: "
                          << pwmValue << "/255\n";
                break;

            case 'X':
            case 'x':
                std::cout << "Vehicle Stopped\n";
                break;

            case 'P':
            case 'p': {
                int newPWM;

                std::cout << "Enter PWM value (0-255): ";

                if (!(std::cin >> newPWM)) {
                    std::cout << "Invalid input!\n";
                    std::cin.clear();
                    std::cin.ignore(
                        std::numeric_limits<std::streamsize>::max(),
                        '\n'
                    );
                    break;
                }

                if (newPWM >= 0 && newPWM <= 255) {
                    pwmValue = newPWM;

                    std::cout << "PWM speed updated: "
                              << pwmValue << "/255\n";
                } else {
                    std::cout << "Error: PWM must be "
                              << "between 0 and 255.\n";
                }
                break;
            }

            case 'V':
            case 'v':
                std::cout << "Current PWM value: "
                          << pwmValue << "/255\n";

                std::cout << "PWM Duty Cycle: "
                          << (pwmValue * 100.0 / 255.0)
                          << "%\n";
                break;

            default:
                std::cout << "Invalid Command!\n";
                break;
        }
    }

    return 0;
}
