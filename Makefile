CXX = g++
CXXFLAGS = -std=c++17 -Wall -I.

SRC = \
    main.cpp \
    devices/Light.cpp \
    devices/Thermostat.cpp \
    devices/Camera.cpp \
    devices/DoorLock.cpp \
    devices/MotionSensor.cpp \
    state/LightState.cpp \
    composite/DeviceLeaf.cpp \
    composite/DeviceGroup.cpp \
    observer/DeviceObserverAdapter.cpp \
    command/TurnOnCommand.cpp \
    command/TurnOffCommand.cpp \
    command/SetTemperatureCommand.cpp \
    command/CommandManager.cpp \
    strategy/EnergySavingMode.cpp \
    strategy/ComfortMode.cpp \
    strategy/AutomationContext.cpp \
    factory/GenericFactory.cpp \
    facade/SmartHomeFacade.cpp

OBJ = $(SRC:.cpp=.o)

TARGET = smarthome

# Default build
all: build

# Build target
build: $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)
	@echo "Build finished!"

# Run target
run: build
	./$(TARGET)

# Clean target
clean:
	rm -f $(OBJ) $(TARGET)
	@echo "Cleaned!"

# Rebuild target
rebuild: clean build
