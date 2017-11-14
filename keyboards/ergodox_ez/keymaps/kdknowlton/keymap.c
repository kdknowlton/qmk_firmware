#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"


#include "keymap_german.h"

#include "keymap_nordic.h"

#define _____ KC_TRNS
#define __T__ KC_TRNS  // Marker for layer change keys that should stay transparent
#define XXXXX KC_NO

#define LAUNCHER LALT(LCTL(LGUI(LSFT(KC_L))))


enum layers {
    _QWERTY,
    _MIRROR,
    _FUNC,
};

enum custom_keycodes {
    PLACEHOLDER = SAFE_RANGE, // can always be here
    VRSN,

};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = KEYMAP(
        ALL_T(KC_GRAVE),    KC_1,               KC_2,   KC_3,       KC_4,               KC_5,   TG(_MIRROR),
        KC_MINUS,           KC_Q,               KC_W,   KC_E,       KC_R,               KC_T,   KC_DELETE,
        CTL_T(KC_ESCAPE),   LT(_MIRROR,KC_A),   KC_S,   KC_D,       LT(_MIRROR,KC_F),   KC_G,
        KC_LSHIFT,          KC_Z,               KC_X,   KC_C,       KC_V,               KC_B,   OSL(_MIRROR),
        _____,              _____,              KC_LALT,TG(_FUNC),  GUI_T(KC_LBRACKET),
                                                    LCTL(KC_LEFT),  LCTL(KC_RIGHT),
                                                                    _____,
                            LT(_MIRROR,KC_ENTER),   KC_BSPACE,      _____,

        TG(_FUNC),      KC_6,   KC_7,               KC_8,       KC_9,   KC_0,                   ALL_T(KC_BSLASH),
        KC_MINUS,       KC_Y,   KC_U,               KC_I,       KC_O,   KC_P,                   KC_EQUAL,
                        KC_H,   LT(_MIRROR,KC_J),   KC_K,       KC_L,   LT(_MIRROR,KC_SCOLON),  RCTL_T(KC_QUOTE),
        OSL(_MIRROR),   KC_N,   KC_M,               KC_COMMA,   KC_DOT, KC_SLASH,               KC_RSHIFT,
                                GUI_T(KC_RBRACKET), TG(_FUNC),  KC_RALT,_____,                  _____,
        LCTL(KC_LEFT),  LCTL(KC_RIGHT),
        _____,
        _____,          KC_TAB,         LT(_MIRROR,KC_SPACE)
    ),

    [_MIRROR] = KEYMAP(
        ALL_T(KC_BSLASH),   KC_0,                   KC_9,   KC_8,       KC_7,               KC_6,   __T__,
        KC_EQUAL,           KC_P,                   KC_O,   KC_I,       KC_U,               KC_Y,   KC_MINUS,
        RCTL_T(KC_QUOTE),   LT(_MIRROR,KC_SCOLON),  KC_L,   KC_K,       LT(_MIRROR,KC_J),   KC_H,
        KC_RSHIFT,          KC_SLASH,               KC_DOT, KC_COMMA,   KC_M,               KC_N,   __T__,
        _____,              _____,                  KC_RALT,_____,      GUI_T(KC_RBRACKET),
                                                                    _____,  _____,
                                                                            _____,
                                            LT(_MIRROR,KC_SPACE),   KC_TAB, _____,

        TG(_FUNC),  KC_5,   KC_4,               KC_3,   KC_2,   KC_1,               ALL_T(KC_GRAVE),
        KC_DELETE,  KC_T,   KC_R,               KC_E,   KC_W,   KC_Q,               KC_MINUS,
                    KC_G,   LT(_MIRROR,KC_F),   KC_D,   KC_S,   LT(_MIRROR,KC_A),   CTL_T(KC_ESCAPE),
        __T__,      KC_B,   KC_V,               KC_C,   KC_X,   KC_Z,               KC_LSHIFT,
                            GUI_T(KC_LBRACKET), _____,  KC_LALT,_____,              _____,
        _____,  _____,
        _____,
        _____,  KC_BSPACE,  LT(_MIRROR,KC_ENTER)
    ),

    [_FUNC] = KEYMAP(
        _____,  KC_F1,          KC_F2,              KC_F3,          KC_F4,                  KC_F5,          _____,
        VRSN,   _____,          LAUNCHER,           KC_UP,          LCTL(LGUI(LSFT(KC_4))), LCTL(KC_UP),    _____,
        _____,  KC_MS_WH_RIGHT, KC_LEFT,            KC_DOWN,        KC_RIGHT,               KC_MS_WH_LEFT,
        _____,  _____,          KC_AUDIO_VOL_DOWN,  KC_AUDIO_MUTE,  KC_AUDIO_VOL_UP,        LCTL(KC_DOWN),  _____,
        _____,  _____,          _____,              __T__,          _____,
                                                                _____,  RESET,
                                                                        _____,
                                                        _____,  _____,  _____,

        __T__,  KC_F6,          KC_F7,              KC_F8,          KC_F9,                  KC_F10,         KC_F11,
        _____,  LCTL(KC_UP),    LAUNCHER,           KC_UP,          LCTL(LGUI(LSFT(KC_4))), KC_F11,         KC_F12,
                KC_MS_WH_RIGHT, KC_LEFT,            KC_DOWN,        KC_RIGHT,               KC_MS_WH_LEFT,  _____,
        _____,  LCTL(KC_DOWN),  KC_AUDIO_VOL_DOWN,  KC_AUDIO_MUTE,  KC_AUDIO_VOL_UP,        KC_F12,         _____,
                                _____,              __T__,          _____,                  _____,          _____,
        _____,  _____,
        _____,
        _____,  _____,  _____
    ),

};

void matrix_init_user(void) {
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // dynamically generate these.
        case VRSN:
            if (record->event.pressed) {
                SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            }
            return false;
            break;
    }
    return true;
}

void matrix_scan_user(void) {
};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    uint8_t layer = biton32(state);
    switch (layer) {
        case 0:
            break;
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        case 3:
            ergodox_right_led_3_on();
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        default:
            break;
    }
    return state;
};
