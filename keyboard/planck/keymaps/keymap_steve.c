// // This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// // this is the style you want to emulate.

// Notes:

/*
  1. make clean
  2. reset
  3. make KEYMAP=steve dfu *make sure keymap is in keymap folder and put only name
*/
#include "planck.h"
#include "backlight.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QW 0
#define _CM 1
#define _DV 2
#define _LW 3
#define _RS 4
#define _MS 5
#define _AR 6
#define _LOL 7

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QW] = { /* Qwerty */
  {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_ESC},
  {KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT},
  {M(0),    KC_LCTL, KC_LALT, MO(_LW), KC_LGUI, KC_SPC,  KC_SPC,  MO(_RS), MO(_LW), KC_DOWN, KC_UP,   KC_RGHT}
},
[_CM] = { /* Colemak */
  {KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_ESC},
  {KC_BSPC, KC_A,    KC_R,    F(10),   KC_T,    KC_D,    KC_H,    KC_N,    F(11),   KC_I,    KC_O,    KC_ENT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT},
  {M(0),    KC_LCTL, KC_LALT, MO(_LW), KC_LGUI, KC_SPC,  KC_SPC,  MO(_RS), KC_VOLD, KC_VOLU, KC_TRNS, KC_MPLY}
},
[_RS] = { /* RAISE */
  {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC},
  {KC_ESC,  KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_QUOT, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS},
  {KC_TRNS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  DF(_QW), DF(_CM), DF(_DV), KC_TRNS, KC_TRNS},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN1, KC_TRNS, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY}
},
[_LW] = { /* LOWER */
  {KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC},
  {KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE},
  {KC_TRNS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  DF(_QW), DF(_CM), DF(_DV), RESET,   KC_TRNS},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY}
},
[_MS] = { /* MOUSE */
  {KC_TILD, KC_EXLM, KC_WH_D, KC_TRNS, KC_WH_U, KC_PERC, KC_CIRC, KC_PGUP, KC_UP,   KC_PGDN, KC_RPRN, KC_BSPC},
  {KC_ESC,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_WBAK, KC_LEFT, KC_DOWN, KC_RGHT, KC_WFWD, KC_PIPE},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN1, KC_TRNS, KC_MNXT, KC_VOLD, KC_VOLU, RESET}
},
[_AR] = { /* ARROWS */
  {KC_TILD, KC_EXLM, KC_WH_D, KC_MS_U, KC_WH_U, KC_PERC, KC_CIRC, KC_PGUP, KC_UP,   KC_PGDN, KC_RPRN, KC_BSPC},
  {KC_ESC,  KC_WH_L, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_R, KC_TRNS, KC_BTN1, KC_TRNS, KC_BTN2, KC_TRNS, KC_TRNS},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN1, KC_TRNS, KC_MNXT, KC_VOLD, KC_VOLU, RESET}
}
};

const uint16_t PROGMEM fn_actions[] = {

  // [0] = ACTION_LAYER_TOGGLE(7),                   // League layer
  // [1] = ACTION_LAYER_TOGGLE(1),                   // Mac layer
  // [2] = 
  // [3] = 
  // [4] = 

  // [5] = ACTION_MODS_TAP_KEY(MOD_LGUI, KC_SPC),    // Linux: SUPER | SPACE
  // [6] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_SPC),    // Mac: COMMAND | SPACE
  // [7] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_BSPC),   // League: COMMAND | SPACE
  // [8] = ACTION_MODS_TAP_KEY(),
  // [9] = ACTION_MODS_TAP_KEY(),

  [10] = ACTION_LAYER_TAP_KEY(5, KC_S),           // Mouse Layer | Colemak: S    
  [11] = ACTION_LAYER_TAP_KEY(6, KC_E)           // Arrow Layer | Colemak: E
  // [12] = ACTION_LAYER_TAP_KEY(5, KC_BSPC),            // Backspace | Layer 5
  // [13] = ACTION_LAYER_TAP_KEY(5, KC_TAB)            // Backspace | Layer 5
  // [13] = ACTION_LAYER_TAP_KEY(),

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            backlight_step();
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};
