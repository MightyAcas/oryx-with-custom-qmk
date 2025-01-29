#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  ST_MACRO_0,
  ST_MACRO_1,
  ST_MACRO_2,
  ST_MACRO_3,
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TAB,         KC_W,           KC_C,           KC_M,           KC_P,           KC_K,                                           KC_X,           KC_L,           KC_O,           KC_U,           KC_J,           KC_MINUS,       
    KC_BSPC,        KC_R,           KC_S,           KC_T,           KC_H,           KC_B,                                           KC_Y,           KC_N,           KC_A,           KC_E,           KC_I,           KC_COMMA,       
    OSM(MOD_LCTL),  KC_Q,           KC_G,           KC_D,           KC_F,           KC_V,                                           KC_Z,           KC_SLASH,       KC_QUOTE,       KC_SCLN,        KC_DOT,         KC_ENTER,       
                                                    KC_SPACE,       OSL(1),                                         OSL(2),         OSM(MOD_RSFT)
  ),
  [1] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_ESCAPE,      KC_HOME,        KC_UP,          KC_END,         KC_PAGE_UP,                                     KC_ASTR,        KC_7,           KC_8,           KC_9,           KC_MINUS,       KC_PSCR,        
    KC_TRANSPARENT, OSM(MOD_LALT),  KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_PGDN,                                        KC_SLASH,       KC_4,           KC_5,           KC_6,           KC_PLUS,        KC_TRANSPARENT, 
    KC_TRANSPARENT, TO(3),          OSM(MOD_LSFT),  KC_CAPS,        QK_LLCK,        RGB_TOG,                                        KC_EQUAL,       KC_1,           KC_2,           KC_3,           KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_LEFT_GUI,    TO(0),                                          LCTL(KC_BSPC),  KC_0
  ),
  [2] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                          KC_PIPE,        KC_AMPR,        KC_EXLM,        KC_QUES,        KC_TILD,        ST_MACRO_0,     
    KC_TRANSPARENT, KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,                                         KC_BSLS,        KC_DLR,         KC_PERC,        KC_CIRC,        KC_GRAVE,       ST_MACRO_1,     
    KC_TRANSPARENT, KC_F11,         KC_F12,         RGB_SPD,        RGB_SPI,        RGB_MODE_FORWARD,                                ST_MACRO_2,     QK_LLCK,        KC_AT,          KC_HASH,        ST_MACRO_3,     KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, LCTL(KC_BSPC),                                  TO(0),          KC_TRANSPARENT
  ),
  [3] = LAYOUT_voyager(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_BSPC,        
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_MINUS,       
    KC_LEFT_SHIFT,  KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_QUOTE,       
    KC_LEFT_CTRL,   KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_ENTER,       
                                                    KC_SPACE,       KC_LEFT_ALT,                                    KC_RIGHT_GUI,   KC_RIGHT_SHIFT
  ),
};

const uint16_t PROGMEM combo0[] = { KC_P, KC_H, COMBO_END};
const uint16_t PROGMEM combo1[] = { KC_L, KC_N, COMBO_END};
const uint16_t PROGMEM combo2[] = { KC_M, KC_T, COMBO_END};
const uint16_t PROGMEM combo3[] = { KC_O, KC_A, COMBO_END};
const uint16_t PROGMEM combo4[] = { KC_8, KC_9, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, KC_LPRN),
    COMBO(combo1, KC_RPRN),
    COMBO(combo2, KC_LBRC),
    COMBO(combo3, KC_RBRC),
    COMBO(combo4, TO(0)),
};



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_0) SS_TAP(X_1) SS_TAP(X_5) SS_TAP(X_0) ));
    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_0) SS_TAP(X_1) SS_TAP(X_5) SS_TAP(X_1) ));
    }
    break;
    case ST_MACRO_2:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_2) SS_TAP(X_0) ));
    }
    break;
    case ST_MACRO_3:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_2) SS_TAP(X_1) ));
    }
    break;

    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}



