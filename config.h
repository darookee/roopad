/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xBEEB
#define PRODUCT_ID      0x1234
#define DEVICE_VER      0x0001
#define MANUFACTURER    darookee.net
#define PRODUCT         Roopad
#define DESCRIPTION     QMK keyboard firmware for Roopad
#define CATERINA_BOOTLOADER

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 4

// ROWS: Top to bottom, COLS: Left to right
/* Row pin configuration
* row: 0  1  2  3  4
* pin:
*/
#define MATRIX_ROW_PINS { D3, D2, D1, D0, D4 }
/* Column pin configuration
 * col: 0  1  2  3
 * pin: F4 E6 B1 D2
 */
#define MATRIX_COL_PINS { B6, B2, B3, B1 }
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/* Set 0 if debouncing isn't needed */
#define DEBOUNCING_DELAY 5

/* Number of backlighting levels */
//#define BACKLIGHT_LEVELS 3

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
//#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* key combination for command */
/*
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
)
*/

/* Underlight configuration
 */
#define RGB_DI_PIN F6
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 4     // Number of LEDs
#define RGBLIGHT_HUE_STEP 10
#define RGBLIGHT_SAT_STEP 17
#define RGBLIGHT_VAL_STEP 17

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* Debug forcibly enabled */
//#define ALWAYS_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
#define NO_ACTION_ONESHOT
#define NO_ACTION_MACRO

//#define BOOTMAGIC_KEY_BOOTLOADER KC_PENT

#endif
