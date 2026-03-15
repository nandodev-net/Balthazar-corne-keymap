/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#define L_DVORAK   0
#define L_NAVIGATE 2
#define L_SYMBOLS  4
#define L_NUMPAD   8
#define L_RGB      16

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // -----------------------------------------------------------------------
  // LAYER 0 - DVORAK
  // Base layer. Home row carries most frequent English letters.
  // Left pinky: plain Shift - no tap/hold ambiguity.
  // Right pinky home: Enter - no stretch needed.
  // Bottom right: - (minus) - ' is already in top row in Dvorak.
  // Left thumb:  GUI | Navigate(hold) | Space/Numpad(hold)
  // Right thumb: Space | Tab/Symbols(hold) | Alt
  // -----------------------------------------------------------------------
    [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC, KC_QUOT, KC_COMM,  KC_DOT,    KC_P,    KC_Y,                         KC_F,    KC_G,    KC_C,    KC_R,    KC_L,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,   KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                         KC_D,    KC_H,    KC_T,    KC_N,    KC_S, KC_ENT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, KC_SCLN,    KC_Q,    KC_J,    KC_K,    KC_X,                         KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,  KC_MINS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(1),  LT(3,KC_SPC),     KC_SPC,   LT(2,KC_TAB), KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  // -----------------------------------------------------------------------
  // LAYER 1 - NAVIGATE
  // Hold left middle thumb (MO1). Right hand: arrows, page, media.
  // Left home row: modifier keys (Shift / Alt / Ctrl) for selections.
  // Bottom left: brightness / volume. Right col: BSP / DEL / END.
  // Right inner thumb activates RGB layer (MO4).
  // -----------------------------------------------------------------------
    [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, XXXXXXX, KC_PGDN, KC_PGUP, KC_PSCR,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX, XXXXXXX, KC_LSFT, KC_LALT, KC_LCTL, XXXXXXX,                      KC_HOME, KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_BRMD, KC_BRMU, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD,                      KC_VOLU, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, KC_END,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT,   MO(4), KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  // -----------------------------------------------------------------------
  // LAYER 2 - SYMBOLS
  // Hold right inner thumb LT(2,TAB). Left hand types symbols.
  // Brackets stacked vertically: () {} [] cols 4-5.
  // Right hand: hash / backslash / slash / pipe / $ / backtick
  // Left thumb MO(3) gives access to Numpad while on this layer.
  // -----------------------------------------------------------------------
    [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_UNDS, KC_EXLM,   KC_AT, KC_LPRN, KC_RPRN, KC_PERC,                      KC_ASTR, KC_AMPR, KC_CIRC,   KC_LT,   KC_GT, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, KC_COLN, KC_LCBR, KC_RCBR,  KC_EQL,                      KC_HASH, KC_BSLS, KC_SLSH, KC_PIPE,  KC_DLR,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, KC_MINS,                      KC_PLUS, KC_QUES, KC_TILD, KC_DQUO, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(3),  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  // -----------------------------------------------------------------------
  // LAYER 3 - NUMPAD + F-KEYS
  // Hold left inner thumb LT(3,SPC) from base, or MO(3) from Symbols.
  // Left hand: F1-F12 across two rows.
  // Right hand: classic numpad layout (7-8-9 / 4-5-6 / 1-2-3).
  // Right thumb: 0 - most used digit at most accessible position.
  // -----------------------------------------------------------------------
    [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                      KC_PLUS,    KC_7,    KC_8,    KC_9, KC_MINS, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,                      KC_ASTR,    KC_4,    KC_5,    KC_6, KC_SLSH, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,    KC_1,    KC_2,    KC_3,  KC_DOT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_0
                                      //`--------------------------'  `--------------------------'
  ),

  // -----------------------------------------------------------------------
  // LAYER 4 - RGB
  // Hold right inner thumb MO(4) while on Navigate (Layer 1).
  // Left home row: toggle / hue / sat / val (up row) / next / down row.
  // QK_BOOT at inner top corners - requires deliberate movement.
  // -----------------------------------------------------------------------
    [4] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,                      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RM_TOGG, RM_HUEU, RM_SATU, RM_VALU, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RM_NEXT, RM_HUED, RM_SATD, RM_VALD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  )
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_180;
    }
    return rotation;
}

static void render_layer(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_DVORAK:   oled_write_P(PSTR("DVORAK\n"),   false); break;
        case L_NAVIGATE: oled_write_P(PSTR("Navigate\n"), false); break;
        case L_SYMBOLS:  oled_write_P(PSTR("Symbols\n"),  false); break;
        case L_NUMPAD:   oled_write_P(PSTR("Numpad\n"),   false); break;
        case L_RGB:      oled_write_P(PSTR("RGB\n"),      false); break;
        default:         oled_write_P(PSTR("???\n"),      false);
    }
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_layer();
        return false;
    }
    return true; // let oled_task_kb render the logo on the slave
}
#endif

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [4] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },

};
#endif
