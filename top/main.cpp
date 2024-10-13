#include "driver.hpp"
#include <iostream>

int main() {
    DeviceDriver driver;
    std::cout << "Resetting device..." << std::endl;
    driver.resetDevice();

    // Test Mode 0
    std::cout << "Entering Mode 0..." << std::endl;
    driver.enterMode0();
    if (driver.isConfigurationDone()) {
        if (driver.isSuccess()) {
            std::cout << "Mode 0 configuration successful!" << std::endl;
        } else {
            std::cout << "Mode 0 configuration failed!" << std::endl;
        }
    } else {
        std::cout << "Mode 0 configuration not completed." << std::endl;
    }

    // Test Mode 1
    std::cout << "Entering Mode 1..." << std::endl;
    driver.enterMode1();
    if (driver.isConfigurationDone()) {
        if (driver.isSuccess()) {
            std::cout << "Mode 1 configuration successful!" << std::endl;
        } else {
            std::cout << "Mode 1 configuration failed!" << std::endl;
        }
    } else {
        std::cout << "Mode 1 configuration not completed." << std::endl;
    }

    // Test Mode 2
    std::cout << "Entering Mode 2..." << std::endl;
    driver.enterMode2();
    if (driver.isConfigurationDone()) {
        if (driver.isSuccess()) {
            std::cout << "Mode 2 configuration successful!" << std::endl;
        } else {
            std::cout << "Mode 2 configuration failed!" << std::endl;
        }
    } else {
        std::cout << "Mode 2 configuration not completed." << std::endl;
    }

    return 0;
}
