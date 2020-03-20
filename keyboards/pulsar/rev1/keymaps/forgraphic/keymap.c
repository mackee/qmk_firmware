
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

enum {
  _BASE = 0,
  _LED  = 1
};

enum {
  TD_C_V       = 0,
  TD_ENTER_LED = 1,
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_C_V] = ACTION_TAP_DANCE_DOUBLE(KC_C, KC_V),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT( /* Base */
    KC_LSHIFT, KC_A,    KC_S,     KC_Y, \
    KC_LCTRL,  KC_Z,    KC_X,     TD(TD_C_V), \
                                           KC_LALT, \
    JP_LBRC,   XXXXXXX, LT(_LED, KC_ENTER), XXXXXXX, JP_RBRC \
  ),
  [_LED] = LAYOUT( /* Base */
    _______, RGB_HUI, RGB_TOG, RGB_MODE_REVERSE, \
    _______, RGB_HUD, _______, RGB_MODE_FORWARD, \
                                        _______, \
    RGB_VAD, _______, _______, _______, RGB_VAI  \
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

void oled_task_user(void) {
  oled_write_P(PSTR("Stats\n"), false);

  switch (biton32(layer_state)) {
    case _BASE:
      oled_write_P(PSTR("Layer\n:BASE\n"), false);
      break;
    case _LED:
      oled_write_P(PSTR("Layer\n:LED\n"), false);
      break;
  }
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
      if (get_mods() & MOD_LCTL) {
        rgblight_step();
      } else if (get_mods() & MOD_LSFT) {
        tap_code(KC_END);
      } else {
        tap_code(KC_MS_WH_DOWN);
      }
    } else {
      if (get_mods() & MOD_LCTL) {
        rgblight_step_reverse();
      } else if (get_mods() & MOD_LSFT) {
        tap_code(KC_HOME);
      } else {
        tap_code(KC_MS_WH_UP);
      }
    }
  }
}
