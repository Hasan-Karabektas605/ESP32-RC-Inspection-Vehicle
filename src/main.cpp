
#include <iostream>

int main() {
    char command;

    std::cout << "ESP32 RC Inspection Vehicle\n";
    std::cout << "Movement Control Simulation\n";

    while (true) {
        std::cout << "\nEnter command (W/A/S/D, X=Stop, Q=Quit): ";
        std::cin >> command;

        if (command == 'Q' || command == 'q') {
            std::cout << "Exiting simulation...\n";
            break;
        }

        switch (command) {
            case 'W':
            case 'w':
                std::cout << "Moving Forward\n";
                break;

            case 'S':
            case 's':
                std::cout << "Moving Backward\n";
                break;

            case 'A':
            case 'a':
                std::cout << "Turning Left\n";
                break;

            case 'D':
            case 'd':
                std::cout << "Turning Right\n";
                break;

            case 'X':
            case 'x':
                std::cout << "Vehicle Stopped\n";
                break;

            default:
                std::cout << "Invalid Command\n";
                break;
        }
    }

    return 0;
}
