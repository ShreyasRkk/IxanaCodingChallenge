#include "driver.hpp"
#include "board.h"
#include "coms.h"
#include "delay.h"

DeviceDriver::DeviceDriver() {
    configurePinModes();
}

void DeviceDriver::configurePinModes() {
    // Setup pin modes based on board.h and gpio.hpp
}

void DeviceDriver::resetDevice() {
    // Implement reset using nRST
}

void DeviceDriver::enterMode0() {
    // Implement Mode 0 logic
}

void DeviceDriver::enterMode1() {
    // Implement Mode 1 logic
}

void DeviceDriver::enterMode2() {
    // Implement Mode 2 logic
}

bool DeviceDriver::isConfigurationDone() {
    // Check if DONE pin indicates configuration is complete
    return true;
}

bool DeviceDriver::isSuccess() {
    // Check if SUCCESS pin indicates successful configuration
    return true;
}
