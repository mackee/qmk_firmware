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

// Defines the keycodes used by our macros in process_record_user
//enum custom_keycodes {
//};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT( /* Base */
    KC_W,          KC_E, KC_R, KC_I, \
    SFT_T(KC_ESC), KC_D, KC_F, KC_M, \
                      KC_LGUI, \
    RGB_MODE_FORWARD, KC_NO, RGB_TOG, KC_NO, RGB_MODE_REVERSE \
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
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
      if (get_mods() & MOD_LGUI) {
          rgblight_increase_hue();
      } else {
          SEND_STRING(SS_LGUI("+"));
      }
    } else {
      if (get_mods() & MOD_LGUI) {
          rgblight_decrease_hue();
      } else {
        SEND_STRING(SS_LGUI("-"));
      }
    }
  }
}

