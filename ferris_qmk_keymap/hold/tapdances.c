#include QMK_KEYBOARD_H
#include "tapdances.h"
#include "../features/caps_word.h"
#include "map.h"

/***                Tap Dance Binds             ***/
// double tap for " 
void quot_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code(KC_QUOTE);
    } 
    else {
        register_code16(S(KC_QUOTE));
    }

}

void quot_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code(KC_QUOTE);
    } else {
        unregister_code16(S(KC_QUOTE));
    }
}

/* Home row mods (double tap hold) */
// Create an instance of 'td_tap_t' for the 'x' tap dance.
static td_tap_t l1tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};
void l1_finished(qk_tap_dance_state_t *state, void *user_data) {
    l1tap_state.state = cur_dance(state);
    switch (l1tap_state.state) {
        case TD_TRIPLE_TAP: 
        case TD_TRIPLE_HOLD: 
            tap_code(KC_F); 
        case TD_DOUBLE_TAP: 
        case TD_DOUBLE_SINGLE_TAP:
            tap_code(KC_F); 
        case TD_SINGLE_TAP: 
        case TD_SINGLE_HOLD: 
            register_code(KC_F); break;
        case TD_DOUBLE_HOLD: 
            register_code(KC_LCTL); break;
        default: return;
    }
}
void l1_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (l1tap_state.state) {
        case TD_SINGLE_TAP: 
        case TD_SINGLE_HOLD: 
        case TD_DOUBLE_TAP: 
        case TD_DOUBLE_SINGLE_TAP: 
        case TD_TRIPLE_TAP: 
        case TD_TRIPLE_HOLD:
            unregister_code(KC_F); break;
        case TD_DOUBLE_HOLD: 
            unregister_code(KC_LCTL); break;
        default: break;
    }
    l1tap_state.state = TD_NONE;
    return;
}
/*************************************/
static td_tap_t l2tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};
void l2_finished(qk_tap_dance_state_t *state, void *user_data) {
    l2tap_state.state = cur_dance(state);
    switch (l2tap_state.state) {
        case TD_TRIPLE_TAP: 
        case TD_TRIPLE_HOLD: 
            tap_code(KC_D); 
        case TD_DOUBLE_TAP: 
        case TD_DOUBLE_SINGLE_TAP: 
            tap_code(KC_D);
        case TD_SINGLE_TAP: 
        case TD_SINGLE_HOLD: 
            register_code(KC_D); break;
        case TD_DOUBLE_HOLD: 
            register_code(KC_LSFT); break;
        default: return;
    }
}
void l2_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (l2tap_state.state) {
        case TD_SINGLE_TAP: 
        case TD_SINGLE_HOLD: 
        case TD_DOUBLE_TAP: 
        case TD_DOUBLE_SINGLE_TAP: 
        case TD_TRIPLE_TAP: 
        case TD_TRIPLE_HOLD: 
            unregister_code(KC_D); break;
        case TD_DOUBLE_HOLD: 
            unregister_code(KC_LSFT); break;
        default: break;
    }
    l2tap_state.state = TD_NONE;
    return;
}
/*************************************/
static td_tap_t l3tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};
void l3_finished(qk_tap_dance_state_t *state, void *user_data) {
    l3tap_state.state = cur_dance(state);
    switch (l3tap_state.state) {
        case TD_TRIPLE_TAP: 
        case TD_TRIPLE_HOLD: 
            tap_code(KC_S); 
        case TD_DOUBLE_TAP: 
        case TD_DOUBLE_SINGLE_TAP: 
            tap_code(KC_S); 
        case TD_SINGLE_TAP: 
        case TD_SINGLE_HOLD: 
            register_code(KC_S); break;
        case TD_DOUBLE_HOLD: 
            register_code(KC_LALT); break;
        default: return;
    }
}
void l3_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (l3tap_state.state) {
        case TD_SINGLE_TAP: 
        case TD_SINGLE_HOLD: 
        case TD_DOUBLE_TAP: 
        case TD_TRIPLE_TAP: 
        case TD_TRIPLE_HOLD: 
        case TD_DOUBLE_SINGLE_TAP: 
            unregister_code(KC_S); break;
        case TD_DOUBLE_HOLD: 
            unregister_code(KC_LALT); break;
        default: break;
    }
    l3tap_state.state = TD_NONE;
    return;
}
/*************************************/
static td_tap_t l4tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};
void l4_finished(qk_tap_dance_state_t *state, void *user_data) {
    l4tap_state.state = cur_dance(state);
    switch (l4tap_state.state) {
        case TD_TRIPLE_TAP: 
        case TD_TRIPLE_HOLD: 
            tap_code(KC_A); 
        case TD_DOUBLE_TAP: 
        case TD_DOUBLE_SINGLE_TAP: 
            tap_code(KC_A); 
        case TD_SINGLE_TAP: 
        case TD_SINGLE_HOLD: 
            register_code(KC_A); break;
        case TD_DOUBLE_HOLD: 
            register_code(KC_LGUI); break;
        default: return;
    }
}
void l4_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (l4tap_state.state) {
        case TD_SINGLE_TAP: 
        case TD_SINGLE_HOLD: 
        case TD_DOUBLE_TAP: 
        case TD_TRIPLE_TAP: 
        case TD_TRIPLE_HOLD: 
        case TD_DOUBLE_SINGLE_TAP: 
            unregister_code(KC_A); break;
        case TD_DOUBLE_HOLD: 
            unregister_code(KC_LGUI); break;
        default: break;
    }
    l4tap_state.state = TD_NONE;
    return;
}

/*************************************/
/*************************************/

static td_tap_t r1tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};
void r1_step(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count > 3) {
        if (state->count == 4 ) {
            tap_code(KC_J);
            tap_code(KC_J);
            tap_code(KC_J);
        }
        tap_code(KC_J);
    }
}

void r1_finished(qk_tap_dance_state_t *state, void *user_data) {
    r1tap_state.state = cur_dance(state);
    switch (r1tap_state.state) {
        case TD_TRIPLE_TAP: 
        case TD_TRIPLE_HOLD: 
            tap_code(KC_J); 
        case TD_DOUBLE_TAP: 
        case TD_DOUBLE_SINGLE_TAP: 
            tap_code(KC_J); 
        case TD_SINGLE_TAP: 
        case TD_SINGLE_HOLD: 
            register_code(KC_J); break;
        case TD_DOUBLE_HOLD:    
            register_code(KC_RCTL); break;
        default: return;
    }
}
void r1_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (r1tap_state.state) {
        case TD_SINGLE_TAP: 
        case TD_SINGLE_HOLD: 
        case TD_DOUBLE_TAP: 
        case TD_TRIPLE_TAP: 
        case TD_TRIPLE_HOLD: 
        case TD_DOUBLE_SINGLE_TAP: 
            unregister_code(KC_J); break;
        case TD_DOUBLE_HOLD: 
            unregister_code(KC_RCTL); break;
        default: break;
    }
    r1tap_state.state = TD_NONE;
    return;
}
/*************************************/
static td_tap_t r2tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};
void r2_step(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count > 3) {
        if (state->count == 4 ) {
            tap_code(KC_K);
            tap_code(KC_K);
            tap_code(KC_K);
        }
        tap_code(KC_K);
    }
}
void r2_finished(qk_tap_dance_state_t *state, void *user_data) {
    r2tap_state.state = cur_dance(state);
    switch (r2tap_state.state) {
        case TD_TRIPLE_TAP: 
        case TD_TRIPLE_HOLD: 
            tap_code(KC_K); 
        case TD_DOUBLE_TAP: 
        case TD_DOUBLE_SINGLE_TAP: 
            tap_code(KC_K); 
        case TD_SINGLE_TAP: 
        case TD_SINGLE_HOLD: 
            register_code(KC_K); break;
        case TD_DOUBLE_HOLD: 
            register_code(KC_RSFT); break;
        default: return;
    }
}
void r2_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (r2tap_state.state) {
        case TD_SINGLE_TAP: 
        case TD_SINGLE_HOLD: 
        case TD_DOUBLE_TAP: 
        case TD_TRIPLE_TAP: 
        case TD_TRIPLE_HOLD: 
        case TD_DOUBLE_SINGLE_TAP: 
            unregister_code(KC_K); break;
        case TD_DOUBLE_HOLD: 
            unregister_code(KC_RSFT); break;
        default: break;
    }
    r2tap_state.state = TD_NONE;
    return;
}
/*************************************/
static td_tap_t r3tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};
void r3_step(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count > 3) {
        if (state->count == 4 ) {
            tap_code(KC_L);
            tap_code(KC_L);
            tap_code(KC_L);
        }
        tap_code(KC_L);
    }
}
void r3_finished(qk_tap_dance_state_t *state, void *user_data) {
    r3tap_state.state = cur_dance(state);
    switch (r3tap_state.state) {
        case TD_TRIPLE_TAP: 
        case TD_TRIPLE_HOLD: 
            tap_code(KC_L); 
        case TD_DOUBLE_TAP: 
        case TD_DOUBLE_SINGLE_TAP: 
            tap_code(KC_L); 
        case TD_SINGLE_TAP: 
        case TD_SINGLE_HOLD: 
            register_code(KC_L); break;
        case TD_DOUBLE_HOLD: 
            register_code(KC_RALT); break;
        default: return;
    }
}
void r3_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (r3tap_state.state) {
        case TD_SINGLE_TAP: 
        case TD_SINGLE_HOLD: 
        case TD_DOUBLE_TAP: 
        case TD_TRIPLE_TAP: 
        case TD_TRIPLE_HOLD: 
        case TD_DOUBLE_SINGLE_TAP: 
            unregister_code(KC_L); break;
        case TD_DOUBLE_HOLD: 
            unregister_code(KC_RALT); break;
        default: break;
    }
    r3tap_state.state = TD_NONE;
    return;
}
/*************************************/
static td_tap_t r4tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};
void r4_finished(qk_tap_dance_state_t *state, void *user_data) {
    r4tap_state.state = cur_dance(state);
    switch (r4tap_state.state) {
        case TD_TRIPLE_TAP: 
        case TD_TRIPLE_HOLD: 
            tap_code(KC_SCLN); 
        case TD_DOUBLE_TAP: 
        case TD_DOUBLE_SINGLE_TAP: 
            tap_code(KC_SCLN);
        case TD_SINGLE_TAP: 
        case TD_SINGLE_HOLD: 
            register_code(KC_SCLN); break;
        case TD_DOUBLE_HOLD: 
            register_code(KC_RGUI); break;
        default: return;
    }
}
void r4_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (r4tap_state.state) {
        case TD_SINGLE_TAP: 
        case TD_SINGLE_HOLD: 
        case TD_DOUBLE_TAP: 
        case TD_TRIPLE_TAP: 
        case TD_TRIPLE_HOLD: 
        case TD_DOUBLE_SINGLE_TAP: 
            unregister_code(KC_SCLN); break;
        case TD_DOUBLE_HOLD: 
            unregister_code(KC_RGUI); break;
        default: break;
    }
    r4tap_state.state = TD_NONE;
    return;
}

/*************************************/
/*************************************/

// Double tap shift for caps word
static td_tap_t sfttap_state = {
    .is_press_action = true,
    .state = TD_NONE
};
void sft_finished(qk_tap_dance_state_t *state, void *user_data) {
    sfttap_state.state = cur_dance(state);
    switch (sfttap_state.state) {
        case TD_SINGLE_TAP: 
            set_oneshot_mods(MOD_BIT(KC_LSFT)); 
        case TD_SINGLE_HOLD: 
        case TD_DOUBLE_HOLD:
        case TD_TRIPLE_HOLD:
            register_code(KC_RSFT); break;
        case TD_DOUBLE_TAP: 
        case TD_DOUBLE_SINGLE_TAP:
        case TD_TRIPLE_TAP:
            caps_word_set(true); break;
        default: break;
    }
    return;
}
void sft_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (sfttap_state.state) {
        case TD_SINGLE_TAP:
        case TD_SINGLE_HOLD:
        case TD_DOUBLE_HOLD:
        case TD_TRIPLE_HOLD:
            unregister_code(KC_RSFT); break;
        case TD_DOUBLE_TAP: 
        case TD_DOUBLE_SINGLE_TAP:
        case TD_TRIPLE_TAP:
            break;
        default: break;
    }
    sfttap_state.state = TD_NONE;
    return;
}


// Tap for OSM CTL, hold for layer switch
static td_tap_t ctltap_state = {
    .is_press_action = true,
    .state = TD_NONE
};
void ctl_step(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        layer_on(NUM);
    }
}

void ctl_finished(qk_tap_dance_state_t *state, void *user_data) {
    ctltap_state.state = cur_dance(state);
    switch (ctltap_state.state) {
        case TD_DOUBLE_TAP:
        case TD_DOUBLE_SINGLE_TAP:
            set_oneshot_mods(MOD_BIT(KC_LCTL)); 
        case TD_SINGLE_TAP: 
        case TD_TRIPLE_TAP:
        case TD_SINGLE_HOLD: 
        case TD_DOUBLE_HOLD: 
        case TD_TRIPLE_HOLD:
            layer_on(NUM); break;
        default: return;
    }
}
void ctl_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (ctltap_state.state) {
        case TD_DOUBLE_TAP:
        case TD_DOUBLE_SINGLE_TAP:
        case TD_SINGLE_TAP:
        case TD_TRIPLE_TAP:
        case TD_SINGLE_HOLD:
        case TD_DOUBLE_HOLD:
        case TD_TRIPLE_HOLD:
            layer_off(NUM); break;
        default: break;
    }
    ctltap_state.state = TD_NONE;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_QUOT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, quot_finished, quot_reset),
    [TD_HOME_L1] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, l1_finished, l1_reset),
    [TD_HOME_L2] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, l2_finished, l2_reset),
    [TD_HOME_L3] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, l3_finished, l3_reset),
    [TD_HOME_L4] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, l4_finished, l4_reset),
    [TD_HOME_R1] = ACTION_TAP_DANCE_FN_ADVANCED(r1_step, r1_finished, r1_reset),
    [TD_HOME_R2] = ACTION_TAP_DANCE_FN_ADVANCED(r2_step, r2_finished, r2_reset),
    [TD_HOME_R3] = ACTION_TAP_DANCE_FN_ADVANCED(r3_step, r3_finished, r3_reset),
    [TD_HOME_R4] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, r4_finished, r4_reset),
    [TD_SFT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, sft_finished, sft_reset),
    [TD_CTL] = ACTION_TAP_DANCE_FN_ADVANCED(ctl_step, ctl_finished, ctl_reset),
};

/* Return an integer that corresponds to what kind of tap dance should be executed.
 *
 * How to figure out tap dance state: interrupted and pressed.
 *
 * Interrupted: If the state of a dance is "interrupted", that means that another key has been hit
 *  under the tapping term. This is typically indicitive that you are trying to "tap" the key.
 *
 * Pressed: Whether or not the key is still being pressed. If this value is true, that means the tapping term
 *  has ended, but the key is still being pressed down. This generally means the key is being "held".
 *
 * One thing that is currenlty not possible with qmk software in regards to tap dance is to mimic the "permissive hold"
 *  feature. In general, advanced tap dances do not work well if they are used with commonly typed letters.
 *  For example "A". Tap dances are best used on non-letter keys that are not hit while typing letters.
 *
 * Good places to put an advanced tap dance:
 *  z,q,x,j,k,v,b, any function key, home/end, comma, semi-colon
 *
 * Criteria for "good placement" of a tap dance key:
 *  Not a key that is hit frequently in a sentence
 *  Not a key that is used frequently to double tap, for example 'tab' is often double tapped in a terminal, or
 *    in a web form. So 'tab' would be a poor choice for a tap dance.
 *  Letters used in common words as a double. For example 'p' in 'pepper'. If a tap dance function existed on the
 *    letter 'p', the word 'pepper' would be quite frustating to type.
 *
 * For the third point, there does exist the 'TD_DOUBLE_SINGLE_TAP', however this is not fully tested
 *
 */
td_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    }

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
    else if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
        else return TD_TRIPLE_HOLD;
    } 
    else return TD_UNKNOWN;
}