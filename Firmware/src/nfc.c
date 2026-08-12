#include <stdint.h>
#include "tl_common.h"
#include "drivers.h"
#include "stack/ble/ble.h"
#include "drivers/8258/flash.h"
#include "nfc.h"
#include "main.h"

uint8_t nfc_reset[] = {0x03, 0xb5, 0xa0};

_attribute_ram_code_ void init_nfc(void)
{
    // Configure IRQ pin to detect NFC taps
    gpio_set_func(NFC_IRQ, AS_GPIO);
    gpio_set_output_en(NFC_IRQ, 0);
    gpio_set_input_en(NFC_IRQ, 1);
    gpio_setup_up_down_resistor(NFC_IRQ, PM_PIN_PULLUP_10K);

    // Intentionally omitting the I2C reset command (0x03, 0xb5, 0xa0) 
    // because it appears to disable or interfere with the RF interface 
    // on some FM11NT081C variants, preventing smartphones from reading it.
}
