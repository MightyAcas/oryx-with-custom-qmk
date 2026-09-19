/*
  Copyright 2018-2022 EricaLinaQi <ericalinaqi@proton.me>
  Adaptation of Alan Reiser's Adaptive keys for Hands Down.
*/

#include QMK_KEYBOARD_H
#include "adaptive_keys.h"
#include <stddef.h>

#ifdef ADAPTIVE_KEYS_ENABLE

#ifndef ADAPTIVE_TERM
#define ADAPTIVE_TERM 500
#endif

#define ADAPTIVE_HISTORY_MAX 8

static uint16_t adaptive_history[ADAPTIVE_HISTORY_MAX];
static uint8_t  adaptive_history_len = 0;
static uint32_t adaptive_history_timer = 0;

static void adaptive_clear_history(void) {
    adaptive_history_len = 0;
}

static void adaptive_push_history(uint16_t keycode) {
    if (adaptive_history_len >= ADAPTIVE_HISTORY_MAX) {
        for (uint8_t i = 1; i < ADAPTIVE_HISTORY_MAX; i++) {
            adaptive_history[i - 1] = adaptive_history[i];
        }
        adaptive_history_len = ADAPTIVE_HISTORY_MAX - 1;
    }
    adaptive_history[adaptive_history_len++] = keycode;
    adaptive_history_timer = timer_read32();
}

static void adaptive_pop_history(void) {
    if (adaptive_history_len > 0) {
        adaptive_history_len--;
    }
    adaptive_history_timer = timer_read32();
}

static uint16_t adaptive_peek_history(void) {
    if (adaptive_history_len > 0) {
        return adaptive_history[adaptive_history_len - 1];
    }
    return KC_NO;
}

static bool adaptive_text_key(uint16_t keycode) {
    if ((keycode >= KC_A && keycode <= KC_Z) ||
        (keycode >= KC_1 && keycode <= KC_0)) {
        return true;
    }

    switch (keycode) {
        case KC_SPC:
        case KC_COMM:
        case KC_DOT:
        case KC_SCLN:
        case KC_QUOT:
        case KC_MINS:
        case KC_EQL:
        case KC_SLSH:
        case KC_BSLS:
        case KC_LBRC:
        case KC_RBRC:
        case KC_GRV:
            return true;
        default:
            return false;
    }
}

static uint16_t adaptive_tap_keycode(uint16_t keycode, keyrecord_t *record) {
    if (IS_QK_MOD_TAP(keycode) || IS_QK_LAYER_TAP(keycode)) {
        return record->tap.count ? get_tap_keycode(keycode) : KC_NO;
    }
    if (keycode >= QK_MODS && keycode <= QK_MODS_MAX) {
        return QK_MODS_GET_BASIC_KEYCODE(keycode);
    }
    return keycode;
}

// Adaptive key struct
typedef struct {
    uint16_t prefix_key;
    uint16_t keycode;
    bool processed;
    const uint16_t *keys;
} ak_t;

#define AK_END 65535
#define BLANK(...)
#define AK_STRUCT {prefix_key, key, processed, &ak_keys##name[0]}

#define AK_ENUM(name, prefix_key, key, processed, ...) AK_##name,
#define AK_DATA(name, prefix_key, key, processed, ...) \
    const uint16_t PROGMEM ak_keys##name[] = {__VA_ARGS__, AK_END};
#define AK_ENTRY(name, prefix_key, key, processed, ...) \
    [AK_##name] = {prefix_key, key, processed, &ak_keys##name[0]},

// Create enum
#undef AK
#define AK AK_ENUM
enum aks {
#include "adaptive_keys.def"
    AK_LENGTH
};
uint16_t AK_LEN = AK_LENGTH;

// Create data arrays
#undef AK
#define AK AK_DATA
#include "adaptive_keys.def"
#undef AK

// Create struct array
#define AK AK_ENTRY
ak_t adaptive_keys[] = {
#include "adaptive_keys.def"
};
#undef AK

ak_t* find_adaptive_key(uint16_t keycode, uint16_t prior_keycode) {
    for (int i = 0; i < AK_LEN; ++i) {
        if (keycode == adaptive_keys[i].keycode &&
            prior_keycode == adaptive_keys[i].prefix_key) {
            return (&adaptive_keys[i]);
        }
    }
    return NULL;
}

static bool send_adaptive_keys(ak_t* ak) {
    for (uint8_t j = 0; pgm_read_word(&ak->keys[j]) != AK_END; ++j) {
        uint16_t out_key = pgm_read_word(&ak->keys[j]);
        tap_code16(out_key);
        if (out_key == KC_BSPC) {
            adaptive_pop_history();
        } else if (adaptive_text_key(out_key)) {
            adaptive_push_history(out_key);
        }
    }
    return ak->processed;
}

bool process_adaptive_key(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) {
        return true;
    }

    uint16_t basic = adaptive_tap_keycode(keycode, record);
    if (basic == KC_NO) {
        return true;
    }

    uint8_t mods = get_mods() | get_oneshot_mods() | get_weak_mods();

    // 1. Intercept Backspace
    if (basic == KC_BSPC) {
        if (mods || keycode != KC_BSPC) {
            // Modified backspace (e.g. Ctrl+Backspace) wipes context
            adaptive_clear_history();
        } else {
            // Single unshifted backspace pops the top character
            adaptive_pop_history();
        }
        return true;
    }

    // 2. Check idle expiration
    if (timer_elapsed32(adaptive_history_timer) > ADAPTIVE_TERM) {
        adaptive_clear_history();
    }

    // 3. Inspect top of history stack
    uint16_t prior_keycode = adaptive_peek_history();
    ak_t* ak = find_adaptive_key(basic, prior_keycode);

    if (ak != NULL) {
        uint8_t saved_mods = get_mods();
        if (!is_caps_word_on()) {
            unregister_mods(MOD_MASK_SHIFT);
        }

        bool return_processed = send_adaptive_keys(ak);
        register_mods(saved_mods);

        if (return_processed && adaptive_text_key(basic)) {
            adaptive_push_history(basic);
        }
        return return_processed;
    }

    // 4. Record plain text keys into history
    if (adaptive_text_key(basic) &&
        (!mods || (basic >= KC_A && basic <= KC_Z && !(mods & ~MOD_MASK_SHIFT)))) {
        adaptive_push_history(basic);
    } else {
        adaptive_clear_history();
    }

    return true;
}
#endif
