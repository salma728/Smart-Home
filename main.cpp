#include <iostream>
#include <string>
#include <sstream>
#include "factory/GenericFactory.h"
#include "facade/SmartHomeFacade.h"
#include "devices/MotionSensor.h"

using namespace std;

void printMenu()
{
    cout << "\n========================================\n";
    cout << "    Smart Home Control System\n";
    cout << "========================================\n";
    cout << "DEVICE MANAGEMENT:\n";
    cout << "  1. Add Light\n";
    cout << "  2. Add Thermostat\n";
    cout << "  3. Add Camera\n";
    cout << "  4. Add Door Lock\n";
    cout << "  5. Add Motion Sensor\n";
    cout << "\nGROUP MANAGEMENT:\n";
    cout << "  6. Create Group\n";
    cout << "  7. Add Device to Group\n";
    cout << "\nDEVICE CONTROL:\n";
    cout << "  8. Turn On Device\n";
    cout << "  9. Turn Off Device\n";
    cout << " 10. Set Temperature\n";
    cout << "\nGROUP CONTROL:\n";
    cout << " 11. Turn On Group\n";
    cout << " 12. Turn Off Group\n";
    cout << "\nAUTOMATION:\n";
    cout << " 13. Connect Motion Sensor to Device\n";
    cout << " 14. Trigger Motion Sensor\n";
    cout << " 15. Set Energy Saving Mode\n";
    cout << " 16. Set Comfort Mode\n";
    cout << " 17. Apply Current Mode\n";
    cout << "\nSYSTEM:\n";
    cout << " 18. View Group Status\n";
    cout << " 19. Undo Last Command\n";
    cout << " 20. Run Demo (Auto)\n";
    cout << "  0. Exit\n";
    cout << "========================================\n";
    cout << "Enter your choice: ";
}

void runDemo(SmartHomeFacade &home)
{
    cout << "\n=== Running Automated Demo ===\n\n";

    // Add devices
    cout << "--- Adding Devices ---\n";
    home.addLight("LivingRoomLight");
    home.addThermostat("HallThermostat");
    home.addCamera("FrontDoorCamera");
    home.addDoorLock("MainDoorLock");
    home.addMotionSensor("LivingRoomSensor");

    // Create groups
    cout << "\n--- Creating Groups ---\n";
    home.createGroup("LivingRoom");
    home.addDeviceToGroup("LivingRoomLight", "LivingRoom");
    home.addDeviceToGroup("LivingRoomSensor", "LivingRoom");

    home.createGroup("Entrance");
    home.addDeviceToGroup("FrontDoorCamera", "Entrance");
    home.addDeviceToGroup("MainDoorLock", "Entrance");

    // Test commands
    cout << "\n--- Testing Commands ---\n";
    home.turnOn("LivingRoomLight");
    home.turnOff("LivingRoomLight");
    home.undoLast();

    cout << "\n--- Testing Thermostat ---\n";
    home.setTemperature("HallThermostat", 25);
    home.undoLast();

    // Test observer
    cout << "\n--- Testing Observer Pattern ---\n";
    home.connectMotionToDevice("LivingRoomSensor", "LivingRoomLight");
    home.connectMotionToDevice("LivingRoomSensor", "FrontDoorCamera");

    cout << "\n>>> Simulating motion...\n";
    auto sensor = dynamic_cast<MotionSensor *>(home.getDevice("LivingRoomSensor"));
    if (sensor)
        sensor->detectMotion();

    // Test groups
    cout << "\n--- Testing Group Operations ---\n";
    home.turnOnGroup("LivingRoom");
    home.turnOffGroup("Entrance");

    // Test automation
    cout << "\n--- Testing Automation ---\n";
    home.setModeEnergySaving();
    home.applyMode();
    home.setModeComfort();
    home.applyMode();

    // Show status
    cout << "\n--- Group Status ---\n";
    home.printGroupStatus("LivingRoom");
    home.printGroupStatus("Entrance");

    cout << "\n=== Demo Finished ===\n";
}

int main()
{
    SmartHomeFacade home(make_unique<GenericFactory>());
    
    cout << "=== Smart Home System Started ===\n";
    cout << "Type 'demo' to run automated demo, or use the menu for interactive control.\n";

    int choice;
    string input;
    string deviceName, groupName, sensorName;
    double temperature;

    while (true)
    {
        printMenu();
        cin >> input;

        // Check for demo command
        if (input == "demo" || input == "20")
        {
            runDemo(home);
            continue;
        }

        try
        {
            choice = stoi(input);
        }
        catch (...)
        {
            cout << "[Error] Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        switch (choice)
        {
        case 0:
            cout << "\nExiting Smart Home System. Goodbye!\n";
            return 0;

        case 1:
            cout << "Enter light name: ";
            cin >> deviceName;
            home.addLight(deviceName);
            break;

        case 2:
            cout << "Enter thermostat name: ";
            cin >> deviceName;
            home.addThermostat(deviceName);
            break;

        case 3:
            cout << "Enter camera name: ";
            cin >> deviceName;
            home.addCamera(deviceName);
            break;

        case 4:
            cout << "Enter door lock name: ";
            cin >> deviceName;
            home.addDoorLock(deviceName);
            break;

        case 5:
            cout << "Enter motion sensor name: ";
            cin >> deviceName;
            home.addMotionSensor(deviceName);
            break;

        case 6:
            cout << "Enter group name: ";
            cin >> groupName;
            home.createGroup(groupName);
            break;

        case 7:
            cout << "Enter device name: ";
            cin >> deviceName;
            cout << "Enter group name: ";
            cin >> groupName;
            home.addDeviceToGroup(deviceName, groupName);
            break;

        case 8:
            cout << "Enter device name: ";
            cin >> deviceName;
            home.turnOn(deviceName);
            break;

        case 9:
            cout << "Enter device name: ";
            cin >> deviceName;
            home.turnOff(deviceName);
            break;

        case 10:
            cout << "Enter thermostat name: ";
            cin >> deviceName;
            cout << "Enter temperature: ";
            cin >> temperature;
            home.setTemperature(deviceName, temperature);
            break;

        case 11:
            cout << "Enter group name: ";
            cin >> groupName;
            home.turnOnGroup(groupName);
            break;

        case 12:
            cout << "Enter group name: ";
            cin >> groupName;
            home.turnOffGroup(groupName);
            break;

        case 13:
            cout << "Enter motion sensor name: ";
            cin >> sensorName;
            cout << "Enter device name to connect: ";
            cin >> deviceName;
            home.connectMotionToDevice(sensorName, deviceName);
            break;

        case 14:
            cout << "Enter motion sensor name: ";
            cin >> sensorName;
            {
                auto sensor = dynamic_cast<MotionSensor *>(home.getDevice(sensorName));
                if (sensor)
                {
                    cout << ">>> Simulating motion...\n";
                    sensor->detectMotion();
                }
                else
                {
                    cout << "[Error] Motion sensor '" << sensorName << "' not found\n";
                }
            }
            break;

        case 15:
            home.setModeEnergySaving();
            cout << "[System] Energy Saving Mode set\n";
            break;

        case 16:
            home.setModeComfort();
            cout << "[System] Comfort Mode set\n";
            break;

        case 17:
            home.applyMode();
            break;

        case 18:
            cout << "Enter group name: ";
            cin >> groupName;
            home.printGroupStatus(groupName);
            break;

        case 19:
            home.undoLast();
            break;

        case 20:
            runDemo(home);
            break;

        default:
            cout << "[Error] Invalid choice. Please try again.\n";
            break;
        }
    }

    return 0;
}
