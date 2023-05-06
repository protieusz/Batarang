// Copyright 2023 %YOUR_FULL_NAME% (@%YOUR_GITHUB_USERNAME%)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum combo_events {
  COMBO_DEL,
  COMBO_TAB
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    
[0] = LAYOUT(
         
KC_Q, KC_W, KC_E, KC_R, KC_T,                            KC_Y, KC_U, KC_I, KC_O, KC_P,
KC_A, KC_S, KC_D, KC_F, KC_G,                            KC_H, KC_J, KC_K, KC_L, 
KC_Z, KC_X, KC_C, KC_V, KC_B,                            KC_N, KC_M, KC_COMM, KC_DOT, KC_ENT,
KC_LCTL, KC_LGUI, KC_LALT, KC_MS_BTN1, LT(1,KC_BSPC), KC_MUTE, LT(2,KC_SPC), KC_MS_BTN2, KC_QUOT, KC_SCLN, KC_SLSH

),

[1] = LAYOUT(

KC_1, KC_2, KC_3, KC_4, KC_5,                                 KC_6, KC_7, KC_8, KC_9, KC_0,
_______, _______, _______, _______, _______,                  KC_MINS, KC_EQL,  KC_TILD, KC_GRV,
_______, _______, _______, _______, _______,                  KC_LBRC, KC_RBRC, _______, _______, _______,
_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,KC_BSLS

),

[2] = LAYOUT(

KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,                     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
_______, _______, _______, _______, _______,                  _______, _______, _______, _______,
_______, _______, _______, _______, _______,                  _______, _______, _______, KC_UP, _______,
_______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT

),

[3] = LAYOUT(

KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                            KC_F6, KC_F7, KC_F8, KC_F9,KC_PSCR, 
KC_F12, KC_F13, KC_F14, _______, _______,                     _______, _______, _______, KC_F10,
_______, _______, _______, _______, _______,                  _______, _______, _______, _______, _______,
_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______

    )
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return true;
}

#ifdef COMBO_ENABLE
const uint16_t PROGMEM combo_del[] = {KC_Y, KC_H, COMBO_END};
const uint16_t PROGMEM combo_tab[] = {KC_Q, KC_A, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [COMBO_DEL] = COMBO(combo_del, KC_DEL),
  [COMBO_TAB] = COMBO(combo_tab, KC_TAB),
};
#endif
