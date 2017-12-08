#include "roopad.h"

void matrix_init_kb(void) {
    // put your keyboard start-up code here
    // runs once when the firmware starts up
    matrix_init_user();

    // JTAG disable for PORT F. write JTD bit twice within four cycles.
    MCUCR |= (1<<JTD);
    MCUCR |= (1<<JTD);

    DDRD |= (1 << 7);
};

void led_set_kb(uint8_t usb_led)
{
    if (usb_led & (1 << USB_LED_NUM_LOCK)) {
        PORTD |= (1<<7);
    } else {
        PORTD &= ~(1<<7);
    }
}
