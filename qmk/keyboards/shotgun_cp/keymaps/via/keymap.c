// Copyright 2021 Hayashi (@w_vwbw)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "pico_eeprom.h"

enum layer_names {
    BASE = 0,
    LOWER,
    UPPER,
    LIGHT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT(
        KC_TAB,  KC_PSLS, KC_PAST, KC_PMNS,
        KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
        KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
        KC_P1,   KC_P2,   KC_P3,   KC_PENT,
        LT(LIGHT, KC_P0),   KC_P0,   KC_PDOT, KC_PENT,
        // ROTARY ENCODER
        KC_A, KC_B, KC_C, KC_D, KC_E, KC_F,
        KC_G, KC_H, KC_I, KC_J
    ),
    [LOWER] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        // ROTARY ENCODER
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [UPPER] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        // ROTARY ENCODER
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [LIGHT] = LAYOUT(
        XXXXXXX, RGB_HUI, RGB_HUD, RGB_TOG,
        XXXXXXX, RGB_SAI, RGB_SAD, XXXXXXX,
        XXXXXXX, RGB_VAI, RGB_VAD, XXXXXXX,
        XXXXXXX, RGB_SPI, RGB_SPD, XXXXXXX,
        LT(LIGHT, KC_P0), RGB_MOD, RGB_RMOD, XXXXXXX,
        // ROTARY ENCODERc
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    )
};

// ENCODER FOR VIA
bool encoder_update_user(uint8_t index, bool clockwise) {
  keypos_t key;
  if (index == 0) {
    if (clockwise) {
        key.row = 0;
        key.col = 4;
    } else {
        key.row = 0;
        key.col = 5;
    }
  } else if (index == 1){
    if (clockwise) {
        key.row = 1;
        key.col = 4;
    } else {
        key.row = 1;
        key.col = 5;
    }
  } else if (index == 2){
    if (clockwise) {
        key.row = 2;
        key.col = 4;
    } else {
        key.row = 2;
        key.col = 5;
    }
  } else if (index == 3){
    if (clockwise) {
        key.row = 3;
        key.col = 4;
    } else {
        key.row = 3;
        key.col = 5;
    }
  } else if (index == 4){
    if (clockwise) {
        key.row = 4;
        key.col = 4;
    } else {
        key.row = 4;
        key.col = 5;
    }
  }
  uint8_t  layer   = layer_switch_get_layer(key);
  uint16_t keycode = keymap_key_to_keycode(layer, key);
  tap_code16(keycode);
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_FN0:
            if (record->event.pressed) {
                printf("save keymap to eeprom\n");
                pico_eepemu_flash_dynamic_keymap();
                printf("complete\n");
                printf("save eeconfig to eeprom\n");
                pico_eepemu_flash_eeconfig();
                printf("complete\n");
            }
            return false;
            break;
    }
    return true;
}
