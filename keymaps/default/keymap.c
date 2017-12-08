#include "roopad.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BL 0
#define _RL 1
#define _ML 2
#define _SL 3
#define _TL 4

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: (Base Layer) Default Layer
   * .-------------------.
   * |NL F|   /|   *|   -|
   * |-------------------|
   * |   7|   8|   9|    |
   * |--------------|    |
   * |   4|   5|   6|   +|
   * |-------------------|
   * |   1|   2|   3|    |
   * |--------------|    |
   * |        0|   .| Ent|
   * '-------------------'
   */
[_BL] = KEYMAP(
  LT(_RL, KC_NLCK), KC_PSLS, KC_PAST, KC_PMNS, \
  KC_P7,            KC_P8,   KC_P9,   KC_PPLS, \
  KC_P4,            KC_P5,   KC_P6, \
  KC_P1,            KC_P2,   KC_P3,   LT(_TL, KC_PENT), \
  LT(_ML, KC_P0),            LT(_SL, KC_PDOT)),

  /* Keymap _RL: RGB Layer
   * .-------------------.
   * |    |    |    | RGB|
   * |-------------------|
   * |    | SAI|M_X |    |
   * |--------------|    |
   * | HUD|    | HUI| VAI|
   * |-------------------|
   * |M_P | SAD|M_B |    |
   * |--------------|    |
   * |   RGBMOD|    | VAD|
   * '-------------------'
   */
[_RL] = KEYMAP(
  KC_TRNS, KC_TRNS, KC_TRNS, RGB_TOG, \
  KC_TRNS,          RGB_SAI,    RGB_M_X, RGB_VAI, \
  RGB_HUD,             KC_TRNS, RGB_HUI, \
  RGB_M_P,          RGB_SAD,    RGB_M_B, RGB_VAD, \
  RGB_MOD,                      KC_TRNS),

  /* Keymap _ML: Media Layer
   * .-------------------.
   * |    |    |    |    |
   * |-------------------|
   * |    |    |    |    |
   * |--------------|    |
   * | << | I> | >> |    |
   * |-------------------|
   * |    | .  | +  |    |
   * |--------------|    |
   * |         | -  | X  |
   * '-------------------'
   */
[_ML] = KEYMAP(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_MPRV, KC_MPLY, KC_MNXT, \
        KC_TRNS, KC_MSTP, KC_VOLU, KC_MUTE, \
        KC_TRNS,          KC_VOLD),

  /* Keymap _SL: Mouse Layer
   * .-------------------.
   * |    |    |    |    |
   * |-------------------|
   * | ^^ |  ^ | >> |    |
   * |--------------|    |
   * | <  | M1 |  > |    |
   * |-------------------|
   * | vv |  v | << |    |
   * |--------------|    |
   * |    M2   |    |    |
   * '-------------------'
   */
[_SL] = KEYMAP(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_MS_WH_UP, KC_MS_UP, KC_MS_WH_RIGHT, KC_TRNS, \
        KC_MS_LEFT, KC_MS_BTN1, KC_MS_RIGHT, \
        KC_MS_WH_DOWN, KC_MS_DOWN, KC_MS_WH_LEFT, KC_MS_BTN3, \
        KC_MS_BTN2,          KC_TRNS),

  /* Keymap _ML: Text Layer
   * .-------------------.
   * |    |    |    |    |
   * |-------------------|
   * |    |    |    |    |
   * |--------------|    |
   * | BSP|    | DEL|    |
   * |-------------------|
   * |    |    |    |    |
   * |--------------|    |
   * |  SPACE  |CALC|    |
   * '-------------------'
   */
[_TL] = KEYMAP(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_BSPC, KC_TRNS, KC_DEL, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_SPC,          KC_CALC),
};

/*enum function_id {
};*/

const uint16_t PROGMEM fn_actions[] = {
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  switch (id) {
  }
}

void matrix_scan_user(void) {
    rgblight_config_t rgblight_config;
    rgblight_config.raw = eeconfig_read_rgblight();

    if (!rgblight_config.enable || rgblight_config.mode != 1) { return; }

    uint8_t layer = biton32(layer_state);
    uint8_t val = rgblight_config.val;

    switch(layer) {
        case _BL:
            rgblight_sethsv_noeeprom(0, 255, val);
            break;
        case _RL:
            rgblight_sethsv_noeeprom(46, 255, val);
            break;
        case _ML:
            rgblight_sethsv_noeeprom(86, 125, val);
            break;
        case _SL:
            rgblight_sethsv_noeeprom(146, 125, val);
            break;
        case _TL:
            rgblight_sethsv_noeeprom(206, 125, val);
            break;
    }
}
