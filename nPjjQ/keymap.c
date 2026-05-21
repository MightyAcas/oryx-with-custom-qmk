#include QMK_KEYBOARD_H
#include "version.h"
#include "features/adaptive_keys.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

bool alpha_pressed = false; // variable for timer to disable arcane key functionality after no letter has been pressed for x amount of time
uint16_t arcane_timer = 0;     // timer 
uint16_t last_key_manual = 0; // for timer reset and adaptive keys
uint16_t last_mod_manual = 0; // for timer reset and adaptive keys

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
  REP_OSM,
};




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TAB,         KC_W,           KC_C,           KC_M,           KC_P,           KC_K,                                           KC_X,           KC_L,           KC_O,           KC_U,           KC_J,           KC_MINUS,       
    LCTL(KC_BSPC),  KC_R,           KC_S,           KC_T,           KC_H,           KC_F,                                           KC_QUOTE,       KC_N,           KC_A,           KC_E,           KC_I,           KC_ENTER,       
    OSM(MOD_RCTL),  KC_Q,           KC_G,           KC_V,           KC_D,           KC_B,                                           KC_Z,           KC_Y,           KC_DOT,         KC_SCLN,        KC_COMMA,       OSM(MOD_LALT),  
                                                    KC_SPACE,       OSL(1),                                         OSL(2),         REP_OSM
  ),
  [1] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_ESCAPE,      KC_HOME,        KC_UP,          KC_END,         KC_PAGE_UP,                                     KC_SLASH,       KC_7,           KC_8,           KC_9,           KC_ASTR,        KC_TRANSPARENT, 
    KC_BSPC,        QK_LLCK,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_PGDN,                                        KC_PLUS,        KC_4,           KC_5,           KC_6,           KC_QUES,        KC_TRANSPARENT, 
    KC_TRANSPARENT, LCTL(KC_Z),     LCTL(KC_C),     LCTL(KC_V),     LCTL(KC_F),     LCTL(KC_A),                                     KC_EQUAL,       KC_1,           KC_2,           KC_3,           KC_EXLM,        KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, TO(0),                                          KC_RIGHT_GUI,   KC_0
  ),
  [2] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                          KC_PIPE,        KC_AMPR,        KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,                                         KC_BSLS,        KC_DLR,         KC_PERC,        KC_CIRC,        KC_NO,          KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_F11,         KC_F12,         RGB_TOG,        RGB_MODE_FORWARD,LED_LEVEL,                                      KC_TILD,        KC_GRAVE,       KC_AT,          KC_HASH,        KC_NO,          KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_PSCR,                                        TO(0),          KC_TRANSPARENT
  ),
  [3] = LAYOUT_voyager(
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

const uint16_t PROGMEM combo0[] = { KC_DELETE, KC_SPACE, COMBO_END};
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




bool remember_last_key_user(uint16_t keycode, keyrecord_t* record,
                            uint8_t* remembered_mods) {
    switch (keycode) {
        case REP_OSM:
            return false;  // Ignore ALTREP keys. If this is not here, only default action will be done, since the process stuff is apparently run after the remember last key stuff, so that the key is only ever trying to repeat itself.
    }

    return true;  // Other keys can be repeated.
}

void matrix_scan_user(void) { // The very important timer.
  if (alpha_pressed && timer_elapsed(arcane_timer) > 1000) { //triggers when timer elapsed
      alpha_pressed = false;
      set_last_keycode(KC_SPACE);
  } else { //timer update
    switch (get_last_keycode()) {
      case KC_A ... KC_Z:
      case KC_SCLN:
      case KC_COMMA:
      case KC_DOT:
        if (last_key_manual != get_last_keycode()) {
          last_key_manual = get_last_keycode();
          last_mod_manual = get_last_mods();
          alpha_pressed = true;
          arcane_timer = timer_read();
        }
      break; //these were all the keys that keep the timer going
      case KC_SPACE:
      case KC_ENTER:
      case KC_BSPC:
      case RCTL(KC_BSPC):
      last_key_manual = get_last_keycode();
      alpha_pressed = false;
      break; //these were all the keys that end the timer prematurely
    }
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  #ifdef ADAPTIVE_KEYS_ENABLE
    if (!process_adaptive_key(keycode, record)) {
      return false;
    }
  #endif
  
  switch (keycode) {
    case REP_OSM: 
      if (record->event.pressed && layer_state_is(0)) {
        if (get_oneshot_mods() & MOD_MASK_SHIFT) {
          caps_word_toggle(); //toggles on caps word if one shot shift is already active (e.g. through double-tapping the key
        } else {
          if (alpha_pressed) {// letter was pressed within timer limits
            arcane_timer = timer_read(); // reset timer
            repeat_key_invoke(&record->event);
          } else {//alpha timer timed out, so key functions just as a OSM shift
            set_oneshot_mods(MOD_BIT(KC_LSFT));
          }
        }
      }
      break;
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
