#ifndef TELEMETRY_LOGGER_H
#define TELEMETRY_LOGGER_H

#include <fstream>
#include <ctime>
#include <string>

class TelemetryLogger {
private:
    std::ofstream file;

public:
    bool start(const std::string& filename = "telemetry.csv") {
        if (file.is_open())
            file.close();

        file.open(filename);

        if (!file.is_open())
            return false;

        file << "Timestamp,Distance_cm,Temperature_C,"
             << "Humidity_percent,Light_raw,Vibration\n";

        return file.good();
    }

    void log(float distance, float temperature,
             float humidity, int light, bool vibration) {

        if (!file.is_open())
            return;

        file << std::time(nullptr) << ","
             << distance << ","
             << temperature << ","
             << humidity << ","
             << light << ","
             << vibration << "\n";

        file.flush();
    }

    void stop() {
        if (file.is_open())
            file.close();
    }
};

#endif
