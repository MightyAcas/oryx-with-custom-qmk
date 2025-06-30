#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
  ST_MACRO_0,
  ST_MACRO_1,
  ST_MACRO_2,
  ST_MACRO_3,
  ST_MACRO_4,
};



#define DUAL_FUNC_0 LT(10, KC_F13)
#define DUAL_FUNC_1 LT(11, KC_1)
#define DUAL_FUNC_2 LT(3, KC_G)
#define DUAL_FUNC_3 LT(7, KC_F19)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TAB,         MT(MOD_LGUI, KC_W),MT(MOD_LALT, KC_C),KC_M,           KC_P,           KC_K,                                           KC_X,           KC_L,           KC_O,           MT(MOD_RALT, KC_U),MT(MOD_RGUI, KC_J),KC_MINUS,       
    KC_BSPC,        KC_R,           KC_S,           MT(MOD_LCTL, KC_T),MT(MOD_LSFT, KC_H),KC_B,                                           KC_Y,           MT(MOD_RSFT, KC_N),MT(MOD_RCTL, KC_A),KC_E,           KC_I,           KC_COMMA,       
    LCTL(KC_Z),     KC_Q,           KC_G,           KC_D,           KC_F,           KC_V,                                           KC_Z,           KC_SLASH,       KC_QUOTE,       KC_SCLN,        KC_DOT,         KC_ENTER,       
                                                    LT(1, KC_SPACE),OSL(2),                                         LCTL(KC_BSPC),  OSM(MOD_RSFT)
  ),
  [1] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_ESCAPE,      KC_HOME,        KC_UP,          KC_END,         KC_PAGE_UP,                                     KC_ASTR,        KC_7,           KC_8,           KC_9,           KC_TILD,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_LEFT_GUI,    KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_PGDN,                                        KC_SLASH,       MT(MOD_RSFT, KC_4),MT(MOD_RCTL, KC_5),MT(MOD_RALT, KC_6),DUAL_FUNC_0,    KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_PSCR,        KC_NUM,         KC_CAPS,        QK_LLCK,        TO(3),                                          KC_EQUAL,       KC_1,           KC_2,           KC_3,           KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    TO(0),          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_0
  ),
  [2] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                          KC_PIPE,        KC_AMPR,        ST_MACRO_0,     ST_MACRO_1,     KC_NO,          ST_MACRO_2,     
    KC_TRANSPARENT, KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,                                         KC_BSLS,        DUAL_FUNC_1,    DUAL_FUNC_2,    DUAL_FUNC_3,    MT(MOD_RGUI, KC_GRAVE),ST_MACRO_3,     
    KC_TRANSPARENT, KC_F11,         KC_F12,         KC_F13,         QK_LLCK,        RGB_MODE_FORWARD,                                ST_MACRO_4,     KC_EXLM,        KC_AT,          KC_HASH,        KC_QUES,        KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, TO(0),                                          KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [3] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_MINUS,       
    KC_BSPC,        KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_QUOTE,       
    KC_LEFT_CTRL,   KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_ENTER,       
                                                    KC_SPACE,       KC_LEFT_SHIFT,                                  KC_LEFT_ALT,    KC_RIGHT_SHIFT
  ),
};

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = LAYOUT(
  'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 
  'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 
  'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 
  'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 
  '*', '*', '*', '*'
);

const uint16_t PROGMEM combo0[] = { KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM combo1[] = { KC_TAB, KC_Q, COMBO_END};
const uint16_t PROGMEM combo2[] = { KC_P, MT(MOD_LSFT, KC_H), COMBO_END};
const uint16_t PROGMEM combo3[] = { KC_L, MT(MOD_RSFT, KC_N), COMBO_END};
const uint16_t PROGMEM combo4[] = { KC_M, MT(MOD_LCTL, KC_T), COMBO_END};
const uint16_t PROGMEM combo5[] = { KC_O, MT(MOD_RCTL, KC_A), COMBO_END};
const uint16_t PROGMEM combo6[] = { MT(MOD_LALT, KC_C), KC_S, COMBO_END};
const uint16_t PROGMEM combo7[] = { MT(MOD_RALT, KC_U), KC_E, COMBO_END};
const uint16_t PROGMEM combo8[] = { MT(MOD_LGUI, KC_W), KC_R, COMBO_END};
const uint16_t PROGMEM combo9[] = { MT(MOD_RGUI, KC_J), KC_I, COMBO_END};

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
};




bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_2) SS_TAP(X_KP_1) ));
    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_2) SS_TAP(X_KP_0) ));
    }
    break;
    case ST_MACRO_2:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_5) SS_TAP(X_KP_0) ));
    }
    break;
    case ST_MACRO_3:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_5) SS_TAP(X_KP_1) ));
    }
    break;
    case ST_MACRO_4:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_5) SS_TAP(X_KP_3) ));
    }
    break;

    case DUAL_FUNC_0:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_PLUS);
        } else {
          unregister_code16(KC_PLUS);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_RIGHT_GUI);
        } else {
          unregister_code16(KC_RIGHT_GUI);
        }  
      }  
      return false;
    case DUAL_FUNC_1:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_DLR);
        } else {
          unregister_code16(KC_DLR);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_RIGHT_SHIFT);
        } else {
          unregister_code16(KC_RIGHT_SHIFT);
        }  
      }  
      return false;
    case DUAL_FUNC_2:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_PERC);
        } else {
          unregister_code16(KC_PERC);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_RIGHT_CTRL);
        } else {
          unregister_code16(KC_RIGHT_CTRL);
        }  
      }  
      return false;
    case DUAL_FUNC_3:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_CIRC);
        } else {
          unregister_code16(KC_CIRC);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_RIGHT_ALT);
        } else {
          unregister_code16(KC_RIGHT_ALT);
        }  
      }  
      return false;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}

// Exclude Space from Tap Flow
bool is_flow_tap_key(uint16_t keycode) {
    if ((get_mods() & (MOD_MASK_CG | MOD_BIT_LALT)) != 0) {
        return false; // Disable Flow Tap on hotkeys.
    }
    switch (get_tap_keycode(keycode)) {
        // Flow tap is enabled only for these keys.
        case KC_A ... KC_Z:
        case KC_DOT:
        case KC_COMM:
        case KC_SCLN:
        case KC_SLSH:
            return true;
    }
    return false;
}

// Magic Key Rules
uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
    switch (keycode) {
        case KC_QUOTE: return KC_L;

        case KC_W: return KC_R;
        case KC_S: return KC_C;
  
        case KC_F: return KC_T;
        case KC_P: return KC_T;

        case KC_B: return KC_T;
      
        case KC_G: return KC_H;
        case KC_M: return KC_B;

        case KC_C: return KC_K;
        case KC_R: return KC_K;
        case KC_A: return KC_Y;
        case KC_E: return KC_X;
        case KC_I: return KC_X;
    }
    return KC_SLASH;
}

