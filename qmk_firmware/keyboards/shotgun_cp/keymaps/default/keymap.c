// Copyright 2021 Hayashi (@w_vwbw)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "lib/add_keycodes.h"

enum layer_names {
    BASE = 0,
    LOWER,
    UPPER,
    LIGHT = 5
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT(
        KC_TAB, KC_PSLS, KC_PAST, KC_PMNS,
        KC_P7, KC_P8, KC_P9, KC_PPLS,
        KC_P4, KC_P5, KC_P6, KC_PPLS,
        KC_P1, KC_P2, KC_P3, KC_PENT,
        KC_P0, KC_PDOT, KC_PDOT, KC_PENT
    )
};

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [BASE] =   {
        ENCODER_CCW_CW(KC_A, KC_B),
        ENCODER_CCW_CW(KC_C, KC_D),
        ENCODER_CCW_CW(KC_E, KC_F),
        ENCODER_CCW_CW(KC_G, KC_H),
        ENCODER_CCW_CW(KC_I, KC_J)
        }
};
