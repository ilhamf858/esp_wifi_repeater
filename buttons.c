#include "user/buttons.h"
#include "osapi.h"
#include "driver/gpio_register.h"
#include "gpio.h"

#define BTN_UP_PIN 14 // D5
#define BTN_DOWN_PIN 12 // D6
#define BTN_OK_PIN 13 // D7
#define BTN_BACK_PIN 0 // D3

static int read_pin(int gpio) {
    return GPIO_INPUT_GET(gpio);
}

void buttons_init(void) {
    // Configure pins as input with pull-ups
    // Adjust macros to your SDK wrappers if different
    PIN_PULLUP_EN(PERIPHS_IO_MUX_MTMS_U);
    // Additional pin mapping may be required per pin
}

int buttons_check(void) {
    if (read_pin(BTN_UP_PIN) == 0) { os_delay_us(200000); if (read_pin(BTN_UP_PIN)==0) return 1; }
    if (read_pin(BTN_DOWN_PIN) == 0) { os_delay_us(200000); if (read_pin(BTN_DOWN_PIN)==0) return 2; }
    if (read_pin(BTN_OK_PIN) == 0) { os_delay_us(200000); if (read_pin(BTN_OK_PIN)==0) return 3; }
    if (read_pin(BTN_BACK_PIN) == 0) { os_delay_us(200000); if (read_pin(BTN_BACK_PIN)==0) return 4; }
    return 0;
}
