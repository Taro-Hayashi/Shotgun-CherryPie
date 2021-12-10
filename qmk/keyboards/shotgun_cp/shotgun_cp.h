// Copyright 2021 Hayashi (@w_vwbw)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "quantum.h"

#define LAYOUT( \
    k00, k01, k02, k03, \
    k10, k11, k12, k13, \
    k20, k21, k22, k23, \
    k30, k31, k32, k33, \
    k40, k41, k42, k43,  \
    r00, r01, r10, r11, r20, r21, \
    r30, r31, r40, r41 \
) { \
    { k00, k01, k02, k03, r00, r01 }, \
    { k10, k11, k12, k13, r10, r11 }, \
    { k20, k21, k22, k23, r20, r21 }, \
    { k30, k31, k32, k33, r30, r31 }, \
    { k40, k41, k42, k43, r40, r41 }  \
}
