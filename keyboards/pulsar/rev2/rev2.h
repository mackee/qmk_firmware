/* Copyright 2020 mackee
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once

#include "quantum.h"

/* This a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
#define LAYOUT( \
    k09, k08, k07, k01, k10,          \
    k05, k04, k03, k06, k11,          \
                   k02,               \
              l01, l02, lt,  l03, l04 \
) \
{ \
    { k01, k02,   k03,   k04,   k05 },   \
    { k06, k07,   k08,   k09,   k10 },   \
    { k11, KC_NO, KC_NO, KC_NO, KC_NO }, \
    { l01, l02,   lt,    l03,   l04 },   \
}

#ifdef VIA_ENABLE

#include "via.h" // only for EEPROM address
#define EEPROM_ENABLED_ENCODER_MODES (VIA_EEPROM_CUSTOM_CONFIG_ADDR)
#define EEPROM_CUSTOM_ENCODER (VIA_EEPROM_CUSTOM_CONFIG_ADDR+1)

enum pulsar_keyboard_value_id {
  id_encoder_modes = 0x80,
  id_encoder_custom
};

enum encoder_modes {
  ENC_MODE_VOLUME,
  ENC_MODE_MEDIA,
  ENC_MODE_SCROLL,
  ENC_MODE_BRIGHTNESS,
  ENC_MODE_BACKLIGHT,
  ENC_MODE_CUSTOM0,
  ENC_MODE_CUSTOM1,
  ENC_MODE_CUSTOM2,
  _NUM_ENCODER_MODES
};

enum custom_encoder_behavior {
    ENC_CUSTOM_CW = 0,
    ENC_CUSTOM_CCW,
    ENC_CUSTOM_PRESS
};

// Encoder Behavior
extern uint8_t encoder_value;
extern uint8_t encoder_mode;
extern uint8_t enabled_encoder_modes;

void change_encoder_mode(bool negative);
uint16_t handle_encoder_clockwise(void);
uint16_t handle_encoder_ccw(void);
uint16_t retrieve_custom_encoder_config(uint8_t encoder_idx, uint8_t behavior);
void set_custom_encoder_config(uint8_t encoder_idx, uint8_t behavior, uint16_t new_code);

#endif
