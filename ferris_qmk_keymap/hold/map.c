#include QMK_KEYBOARD_H
#include "map.h"
#include "features/caps_word.h"

layer_state_t layer_state_set_user(layer_state_t state)                     {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  process_caps_word(keycode, record);
  return true;
}

bool caps_word_press_user(uint16_t keycode) {
  switch (keycode) {
    // Keycodes that continue Caps Word, with shift applied.
    case KC_A ... KC_Z:
    case KC_MINS:
    case TD(TD_HOME_L1):
    case TD(TD_HOME_L2):
    case TD(TD_HOME_L3):
    case TD(TD_HOME_L4):
    case TD(TD_HOME_R1):
    case TD(TD_HOME_R2):
    case TD(TD_HOME_R3):
      add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to the next key.
      return true;

    // Keycodes that continue Caps Word, without shifting.
    case KC_1 ... KC_0:
    case KC_BSPC:
    case KC_DEL:
    case KC_UNDS:
    case KC_RSFT:
      return true;

    default:
      return false;  // Deactivate Caps Word.
  }
}


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        default:
            return TAPPING_TERM;
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [ALPHA] = LAYOUT_ferris_wrapper(
        __________ALPHA_L1____________, __________ALPHA_R1____________,
        __________ALPHA_L2____________, __________ALPHA_R2____________,
        __________ALPHA_L3____________, __________ALPHA_R3____________,
        _THUMB_L, _THUMB_R
    ),
    [SYM] = LAYOUT_ferris_wrapper(
        ___________SYM_L1_____________, ___________SYM_R1_____________,
        ___________SYM_L2_____________, ___________SYM_R2_____________,
        ___________SYM_L3_____________, ___________SYM_R3_____________,
        _THUMB_L, _THUMB_R
    ),
    [NUM] = LAYOUT_ferris_wrapper(
        ___________NAV_L1_____________, ___________NAV_R1_____________,
        ___________NAV_L2_____________, ___________NAV_R2_____________,
        ___________NAV_L3_____________, ___________NAV_R3_____________,
        _THUMB_L, _THUMB_R
    ),
    [ADJ] = LAYOUT_ferris_wrapper(
        ___________ADJ_L1_____________, ___________ADJ_R1_____________,
        ___________ADJ_L2_____________, ___________ADJ_R2_____________,
        ___________ADJ_L3_____________, ___________ADJ_R3_____________,
        _THUMB_L, _THUMB_R 
    )
};