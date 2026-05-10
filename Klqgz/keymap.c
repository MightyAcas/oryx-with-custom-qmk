#include QMK_KEYBOARD_H
#include "version.h"
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
  AD_H,
  AD_C,
  AD_Y,
  AD_Q,
  AD_L,
  AD_B,
  AD_R,
  AD_S,
  AD_V,
  AD_D,
  AD_E,
  AD_O,
  AD_G,
};




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TAB,         AD_B,           AD_C,           KC_M,           KC_P,           KC_K,                                           KC_X,           AD_L,           AD_O,           KC_U,           KC_J,           KC_MINUS,       
    KC_BSPC,        KC_N,           AD_S,           KC_T,           AD_H,           KC_W,                                           KC_QUOTE,       AD_R,           KC_A,           AD_E,           KC_I,           KC_ENTER,       
    LCTL(KC_Z),     AD_Q,           AD_G,           AD_V,           AD_D,           KC_F,                                           KC_Z,           AD_Y,           KC_DOT,         KC_SCLN,        KC_COMMA,       KC_ESCAPE,      
                                                    KC_SPACE,       OSL(1),                                         RCTL(KC_BSPC),  OSM(MOD_RSFT)
  ),
  [1] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_F2,          KC_PSCR,        KC_HOME,        KC_UP,          KC_END,         KC_PAGE_UP,                                     KC_BSLS,        KC_7,           KC_8,           KC_9,           LED_LEVEL,      KC_F5,          
    KC_TRANSPARENT, QK_LLCK,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_PGDN,                                        KC_GRAVE,       KC_4,           KC_5,           KC_6,           KC_EQUAL,       KC_F8,          
    KC_F4,          KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_UP,       KC_MS_RIGHT,    KC_MS_BTN2,                                     KC_SLASH,       KC_1,           KC_2,           KC_3,           KC_TRANSPARENT, KC_F11,         
                                                    KC_MS_BTN1,     TO(0),                                          KC_TRANSPARENT, MT(MOD_RSFT, KC_0)
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
const uint16_t PROGMEM combo2[] = { KC_P, AD_H, COMBO_END};
const uint16_t PROGMEM combo3[] = { AD_Y, KC_N, COMBO_END};
const uint16_t PROGMEM combo4[] = { KC_M, KC_T, COMBO_END};
const uint16_t PROGMEM combo5[] = { AD_O, KC_A, COMBO_END};
const uint16_t PROGMEM combo6[] = { AD_S, AD_C, COMBO_END};
const uint16_t PROGMEM combo7[] = { AD_E, KC_U, COMBO_END};
const uint16_t PROGMEM combo8[] = { AD_Q, AD_R, COMBO_END};
const uint16_t PROGMEM combo9[] = { AD_B, KC_I, COMBO_END};
const uint16_t PROGMEM combo10[] = { AD_R, AD_L, COMBO_END};
const uint16_t PROGMEM combo11[] = { AD_S, AD_G, COMBO_END};
const uint16_t PROGMEM combo12[] = { KC_T, AD_V, COMBO_END};
const uint16_t PROGMEM combo13[] = { AD_H, AD_D, COMBO_END};
const uint16_t PROGMEM combo14[] = { KC_N, KC_COMMA, COMBO_END};
const uint16_t PROGMEM combo15[] = { KC_A, KC_QUOTE, COMBO_END};
const uint16_t PROGMEM combo16[] = { AD_E, KC_SCLN, COMBO_END};
const uint16_t PROGMEM combo17[] = { KC_I, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo18[] = { KC_COMMA, KC_QUOTE, KC_SCLN, COMBO_END};
const uint16_t PROGMEM combo19[] = { AD_Y, AD_O, KC_U, COMBO_END};
const uint16_t PROGMEM combo20[] = { KC_SPACE, KC_BSPC, COMBO_END};
const uint16_t PROGMEM combo21[] = { KC_COMMA, KC_QUOTE, COMBO_END};
const uint16_t PROGMEM combo22[] = { KC_QUOTE, KC_SCLN, COMBO_END};

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
    COMBO(combo21, KC_QUES),
    COMBO(combo22, KC_EXLM),
};

bool remember_last_key_user(uint16_t keycode, keyrecord_t* record,
                            uint8_t* remembered_mods) {
    switch (keycode) {
        case AD_H:
        case AD_C:
        case AD_Y:
        case AD_Q:
        case AD_L:
        case AD_B:
        case AD_R:
        case AD_S:
        case AD_V:
        case AD_D:
        case AD_E:
        case AD_O:
        case AD_G:
            return false;  // Ignore ALTREP keys. If this is not here, only default action will be done, since the process stuff is apparently run after the remember last key stuff, so that the key is only ever trying to repeat itself.
    }

    return true;  // Other keys can be repeated.
}

static void process_adaptive_h(uint16_t keycode, uint8_t mods) {
    switch (keycode) {
          case KC_W:
          if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              SEND_STRING(SS_TAP(X_C));
          } else { //unshifted previous key
              SEND_STRING(SS_TAP(X_C));
          }
          break;      
          case KC_QUOTE:
          if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              SEND_STRING(SS_TAP(X_R));
          } else { //unshifted previous key
              SEND_STRING(SS_TAP(X_R));
          }
          break;     
          case KC_N:
          if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              SEND_STRING(SS_TAP(X_G));
          } else { //unshifted previous key
              SEND_STRING(SS_TAP(X_G));
          }
          break;      
      default: SEND_STRING(SS_TAP(X_H));
    }
}

static void process_adaptive_c(uint16_t keycode, uint8_t mods) {
    switch (keycode) {
          case KC_W:
          if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              SEND_STRING(SS_TAP(X_H));
          } else { //unshifted previous key
              SEND_STRING(SS_TAP(X_H));
          }
          break;      
          case KC_S:
          if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              SEND_STRING(SS_TAP(X_D));
          } else { //unshifted previous key
              SEND_STRING(SS_TAP(X_D));
          }
          break;     
          case KC_B:
          if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              SEND_STRING(SS_TAP(X_S));
          } else { //unshifted previous key
              SEND_STRING(SS_TAP(X_S));
          }
          break;     
      default: SEND_STRING(SS_TAP(X_C));
    }
}

static void process_adaptive_y(uint16_t keycode, uint8_t mods) {
    switch (keycode) {
          case KC_L:
          if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              SEND_STRING(SS_TAP(X_Q));
          } else { //unshifted previous key
              SEND_STRING(SS_TAP(X_Q));
          }
          break;      
          case KC_R:
          if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              SEND_STRING(SS_TAP(X_Q));
          } else { //unshifted previous key
              SEND_STRING(SS_TAP(X_Q));
          }
          break;      
      default: SEND_STRING(SS_TAP(X_Y));
    }
}

static void process_adaptive_q(uint16_t keycode, uint8_t mods) {
    switch (keycode) {
          case KC_L:
          if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              SEND_STRING(SS_TAP(X_Y));
          } else { //unshifted previous key
              SEND_STRING(SS_TAP(X_Y));
          }
          break;      
          case KC_R:
          if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              SEND_STRING(SS_TAP(X_Y));
          } else { //unshifted previous key
              SEND_STRING(SS_TAP(X_Y));
          }
          break;      
      default: SEND_STRING(SS_TAP(X_Q));
    }
}

static void process_adaptive_l(uint16_t keycode, uint8_t mods) {
    switch (keycode) {
          case KC_R:
          if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              SEND_STRING(SS_TAP(X_B));
          } else { //unshifted previous key
              SEND_STRING(SS_TAP(X_B));
          }
          break;      
      default: SEND_STRING(SS_TAP(X_L));
    }
}

static void process_adaptive_b(uint16_t keycode, uint8_t mods) {
    switch (keycode) {
          case KC_R:
          if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              SEND_STRING(SS_TAP(X_L));
          } else { //unshifted previous key
              SEND_STRING(SS_TAP(X_L));
          }
          break;      
      default: SEND_STRING(SS_TAP(X_B));
    }
}

static void process_adaptive_r(uint16_t keycode, uint8_t mods) {
    switch (keycode) {
          case KC_QUOTE:
          if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              SEND_STRING(SS_TAP(X_H));
          } else { //unshifted previous key
              SEND_STRING(SS_TAP(X_H));
          }
          break;      
      default: SEND_STRING(SS_TAP(X_R));
    }
}

static void process_adaptive_s(uint16_t keycode, uint8_t mods) {
    switch (keycode) {
          case KC_G:
          if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              SEND_STRING(SS_TAP(X_V));
          } else { //unshifted previous key
              SEND_STRING(SS_TAP(X_V));
          }
          break;      
          case KC_B:
          if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              SEND_STRING(SS_TAP(X_C));
          } else { //unshifted previous key
              SEND_STRING(SS_TAP(X_C));
          }
          break;     
      default: SEND_STRING(SS_TAP(X_S));
    }
}

static void process_adaptive_v(uint16_t keycode, uint8_t mods) {
    switch (keycode) {
          case KC_G:
          if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              SEND_STRING(SS_TAP(X_S));
          } else { //unshifted previous key
              SEND_STRING(SS_TAP(X_S));
          }
          break;      
      default: SEND_STRING(SS_TAP(X_V));
    }
}

static void process_adaptive_d(uint16_t keycode, uint8_t mods) {
    switch (keycode) {
          case KC_S:
          if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              SEND_STRING(SS_TAP(X_C));
          } else { //unshifted previous key
              SEND_STRING(SS_TAP(X_C));
          }
          break;      
      default: SEND_STRING(SS_TAP(X_D));
    }
}

static void process_adaptive_e(uint16_t keycode, uint8_t mods) {
    switch (keycode) {
          case KC_U:
          if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              SEND_STRING(SS_TAP(X_O));
          } else { //unshifted previous key
              SEND_STRING(SS_TAP(X_O));
          }
          break;      
      default: SEND_STRING(SS_TAP(X_E));
    }
}

static void process_adaptive_o(uint16_t keycode, uint8_t mods) {
    switch (keycode) {
          case KC_U:
          if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              SEND_STRING(SS_TAP(X_E));
          } else { //unshifted previous key
              SEND_STRING(SS_TAP(X_E));
          }
          break;      
      default: SEND_STRING(SS_TAP(X_O));
    }
}

static void process_adaptive_g(uint16_t keycode, uint8_t mods) {
    switch (keycode) {
          case KC_N:
          if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              SEND_STRING(SS_TAP(X_H));
          } else { //unshifted previous key
              SEND_STRING(SS_TAP(X_H));
          }
          break;      
      default: SEND_STRING(SS_TAP(X_G));
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
    case AD_H: 
      if (record->event.pressed && layer_state_is(0)) {
        if (get_oneshot_mods() & MOD_MASK_SHIFT) {
          caps_word_toggle(); //toggles on caps word if one shot shift is already active (e.g. through double-tapping the key
        } else {
          if (alpha_pressed) {// letter was pressed within timer limits
            arcane_timer = timer_read(); // reset timer
            process_adaptive_h(get_last_keycode(), get_last_mods()); // call arcane code
          } else {//alpha timer timed out, so key functions just as a OSM shift
            set_oneshot_mods(MOD_BIT(KC_LSFT));
          }
        }
      }
      break;

    case AD_C: 
      if (record->event.pressed && layer_state_is(0)) {
        if (get_oneshot_mods() & MOD_MASK_SHIFT) {
          caps_word_toggle(); //toggles on caps word if one shot shift is already active (e.g. through double-tapping the key
        } else {
          if (alpha_pressed) {// letter was pressed within timer limits
            arcane_timer = timer_read(); // reset timer
            process_adaptive_c(get_last_keycode(), get_last_mods()); // call arcane code
          } else {//alpha timer timed out, so key functions just as a OSM shift
            set_oneshot_mods(MOD_BIT(KC_LSFT));
          }
        }
      }
      break;

    case AD_Y: 
      if (record->event.pressed && layer_state_is(0)) {
        if (get_oneshot_mods() & MOD_MASK_SHIFT) {
          caps_word_toggle(); //toggles on caps word if one shot shift is already active (e.g. through double-tapping the key
        } else {
          if (alpha_pressed) {// letter was pressed within timer limits
            arcane_timer = timer_read(); // reset timer
            process_adaptive_y(get_last_keycode(), get_last_mods()); // call arcane code
          } else {//alpha timer timed out, so key functions just as a OSM shift
            set_oneshot_mods(MOD_BIT(KC_LSFT));
          }
        }
      }
      break;

    case AD_Q: 
      if (record->event.pressed && layer_state_is(0)) {
        if (get_oneshot_mods() & MOD_MASK_SHIFT) {
          caps_word_toggle(); //toggles on caps word if one shot shift is already active (e.g. through double-tapping the key
        } else {
          if (alpha_pressed) {// letter was pressed within timer limits
            arcane_timer = timer_read(); // reset timer
            process_adaptive_q(get_last_keycode(), get_last_mods()); // call arcane code
          } else {//alpha timer timed out, so key functions just as a OSM shift
            set_oneshot_mods(MOD_BIT(KC_LSFT));
          }
        }
      }
      break;

    case AD_L: 
      if (record->event.pressed && layer_state_is(0)) {
        if (get_oneshot_mods() & MOD_MASK_SHIFT) {
          caps_word_toggle(); //toggles on caps word if one shot shift is already active (e.g. through double-tapping the key
        } else {
          if (alpha_pressed) {// letter was pressed within timer limits
            arcane_timer = timer_read(); // reset timer
            process_adaptive_l(get_last_keycode(), get_last_mods()); // call arcane code
          } else {//alpha timer timed out, so key functions just as a OSM shift
            set_oneshot_mods(MOD_BIT(KC_LSFT));
          }
        }
      }
      break;

    case AD_B: 
      if (record->event.pressed && layer_state_is(0)) {
        if (get_oneshot_mods() & MOD_MASK_SHIFT) {
          caps_word_toggle(); //toggles on caps word if one shot shift is already active (e.g. through double-tapping the key
        } else {
          if (alpha_pressed) {// letter was pressed within timer limits
            arcane_timer = timer_read(); // reset timer
            process_adaptive_b(get_last_keycode(), get_last_mods()); // call arcane code
          } else {//alpha timer timed out, so key functions just as a OSM shift
            set_oneshot_mods(MOD_BIT(KC_LSFT));
          }
        }
      }
      break;

    case AD_R: 
      if (record->event.pressed && layer_state_is(0)) {
        if (get_oneshot_mods() & MOD_MASK_SHIFT) {
          caps_word_toggle(); //toggles on caps word if one shot shift is already active (e.g. through double-tapping the key
        } else {
          if (alpha_pressed) {// letter was pressed within timer limits
            arcane_timer = timer_read(); // reset timer
            process_adaptive_r(get_last_keycode(), get_last_mods()); // call arcane code
          } else {//alpha timer timed out, so key functions just as a OSM shift
            set_oneshot_mods(MOD_BIT(KC_LSFT));
          }
        }
      }
      break;

    case AD_S: 
      if (record->event.pressed && layer_state_is(0)) {
        if (get_oneshot_mods() & MOD_MASK_SHIFT) {
          caps_word_toggle(); //toggles on caps word if one shot shift is already active (e.g. through double-tapping the key
        } else {
          if (alpha_pressed) {// letter was pressed within timer limits
            arcane_timer = timer_read(); // reset timer
            process_adaptive_s(get_last_keycode(), get_last_mods()); // call arcane code
          } else {//alpha timer timed out, so key functions just as a OSM shift
            set_oneshot_mods(MOD_BIT(KC_LSFT));
          }
        }
      }
      break;

    case AD_V: 
      if (record->event.pressed && layer_state_is(0)) {
        if (get_oneshot_mods() & MOD_MASK_SHIFT) {
          caps_word_toggle(); //toggles on caps word if one shot shift is already active (e.g. through double-tapping the key
        } else {
          if (alpha_pressed) {// letter was pressed within timer limits
            arcane_timer = timer_read(); // reset timer
            process_adaptive_v(get_last_keycode(), get_last_mods()); // call arcane code
          } else {//alpha timer timed out, so key functions just as a OSM shift
            set_oneshot_mods(MOD_BIT(KC_LSFT));
          }
        }
      }
      break;

    case AD_D: 
      if (record->event.pressed && layer_state_is(0)) {
        if (get_oneshot_mods() & MOD_MASK_SHIFT) {
          caps_word_toggle(); //toggles on caps word if one shot shift is already active (e.g. through double-tapping the key
        } else {
          if (alpha_pressed) {// letter was pressed within timer limits
            arcane_timer = timer_read(); // reset timer
            process_adaptive_d(get_last_keycode(), get_last_mods()); // call arcane code
          } else {//alpha timer timed out, so key functions just as a OSM shift
            set_oneshot_mods(MOD_BIT(KC_LSFT));
          }
        }
      }
      break;

    case AD_E: 
      if (record->event.pressed && layer_state_is(0)) {
        if (get_oneshot_mods() & MOD_MASK_SHIFT) {
          caps_word_toggle(); //toggles on caps word if one shot shift is already active (e.g. through double-tapping the key
        } else {
          if (alpha_pressed) {// letter was pressed within timer limits
            arcane_timer = timer_read(); // reset timer
            process_adaptive_e(get_last_keycode(), get_last_mods()); // call arcane code
          } else {//alpha timer timed out, so key functions just as a OSM shift
            set_oneshot_mods(MOD_BIT(KC_LSFT));
          }
        }
      }
      break;

    case AD_O: 
      if (record->event.pressed && layer_state_is(0)) {
        if (get_oneshot_mods() & MOD_MASK_SHIFT) {
          caps_word_toggle(); //toggles on caps word if one shot shift is already active (e.g. through double-tapping the key
        } else {
          if (alpha_pressed) {// letter was pressed within timer limits
            arcane_timer = timer_read(); // reset timer
            process_adaptive_o(get_last_keycode(), get_last_mods()); // call arcane code
          } else {//alpha timer timed out, so key functions just as a OSM shift
            set_oneshot_mods(MOD_BIT(KC_LSFT));
          }
        }
      }
      break;

    case AD_G: 
      if (record->event.pressed && layer_state_is(0)) {
        if (get_oneshot_mods() & MOD_MASK_SHIFT) {
          caps_word_toggle(); //toggles on caps word if one shot shift is already active (e.g. through double-tapping the key
        } else {
          if (alpha_pressed) {// letter was pressed within timer limits
            arcane_timer = timer_read(); // reset timer
            process_adaptive_g(get_last_keycode(), get_last_mods()); // call arcane code
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
