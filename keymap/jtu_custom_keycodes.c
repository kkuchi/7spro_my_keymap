#include QMK_KEYBOARD_H
#include "jtu_custom_keycodes.h"

bool process_record_user_jtu(uint16_t keycode, keyrecord_t *record) {
  static bool lshift = false;
  static bool rshift = false;

  switch (keycode) {
    // 2, @
    case JU_2:
      if (record->event.pressed) {
        // shift check
        lshift = keyboard_report->mods & MOD_BIT(KC_LSFT);
        rshift = keyboard_report->mods & MOD_BIT(KC_RSFT);
        // shift pressed
        if (lshift || rshift) {
          // shift release
          if (lshift) unregister_code(KC_LSFT);
          if (rshift) unregister_code(KC_RSFT);
          // send @ (US: [)
          register_code(KC_LBRC);
          unregister_code(KC_LBRC);
          // shift press
          if (lshift) register_code(KC_LSFT);
          if (rshift) register_code(KC_RSFT);
        } else {
          // send 2
          register_code(KC_2);
          unregister_code(KC_2);
        }
      }
      return false;
    // 6, ^
    case JU_6:
      if (record->event.pressed) {
        // shift check
        lshift = keyboard_report->mods & MOD_BIT(KC_LSFT);
        rshift = keyboard_report->mods & MOD_BIT(KC_RSFT);
        // shift pressed
        if (lshift || rshift) {
          // shift release
          if (lshift) unregister_code(KC_LSFT);
          if (rshift) unregister_code(KC_RSFT);
          // send ^ (US: =)
          register_code(KC_EQL);
          unregister_code(KC_EQL);
          // shift press
          if (lshift) register_code(KC_LSFT);
          if (rshift) register_code(KC_RSFT);
        } else {
          // send 6
          register_code(KC_6);
          unregister_code(KC_6);
        }
      }
      return false;
    // 7, &
    case JU_7:
      if (record->event.pressed) {
        lshift = keyboard_report->mods & MOD_BIT(KC_LSFT);
        rshift = keyboard_report->mods & MOD_BIT(KC_RSFT);
        if (lshift || rshift) {
          if (lshift) unregister_code(KC_LSFT);
          if (rshift) unregister_code(KC_RSFT);
          // send & (shift+6)
          register_code(KC_LSFT);
          register_code(KC_6);
          unregister_code(KC_6);
          unregister_code(KC_LSFT);
          if (lshift) register_code(KC_LSFT);
          if (rshift) register_code(KC_RSFT);
        } else {
          register_code(KC_7);
          unregister_code(KC_7);
        }
      }
      return false;
    // 8, *
    case JU_8:
      if (record->event.pressed) {
        lshift = keyboard_report->mods & MOD_BIT(KC_LSFT);
        rshift = keyboard_report->mods & MOD_BIT(KC_RSFT);
        if (lshift || rshift) {
          if (lshift) unregister_code(KC_LSFT);
          if (rshift) unregister_code(KC_RSFT);
          // send + (US:shift+:, JIS:shift+;)
          register_code(KC_LSFT);
          register_code(KC_QUOT);
          unregister_code(KC_QUOT);
          unregister_code(KC_LSFT);
          if (lshift) register_code(KC_LSFT);
          if (rshift) register_code(KC_RSFT);
        } else {
          register_code(KC_8);
          unregister_code(KC_8);
        }
      }
      return false;
    // 9, (
    case JU_9:
      if (record->event.pressed) {
        lshift = keyboard_report->mods & MOD_BIT(KC_LSFT);
        rshift = keyboard_report->mods & MOD_BIT(KC_RSFT);
        if (lshift || rshift) {
          if (lshift) unregister_code(KC_LSFT);
          if (rshift) unregister_code(KC_RSFT);
          // send ( (shift+8)
          register_code(KC_LSFT);
          register_code(KC_8);
          unregister_code(KC_8);
          unregister_code(KC_LSFT);
          if (lshift) register_code(KC_LSFT);
          if (rshift) register_code(KC_RSFT);
        } else {
          register_code(KC_9);
          unregister_code(KC_9);
        }
      }
      return false;
    // 0, )
    case JU_0:
      if (record->event.pressed) {
        lshift = keyboard_report->mods & MOD_BIT(KC_LSFT);
        rshift = keyboard_report->mods & MOD_BIT(KC_RSFT);
        if (lshift || rshift) {
          if (lshift) unregister_code(KC_LSFT);
          if (rshift) unregister_code(KC_RSFT);
          // send ) (shift+9)
          register_code(KC_LSFT);
          register_code(KC_9);
          unregister_code(KC_9);
          unregister_code(KC_LSFT);
          if (lshift) register_code(KC_LSFT);
          if (rshift) register_code(KC_RSFT);
        } else {
          register_code(KC_0);
          unregister_code(KC_0);
        }
      }
      return false;
    // -, _
    case JU_MINS:
      if (record->event.pressed) {
        lshift = keyboard_report->mods & MOD_BIT(KC_LSFT);
        rshift = keyboard_report->mods & MOD_BIT(KC_RSFT);
        if (lshift || rshift) {
          if (lshift) unregister_code(KC_LSFT);
          if (rshift) unregister_code(KC_RSFT);
          // send _ (US:shift+international1, JIS:shift+\)
          register_code(KC_LSFT);
          register_code(KC_INT1);
          unregister_code(KC_INT1);
          unregister_code(KC_LSFT);
          if (lshift) register_code(KC_LSFT);
          if (rshift) register_code(KC_RSFT);
        } else {
          register_code(KC_MINS);
          unregister_code(KC_MINS);
        }
      }
      return false;
    // =, +
    case JU_EQL:
      if (record->event.pressed) {
        lshift = keyboard_report->mods & MOD_BIT(KC_LSFT);
        rshift = keyboard_report->mods & MOD_BIT(KC_RSFT);
        if (lshift || rshift) {
          if (lshift) unregister_code(KC_LSFT);
          if (rshift) unregister_code(KC_RSFT);
          // send + (shift+;)
          register_code(KC_LSFT);
          register_code(KC_SCLN);
          unregister_code(KC_SCLN);
          unregister_code(KC_LSFT);
          if (lshift) register_code(KC_LSFT);
          if (rshift) register_code(KC_RSFT);
        } else {
          register_code(KC_LSFT);
          register_code(KC_MINS);
          unregister_code(KC_MINS);
          unregister_code(KC_LSFT);
        }
      }
      return false;
    // [, {
    case JU_LBRC:
      if (record->event.pressed) {
        lshift = keyboard_report->mods & MOD_BIT(KC_LSFT);
        rshift = keyboard_report->mods & MOD_BIT(KC_RSFT);
        if (lshift || rshift) {
          if (lshift) unregister_code(KC_LSFT);
          if (rshift) unregister_code(KC_RSFT);
          // send { (US:shift+], JIS:shift+[)
          register_code(KC_LSFT);
          register_code(KC_RBRC);
          unregister_code(KC_RBRC);
          unregister_code(KC_LSFT);
          if (lshift) register_code(KC_LSFT);
          if (rshift) register_code(KC_RSFT);
        } else {
          // send [ (US:], JIS:[)
          register_code(KC_RBRC);
          unregister_code(KC_RBRC);
        }
      }
      return false;
    // ], }
    case JU_RBRC:
      if (record->event.pressed) {
        lshift = keyboard_report->mods & MOD_BIT(KC_LSFT);
        rshift = keyboard_report->mods & MOD_BIT(KC_RSFT);
        if (lshift || rshift) {
          if (lshift) unregister_code(KC_LSFT);
          if (rshift) unregister_code(KC_RSFT);
          // send } (US:shift+NUHS, JIS:shift+])
          register_code(KC_LSFT);
          register_code(KC_NUHS);
          unregister_code(KC_NUHS);
          unregister_code(KC_LSFT);
          if (lshift) register_code(KC_LSFT);
          if (rshift) register_code(KC_RSFT);
        } else {
          // send ] (US:NUHS, JIS:])
          register_code(KC_NUHS);
          unregister_code(KC_NUHS);
        }
      }
      return false;
    // \, |
    case JU_BSLS:
      if (record->event.pressed) {
        lshift = keyboard_report->mods & MOD_BIT(KC_LSFT);
        rshift = keyboard_report->mods & MOD_BIT(KC_RSFT);
        if (lshift || rshift) {
          if (lshift) unregister_code(KC_LSFT);
          if (rshift) unregister_code(KC_RSFT);
          // send | (US:shift+international3, JIS:shift+\)
          register_code(KC_LSFT);
          register_code(KC_INT3);
          unregister_code(KC_INT3);
          unregister_code(KC_LSFT);
          if (lshift) register_code(KC_LSFT);
          if (rshift) register_code(KC_RSFT);
        } else {
          // send \ (US:international1, JIS:\)
          register_code(KC_INT1);
          unregister_code(KC_INT1);
        }
      }
      return false;
    // ;, :
    case JU_SCLN:
      if (record->event.pressed) {
        lshift = keyboard_report->mods & MOD_BIT(KC_LSFT);
        rshift = keyboard_report->mods & MOD_BIT(KC_RSFT);
        if (lshift || rshift) {
          if (lshift) unregister_code(KC_LSFT);
          if (rshift) unregister_code(KC_RSFT);
          // send : (US:', JIS::)
          register_code(KC_QUOT);
          unregister_code(KC_QUOT);
          if (lshift) register_code(KC_LSFT);
          if (rshift) register_code(KC_RSFT);
        } else {
          // send ;
          register_code(KC_SCLN);
          unregister_code(KC_SCLN);
        }
      }
      return false;
    // ', "
    case JU_QUOT:
      if (record->event.pressed) {
        lshift = keyboard_report->mods & MOD_BIT(KC_LSFT);
        rshift = keyboard_report->mods & MOD_BIT(KC_RSFT);
        if (lshift || rshift) {
          if (lshift) unregister_code(KC_LSFT);
          if (rshift) unregister_code(KC_RSFT);
          // send " (shift+2)
          register_code(KC_LSFT);
          register_code(KC_2);
          unregister_code(KC_2);
          unregister_code(KC_LSFT);
          if (lshift) register_code(KC_LSFT);
          if (rshift) register_code(KC_RSFT);
        } else {
          // send ' (shift+7)
          register_code(KC_LSFT);
          register_code(KC_7);
          unregister_code(KC_7);
          unregister_code(KC_LSFT);
        }
      }
      return false;
    // `, ~
    case JU_GRV:
      if (record->event.pressed) {
        lshift = keyboard_report->mods & MOD_BIT(KC_LSFT);
        rshift = keyboard_report->mods & MOD_BIT(KC_RSFT);
        if (lshift || rshift) {
          if (lshift) unregister_code(KC_LSFT);
          if (rshift) unregister_code(KC_RSFT);
          // send ~ (US:shift+=, JIS:shift+^)
          register_code(KC_LSFT);
          register_code(KC_EQL);
          unregister_code(KC_EQL);
          unregister_code(KC_LSFT);
          if (lshift) register_code(KC_LSFT);
          if (rshift) register_code(KC_RSFT);
        } else {
          // send ` (US:shift+[, JIS:shift+@)
          register_code(KC_LSFT);
          register_code(KC_LBRC);
          unregister_code(KC_LBRC);
          unregister_code(KC_LSFT);
        }
      }
      return false;
    case JU_CAPS:
      if (record->event.pressed) {
        register_code(KC_LSFT);
        register_code(KC_CAPS);
        unregister_code(KC_CAPS);
        unregister_code(KC_LSFT);
      }
      return false;
  }
  return true;
}
