/* Copyright 2020 mackee_w
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
#include "rev2.h"
#include "debug.h"
#include "print.h"
#include "tmk_core/common/eeprom.h"

#include "raw_hid.h"
#include "dynamic_keymap.h"
#include "tmk_core/common/eeprom.h"
#include "version.h"

// Optional override functions below.
// You can leave any or all of these undefined.
// These are only required if you want to perform custom actions.
//


void matrix_init_kb(void) {
  // put your keyboard start-up code here
  // runs once when the firmware starts up

  matrix_init_user();
}

void matrix_scan_kb(void) {
  // put your looping keyboard code here
  // runs every cycle (a lot)

  matrix_scan_user();
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
  // put your per-action keyboard code here
  // runs for every action, just before processing by the firmware

  return process_record_user(keycode, record);
}

void led_set_kb(uint8_t usb_led) {
  // put your keyboard LED indicator (ex: Caps Lock LED) toggling code here

  led_set_user(usb_led);
}

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  //debug_enable=true;
  //debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}

#ifdef VIA_ENABLE

uint8_t encoder_value = 32;
uint8_t encoder_mode = ENC_MODE_SCROLL;
uint8_t enabled_encoder_modes = 0xFF;

void raw_hid_receive_kb(int8_t *data, uint8_t length) {
    uint8_t *command_id = (uint8_t *)&(data[0]);
    uint8_t *command_data = (uint8_t *)&(data[1]);
    uprintf("command_id=%u\n", *command_id);
    switch (*command_id) {
        case id_get_keyboard_value:
            switch (command_data[0]) {
                case id_encoder_modes:
                    {
                        command_data[1] = enabled_encoder_modes;
                        break;
                    }
                case id_encoder_custom:
                    {
                        uint8_t custom_encoder_idx = command_data[1];
                        uint16_t keycode = retrieve_custom_encoder_config(custom_encoder_idx, ENC_CUSTOM_CW);
                        command_data[2] =  keycode >> 8;
                        command_data[3] = keycode & 0xFF;
                        keycode = retrieve_custom_encoder_config(custom_encoder_idx, ENC_CUSTOM_CCW);
                        command_data[4] =  keycode >> 8;
                        command_data[5] = keycode & 0xFF;
                        keycode = retrieve_custom_encoder_config(custom_encoder_idx, ENC_CUSTOM_PRESS);
                        command_data[6] =  keycode >> 8;
                        command_data[7] = keycode & 0xFF;
                        break;
                    }
                default:
                    {
                        *command_id = id_unhandled;
                        break;
                    }
            }
            break;
        case id_set_keyboard_value:
            switch (command_data[0]) {
                case id_encoder_modes:
                    {
                        enabled_encoder_modes = command_data[1];
                        eeprom_update_byte((uint8_t*)EEPROM_ENABLED_ENCODER_MODES, enabled_encoder_modes);
                        break;
                    }
                case id_encoder_custom:
                    {
                        uint8_t custom_encoder_idx = command_data[1];
                        uint8_t encoder_behavior = command_data[2];
                        uint16_t keycode = (command_data[3] << 8) | command_data[4];
                        set_custom_encoder_config(custom_encoder_idx, encoder_behavior, keycode);
                        break;
                    }
                default:
                    {
                        *command_id = id_unhandled;
                        break;
                    }
            }
            break;
        default:
            {
                *command_id = id_unhandled;
                break;
            }
    }
}

void change_encoder_mode(bool negative){
    if(enabled_encoder_modes == 0){
        enabled_encoder_modes = 0x7F;
    }
    do {
      if(negative){
          if (encoder_mode == 0){
              encoder_mode = _NUM_ENCODER_MODES - 1;
          } else{
              encoder_mode = encoder_mode - 1;
          }
      } else {
          encoder_mode = (encoder_mode + 1) % _NUM_ENCODER_MODES;
      }
    } while(((1 << encoder_mode) & enabled_encoder_modes) == 0);
}

uint16_t handle_encoder_clockwise(){
    uint16_t mapped_code = 0;
    switch(encoder_mode){
        default:
        case ENC_MODE_VOLUME:
            mapped_code = KC_VOLU;
            break;
        case ENC_MODE_MEDIA:
            mapped_code = KC_MEDIA_NEXT_TRACK;
            break;
        case ENC_MODE_SCROLL:
            mapped_code = KC_WH_D;
            break;
        case ENC_MODE_BRIGHTNESS:
            mapped_code = KC_BRIGHTNESS_UP;
            break;
        case ENC_MODE_CUSTOM0:
            mapped_code = retrieve_custom_encoder_config(0, ENC_CUSTOM_CW);
            break;
        case ENC_MODE_CUSTOM1:
            mapped_code = retrieve_custom_encoder_config(1, ENC_CUSTOM_CW);
            break;
        case ENC_MODE_CUSTOM2:
            mapped_code = retrieve_custom_encoder_config(2, ENC_CUSTOM_CW);
            break;
    }
    return mapped_code;
}

uint16_t handle_encoder_ccw(){
    uint16_t mapped_code = 0;
    switch(encoder_mode){
        default:
        case ENC_MODE_VOLUME:
            mapped_code = KC_VOLD;
            break;
        case ENC_MODE_MEDIA:
            mapped_code = KC_MEDIA_PREV_TRACK;
            break;
        case ENC_MODE_SCROLL:
            mapped_code = KC_WH_U;
            break;
        case ENC_MODE_BRIGHTNESS:
            mapped_code = KC_BRIGHTNESS_DOWN;
            break;
        case ENC_MODE_CUSTOM0:
            mapped_code = retrieve_custom_encoder_config(0, ENC_CUSTOM_CCW);
            break;
        case ENC_MODE_CUSTOM1:
            mapped_code = retrieve_custom_encoder_config(1, ENC_CUSTOM_CCW);
            break;
        case ENC_MODE_CUSTOM2:
            mapped_code = retrieve_custom_encoder_config(2, ENC_CUSTOM_CCW);
            break;
    }
    return mapped_code;
}

uint16_t retrieve_custom_encoder_config(uint8_t encoder_idx, uint8_t behavior){
    void* addr = (void*)(EEPROM_CUSTOM_ENCODER + (encoder_idx * 6) + (behavior * 2));
    //big endian
    uint16_t keycode = eeprom_read_byte(addr) << 8;
    keycode |= eeprom_read_byte(addr + 1);
    return keycode;
    return 0;
}

void set_custom_encoder_config(uint8_t encoder_idx, uint8_t behavior, uint16_t new_code){
    void* addr = (void*)(EEPROM_CUSTOM_ENCODER + (encoder_idx * 6) + (behavior * 2));
    eeprom_update_byte(addr, (uint8_t)(new_code >> 8));
    eeprom_update_byte(addr + 1, (uint8_t)(new_code & 0xFF));
}

uint8_t layer;

uint32_t layer_state_set_kb(uint32_t state) {
  state = layer_state_set_user(state);
  layer = biton32(state);
  return state;
}

/* Artificial delay added to get media keys to work in the encoder*/
#define MEDIA_KEY_DELAY 10

void encoder_update_kb(uint8_t index, bool clockwise) {
    encoder_value = (encoder_value + (clockwise ? 1 : -1)) % 64;
    uprintf("index=%u, clockwise=%b, layer=%u, encoder_mode=%u\n", index, clockwise, layer, encoder_mode);
    if (index == 0) {
        if (layer == 0){
            uint16_t mapped_code = 0;
            if (clockwise) {
                mapped_code = handle_encoder_clockwise();
            } else {
                mapped_code = handle_encoder_ccw();
            }
            uprintf("mapcode=%s\n", mapped_code);
            uint16_t held_keycode_timer = timer_read();
            if(mapped_code != 0){
                register_code16(mapped_code);
                while (timer_elapsed(held_keycode_timer) < MEDIA_KEY_DELAY){ /* no-op */ }
                unregister_code16(mapped_code);
            }
        } else {
            if(clockwise){
                change_encoder_mode(false);
            } else {
                change_encoder_mode(true);
            }
        }
    }
}

#endif
