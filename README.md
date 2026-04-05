# Smart Home Automation System

A modular C++ implementation of a Smart Home Automation System that demonstrates various design patterns for managing smart devices, grouping them, and automating their interactions.

## Project Overview

This project simulates a modern smart home environment with various devices such as lights, thermostats, security cameras, door locks, and motion sensors. The system provides a flexible and extensible architecture that allows easy creation, management, and automation of these devices.

## Features

### Device Management
- **Multiple Device Types**: Lights, Thermostats, Cameras, Door Locks, Motion Sensors
- **Dynamic Device Creation**: Factory pattern for creating devices
- **Centralized Control**: Facade pattern for simplified system interaction

### Device Organization
- **Grouping by Location**: Organize devices by room, floor, or zone
- **Group Operations**: Turn on/off all devices in a group simultaneously
- **Composite Pattern**: Treat individual devices and groups uniformly

### Interaction and Automation
- **Observer Pattern**: Devices can react to events (e.g., motion sensor triggers light)
- **Command Pattern**: Commands can be executed, queued, and undone
- **Strategy Pattern**: Different automation modes (Energy Saving, Comfort)
- **State Pattern**: Devices manage internal states (e.g., Light: OFF, ON, DIMMED)

## Design Patterns Used

1. **Factory Pattern** - `DeviceFactory`, `GenericFactory`
   - Creates different types of devices dynamically
   - Supports multiple brands/variants without core system changes

2. **Composite Pattern** - `DeviceGroup`, `DeviceLeaf`, `IComponent`
   - Organizes devices into hierarchical groups
   - Allows uniform operations on individual devices and groups

3. **Observer Pattern** - `MotionSensor`, `DeviceObserverAdapter`, `IObserver`
   - Enables devices to communicate changes automatically
   - Motion sensors trigger other devices

4. **Command Pattern** - `CommandManager`, `TurnOnCommand`, `TurnOffCommand`, `SetTemperatureCommand`
   - Represents operations as objects
   - Supports undo functionality

5. **Strategy Pattern** - `AutomationContext`, `EnergySavingMode`, `ComfortMode`
   - Different automation modes can be switched at runtime
   - Extensible for new modes

6. **State Pattern** - `LightState`, `LightOnState`, `LightOffState`, `LightDimmedState`
   - Manages device state transitions
   - Smooth state changes based on commands

7. **Facade Pattern** - `SmartHomeFacade`
   - Provides simplified interface to complex subsystem
   - Hides implementation details from clients

## Project Structure

```
Smart home/
├── devices/          # Device implementations
│   ├── Light.cpp/h
│   ├── Thermostat.cpp/h
│   ├── Camera.cpp/h
│   ├── DoorLock.cpp/h
│   ├── MotionSensor.cpp/h
│   └── IDevice.h
├── factory/          # Factory pattern
│   ├── DeviceFactory.h
│   ├── GenericFactory.cpp/h
├── composite/        # Composite pattern
│   ├── DeviceGroup.cpp/h
│   ├── DeviceLeaf.cpp/h
│   └── IComponent.h
├── command/          # Command pattern
│   ├── Command.h
│   ├── CommandManager.cpp/h
│   ├── TurnOnCommand.cpp/h
│   ├── TurnOffCommand.cpp/h
│   └── SetTemperatureCommand.cpp/h
├── observer/         # Observer pattern
│   ├── IObserver.h
│   ├── ISubject.h
│   └── DeviceObserverAdapter.cpp/h
├── strategy/         # Strategy pattern
│   ├── AutomationMode.h
│   ├── AutomationContext.cpp/h
│   ├── EnergySavingMode.cpp/h
│   └── ComfortMode.cpp/h
├── state/            # State pattern
│   └── LightState.cpp/h
├── facade/           # Facade pattern
│   └── SmartHomeFacade.cpp/h
├── main.cpp          # Demo program
├── CMakeLists.txt    # CMake build file
├── Makefile          # Make build file
└── README.md         # This file
```

## Building the Project

### Using Make (Linux/Mac/Windows with MinGW)

```bash
# Build the project
make build
# or
mingw32-make build

# Run the executable
./smarthome
# or on Windows
smarthome.exe

# Clean build files
make clean
```

### Using CMake

```bash
# Create build directory
mkdir build
cd build

# Configure and build
cmake ..
cmake --build .

# Run the executable
./smarthome
# or on Windows
smarthome.exe
```

## Requirements

- C++17 compatible compiler (GCC, Clang, or MSVC)
- Make or CMake (for building)
- Windows: MinGW-w64 or Visual Studio

## Usage Example

```cpp
#include "facade/SmartHomeFacade.h"
#include "factory/GenericFactory.h"

// Create the smart home system
SmartHomeFacade home(make_unique<GenericFactory>());

// Add devices
home.addLight("LivingRoomLight");
home.addThermostat("HallThermostat");
home.addCamera("FrontDoorCamera");

// Create groups
home.createGroup("LivingRoom");
home.addDeviceToGroup("LivingRoomLight", "LivingRoom");

// Control devices
home.turnOn("LivingRoomLight");
home.setTemperature("HallThermostat", 25);

// Control groups
home.turnOnGroup("LivingRoom");

// Connect motion sensor to devices
home.connectMotionToDevice("LivingRoomSensor", "LivingRoomLight");

// Set automation mode
home.setModeEnergySaving();
home.applyMode();

// Undo last command
home.undoLast();
```

## Example Scenarios

### 1. Motion Detection Triggers Light
When a motion sensor detects movement, it automatically turns on connected lights.

### 2. Group Operations
Turn off all devices in a room with a single command.

### 3. Command Undo
All device operations can be undone, restoring previous states.

### 4. Automation Modes
- **Energy Saving Mode**: Automatically manages devices for efficiency
- **Comfort Mode**: Maintains preset preferences

### 5. Device State Management
Lights smoothly transition between OFF, ON, and DIMMED states.

## Notes

- The system uses modern C++ features (smart pointers, move semantics)
- All patterns are properly implemented and integrated
- The code follows object-oriented design principles
- Error handling and user feedback are included throughout

## License

This project is for educational purposes, demonstrating design patterns in C++.

