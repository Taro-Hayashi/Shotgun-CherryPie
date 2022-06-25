// Copyright 2022 Taro Hayashi (@w_vwbw)
// SPDX-License-Identifier: GPL-2.0-or-later

#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED

RGB_MATRIX_EFFECT(SEPARATED)
RGB_MATRIX_EFFECT(OVERGLOW_REACTIVE)
RGB_MATRIX_EFFECT(OVERGLOW_REACTIVE_SEPARATED)
RGB_MATRIX_EFFECT(UNDERGLOW_REACTIVE)
RGB_MATRIX_EFFECT(UNDERGLOW_REACTIVE_SEPARATED)

#    ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

#define UNDERGLOW_NUM 12
#define OVERGLOW_NUM 16

static bool SEPARATED(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    uint8_t i = led_min;
    // UNDERGLOW
    for (; i < UNDERGLOW_NUM; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        HSV hsv = rgb_matrix_config.hsv;
        hsv.h += rgb_matrix_config.speed + (40 * get_highest_layer(layer_state));
        RGB rgb = rgb_matrix_hsv_to_rgb(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    // OVERGLOW
    for (; i < UNDERGLOW_NUM + OVERGLOW_NUM; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        HSV hsv = rgb_matrix_config.hsv;
        RGB rgb = rgb_matrix_hsv_to_rgb(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    return led_max < DRIVER_LED_TOTAL;
}

static bool OVERGLOW_REACTIVE(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    uint8_t count = g_last_hit_tracker.count;
    uint8_t i = led_min;
    // UNDERGLOW
    for (; i < UNDERGLOW_NUM; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        HSV hsv = rgb_matrix_config.hsv;
        RGB rgb = rgb_matrix_hsv_to_rgb(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    // OVERGLOW
    for (; i < UNDERGLOW_NUM + OVERGLOW_NUM; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        HSV hsv = rgb_matrix_config.hsv;
        hsv.v   = 0;
        for (uint8_t j = 0; j < count; j++) {
            int16_t  dx   = g_led_config.point[i].x - g_last_hit_tracker.x[j];
            int16_t  dy   = g_led_config.point[i].y - g_last_hit_tracker.y[j];
            uint8_t  dist = sqrt16(dx * dx + dy * dy);
            uint16_t tick = scale16by8(g_last_hit_tracker.tick[j], qadd8(rgb_matrix_config.speed, 1));
            uint16_t effect = tick + dist * 5;
            if (effect > 255) effect = 255;
            hsv.v = qadd8(hsv.v, 255 - effect);
        }
        hsv.v = scale8(hsv.v, rgb_matrix_config.hsv.v);
        RGB rgb = rgb_matrix_hsv_to_rgb(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    return led_max < DRIVER_LED_TOTAL;
}

static bool OVERGLOW_REACTIVE_SEPARATED(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    uint8_t count = g_last_hit_tracker.count;
    uint8_t i = led_min;
    // UNDERGLOW
    for (; i < UNDERGLOW_NUM; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        HSV hsv = rgb_matrix_config.hsv;
        hsv.h += rgb_matrix_config.speed + (40 * get_highest_layer(layer_state));
        RGB rgb = rgb_matrix_hsv_to_rgb(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    // OVERGLOW
    for (; i < UNDERGLOW_NUM + OVERGLOW_NUM; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        HSV hsv = rgb_matrix_config.hsv;
        hsv.v   = 0;
        for (uint8_t j = 0; j < count; j++) {
            int16_t  dx   = g_led_config.point[i].x - g_last_hit_tracker.x[j];
            int16_t  dy   = g_led_config.point[i].y - g_last_hit_tracker.y[j];
            uint8_t  dist = sqrt16(dx * dx + dy * dy);
            uint16_t tick = scale16by8(g_last_hit_tracker.tick[j], qadd8(rgb_matrix_config.speed, 1));
            uint16_t effect = tick + dist * 5;
            if (effect > 255) effect = 255;
            hsv.v = qadd8(hsv.v, 255 - effect);
        }
        hsv.v = scale8(hsv.v, rgb_matrix_config.hsv.v);
        RGB rgb = rgb_matrix_hsv_to_rgb(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    return led_max < DRIVER_LED_TOTAL;
}

static bool UNDERGLOW_REACTIVE(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    uint8_t count = g_last_hit_tracker.count;
    uint8_t i = led_min;
    // UNDERGLOW
    for (; i < UNDERGLOW_NUM; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        HSV hsv = rgb_matrix_config.hsv;
        hsv.v   = 0;
        for (uint8_t j = 0; j < count; j++) {
            int16_t  dx   = g_led_config.point[i].x - g_last_hit_tracker.x[j];
            int16_t  dy   = g_led_config.point[i].y - g_last_hit_tracker.y[j];
            uint8_t  dist = sqrt16(dx * dx + dy * dy);
            uint16_t tick = scale16by8(g_last_hit_tracker.tick[j], qadd8(rgb_matrix_config.speed, 1));
            uint16_t effect = tick + dist * 5;
            if (effect > 255) effect = 255;
            hsv.v = qadd8(hsv.v, 255 - effect);
        }
        hsv.v = scale8(hsv.v, rgb_matrix_config.hsv.v);
        RGB rgb = rgb_matrix_hsv_to_rgb(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    // OVERGLOW
    for (; i < UNDERGLOW_NUM + OVERGLOW_NUM; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        HSV hsv = rgb_matrix_config.hsv;
        RGB rgb = rgb_matrix_hsv_to_rgb(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    return led_max < DRIVER_LED_TOTAL;
}

static bool UNDERGLOW_REACTIVE_SEPARATED(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    uint8_t count = g_last_hit_tracker.count;
    uint8_t i = led_min;
    // UNDERGLOW
    for (; i < UNDERGLOW_NUM; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        HSV hsv = rgb_matrix_config.hsv;
        hsv.v   = 0;
        for (uint8_t j = 0; j < count; j++) {
            int16_t  dx   = g_led_config.point[i].x - g_last_hit_tracker.x[j];
            int16_t  dy   = g_led_config.point[i].y - g_last_hit_tracker.y[j];
            uint8_t  dist = sqrt16(dx * dx + dy * dy);
            uint16_t tick = scale16by8(g_last_hit_tracker.tick[j], qadd8(rgb_matrix_config.speed, 1));
            uint16_t effect = tick + dist * 5;
            if (effect > 255) effect = 255;
            hsv.v = qadd8(hsv.v, 255 - effect);
        }
        hsv.v = scale8(hsv.v, rgb_matrix_config.hsv.v);
        RGB rgb = rgb_matrix_hsv_to_rgb(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    // OVERGLOW
    for (; i < UNDERGLOW_NUM + OVERGLOW_NUM; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        HSV hsv = rgb_matrix_config.hsv;
        hsv.h += rgb_matrix_config.speed + (40 * get_highest_layer(layer_state));
        RGB rgb = rgb_matrix_hsv_to_rgb(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    return led_max < DRIVER_LED_TOTAL;
}

#    endif
#endif
