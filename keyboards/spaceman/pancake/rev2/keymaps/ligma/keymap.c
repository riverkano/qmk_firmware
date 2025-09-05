/* Copyright Spaceman 2021
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

enum layers {
    _ABC,
    _123,
    _SYM,
    _WIN,
    _W123,
    _WSYM
};

enum my_keycodes {
    SIN = SAFE_RANGE,
    COS,
    TAN,
    ARC,
    HYPER,
};

#define HYPER MT(MOD_LGUI | MOD_LCTL | MOD_LALT, KC_F18)
#define EMOJI LWIN(KC_DOT)

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SIN:
            if (record->event.pressed) {
                SEND_STRING("sin");
            }
            break;

        case COS:
            if (record->event.pressed) {
                SEND_STRING("cos");
            }
            break;

        case TAN:
            if (record->event.pressed) {
                SEND_STRING("tan");
            }
            break;

        case ARC:
            if (record->event.pressed) {
                SEND_STRING("arc");
            }
            break;
    }
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_ABC] = LAYOUT_ortho_4x12(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT, KC_ENT,
        TT(1),   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_QUES, KC_SCLN, KC_UP,   TT(2),
        HYPER,   KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, KC_BSPC, KC_SPC,  KC_COMM, KC_DOT,  KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_123] = LAYOUT_ortho_4x12(
        TG(3),   _______, _______, ARC,     SIN,     KC_CIRC, KC_P7,   KC_P8,   KC_P9,   KC_PAST, KC_PSLS, KC_DEL,
        _______, _______, _______, _______, COS,     _______, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_PMNS, _______,
        _______, _______, _______, KC_Y,    TAN,     _______, KC_P1,   KC_P2,   KC_P3,   KC_PEQL, _______, _______,
        _______, _______, _______, _______, _______, _______, KC_P0,   _______, KC_PDOT, _______, _______, _______
    ),

    [_SYM] = LAYOUT_ortho_4x12(
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC,  KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
        _______, _______, _______, _______, _______, _______, _______,  _______, _______, KC_LBRC, KC_RBRC, KC_NUHS,
        _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, KC_VOLU, _______,
        TG(3),   _______, _______, _______, _______, _______, KC_MINUS, _______, _______, KC_BRID, KC_VOLD, KC_BRIU
    ),

    [_WIN] = LAYOUT_ortho_4x12(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT, KC_ENT,
        TT(4),   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_QUES, KC_SCLN, KC_UP,   TT(5),
        EMOJI,   KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_BSPC, KC_SPC,  KC_COMM, KC_DOT,  KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_W123] = LAYOUT_ortho_4x12(
        _______, _______, _______, ARC,     SIN,     KC_CIRC, KC_7,    KC_8,   KC_9,   KC_PAST, KC_PSLS, _______,
        _______, _______, _______, _______, COS,     _______, KC_4,    KC_5,   KC_6,   KC_PPLS, KC_PMNS, _______,
        _______, _______, _______, KC_Y,    TAN,     _______, KC_1,    KC_2,   KC_3,   KC_EQL,  _______, _______,
        _______, _______, _______, _______, _______, _______, KC_0,    _______, KC_DOT, _______, _______, _______
    ),

    [_WSYM] = LAYOUT_ortho_4x12(
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC,  KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
        _______, _______, _______, _______, _______, _______, _______,  _______, _______, KC_LBRC, KC_RBRC, KC_NUHS,
        _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, KC_VOLU, _______,
        _______, _______, _______, _______, _______, _______, KC_MINUS, _______, _______, KC_BRID, KC_VOLD, KC_BRIU
    ),

}; // This correctly closes the keymaps array

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    // Clear the screen's buffer
    oled_clear();

    // Your custom layer name logic
    switch (get_highest_layer(layer_state)) {
        case _ABC:
            oled_write_P(PSTR("Mac  ABC\n"), false);
            break;
        case _123:
            oled_write_P(PSTR("Mac  123\n"), false);
            break;
        case _SYM:
            oled_write_P(PSTR("Mac  !@#\n"), false);
            break;
        case _WIN:
            oled_write_P(PSTR("Win  ABC\n"), false);
            break;
        case _W123:
            oled_write_P(PSTR("Win  123\n"), false);
            break;
        case _WSYM:
            oled_write_P(PSTR("Win  !@#\n"), false);
            break;
        default:
            oled_write_P(PSTR("?\n"), false);
            break;
    }

    // This is the key: returning false triggers the early exit in rev2.c
    return false;
}
#endif // OLED_ENABLE