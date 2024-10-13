# IxanaCodingChallenge


# Device Driver for Modes 0, 1, and 2

## Overview
This project implements a device driver that configures a device to operate in **Modes 0, 1, and 2** based on the provided pin descriptions. The driver controls the configuration of these modes through various GPIO pins (`nRST`, `DONE`, `SUCCESS`, `CTRL`, `SELECT`, and `nTEST`) and uses helper functions for delay and communication.

The driver interacts with these pins to reset the device, enter a specific mode, and check whether the configuration was successful or not.

### Key Components:
1. **driver.hpp**: Header file defining the `DeviceDriver` class.
2. **driver.cpp**: Implementation of the `DeviceDriver` class, including pin initialization, reset, mode entry, and status checking.
3. **main.cpp**: Example application that demonstrates how to use the `DeviceDriver` class to configure the device for each mode.

## Project Structure

top
├── driver.hpp          # Header file for DeviceDriver class
├── driver.cpp          # Implementation file for DeviceDriver class
├── main.cpp            # Example application
└── inc/                # Directory containing provided helper files
    ├── board.h         # Board-specific definitions for pin numbers
    ├── coms.h          # Communication functions (e.g., send_communications)
    ├── delay.h         # Delay functions (e.g., delay_us)
    └── gpio.hpp        # GPIO handling for pin initialization, writing, reading


## Assumptions
The GPIO, communication, and delay functions are assumed to be defined in the provided gpio.hpp, coms.h, and delay.h files, but the actual implementations are not provided in this project. These functions are assumed to work as per their declarations:
gpio_out_t::init(), gpio_out_t::write()
gpio_in_t::init(), gpio_in_t::read()
delay_us(), send_communications()
The example data sent during configuration (0xAB, 0xCD, 0x12, 0x34, 0x56, 0x78) is arbitrary and serves only as an example.

## Time Estimation
The project took approximately 5 hours to complete, including:

Reading and understanding the requirements.
Designing the device driver class and functions.
Writing and testing the code for driver.cpp, driver.hpp, and main.cpp.
Creating the README and documenting the project.

## Additional Information
This implementation follows the given instructions strictly and does not modify any provided files (board.h, gpio.hpp, coms.h, delay.h). All functions declared in these files are assumed to be implemented elsewhere.
The driver handles the timing requirement for Mode 0 by calculating the necessary delay after sending the configuration data.
