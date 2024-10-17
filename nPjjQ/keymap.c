#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  HSV_193_230_116,
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_ESCAPE,      KC_RIGHT_GUI,   OSM(MOD_LALT),  KC_MS_BTN2,     KC_MS_BTN1,     LGUI(KC_DOT),                                   KC_CAPS,        KC_MEDIA_PLAY_PAUSE,KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_PSCR,        RGB_TOG,        
    KC_TAB,         KC_W,           KC_C,           KC_M,           KC_P,           KC_B,                                           KC_X,           KC_L,           KC_O,           KC_U,           KC_J,           KC_MINUS,       
    KC_BSPC,        KC_R,           KC_S,           KC_T,           KC_H,           KC_F,                                           KC_Y,           KC_N,           KC_A,           KC_E,           KC_I,           KC_COMMA,       
    OSM(MOD_LCTL),  KC_Q,           KC_V,           KC_G,           KC_D,           KC_K,                                           KC_Z,           KC_SLASH,       KC_QUOTE,       KC_SCLN,        KC_DOT,         KC_ENTER,       
                                                    KC_SPACE,       OSL(1),                                         RCTL(KC_BSPC),  OSM(MOD_RSFT)
  ),
  [1] = LAYOUT_voyager(
    KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,                                          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,         
    KC_GRAVE,       KC_HASH,        KC_AT,          KC_LCBR,        KC_RCBR,        KC_CIRC,                                        KC_ASTR,        KC_1,           KC_2,           KC_3,           KC_MINUS,       KC_DLR,         
    KC_TRANSPARENT, KC_EXLM,        KC_QUES,        KC_LPRN,        KC_RPRN,        KC_AMPR,                                        KC_SLASH,       KC_4,           KC_5,           KC_6,           KC_PLUS,        KC_PERC,        
    KC_PIPE,        KC_LABK,        KC_RABK,        KC_LBRC,        KC_RBRC,        KC_BSLS,                                        KC_EQUAL,       KC_7,           KC_8,           KC_9,           KC_ENTER,       KC_TILD,        
                                                    KC_TRANSPARENT, TO(0),                                          TO(3),          KC_0
  ),
  [2] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, HSV_193_230_116,KC_HOME,        KC_UP,          KC_END,         KC_PAGE_UP,                                     KC_ASTR,        KC_1,           KC_2,           KC_3,           KC_MINUS,       KC_DLR,         
    KC_TRANSPARENT, KC_DELETE,      KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_PGDN,                                        KC_SLASH,       KC_4,           KC_5,           KC_6,           KC_PLUS,        KC_PERC,        
    KC_TRANSPARENT, RGB_SAD,        RGB_SAI,        RGB_VAD,        RGB_VAI,        OSM(MOD_LSFT),                                  KC_EQUAL,       KC_7,           KC_8,           KC_9,           KC_ENTER,       KC_TILD,        
                                                    OSM(MOD_LALT),  OSM(MOD_LGUI),                                  TO(0),          KC_0
  ),
  [3] = LAYOUT_voyager(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_RIGHT_GUI,   
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_MINUS,       
    KC_LEFT_SHIFT,  KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_QUOTE,       
    KC_LEFT_CTRL,   KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_ENTER,       
                                                    KC_SPACE,       KC_BSPC,                                        TO(0),          KC_BSPC
  ),
};

const uint16_t PROGMEM combo0[] = { KC_M, KC_T, COMBO_END};
const uint16_t PROGMEM combo1[] = { KC_UP, KC_DOWN, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, TO(2)),
    COMBO(combo1, TO(0)),
};



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case HSV_193_230_116:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(193,230,116);
      }
      return false;
  }
  return true;
}



