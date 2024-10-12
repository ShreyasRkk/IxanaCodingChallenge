#ifndef DRIVER_HPP
#define DRIVER_HPP

#include "gpio.hpp"

class DeviceDriver {
public:
    DeviceDriver();
    void resetDevice();
    void enterMode0();
    void enterMode1();
    void enterMode2();
    bool isConfigurationDone();
    bool isSuccess();
private:
    void configurePinModes();
};

#endif
