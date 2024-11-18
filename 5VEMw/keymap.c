#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

#include "features/sentence_case.h"

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  T_S_C,
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_RIGHT_GUI,   
    KC_TAB,         KC_W,           KC_C,           KC_M,           KC_P,           KC_B,                                           KC_X,           KC_L,           KC_O,           KC_U,           KC_J,           KC_MINUS,       
    KC_BSPC,        KC_R,           KC_S,           KC_T,           KC_H,           KC_F,                                           KC_Y,           KC_N,           KC_A,           KC_E,           KC_I,           KC_COMMA,       
    OSM(MOD_LCTL),  KC_Q,           KC_V,           KC_G,           KC_D,           KC_K,                                           KC_Z,           QK_AREP,        KC_QUOTE,       KC_SCLN,        KC_DOT,         KC_ENTER,       
                                                    KC_SPACE,       OSL(1),                                         OSL(2),         OSM(MOD_RSFT)
  ),
  [1] = LAYOUT_voyager(
    KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,                                          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,         
    KC_TRANSPARENT, TO(3),          KC_MS_WH_UP,    KC_MS_UP,       KC_MS_WH_DOWN,  LED_LEVEL,                                      KC_ASTR,        KC_7,           KC_8,           KC_9,           KC_MINUS,       KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_MS_BTN1,     KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_MS_BTN2,                                     KC_SLASH,       KC_4,           KC_5,           KC_6,           KC_PLUS,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_MS_WH_LEFT,  KC_PSCR,        KC_MS_BTN3,     QK_LLCK,        KC_MS_WH_RIGHT,                                 KC_EQUAL,       KC_1,           KC_2,           KC_3,           KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, TO(0),                                          LCTL(KC_BSPC),  KC_0
  ),
  [2] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, RGB_VAI,        KC_HOME,        KC_UP,          KC_END,         KC_PAGE_UP,                                     KC_PIPE,        KC_AMPR,        KC_QUES,        KC_EXLM,        KC_TILD,        KC_TRANSPARENT, 
    KC_TRANSPARENT, RGB_VAD,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_PGDN,                                        KC_BSLS,        KC_DLR,         KC_PERC,        KC_CIRC,        KC_GRAVE,       KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          T_S_C,          QK_LLCK,        KC_AT,          KC_HASH,        KC_NO,          KC_TRANSPARENT, 
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

const uint16_t PROGMEM combo0[] = { KC_T, KC_G, COMBO_END};
const uint16_t PROGMEM combo1[] = { KC_A, KC_QUOTE, COMBO_END};
const uint16_t PROGMEM combo2[] = { KC_P, KC_H, COMBO_END};
const uint16_t PROGMEM combo3[] = { KC_L, KC_N, COMBO_END};
const uint16_t PROGMEM combo4[] = { KC_M, KC_T, COMBO_END};
const uint16_t PROGMEM combo5[] = { KC_O, KC_A, COMBO_END};
const uint16_t PROGMEM combo6[] = { KC_C, KC_M, COMBO_END};
const uint16_t PROGMEM combo7[] = { KC_H, KC_D, COMBO_END};
const uint16_t PROGMEM combo8[] = { KC_N, KC_SLASH, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, KC_LBRC),
    COMBO(combo1, KC_RBRC),
    COMBO(combo2, KC_LCBR),
    COMBO(combo3, KC_RCBR),
    COMBO(combo4, KC_LABK),
    COMBO(combo5, KC_RABK),
    COMBO(combo6, OSM(MOD_LALT)),
    COMBO(combo7, KC_LPRN),
    COMBO(combo8, KC_RPRN),
};


extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {0,0,0}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {0,0,0}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {0,0,0}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {0,0,0}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {0,0,0}, {193,230,116}, {193,230,116} },

    [1] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {0,0,0}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {0,0,0}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {0,245,245}, {193,230,116}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {0,0,0}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {0,0,0}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {0,0,0}, {193,230,116}, {193,230,116} },

    [2] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {0,0,0}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {193,230,116}, {193,230,116}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {0,0,0}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {0,0,0}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {0,0,0}, {0,0,0}, {193,230,116}, {74,255,255} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (keyboard_config.disable_layer_led) { return false; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_sentence_case(keycode, record)) { return false; }
  switch (keycode) {

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
        case KC_B: return KC_T;
        case KC_C: return KC_K;
        case KC_F: return KC_T;
        case KC_G: return KC_H;
        case KC_P: return KC_T;
        case KC_R: return KC_K;
        case KC_S: return KC_K;
    }
    return KC_SLASH;
}


