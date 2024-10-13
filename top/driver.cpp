#include "driver.hpp"
#include "board.h"
#include "coms.h"
#include "delay.h"

DeviceDriver::DeviceDriver() {
    configurePinModes();
}

void DeviceDriver::configurePinModes() {
    // Setting up GPIO pins using the pins defined in board.h
    gpio_out_t nRST(PIN_NRST);  
    gpio_out_t nTEST(PIN_NTEST);  
    gpio_in_t DONE(PIN_DONE);  
    gpio_in_t SUCCESS(PIN_SUCCESS);  
    gpio_out_t CTRL(PIN_CTRL);  
    gpio_out_t SELECT(PIN_SELECT);  

    // Initializing the pins 
    nRST.init(PUPD_UP, OUT_PUSHPULL);
    nTEST.init(PUPD_UP, OUT_PUSHPULL);
    DONE.init(PUPD_NONE);
    SUCCESS.init(PUPD_NONE);
    CTRL.init(PUPD_UP, OUT_PUSHPULL);
    SELECT.init(PUPD_UP, OUT_PUSHPULL);

    // Ensuring nTEST is always high
    nTEST.write(true);
}

void DeviceDriver::resetDevice() {
    gpio_out_t nRST(PIN_NRST);

    // Holding the device in reset
    nRST.write(false);
    delay_us(100);  

    // Releasing the reset, enabling config mode
    nRST.write(true);
}

void DeviceDriver::enterMode0() {
    gpio_out_t CTRL(PIN_CTRL);
    gpio_out_t SELECT(PIN_SELECT);

    SELECT.write(true);
    CTRL.write(false);

    // Trigger config by resetting the device
    resetDevice();

    // Send data
    uint8_t config_data[] = {0xAB, 0xCD};  // Example data
    sendConfigData(config_data, sizeof(config_data));

    SELECT.write(false);
}

void DeviceDriver::enterMode1() {
    gpio_out_t CTRL(PIN_CTRL);
    gpio_out_t SELECT(PIN_SELECT);

    SELECT.write(true);
    CTRL.write(true);

    resetDevice();

    uint8_t config_data[] = {0x12, 0x34}; 
    sendConfigData(config_data, sizeof(config_data));
    SELECT.write(false);
}

void DeviceDriver::enterMode2() {
    gpio_out_t CTRL(PIN_CTRL);
    gpio_out_t SELECT(PIN_SELECT);

    SELECT.write(true);
    CTRL.write(true);

    resetDevice();

    uint8_t config_data[] = {0x56, 0x78};
    sendConfigData(config_data, sizeof(config_data));

    SELECT.write(false);
}

bool DeviceDriver::isConfigurationDone() {
    gpio_in_t DONE(PIN_DONE);
    return DONE.read();
}

bool DeviceDriver::isSuccess() {
    gpio_in_t SUCCESS(PIN_SUCCESS);
    return SUCCESS.read();
}

void DeviceDriver::sendConfigData(const void* data, uint32_t size) {
    // Send configuration data using the send_communications() function
    bool result = send_communications(data, size);

    if (result) {
        uint32_t time_required = 1 + size * 8 / 1000000; 
        delay_us(time_required);  
    }
}
