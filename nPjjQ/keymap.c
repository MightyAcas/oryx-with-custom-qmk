#include QMK_KEYBOARD_H
#include "version.h"
#include "features/adaptive_keys.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
};




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TAB,         KC_W,           KC_C,           KC_M,           KC_P,           KC_K,                                           KC_X,           KC_L,           KC_O,           KC_U,           KC_J,           KC_MINUS,       
    KC_BSPC,        KC_R,           KC_S,           KC_T,           KC_H,           KC_F,                                           KC_QUOTE,       KC_N,           KC_A,           KC_E,           KC_I,           KC_ENTER,       
    LCTL(KC_BSPC),  KC_Q,           KC_G,           KC_V,           KC_D,           KC_B,                                           KC_Z,           KC_Y,           KC_DOT,         KC_SCLN,        KC_COMMA,       KC_LEFT_ALT,    
                                                    KC_SPACE,       OSL(1),                                         OSL(2),         OSM(MOD_RSFT)
  ),
  [1] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_ESCAPE,      KC_HOME,        KC_UP,          KC_END,         KC_PAGE_UP,                                     KC_PLUS,        KC_7,           KC_8,           KC_9,           KC_ASTR,        KC_TRANSPARENT, 
    KC_TRANSPARENT, QK_LLCK,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_PGDN,                                        KC_SLASH,       KC_4,           KC_5,           KC_6,           KC_QUES,        KC_TRANSPARENT, 
    KC_LEFT_GUI,    LCTL(KC_Z),     LCTL(KC_C),     LCTL(KC_V),     LCTL(KC_F),     LCTL(KC_A),                                     KC_EQUAL,       KC_1,           KC_2,           KC_3,           KC_EXLM,        KC_LEFT_CTRL,   
                                                    KC_TRANSPARENT, TO(0),                                          KC_PSCR,        KC_0
  ),
  [2] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                          KC_PIPE,        KC_AMPR,        KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,                                         KC_BSLS,        KC_DLR,         KC_PERC,        KC_CIRC,        KC_NO,          KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_F11,         KC_F12,         RGB_TOG,        RGB_MODE_FORWARD,LED_LEVEL,                                      KC_TILD,        KC_GRAVE,       KC_AT,          KC_HASH,        KC_NO,          KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_NO,                                          TO(0),          KC_TRANSPARENT
  ),
  [3] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSPC,        
    KC_LEFT_CTRL,   KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_RIGHT_ALT,   
    KC_LEFT_ALT,    KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_RIGHT_CTRL,  
                                                    KC_SPACE,       KC_RIGHT_SHIFT,                                 KC_LEFT_ALT,    KC_ENTER
  ),
};

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = LAYOUT(
  'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 
  'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 
  'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 
  'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 
  '*', '*', '*', '*'
);

const uint16_t PROGMEM combo0[] = { KC_LEFT_ALT, KC_ENTER, COMBO_END};
const uint16_t PROGMEM combo1[] = { KC_TAB, KC_Q, COMBO_END};
const uint16_t PROGMEM combo2[] = { KC_P, KC_H, COMBO_END};
const uint16_t PROGMEM combo3[] = { KC_L, KC_N, COMBO_END};
const uint16_t PROGMEM combo4[] = { KC_M, KC_T, COMBO_END};
const uint16_t PROGMEM combo5[] = { KC_O, KC_A, COMBO_END};
const uint16_t PROGMEM combo6[] = { KC_C, KC_S, COMBO_END};
const uint16_t PROGMEM combo7[] = { KC_U, KC_E, COMBO_END};
const uint16_t PROGMEM combo8[] = { KC_W, KC_R, COMBO_END};
const uint16_t PROGMEM combo9[] = { KC_J, KC_I, COMBO_END};
const uint16_t PROGMEM combo10[] = { OSL(2), OSM(MOD_RSFT), COMBO_END};
const uint16_t PROGMEM combo11[] = { KC_SPACE, OSL(1), COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, TO(0)),
    COMBO(combo1, KC_ESCAPE),
    COMBO(combo2, KC_LPRN),
    COMBO(combo3, KC_RPRN),
    COMBO(combo4, KC_LBRC),
    COMBO(combo5, KC_RBRC),
    COMBO(combo6, KC_LCBR),
    COMBO(combo7, KC_RCBR),
    COMBO(combo8, KC_LABK),
    COMBO(combo9, KC_RABK),
    COMBO(combo10, TO(3)),
    COMBO(combo11, KC_CAPS),
};







bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  #ifdef ADAPTIVE_KEYS_ENABLE
    if (!process_adaptive_key(keycode, record)) {
      return false;
    }
  #endif
  
  switch (keycode) {

    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}
