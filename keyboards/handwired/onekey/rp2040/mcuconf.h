// Copyright 2022 Stefan Kerkmann
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include_next <mcuconf.h>

 #undef RP_PWM_USE_PWM2
 #define RP_PWM_USE_PWM2 TRUE

// #undef RP_PWM_USE_PWM4
// #define RP_PWM_USE_PWM4 TRUE

#undef RP_I2C_USE_I2C1
#define RP_I2C_USE_I2C1 TRUE

#undef RP_SPI_USE_SPI0
#define RP_SPI_USE_SPI0 TRUE