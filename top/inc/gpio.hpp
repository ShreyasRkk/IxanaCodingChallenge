#ifndef GPIO_HPP_
#define GPIO_HPP_

#include <stdint.h>
// NOTE one pin may only be used as a single in/out at a time

enum PUPD
{
  PUPD_NONE,
  PUPD_UP,
  PUPD_DOWN,
};

enum OUT
{
  OUT_PUSHPULL,
  OUT_OPENDRAIN,
};

enum EDGE
{
  EDGE_POSITIVE,
  EDGE_NEGATIVE,
  EDGE_BOTH,
};

struct gpio_in_t
{
  gpio_in_t(uint8_t p) : pin(p) {}

  /// @brief initialize any clocks and connect the pin to the pad as an input
  /// @param pullup_pulldown configures the pull up/down resistor on the pad
  /// @return true: succeeded, false: failed
  bool init(PUPD pullup_pulldown);

  /// @brief stop any clocks for the pin and disconnect the pad
  /// @return true: succeeded, false: failed
  bool deinit();

  /// @return true: the pad is logic high, false: the pad is logic low
  bool read();

private:
  const uint8_t pin;
};

struct gpio_out_t
{
  gpio_out_t(uint8_t pin) : pin(pin) {}

  /// @brief initialize any clocks and connect the pin to the pad as an output
  /// @param pullup_pulldown set the pull up/down resistor on the pad
  /// @param out set the output type
  /// @return true: succeeded, false: failed
  bool init(PUPD pullup_pulldown, OUT out_type);

  /// @brief stop any clocks for the pin and disconnect the pad
  /// @return true: succeeded, false: failed
  bool deinit();

  /// @return true: the pad is logic high, false: the pad is logic low
  bool read();
  
  /// @param value true: set the pin to logic high, false: set the pin to logic low
  void write(bool value);

private:
  const uint8_t pin;
};

#endif