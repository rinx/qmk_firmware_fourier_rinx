#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _MQWERTY 1
#define _LOWER 2
#define _MLOWER 3
#define _RAISE 4
#define _MRAISE 5
#define _FUNCT 6
#define _MFUNCT 7
#define _ARROW 8
#define _MARROW 9
#define _ADMINI 10
#define _MADMINI 11

#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define WINUNDO ACTION_MODS_KEY(MOD_LCTL, KC_Z)
#define WINCUT ACTION_MODS_KEY(MOD_LCTL, KC_X)
#define WINCOPY ACTION_MODS_KEY(MOD_LCTL, KC_C)
#define WINPASTE ACTION_MODS_KEY(MOD_LCTL, KC_V)
#define WINFIND ACTION_MODS_KEY(MOD_LCTL, KC_F)
#define MACUNDO ACTION_MODS_KEY(MOD_LGUI, KC_Z)
#define MACREDO ACTION_MODS_KEY(MOD_LGUI | MOD_LSFT, KC_Z)
#define MACCUT ACTION_MODS_KEY(MOD_LGUI, KC_X)
#define MACCOPY ACTION_MODS_KEY(MOD_LGUI, KC_C)
#define MACPASTE ACTION_MODS_KEY(MOD_LGUI, KC_V)
#define MACFIND ACTION_MODS_KEY(MOD_LGUI, KC_F)
#define SPTLGHT ACTION_MODS_KEY(MOD_LGUI, KC_SPC)
#define MISSIONCTL ACTION_MODS_KEY(MOD_LCTL, KC_UP)
#define ROFI ACTION_MODS_KEY(MOD_LGUI, KC_D)

// macros
#define SEND_KEYMAP_URI 0
#define MAC_COPY_PASTE 1
#define WIN_COPY_PASTE 2

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  MQWERTY,
  LOWER,
  MLOWER,
  RAISE,
  MRAISE,
  FUNCT,
  MFUNCT,
  ARROW,
  MARROW,
  ADMINI,
  MADMINI,
  DYNAMIC_MACRO_RANGE
};

#include "dynamic_macro.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |   \  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |      |      |      |      |      |      |      |      |      | Arrow|      |
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  | Enter|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   [  | Raise|      |      |      |      |      |      |      |      | Lower|   ]  |
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Shift|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |    Lower    |    Raise    |      |      |  SPL |      |
 * | Ctrl | Alt  | GUI  | NONE |    Space    |  Backspace  | GUI  |  C/P | ROFI | Funct|
 * `-----------------------------------------------------------------------------------'
 */
  [_QWERTY] = LAYOUT(
    KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, XXXXXXX, KC_BSLS,
    CTL_T(KC_TAB), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, LT(_ARROW, KC_SCLN), KC_ENT,
    SFT_T(KC_LBRC), LT(_RAISE, KC_Z), KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, LT(_LOWER, KC_SLSH), SFT_T(KC_RBRC),
    KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX, LT(_LOWER, KC_SPC), LT(_RAISE, KC_BSPC), KC_RGUI, M(WIN_COPY_PASTE), ROFI, FUNCT
  ),
  [_MQWERTY] = LAYOUT(
    KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, XXXXXXX, KC_BSLS,
    CTL_T(KC_TAB), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, LT(_MARROW, KC_SCLN), KC_ENT,
    SFT_T(KC_LBRC), LT(_MRAISE, KC_Z), KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, LT(_MLOWER, KC_SLSH), SFT_T(KC_RBRC),
    KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX, LT(_MLOWER, KC_SPC), LT(_MRAISE, KC_BSPC), KC_RGUI, M(MAC_COPY_PASTE), SPTLGHT, MFUNCT
  ),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      | FIND |      |      |   _  |   +  |   {  |   }  |   '  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | UNDO | CUT  | COPY | PASTE|      |      |      |      |      |XXXXXX|      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |XXXXXXXXXXXXX|             |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
  [_LOWER] = LAYOUT(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, XXXXXXX, KC_BSPC,
    _______, _______, _______, _______, WINFIND, _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR,          KC_QUOT,
    _______, WINUNDO, WINCUT, WINCOPY, WINPASTE, _______, _______,          _______, _______, _______, _______, _______,
    _______, _______, _______, XXXXXXX, _______,          _______,                   _______, _______, _______, _______
  ),
  [_MLOWER] = LAYOUT(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, XXXXXXX, KC_BSPC,
    _______, _______, _______, _______, MACFIND, _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR,          KC_QUOT,
    _______, MACUNDO, MACCUT, MACCOPY, MACPASTE, _______, _______,          _______, _______, _______, _______, _______,
    _______, _______, _______, XXXXXXX, _______,          _______,                   _______, _______, _______, _______
  ),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      | FIND |      |      |   -  |   =  |   [  |   ]  |   '  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |XXXXXX| CUT  | COPY | PASTE|      |      |      |      |      |      |  Up  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |             |XXXXXXXXXXXXX|      | Left | Down | Right|
 * `-----------------------------------------------------------------------------------'
 */
  [_RAISE] = LAYOUT(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX, KC_DEL,
    _______, _______, _______, _______, WINFIND, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC,          KC_QUOT,
    _______, _______, WINCUT, WINCOPY, WINPASTE, _______, _______,          _______, _______, _______, _______, KC_UP,
    _______, _______, _______, XXXXXXX, _______,          _______,                   _______, KC_LEFT, KC_DOWN, KC_RGHT
  ),
  [_MRAISE] = LAYOUT(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX, KC_DEL,
    _______, _______, _______, _______, MACFIND, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC,          KC_QUOT,
    _______, _______, MACCUT, MACCOPY, MACPASTE, _______, _______,          _______, _______, _______, _______, KC_UP,
    _______, _______, _______, XXXXXXX, _______,          _______,                   _______, KC_LEFT, KC_DOWN, KC_RGHT
  ),

/* Function
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |ADMINI|      |      |      |             |             |      |      |      |XXXXXX|
 * `-----------------------------------------------------------------------------------'
 */
  [_FUNCT] = LAYOUT(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11, XXXXXXX, KC_F12,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______,
    ADMINI, _______, _______, XXXXXXX, _______,          _______,                   _______, _______, _______, _______
  ),
  [_MFUNCT] = LAYOUT(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11, XXXXXXX, KC_F12,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______,
    MADMINI, _______, _______, XXXXXXX, _______,          _______,                   _______, _______, _______, _______
  ),

/* Arrow
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      | Left | Down |  Up  | Right|XXXXXX|      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |             |             |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
  [_ARROW] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, _______,
    _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______,          _______,
    _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______,
    _______, _______, _______, XXXXXXX, _______,          _______,                   _______, _______, _______, _______
  ),
  [_MARROW] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, _______,
    _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______,          _______,
    _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______,
    _______, _______, _______, XXXXXXX, _______,          _______,                   _______, _______, _______, _______
  ),

/* Admini
 * ,-----------------------------------------------------------------------------------.
 * | RESET|      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |XXXXXX| W/M  |      |      |             |             |      |      |      |XXXXXX|
 * `-----------------------------------------------------------------------------------'
 */

  [_ADMINI] = LAYOUT(
    RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______,
    _______, MQWERTY, _______, XXXXXXX, _______,          _______,                   _______, _______, _______, _______
  ),
  [_MADMINI] = LAYOUT(
    RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______,
    _______, QWERTY,  _______, XXXXXXX, _______,          _______,                   _______, _______, _______, _______
  )

};

static uint16_t start;
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch(id) {
        case SEND_KEYMAP_URI:
            if (record->event.pressed) {
                SEND_STRING("https://github.com/rinx/qmk_firmware_fourier_rinx/blob/master/keymap.c");
            }
            break;
        case MAC_COPY_PASTE:
            if (record->event.pressed) {
                start = timer_read();
            } else {
                if (timer_elapsed(start) >= TAPPING_TERM)
                    return MACRO(D(LGUI), T(C), U(LGUI), END);
                else
                    return MACRO(D(LGUI), T(V), U(LGUI), END);
            }
            break;
        case WIN_COPY_PASTE:
            if (record->event.pressed) {
                start = timer_read();
            } else {
                if (timer_elapsed(start) >= TAPPING_TERM)
                    return MACRO(D(LCTL), T(C), U(LCTL), END);
                else
                    return MACRO(D(LCTL), T(V), U(LCTL), END);
            }
            break;
    }
    return MACRO_NONE;
};

void matrix_init_user(void) {
};

void matrix_scan_user(void) {
};

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  if (!process_record_dynamic_macro(keycode, record)) {
    return false;
  }

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistant_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case MQWERTY:
      if (record->event.pressed) {
        persistant_default_layer_set(1UL<<_MQWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
      } else {
        layer_off(_LOWER);
      }
      return false;
      break;
    case MLOWER:
      if (record->event.pressed) {
        layer_on(_MLOWER);
      } else {
        layer_off(_MLOWER);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
      } else {
        layer_off(_RAISE);
      }
      return false;
      break;
    case MRAISE:
      if (record->event.pressed) {
        layer_on(_MRAISE);
      } else {
        layer_off(_MRAISE);
      }
      return false;
      break;
    case FUNCT:
      if (record->event.pressed) {
        layer_on(_FUNCT);
      } else {
        layer_off(_FUNCT);
      }
      return false;
      break;
    case MFUNCT:
      if (record->event.pressed) {
        layer_on(_MFUNCT);
      } else {
        layer_off(_MFUNCT);
      }
      return false;
      break;
    case ARROW:
      if (record->event.pressed) {
        layer_on(_ARROW);
      } else {
        layer_off(_ARROW);
      }
      return false;
      break;
    case MARROW:
      if (record->event.pressed) {
        layer_on(_MARROW);
      } else {
        layer_off(_MARROW);
      }
      return false;
      break;
    case ADMINI:
      if (record->event.pressed) {
        layer_on(_ADMINI);
      } else {
        layer_off(_ADMINI);
      }
      return false;
      break;
    case MADMINI:
      if (record->event.pressed) {
        layer_on(_MADMINI);
      } else {
        layer_off(_MADMINI);
      }
      return false;
      break;
    }
    return true;
};
