// Copyright 2021 Hayashi (@w_vwbw)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "shotgun_cp.h"

void keyboard_post_init_kb(void) {
    debug_enable   = true;
    debug_keyboard = true;
    keyboard_post_init_user();
}

const float r = 64 / 5;   // ROW UNIT
const float c = 224 / 4;  // COL UNIT

led_config_t g_led_config = {
  {    // KEY MATRIX MAP
    { 28, 29, 30, 31 },
    { 32, 33, 34, 35 },
    { 36, 37, 38, 39 },
    { 40, 41, 42, 43 },
    { 44, 45, 46, 47 },
  }, { // PHISICAL MAP
       // UNDERGLOW
      { 3*c, 4.9*r},
      { 3.9*c, 4*r}, { 3.9*c, 3*r}, { 3.9*c, 2*r}, { 3.9*c, 1*r},
      { 3*c, 0.1*r}, { 2*c, 0.1*r}, { 1*c, 0.1*r},
      { 0.1*c, 1*r}, { 0.1*c, 1*r}, { 0.1*c, 3*r}, { 0.1*c, 4*r},
	     // OVERGLOW
       { 3*c, 4.9*r},
       { 3.9*c, 4*r}, { 3.9*c, 3*r}, { 3.9*c, 2*r}, { 3.9*c, 1*r},
       { 3*c, 0.1*r}, { 2*c, 0.1*r}, { 1*c, 0.1*r},
       { 0.1*c, 1*r}, { 0.1*c, 2*r}, { 0.1*c, 3*r}, { 0.1*c, 4*r},
       { 2.1*c, 4*r}, { 2.1*c, 3*r}, { 2*c, 2*r}, { 2*c, 1*r},
       // KEY MATRIX
       {0.5*c, 4.5*r}, {1.5*c, 4.5*r}, {2.5*c, 4.5*r}, {3.5*c, 4.5*r},
       {0.5*c, 3.5*r}, {1.5*c, 3.5*r}, {2.5*c, 3.5*r}, {3.5*c, 3.5*r},
       {0.5*c, 2.5*r}, {1.5*c, 2.5*r}, {2.5*c, 2.5*r}, {3.5*c, 2.5*r},
       {0.5*c, 1.5*r}, {1.5*c, 1.5*r}, {2.5*c, 1.5*r}, {3.5*c, 1.5*r},
       {0.5*c, 0.5*r}, {1.5*c, 0.5*r}, {2.5*c, 0.5*r}, {3.5*c, 0.5*r}
  }, { // FLAGS
       // UNDERGLOW
      LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW,
      LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW,
      LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW,
	     // OVERGLOW
      LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW,
      LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW,
      LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW,
      LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW,
      // KEY MATRIX
      LED_FLAG_KEYLIGHT,LED_FLAG_KEYLIGHT,LED_FLAG_KEYLIGHT,LED_FLAG_KEYLIGHT,
      LED_FLAG_KEYLIGHT,LED_FLAG_KEYLIGHT,LED_FLAG_KEYLIGHT,LED_FLAG_KEYLIGHT,
      LED_FLAG_KEYLIGHT,LED_FLAG_KEYLIGHT,LED_FLAG_KEYLIGHT,LED_FLAG_KEYLIGHT,
      LED_FLAG_KEYLIGHT,LED_FLAG_KEYLIGHT,LED_FLAG_KEYLIGHT,LED_FLAG_KEYLIGHT
  }
};
