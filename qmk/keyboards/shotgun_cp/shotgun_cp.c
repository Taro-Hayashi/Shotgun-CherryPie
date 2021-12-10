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
       { 2.1*c, 4*r}, { 2.1*c, 3*r}, { 2*c, 2*r}, { 2*c, 1*r}
  }, { // FLAGS
       // UNDERGLOW
      LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW,
      LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW,
      LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW,
	     // OVERGLOW
      LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW,
      LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW,
      LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW,
      LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW
  }
};
