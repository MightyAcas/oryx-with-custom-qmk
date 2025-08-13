#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

bool alpha_pressed = false; // variable for timer to disable arcane key functionality after no letter has been pressed for x amount of time
bool dot_trigger = false; //. pressed previously?
bool comma_trigger = false; //comma pressed previously?
bool shift_trigger = false; //was key shifted?
uint16_t arcane_timer = 0;     // timer 
uint16_t last_key_manual = 0; // for timer reset

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
  ST_MACRO_0,
  ST_MACRO_1,
  ST_MACRO_2,
  ST_MACRO_3,
  ARCANE_L
};



#define DUAL_FUNC_0 LT(3, KC_3)
#define DUAL_FUNC_1 LT(7, KC_M)
#define DUAL_FUNC_2 LT(12, KC_K)
#define DUAL_FUNC_3 LT(13, KC_F9)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TAB,         KC_W,           KC_C,           KC_M,           KC_P,           KC_K,                                           KC_Z,           KC_L,           KC_O,           KC_U,           KC_J,           KC_MINUS,       
    KC_BSPC,        KC_R,           KC_S,           KC_T,           KC_H,           KC_B,                                           KC_X,           KC_N,           KC_A,           KC_E,           KC_I,           KC_COMMA,       
    LCTL(KC_Z),     KC_Q,           KC_G,           KC_D,           KC_F,           KC_V,                                           KC_SLASH,       KC_Y,           KC_QUOTE,       KC_SCLN,        KC_DOT,         KC_ENTER,       
                                                    KC_SPACE,       OSL(1),                                         LCTL(KC_BSPC),  ARCANE_L
  ),
  [1] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_ESCAPE,      ST_MACRO_0,     ST_MACRO_1,     KC_AMPR,        KC_PIPE,                                        KC_ASTR,        KC_7,           KC_8,           KC_9,           KC_EXLM,        KC_TRANSPARENT, 
    KC_TRANSPARENT, MT(MOD_RGUI, KC_GRAVE),DUAL_FUNC_0,    DUAL_FUNC_1,    DUAL_FUNC_2,    KC_BSLS,                                        KC_SLASH,       MT(MOD_RSFT, KC_4),MT(MOD_RCTL, KC_5),MT(MOD_RALT, KC_6),DUAL_FUNC_3,    KC_QUES,        
    KC_TRANSPARENT, KC_TILD,        KC_HASH,        KC_AT,          QK_LLCK,        TO(2),                                          KC_EQUAL,       KC_1,           KC_2,           KC_3,           KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, TO(0),                                          KC_TRANSPARENT, KC_0
  ),
  [2] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                          KC_PAGE_UP,     KC_HOME,        KC_UP,          KC_END,         KC_NO,          ST_MACRO_2,     
    KC_TRANSPARENT, MT(MOD_LGUI, KC_F6),MT(MOD_LALT, KC_F7),MT(MOD_LCTL, KC_F8),MT(MOD_LSFT, KC_F9),KC_F10,                                         KC_PGDN,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_LEFT_GUI,    ST_MACRO_3,     
    KC_TRANSPARENT, KC_F11,         KC_F12,         KC_F13,         TO(3),          RGB_MODE_FORWARD,                                KC_PSCR,        QK_LLCK,        KC_CAPS,        KC_NUM,         KC_NO,          KC_TRANSPARENT, 
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

const uint16_t PROGMEM combo0[] = { KC_B, KC_G, COMBO_END};
const uint16_t PROGMEM combo1[] = { KC_TAB, KC_Q, COMBO_END};
const uint16_t PROGMEM combo2[] = { KC_P, KC_H, COMBO_END};
const uint16_t PROGMEM combo3[] = { KC_L, KC_N, COMBO_END};
const uint16_t PROGMEM combo4[] = { KC_M, KC_T, COMBO_END};
const uint16_t PROGMEM combo5[] = { KC_O, KC_A, COMBO_END};
const uint16_t PROGMEM combo6[] = { KC_S, KC_C, COMBO_END};
const uint16_t PROGMEM combo7[] = { KC_E, KC_U, COMBO_END};
const uint16_t PROGMEM combo8[] = { KC_R, KC_W, COMBO_END};
const uint16_t PROGMEM combo9[] = { KC_I, KC_J, COMBO_END};

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

// Everything below is taken from wYvern1349's oryx with custom qmk repo
// this implementation is capaple of having OSM shift, caps word, repeat, and magic all on the same key.
// however, i've opted to not use repeat in favor of only using it as my magic/OSM Shift key.
// it would get more complicated if I chose to expand beyond this scope, so i'm choosing to keep it short and clean for the sake of my own sanity. but know that it's capable of really cool stuff that I'm not using!

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case ARCANE_L:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_MINS:
        case KC_DEL:
        case KC_UNDS:
        case KC_COMMA:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}

bool remember_last_key_user(uint16_t keycode, keyrecord_t* record,
                            uint8_t* remembered_mods) {
    switch (keycode) {
        case ARCANE_L:
            return false;  // Ignore ALTREP keys. If this is not here, only default action will be done, since the process stuff is apparently run after the remember last key stuff, so that the key is only ever trying to repeat itself.
    }

    return true;  // Other keys can be repeated.
}

static void process_arcane_l(uint16_t keycode, uint8_t mods) {
    switch (keycode) {
        case KC_G:
          //sfbs
          if (is_caps_word_on()) { //checks for caps word status
              send_string("S");
          } else if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              send_string("s");
          } else { //unshifted previous key
              send_string("s");
          }
         break;
        case KC_L:
          if (is_caps_word_on()) {
              send_string("Y");
          } else if (mods & MOD_MASK_SHIFT) {
              send_string("y");
          } else {
              send_string("y");
          }
         break;
        case KC_N:
          if (is_caps_word_on()) {
              send_string("Y");
          } else if (mods & MOD_MASK_SHIFT) {
              send_string("y");
          } else {
              send_string("y");
          }
         break;
        case KC_S:
          if (is_caps_word_on()) {
              send_string("C");
          } else if (mods & MOD_MASK_SHIFT) {
              send_string("c");
          } else {
              send_string("c");
          }
         break;
        case KC_W:
          if (is_caps_word_on()) {
              send_string("R");
          } else if (mods & MOD_MASK_SHIFT) {
              send_string("r");
          } else {
              send_string("r");
          }
         break;
        case KC_Y:
          if (is_caps_word_on()) {
              send_string("L");
          } else if (mods & MOD_MASK_SHIFT) {
              send_string("l");
          } else {
              send_string("l");
          }
         break;
      //2u scissors
        case KC_QUOTE:
          if (is_caps_word_on()) {
              send_string("L");
          } else if (mods & MOD_MASK_SHIFT) {
              send_string("l");
          } else {
              send_string("l");
          }
         break;
        case KC_U:
          if (is_caps_word_on()) {
              send_string("'");
          } else if (mods & MOD_MASK_SHIFT) {
              send_string("'");
          } else {
              send_string("'");
          }
         break;
        case KC_Z:
          if (is_caps_word_on()) {
              send_string("Y");
          } else if (mods & MOD_MASK_SHIFT) {
              send_string("y");
          } else {
              send_string("y");
          }
         break;
      //1u scissors
        case KC_A:
          if (is_caps_word_on()) {
              send_string("L");
          } else if (mods & MOD_MASK_SHIFT) {
              send_string("l");
          } else {
              send_string("l");
          }
         break;
        case KC_E:
          if (is_caps_word_on()) {
              send_string("L");
          } else if (mods & MOD_MASK_SHIFT) {
              send_string("l");
          } else { 
              send_string("l");
          }
         break;
      //lateral stretch
        case KC_C:
          if (is_caps_word_on()) {
              send_string("K");
          } else if (mods & MOD_MASK_SHIFT) { 
              send_string("k");
          } else { 
              send_string("k");
          }
         break;
        case KC_M:
          if (is_caps_word_on()) {
              send_string("B");
          } else if (mods & MOD_MASK_SHIFT) {
              send_string("b");
          } else {
              send_string("b");
          }
         break;
      //redirects
        case KC_R:
          if (is_caps_word_on()) {
              send_string("D");
          } else if (mods & MOD_MASK_SHIFT) {
              send_string("d");
          } else { 
              send_string("d");
          }
         break;
        case KC_T:
          if (is_caps_word_on()) {
              send_string("R");
          } else if (mods & MOD_MASK_SHIFT) {
              send_string("r");
          } else {
              send_string("r");
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
      dot_trigger = false;
      comma_trigger = false;
      shift_trigger = false;
      set_last_keycode(KC_SPACE);
  } else { //timer update
    switch (get_last_keycode()) {
      case KC_A ... KC_Z:
      case KC_SCLN:
      case KC_COMMA:
      case KC_DOT:
        if (last_key_manual != get_last_keycode()) {
          last_key_manual = get_last_keycode();
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
      dot_trigger = false;
      comma_trigger = false;
      shift_trigger = false;
      break; //these were all the keys that end the timer prematurely
    }
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_COMMA:
      if (record->event.pressed && layer_state_is(0)) {
            if (dot_trigger) {
               if (is_caps_word_on()) { //checks for caps word status
              SEND_STRING(SS_TAP(X_BSPC) SS_RSFT(SS_TAP(X_QUOTE)) SS_RSFT(SS_TAP(X_O)));
            } else if (shift_trigger) { 
              SEND_STRING(SS_TAP(X_BSPC) SS_RSFT(SS_TAP(X_QUOTE)) SS_RSFT(SS_TAP(X_O)));
            } else { //unshifted previous key
              SEND_STRING(SS_TAP(X_BSPC) SS_RSFT(SS_TAP(X_QUOTE)) SS_TAP(X_O));
            }
            dot_trigger = false;
            shift_trigger = false;
            set_last_keycode(KC_D);
            return false;
            } else {
        dot_trigger = false;
        comma_trigger = true;
        shift_trigger = false;
        if (get_oneshot_mods() & MOD_MASK_SHIFT) {
          shift_trigger = true;
        }
      }
      }
    break;
    case KC_DOT:
    if (record->event.pressed && layer_state_is(0)) {
        dot_trigger = true;
        comma_trigger = false;
        shift_trigger = false;
        if (get_oneshot_mods() & MOD_MASK_SHIFT) {
          shift_trigger = true;
        }
      }
    break;
    case ARCANE_L: 
               if (record->event.pressed && layer_state_is(0)) {
                 if (get_oneshot_mods() & MOD_MASK_SHIFT) {
                    caps_word_toggle(); //toggles on caps word if one shot shift is already active (e.g. through double-tapping the key
               } else {
                   if (alpha_pressed) {// letter was pressed within timer limits
                     arcane_timer = timer_read(); // reset timer
                     process_arcane_l(get_last_keycode(), get_last_mods()); // call arcane code
                     dot_trigger = false;
                     comma_trigger = false;
                     shift_trigger = false;
                   } else {//alpha timer timed out, so key functions just as a OSM shift
                      set_oneshot_mods(MOD_BIT(KC_LSFT));
                   }
                 }
               }
       break; 
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
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_5) SS_TAP(X_KP_0) ));
    }
    break;
    case ST_MACRO_3:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_5) SS_TAP(X_KP_1) ));
    }
    break;

    case DUAL_FUNC_0:
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
    case DUAL_FUNC_1:
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
    case DUAL_FUNC_2:
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
    case DUAL_FUNC_3:
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
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}


