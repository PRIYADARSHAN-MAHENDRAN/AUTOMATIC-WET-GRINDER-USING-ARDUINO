# Wet Grinder Control System

This project involves a control system for a wet grinder, utilizing various sensors and relays to automate the grinding process based on user-selected consistency and temperature monitoring. The system is built using an Arduino microcontroller.

## Table of Contents

- [Pin Assignments](#pin-assignments)
- [Setup](#setup)
- [Loop](#loop)
- [Functions](#functions)
  - [checkConsistencySelection](#checkconsistencyselection)
  - [startGrindingTask](#startgrindingtask)
  - [checkMotorTemperature](#checkmotortemperature)
  - [readMotorTemperature](#readmotortemperature)
- [Hardware Requirements](#hardware-requirements)
- [Software Requirements](#software-requirements)
- [Installation](#installation)
- [Usage](#usage)
- [License](#license)

## Pin Assignments

- `consistencyButtonThickPin`: Pin 2 (used for selecting thick consistency)
- `consistencyButtonWateryPin`: Pin 4 (used for selecting watery consistency)
- `waterPumpRelayPin`: Pin 7 (controls the water pump)
- `wetGrinderMotorRelayPin`: Pin 8 (controls the wet grinder motor)
- `temperatureSensorPin`: Analog Pin A0 (reads the motor temperature)
- `buzzerPin`: Pin 13 (activates a buzzer for notifications)

## Setup

The `setup` function initializes the pin modes and begins serial communication for debugging. It sets the pin modes for the consistency buttons, water pump relay, wet grinder motor relay, and buzzer. Additionally, it starts serial communication for debugging purposes.

## Loop

The `loop` function waits for a consistency selection and then proceeds with the grinding task while monitoring the motor temperature. It handles the main logic of the control system, including checking the consistency selection, monitoring the motor temperature, starting the grinding task, and providing buzzer notifications upon task completion.

## Functions

### checkConsistencySelection

Checks which consistency button is pressed and returns the selection. It reads the state of the consistency buttons and determines whether the thick or watery consistency button has been pressed, returning the appropriate value.

### startGrindingTask

Starts the grinding task based on the selected consistency and monitors the motor temperature. It controls the wet grinder motor and water pump based on the selected consistency and ensures the motor temperature is within a safe range during the grinding process.

### checkMotorTemperature

Monitors the motor temperature and stops the motor if it exceeds a threshold. It reads the motor temperature and stops the wet grinder motor if the temperature exceeds a predefined threshold, waiting for it to cool down before resuming operation.

### readMotorTemperature

Reads the motor temperature from the sensor and converts it to a usable value. It reads the analog value from the temperature sensor, converts it to a voltage, and then calculates the corresponding temperature.

## Hardware Requirements

- Arduino board (e.g., Arduino Uno)
- Relay modules (2x)
- Temperature sensor (e.g., LM35)
- Push buttons (2x)
- Buzzer
- Wet grinder
- Water pump
- Connecting wires

## Software Requirements

- Arduino IDE

## Installation

1. Connect the hardware components to the Arduino as per the pin assignments.
2. Upload the code to the Arduino using the Arduino IDE.

## Usage

1. Power the Arduino and connected components.
2. Press the desired consistency button (thick or watery).
3. The system will automatically start the grinding process, monitor the motor temperature, and control the water pump.
4. A buzzer will sound upon completion.

## License

This project is licensed under the MIT License.
