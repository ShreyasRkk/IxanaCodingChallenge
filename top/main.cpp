#include "driver.hpp"
#include <iostream>

int main() {
    DeviceDriver driver;

    driver.resetDevice();
    
    // Example for Mode 0
    driver.enterMode0();
    if (driver.isConfigurationDone()) {
        if (driver.isSuccess()) {
            std::cout << "Mode 0 configuration successful!" << std::endl;
        } else {
            std::cout << "Mode 0 configuration failed!" << std::endl;
        }
    }

    // Example for Mode 1
    driver.enterMode1();
    if (driver.isConfigurationDone()) {
        if (driver.isSuccess()) {
            std::cout << "Mode 1 configuration successful!" << std::endl;
        } else {
            std::cout << "Mode 1 configuration failed!" << std::endl;
        }
    }

    // Example for Mode 2
    driver.enterMode2();
    if (driver.isConfigurationDone()) {
        if (driver.isSuccess()) {
            std::cout << "Mode 2 configuration successful!" << std::endl;
        } else {
            std::cout << "Mode 2 configuration failed!" << std::endl;
        }
    }

    return 0;
}
