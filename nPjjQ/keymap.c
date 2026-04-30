#include QMK_KEYBOARD_H
#include "version.h"
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
    KC_TAB,         KC_W,           KC_C,           KC_M,           KC_P,           KC_K,                                           KC_Z,           KC_L,           KC_O,           KC_U,           KC_J,           KC_MINUS,       
    KC_BSPC,        KC_R,           KC_S,           KC_T,           KC_H,           KC_F,                                           KC_X,           KC_N,           KC_A,           KC_E,           KC_I,           KC_ENTER,       
    LCTL(KC_Z),     KC_Q,           KC_V,           KC_G,           KC_D,           KC_B,                                           KC_SLASH,       KC_COMMA,       KC_QUOTE,       KC_SCLN,        KC_DOT,         KC_ESCAPE,      
                                                    KC_SPACE,       OSL(1),                                         OSM(MOD_RSFT),  KC_Y
  ),
  [1] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_F2,          KC_PSCR,        KC_HOME,        KC_UP,          KC_END,         KC_PAGE_UP,                                     KC_BSLS,        KC_7,           KC_8,           KC_9,           LED_LEVEL,      KC_F5,          
    KC_TRANSPARENT, QK_LLCK,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_PGDN,                                        KC_GRAVE,       KC_4,           KC_5,           KC_6,           KC_EQUAL,       KC_F8,          
    KC_F4,          KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_UP,       KC_MS_RIGHT,    KC_MS_BTN2,                                     KC_TRANSPARENT, KC_1,           KC_2,           KC_3,           KC_TRANSPARENT, KC_F11,         
                                                    KC_MS_BTN1,     TO(0),                                          KC_TRANSPARENT, KC_0
  ),
  [2] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_MINUS,       
    KC_LEFT_SHIFT,  KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_ENTER,       
    KC_LEFT_CTRL,   KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_QUOTE,       
                                                    KC_SPACE,       KC_BSPC,                                        KC_DELETE,      KC_SPACE
  ),
};

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = LAYOUT(
  'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 
  'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 
  'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 
  'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 
  '*', '*', '*', '*'
);

const uint16_t PROGMEM combo0[] = { KC_M, KC_COMMA, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo1[] = { KC_TAB, KC_Q, COMBO_END};
const uint16_t PROGMEM combo2[] = { KC_P, KC_H, COMBO_END};
const uint16_t PROGMEM combo3[] = { KC_L, KC_N, COMBO_END};
const uint16_t PROGMEM combo4[] = { KC_M, KC_T, COMBO_END};
const uint16_t PROGMEM combo5[] = { KC_O, KC_A, COMBO_END};
const uint16_t PROGMEM combo6[] = { KC_S, KC_C, COMBO_END};
const uint16_t PROGMEM combo7[] = { KC_E, KC_U, COMBO_END};
const uint16_t PROGMEM combo8[] = { KC_R, KC_W, COMBO_END};
const uint16_t PROGMEM combo9[] = { KC_J, KC_I, COMBO_END};
const uint16_t PROGMEM combo10[] = { KC_R, KC_Q, COMBO_END};
const uint16_t PROGMEM combo11[] = { KC_S, KC_V, COMBO_END};
const uint16_t PROGMEM combo12[] = { KC_T, KC_G, COMBO_END};
const uint16_t PROGMEM combo13[] = { KC_H, KC_D, COMBO_END};
const uint16_t PROGMEM combo14[] = { KC_N, KC_COMMA, COMBO_END};
const uint16_t PROGMEM combo15[] = { KC_A, KC_QUOTE, COMBO_END};
const uint16_t PROGMEM combo16[] = { KC_E, KC_SCLN, COMBO_END};
const uint16_t PROGMEM combo17[] = { KC_I, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo18[] = { KC_COMMA, KC_QUOTE, KC_SCLN, COMBO_END};
const uint16_t PROGMEM combo19[] = { KC_L, KC_O, KC_U, COMBO_END};
const uint16_t PROGMEM combo20[] = { KC_SPACE, KC_BSPC, COMBO_END};

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
    COMBO(combo10, KC_LEFT_GUI),
    COMBO(combo11, KC_LEFT_ALT),
    COMBO(combo12, KC_LEFT_CTRL),
    COMBO(combo13, KC_LEFT_SHIFT),
    COMBO(combo14, KC_RIGHT_SHIFT),
    COMBO(combo15, KC_RIGHT_CTRL),
    COMBO(combo16, KC_RIGHT_ALT),
    COMBO(combo17, KC_RIGHT_GUI),
    COMBO(combo18, TO(2)),
    COMBO(combo19, KC_CAPS),
    COMBO(combo20, LCTL(KC_BSPC)),
};







bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case QK_MODS ... QK_MODS_MAX:
    // Mouse and consumer keys (volume, media) with modifiers work inconsistently across operating systems,
    // this makes sure that modifiers are always applied to the key that was pressed.
    if (IS_MOUSE_KEYCODE(QK_MODS_GET_BASIC_KEYCODE(keycode))) {
      if (record->event.pressed) {
        add_mods(QK_MODS_GET_MODS(keycode));
        send_keyboard_report();
        wait_ms(2);
        register_code(QK_MODS_GET_BASIC_KEYCODE(keycode));
        return false;
      } else {
        wait_ms(2);
        del_mods(QK_MODS_GET_MODS(keycode));
      }
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
