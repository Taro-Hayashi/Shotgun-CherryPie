// Copyright 2021 Hayashi (@w_vwbw)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "config_common.h"

#define VENDOR_ID    0xFEED
#define PRODUCT_ID   0x0892
#define DEVICE_VER   0x0001
#define MANUFACTURER hyashi
#define PRODUCT      ShotgunCherryPie

/* KEY MATRIX */
#define MATRIX_ROWS 5
#define MATRIX_COLS 6
#define MATRIX_ROW_PINS { 9, 10, 11, 12, 14 }
#define MATRIX_COL_PINS { 5, 4, 2, 3, 7, 8 }    // 7, 8 FOR VIA
#define DIODE_DIRECTION COL2ROW

#define ENCODERS_PAD_A { 27, 26, 21, 19, 17 }
#define ENCODERS_PAD_B { 28, 22, 20, 18, 16 }
#define ENCODER_RESOLUTIONS { 4, 4, 4, 4, 4, }

/* RGB MATRIX */
#define RGB_DI_PIN 0
#define DRIVER_LED_TOTAL 28
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 200
#define RGB_MATRIX_HUE_STEP 4
#define RGB_MATRIX_SAT_STEP 8
#define RGB_MATRIX_VAL_STEP 8
#define RGB_MATRIX_SPD_STEP 8
#define RGB_MATRIX_STARTUP_VAL 120

/* LIGHT PATTERN */
#define RGB_MATRIX_KEYPRESSES
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS

/* ETC */
#define DEBOUNCE 5
#define LOCKING_SUPPORT_ENABLE
#define LOCKING_RESYNC_ENABLE
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
#define DEBUG_MATRIX_SCAN_RATE
#define DEBUG_ACTION
