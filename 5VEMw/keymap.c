#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

#include "features/sentence_case.h"

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  ST_MACRO_0,
  ST_MACRO_1,
  ST_MACRO_2,
  ST_MACRO_3,
  T_S_C,
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_ESCAPE,      ST_MACRO_0,     ST_MACRO_1,     KC_LBRC,        KC_LPRN,        OSM(MOD_LALT),                                  KC_CAPS,        KC_RPRN,        KC_RBRC,        ST_MACRO_2,     ST_MACRO_3,     KC_RIGHT_GUI,  
    KC_TAB,         KC_W,           KC_C,           KC_M,           KC_P,           KC_B,                                           KC_X,           KC_L,           KC_O,           KC_U,           KC_J,           KC_MINUS,       
    KC_BSPC,        KC_R,           KC_S,           KC_T,           KC_H,           KC_F,                                           KC_Y,           KC_N,           KC_A,           KC_E,           KC_I,           KC_COMMA,       
    OSM(MOD_LCTL),  KC_Q,           KC_V,           KC_G,           KC_D,           KC_K,                                           KC_Z,           QK_AREP,        KC_QUOTE,       KC_SCLN,        KC_DOT,         KC_ENTER,       
                                                    KC_SPACE,       OSL(1),                                         OSL(2),         OSM(MOD_RSFT)
  ),
  [1] = LAYOUT_voyager(
    KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,                                          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,         
    KC_TRANSPARENT, TO(3),          KC_MS_WH_UP,    KC_MS_UP,       KC_MS_WH_DOWN,  RGB_MODE_FORWARD,                               KC_ASTR,        KC_7,           KC_8,           KC_9,           KC_MINUS,       KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_MS_BTN1,     KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_MS_BTN2,                                     KC_SLASH,       KC_4,           KC_5,           KC_6,           KC_PLUS,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_MS_WH_LEFT,  KC_PSCR,        KC_MS_BTN3,     QK_LLCK,        KC_MS_WH_RIGHT,                                 KC_EQUAL,       KC_1,           KC_2,           KC_3,           KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, TO(0),                                          LCTL(KC_BSPC),  KC_0
  ),
  [2] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, RGB_VAI,        KC_HOME,        KC_UP,          KC_END,         KC_PAGE_UP,                                     KC_PIPE,        KC_AMPR,        KC_QUES,        KC_EXLM,        KC_TILD,        KC_TRANSPARENT, 
    KC_TRANSPARENT, RGB_VAD,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_PGDN,                                        KC_BSLS,        KC_DLR,         KC_PERC,        KC_CIRC,        KC_GRAVE,       KC_TRANSPARENT, 
    KC_TRANSPARENT, RGB_SPD,        RGB_SPI,        KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          QK_LLCK,        KC_AT,          KC_HASH,        KC_NO,          KC_TRANSPARENT, 
                                                    KC_LEFT_GUI,    OSM(MOD_LALT),                                  TO(0),          KC_NO
  ),
  [3] = LAYOUT_voyager(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_RIGHT_GUI,   
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_MINUS,       
    KC_LEFT_SHIFT,  KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_QUOTE,       
    KC_LEFT_CTRL,   KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_ENTER,       
                                                    KC_SPACE,       KC_BSPC,                                        TO(0),          KC_LEFT_ALT
  ),
};




bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_sentence_case(keycode, record)) { return false; }
  switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_2) SS_TAP(X_KP_0) ));
    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_2) SS_TAP(X_KP_1) ));
    }
    break;
    case ST_MACRO_2:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_5) SS_TAP(X_KP_1) ));
    }
    break;
    case ST_MACRO_3:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_5) SS_TAP(X_KP_0) ));
    }
    break;

    case T_S_C:
      // When the custom keycode is pressed, switch the value of the boolean variable and call the toggle function
      if (record->event.pressed) {
        sentence_case_toggle();
      }
      return false; // Skip all further processing of this key
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}



// Custom QMK
uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
    switch (keycode) {
        case KC_C: return KC_K;
        case KC_QUOTE: return KC_L;
      
        case KC_G: return KC_H;
        case KC_P: return KC_T;
        case KC_R: return KC_K;
      
        case KC_S: return KC_C;
        case KC_W: return KC_R;
      
        case KC_F: return KC_T;
      
        case KC_B: return KC_T;
        case KC_A: return KC_X;
        case KC_E: return KC_X;
        case KC_I: return KC_X;
    }
    return KC_SLASH;
}


