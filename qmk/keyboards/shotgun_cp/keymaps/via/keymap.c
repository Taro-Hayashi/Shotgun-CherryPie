// Copyright 2021 Hayashi (@w_vwbw)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

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

keyevent_t encoder1_ccw = {
    .key = (keypos_t){.row = 0, .col = 5},
    .pressed = false
};

keyevent_t encoder1_cw = {
    .key = (keypos_t){.row = 0, .col = 4},
    .pressed = false
};

keyevent_t encoder2_ccw = {
    .key = (keypos_t){.row = 1, .col = 5},
    .pressed = false
};

keyevent_t encoder2_cw = {
    .key = (keypos_t){.row = 1, .col = 4},
    .pressed = false
};

keyevent_t encoder3_ccw = {
    .key = (keypos_t){.row = 2, .col = 5},
    .pressed = false
};

keyevent_t encoder3_cw = {
    .key = (keypos_t){.row = 2, .col = 4},
    .pressed = false
};

keyevent_t encoder4_ccw = {
    .key = (keypos_t){.row = 3, .col = 5},
    .pressed = false
};

keyevent_t encoder4_cw = {
    .key = (keypos_t){.row = 3, .col = 4},
    .pressed = false
};

keyevent_t encoder5_ccw = {
    .key = (keypos_t){.row = 4, .col = 5},
    .pressed = false
};

keyevent_t encoder5_cw = {
    .key = (keypos_t){.row = 4, .col = 4},
    .pressed = false
};



void matrix_scan_user(void) {
    if (IS_PRESSED(encoder1_ccw)) {
        encoder1_ccw.pressed = false;
        encoder1_ccw.time = (timer_read() | 1);
        action_exec(encoder1_ccw);
    }

    if (IS_PRESSED(encoder1_cw)) {
        encoder1_cw.pressed = false;
        encoder1_cw.time = (timer_read() | 1);
        action_exec(encoder1_cw);
    }

    if (IS_PRESSED(encoder2_ccw)) {
        encoder2_ccw.pressed = false;
        encoder2_ccw.time = (timer_read() | 1);
        action_exec(encoder2_ccw);
    }

    if (IS_PRESSED(encoder2_cw)) {
        encoder2_cw.pressed = false;
        encoder2_cw.time = (timer_read() | 1);
        action_exec(encoder2_cw);
    }

    if (IS_PRESSED(encoder3_ccw)) {
        encoder3_ccw.pressed = false;
        encoder3_ccw.time = (timer_read() | 1);
        action_exec(encoder3_ccw);
    }

    if (IS_PRESSED(encoder3_cw)) {
        encoder3_cw.pressed = false;
        encoder3_cw.time = (timer_read() | 1);
        action_exec(encoder3_cw);
    }

    if (IS_PRESSED(encoder4_ccw)) {
        encoder4_ccw.pressed = false;
        encoder4_ccw.time = (timer_read() | 1);
        action_exec(encoder4_ccw);
    }

    if (IS_PRESSED(encoder4_cw)) {
        encoder4_cw.pressed = false;
        encoder4_cw.time = (timer_read() | 1);
        action_exec(encoder4_cw);
    }
    
    if (IS_PRESSED(encoder5_ccw)) {
        encoder5_ccw.pressed = false;
        encoder5_ccw.time = (timer_read() | 1);
        action_exec(encoder5_ccw);
    }

    if (IS_PRESSED(encoder5_cw)) {
        encoder5_cw.pressed = false;
        encoder5_cw.time = (timer_read() | 1);
        action_exec(encoder5_cw);
    }
}


bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            encoder1_cw.pressed = true;
            encoder1_cw.time = (timer_read() | 1);
            action_exec(encoder1_cw);
        } else {
            encoder1_ccw.pressed = true;
            encoder1_ccw.time = (timer_read() | 1);
            action_exec(encoder1_ccw);
        }
    } else if (index == 1) {
        if (clockwise) {
            encoder2_cw.pressed = true;
            encoder2_cw.time = (timer_read() | 1);
            action_exec(encoder2_cw);
        } else {
            encoder2_ccw.pressed = true;
            encoder2_ccw.time = (timer_read() | 1);
            action_exec(encoder2_ccw);
        }
    } else if (index == 2) {
        if (clockwise) {
            encoder3_cw.pressed = true;
            encoder3_cw.time = (timer_read() | 1);
            action_exec(encoder3_cw);
        } else {
            encoder3_ccw.pressed = true;
            encoder3_ccw.time = (timer_read() | 1);
            action_exec(encoder3_ccw);
        }
    } else if (index == 3) {
        if (clockwise) {
            encoder4_cw.pressed = true;
            encoder4_cw.time = (timer_read() | 1);
            action_exec(encoder4_cw);
        } else {
            encoder4_ccw.pressed = true;
            encoder4_ccw.time = (timer_read() | 1);
            action_exec(encoder4_ccw);
        }
    } else if (index == 4) {
        if (clockwise) {
            encoder5_cw.pressed = true;
            encoder5_cw.time = (timer_read() | 1);
            action_exec(encoder5_cw);
        } else {
            encoder5_ccw.pressed = true;
            encoder5_ccw.time = (timer_read() | 1);
            action_exec(encoder5_ccw);
        }
    }

    return true;
}
