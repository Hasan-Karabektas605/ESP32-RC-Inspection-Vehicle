# ESP32-RC-Inspection-Vehicle

An embedded systems project focused on developing a Wi-Fi-controlled robotic inspection vehicle using the ESP32 microcontroller and modular C++ software.

## Project Overview

The goal is to design and implement a remotely controlled inspection vehicle capable of receiving commands from a computer and transmitting real-time sensor telemetry.

The project combines embedded programming, wireless communication, sensor integration, motor control, and safety mechanisms.

## Technologies

- **Microcontroller:** ESP32
- **Programming Language:** C++
- **Wireless Communication:** Wi-Fi
- **Development:** Embedded Systems
- **Sensors:** HC-SR04, DHT11, LDR, SW-420
- **Desktop Application:** C++ (planned)

## Software Modules

The repository contains modular components for vehicle control, monitoring, and safety.

| Module | Purpose |
|--------|---------|
| `main.cpp` | Vehicle control simulation |
| `motor_runtime.h` | Motor runtime monitoring |
| `motor_speed_controller.h` | Motor speed control |
| `distance_filter.h` | Distance measurement filtering |
| `obstacle_alert.h` | Obstacle detection alerts |
| `communication_watchdog.h` | Communication timeout monitoring |
| `telemetry_logger.h` | Sensor telemetry logging |
| `wifi_monitor.h` | Wi-Fi connection monitoring |
| `sensor_failure_guard.h` | Distance sensor failure protection |

## System Architecture

```text
       C++ Desktop Application
                 |
          Wi-Fi Connection
                 |
             ESP32 MCU
                 |
      +----------+----------+
      |          |          |
 Motor Control  Sensors   Safety
      |          |          |
 DC Motors    HC-SR04    Watchdog
              DHT11      Alerts
              LDR        Failure Guard
              SW-420
```

## Key Features

### Vehicle Control
- Modular motor control architecture
- Motor speed management
- Remote-control functionality under development

### Sensor Monitoring
- Distance measurement filtering
- Obstacle detection logic
- Sensor failure monitoring
- Planned environmental and vibration sensing

### Communication and Telemetry
- Wi-Fi monitoring module
- Communication watchdog
- Telemetry logging
- Planned bidirectional communication with a C++ desktop application

### Safety
- Communication timeout detection
- Obstacle proximity alerts
- Invalid distance reading detection
- Sensor timeout protection

## Development Status

**Status: Work in Progress**

The repository currently focuses on developing modular C++ components and vehicle control simulation.

Individual modules are being developed before full integration into the main application and physical hardware.

## Project Objectives

This project aims to develop practical experience in:

- Embedded C++ programming
- ESP32 microcontroller development
- Real-time sensor data processing
- Wireless communication protocols
- Modular software architecture
- Fault detection and safety mechanisms
- Hardware and software integration

## Academic Context

Developed as part of a university Design Laboratory project, with a focus on practical embedded systems engineering.

## Future Improvements

Potential extensions include advanced telemetry visualization, improved motor control, automated safety responses, and additional diagnostic capabilities.

---

**Project Category:** Embedded Systems / Robotics / IoT

**Development Language:** C++
