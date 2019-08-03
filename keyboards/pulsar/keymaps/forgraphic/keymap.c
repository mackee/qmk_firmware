
/* Copyright 2019 mackee
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
#include QMK_KEYBOARD_H

#include "keymap_jp.h"

// Defines the keycodes used by our macros in process_record_user
//enum custom_keycodes {
//};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT( /* Base */
    KC_LSHIFT, KC_A, KC_S, KC_Y, \
    KC_LCTRL,  KC_Z, KC_X, KC_C, \
                           KC_LALT, \
    JP_LBRC, KC_NO, RGB_TOG, KC_NO, JP_RBRC \
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_C:
      if (record->event.pressed && get_mods() & MOD_LALT) {
        unregister_code(KC_LALT);
        tap_code(KC_V);
        register_code(KC_LALT);
        return false;
      }
  }
  return true;
}

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

void led_set_user(uint8_t usb_led) {
}

void encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) {
    if (clockwise) {
      if (get_mods() & MOD_LALT) {
        rgblight_increase_hue();
      } else if (get_mods() & MOD_LCTL) {
        rgblight_step();
      } else if (get_mods() & MOD_LSFT) {
        SEND_STRING(SS_TAP(X_END));
      } else {
        SEND_STRING(SS_LCTRL(";"));
      }
    } else {
      if (get_mods() & MOD_LALT) {
        rgblight_decrease_hue();
      } else if (get_mods() & MOD_LCTL) {
        rgblight_step_reverse();
      } else if (get_mods() & MOD_LSFT) {
        SEND_STRING(SS_TAP(X_HOME));
      } else {
        SEND_STRING(SS_LCTRL("-"));
      }
    }
  }
}
