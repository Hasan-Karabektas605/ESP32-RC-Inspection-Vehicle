
#ifndef WIFI_MONITOR_H
#define WIFI_MONITOR_H

#include <WiFi.h>

struct WiFiStatus {
    int rssi;
    const char* quality;
    bool connected;
};

inline WiFiStatus getWiFiStatus() {
    if (WiFi.status() != WL_CONNECTED) {
        return {-127, "DISCONNECTED", false};
    }

    int rssi = WiFi.RSSI();
    const char* quality;

    if (rssi >= -50) {
        quality = "EXCELLENT";
    } else if (rssi >= -65) {
        quality = "GOOD";
    } else if (rssi >= -75) {
        quality = "FAIR";
    } else {
        quality = "WEAK";
    }

    return {rssi, quality, true};
}

#endif
