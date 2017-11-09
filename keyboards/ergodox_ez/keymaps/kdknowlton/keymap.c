#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"


#include "keymap_german.h"

#include "keymap_nordic.h"


enum layers {
    _QWERTY,
    _MIRROR,
    _FUNCTION,
    _EXTRA,
}

enum custom_keycodes {
    PLACEHOLDER = SAFE_RANGE, // can always be here
    VRSN,

};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = KEYMAP(
        ALL_T(KC_GRAVE),    KC_1,       KC_2,       KC_3,           KC_4,   KC_5,   TG(_MIRROR),
        ALT_T(KC_TAB),      KC_Q,       KC_W,       KC_E,           KC_R,   KC_T,   LT(_FUNCTION,KC_DELETE),
        CTL_T(KC_ESCAPE),   KC_A,       KC_S,       KC_D,           KC_F,   KC_G,
        KC_LSHIFT,          KC_Z,       KC_X,       KC_C,           KC_V,   KC_B,   KC_LBRACKET,
        KC_TRNS,            KC_TRNS,    KC_TRNS,    OSL(_FUNCTION), KC_LGUI,
                                                                KC_PGUP,    KC_PGDOWN,
                                                                            KC_APPLICATION,
                                                    KC_ENTER,   KC_BSPACE,  LT(_MIRROR,KC_SPACE),

        TG(_FUNCTION),  KC_6,   KC_7,       KC_8,           KC_9,       KC_0,       ALL_T(KC_BSLASH),
        KC_MINUS,       KC_Y,   KC_U,       KC_I,           KC_O,       KC_P,       ALGR_T(KC_EQUAL),
                        KC_H,   KC_J,       KC_K,           KC_L,       KC_SCOLON,  RCTL_T(KC_QUOTE),
        KC_RBRACKET,    KC_N,   KC_M,       KC_COMMA,       KC_DOT,     KC_SLASH,   KC_RSHIFT,
                                KC_RGUI,    OSL(_FUNCTION), KC_TRNS,    KC_TRNS,    KC_TRNS,
                KC_HOME,KC_END,
                        OSL(_EXTRA),
        KC_TAB, KC_TRNS,KC_SPACE
    ),

    [_MIRROR] = KEYMAP(
        ALL_T(KC_BSLASH),   KC_0,       KC_9,       KC_8,       KC_7,   KC_6,   KC_TRNS,
        ALGR_T(KC_EQUAL),   KC_P,       KC_O,       KC_I,       KC_U,   KC_Y,   KC_MINUS,
        RCTL_T(KC_QUOTE),   KC_SCOLON,  KC_L,       KC_K,       KC_J,   KC_H,
        KC_RSHIFT,          KC_SLASH,   KC_DOT,     KC_COMMA,   KC_M,   KC_N,   KC_RBRACKET,
        KC_TRNS,            KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_RGUI,
                                                                KC_TRNS,    KC_TRNS,
                                                                            KC_TRNS,
                                                    KC_SPACE,   KC_TRNS,    KC_TRNS,

        TG(_FUNCTION),              KC_5,       KC_4,       KC_3,       KC_2,       KC_1,       ALL_T(KC_GRAVE),
        LT(_FUNCTION,KC_DELETE),    KC_T,       KC_R,       KC_E,       KC_W,       KC_Q,       ALT_T(KC_TAB),
                                    KC_G,       KC_F,       KC_D,       KC_S,       KC_A,       CTL_T(KC_ESCAPE),
        KC_LBRACKET,                KC_B,       KC_V,       KC_C,       KC_X,       KC_Z,       KC_LSHIFT,
                                    KC_LGUI,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                    KC_TRNS,    KC_TRNS,
                                KC_TRNS,
        KC_TRNS,    KC_BSPACE,  KC_ENTER
    ),

    [_FUNCTION] = KEYMAP(
        KC_TRNS,KC_F1,          KC_F2,                          KC_F3,          KC_F4,                  KC_F5,          KC_TRNS,
        VRSN,   KC_TRNS,        LALT(LCTL(LGUI(LSFT(KC_L)))),   KC_UP,          LCTL(LGUI(LSFT(KC_4))), LCTL(KC_UP),    KC_TRNS,
        KC_TRNS,LCTL(KC_LEFT),  KC_LEFT,                        KC_DOWN,        KC_RIGHT,               LCTL(KC_RIGHT),
        KC_TRNS,KC_TRNS,        KC_AUDIO_VOL_DOWN,              KC_AUDIO_MUTE,  KC_AUDIO_VOL_UP,        LCTL(KC_DOWN),  KC_TRNS,
        KC_TRNS,KC_TRNS,        KC_TRNS,                        KC_TRNS,        KC_TRNS,
                                                                                        KC_TRNS,    KC_TRNS,
                                                                                                    KC_TRNS,
                                                                            KC_TRNS,    KC_TRNS,    KC_TRNS,

        KC_TRNS,KC_F6,          KC_F7,                          KC_F8,          KC_F9,                  KC_F10,         KC_F11,
        KC_TRNS,LCTL(KC_UP),    LALT(LCTL(LGUI(LSFT(KC_L)))),   KC_UP,          LCTL(LGUI(LSFT(KC_4))), KC_F11,         KC_F12,
                LCTL(KC_LEFT),  KC_LEFT,                        KC_DOWN,        KC_RIGHT,               LCTL(KC_RIGHT), KC_TRNS,
        KC_TRNS,LCTL(KC_DOWN),  KC_AUDIO_VOL_DOWN,              KC_AUDIO_MUTE,  KC_AUDIO_VOL_UP,        KC_F12,         KC_TRNS,
                                KC_TRNS,                        KC_TRNS,        KC_TRNS,                KC_TRNS,        KC_TRNS,
                    KC_TRNS,    KC_TRNS,
                                KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS
    ),

    [_EXTRA] = KEYMAP(
        RESET,  KC_TRNS,KC_TRNS,        KC_TRNS,    KC_TRNS,        KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,KC_MS_BTN1,     KC_MS_UP,   KC_MS_BTN2,     KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,KC_MS_LEFT,     KC_MS_DOWN, KC_MS_RIGHT,    KC_TRNS,
        KC_TRNS,KC_TRNS,KC_MS_WH_LEFT,  KC_MS_BTN3, KC_MS_WH_RIGHT, KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,        KC_TRNS,    KC_TRNS,
                                        KC_TRNS,    KC_TRNS,
                                                    KC_TRNS,
                            KC_TRNS,    KC_TRNS,    KC_TRNS,

        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                KC_TRNS,KC_TRNS,
                        KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS
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
    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
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
};
