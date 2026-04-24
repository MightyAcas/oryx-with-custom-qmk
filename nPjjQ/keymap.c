#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
  MAGIC_KEY,
};




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TAB,         KC_W,           KC_C,           KC_M,           KC_P,           KC_K,                                           KC_Z,           KC_L,           KC_O,           KC_U,           KC_J,           KC_MINUS,       
    KC_BSPC,        KC_R,           KC_S,           KC_T,           KC_H,           KC_F,                                           KC_X,           KC_N,           KC_A,           KC_E,           KC_I,           KC_ENTER,       
    LCTL(KC_Z),     KC_Q,           KC_V,           KC_G,           KC_D,           KC_B,                                           KC_COMMA,       MAGIC_KEY,      KC_QUOTE,       KC_SCLN,        KC_DOT,         KC_ESCAPE,      
                                                    KC_SPACE,       OSL(1),                                         OSM(MOD_RSFT),  KC_Y
  ),
  [1] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_F2,          KC_ESCAPE,      KC_HOME,        KC_UP,          KC_END,         KC_PAGE_UP,                                     KC_ASTR,        KC_7,           KC_8,           KC_9,           KC_BSLS,        KC_F5,          
    LCTL(KC_BSPC),  LED_LEVEL,      KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_PGDN,                                        KC_GRAVE,       KC_4,           KC_5,           KC_6,           KC_PLUS,        KC_F8,          
    KC_F4,          KC_LEFT_GUI,    KC_LEFT_ALT,    KC_LEFT_CTRL,   KC_LEFT_SHIFT,  QK_LLCK,                                        KC_SLASH,       KC_1,           KC_2,           KC_3,           KC_TRANSPARENT, KC_F11,         
                                                    KC_TRANSPARENT, TO(0),                                          KC_TRANSPARENT, KC_0
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
const uint16_t PROGMEM combo20[] = { KC_COMMA, KC_QUOTE, KC_SCLN, KC_DOT, COMBO_END};

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
    COMBO(combo20, KC_PSCR),
};




bool remember_last_key_user(uint16_t keycode, keyrecord_t* record,
                            uint8_t* remembered_mods) {
    switch (keycode) {
        case MAGIC_KEY:
            return false;  // Ignore ALTREP keys. If this is not here, only default action will be done, since the process stuff is apparently run after the remember last key stuff, so that the key is only ever trying to repeat itself.
    }

    return true;  // Other keys can be repeated.
}

static void process_arcane_l(uint16_t keycode, uint8_t mods) {
    switch (keycode) {
        case KC_A:
          if (is_caps_word_on()) { //checks for caps word status
              SEND_STRING(SS_RSFT(SS_TAP(X_V)));
          } else if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              SEND_STRING(SS_RSFT(SS_TAP(X_V)));
          } else { //unshifted previous key
              SEND_STRING(SS_TAP(X_V));
          }
          break;        
        case KC_QUOTE:
          if (is_caps_word_on()) { //checks for caps word status
              SEND_STRING(SS_LSFT(SS_TAP(X_L)));
          } else if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              SEND_STRING(SS_TAP(X_L));
          } else { //unshifted previous key
              SEND_STRING(SS_TAP(X_L));
          }
         break;        
        case KC_COMMA: //I'm using this as a "get one-shot shift to trigger within a word" key for abbreviations and the like... could wait for the timer to run out, but I lack the patience.
            if (is_caps_word_on()) { //checks for caps word status
              SEND_STRING(SS_TAP(X_BSPC)); //erases comma since I don't actually want it, just using it as a trigger for the two lines following
              alpha_pressed = false; //basically ends the timer for the arcane functionality prematurely
              set_oneshot_mods(MOD_BIT(KC_LSFT)); //activates one-shot shift
          } else if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              SEND_STRING(SS_TAP(X_BSPC));
              alpha_pressed = false;
              set_oneshot_mods(MOD_BIT(KC_LSFT));
          } else { //unshifted previous key
              SEND_STRING(SS_TAP(X_BSPC));
              alpha_pressed = false;
              set_oneshot_mods(MOD_BIT(KC_LSFT));
          }
        break;
      default: set_oneshot_mods(MOD_BIT(KC_LSFT));
    }
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
  switch (keycode) {
    case MAGIC_KEY: 
      if (record->event.pressed && layer_state_is(0)) {
        if (get_oneshot_mods() & MOD_MASK_SHIFT) {
          caps_word_toggle(); //toggles on caps word if one shot shift is already active (e.g. through double-tapping the key
        } else {
          if (alpha_pressed) {// letter was pressed within timer limits
            arcane_timer = timer_read(); // reset timer
            process_arcane_l(get_last_keycode(), get_last_mods()); // call arcane code
          } else {//alpha timer timed out, so key functions just as a OSM shift
            set_oneshot_mods(MOD_BIT(KC_LSFT));
          }
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
