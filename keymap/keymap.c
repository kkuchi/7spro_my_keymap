
/*
JIS環境でUS配列の文字・記号入力をするためのキーマップ。
コード用に各種記号・数字はレイヤーから入力。
*/

#include QMK_KEYBOARD_H
#include "keymap_jp.h"
#include "jtu_custom_keycodes.h"

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;



// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
  _QWERTY = 0,
  _MAC,
  _GAMING,
  _FN,
  _ADJUST,
  _UNIX,
  _NUMPAD,
  _SYMBOL
};

// 各種カスタムキーコードの定義
enum custom_keycodes {
  RGB_RST = JTU_SAFE_RANGE,
  CK_CTROW // １行カットのカスタムキーコード
};

#define CK_CAPS LSFT(KC_LCTL) // CapsLockはShift+LCtrl

#define KC_VD_R RGUI(RCTL(KC_RIGHT)) // 仮想デスクトップ右移動
#define KC_VD_L RGUI(RCTL(KC_LEFT)) //  仮想デスクトップの左移動

#define CK_MHLC RCTL_T(JP_MHEN) // 短く押して無変換, 長押しでCtrl
#define CK_HKRC RCTL_T(JP_HENK) // 短く押して変換, 長押しでCtrl

#define LT_NPSP LT(_NUMPAD, KC_SPC) // 短く押してspace, 長押しで_NUMPADレイヤー
#define LT_SBET LT(_SYMBOL, KC_ENT) // 短く押してenter, 長押しで_SYMBOLレイヤー

// Mac用
#define MK_ESLC LGUI_T(JP_MEISU) // 短く押して英数, 長押しでCommand
#define MK_KNRC RGUI_T(JP_MKANA) // 短く押してかな, 長押しでCommand

// キーマップ
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // default layer
  /* |---------------------------|                     |------------------------------------|
      | Esc | 1 | 2 | 3 | 4 | 5 |                       | 6 | 7 | 8 | 9 | 0 | - | = | \ | ` |
      |  Tab  | Q | W | E | R | T |                      | Y | U | I | O | O | [ | ] | BSpace |
      | MO(_UNIX)| A | S | D | F | G |                      | H | J | K | L | ; | ' |   Enter   |
      |    Shift   | Z | X | C | V | B |                      | N | M | , | . | / | Shift | Mo(_FN) |
      | Mo(_FN) | Alt | RCTL_T(無変換) | LT(_NUMPAD, Space) |       | LT(_SYMBOL, Enter) | RCTL_T(変換) | ALt | Windows |
      |----------------------------------------------------|      |----------------------------------------------------|
  */
  [_QWERTY] = LAYOUT(
  //,-----------------------------------------------------|   |--------------------------------------------------------------------------------.
       KC_ESC,    KC_1,    JU_2,    KC_3,    KC_4,    KC_5,        JU_6,    JU_7,    JU_8,    JU_9,    JU_0, JU_MINS,  JU_EQL,  JP_YEN,  JU_GRV,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, JU_LBRC, JU_RBRC, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------|
    MO(_UNIX),    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,        KC_H,    KC_J,    KC_K,    KC_L, JU_SCLN, JU_QUOT,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT, MO(_FN),
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
               MO(_FN), KC_RALT, CK_MHLC, LT_NPSP,              LT_SBET, CK_HKRC,          KC_RALT, KC_RGUI
          //`---------------------------------------------|   |--------------------------------------------'
  ),

  // Mac用のモディファイヤキーレイヤー
  // MO(_UNIX)をControl、CtrlをCommand(GUI), Windows(GUI}をCAPSLOCKに変更
  // _UNIXの`で切り替え
  [_MAC] = LAYOUT(
    //,-----------------------------------------------------|   |--------------------------------------------------------------------------------.
      _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------|
      KC_LCTL, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
               _______, KC_LALT, MK_ESLC, _______,              _______, MK_KNRC,          _______, JP_CAPS
          //`---------------------------------------------|   |--------------------------------------------'
  ),

  // テンキーレイヤー。
  /* |-------------------------------------------------------------------------------------------------------------------|
      |Esc | 1 | 2 | 3 | 4 | 5 |                          | 6 | 7 | 8 | 9 | 0 | - | = | \ | ` |
      | Tab |   |   | * |   |   |                           |   | 7 | 8 | 9 |   |   |   | BSpace |
  | MO(_UNIX)|   |   | + |Tab|   |                            | / | 4 | 5 | 6 | - | = |   Enter   |
      | Shift |   |   |   |   |   |                             | 0 | 1 | 2 | 3 |   | Shift | Mo(_FN) |
      | Mo(_FN) | Alt | RCTL_T(英数) | LT(_NUMPAD, Space) |       | LT(_SYMBOL, Enter) | RCTL_T(かな) | ALt | Windows
  */

  [_NUMPAD] = LAYOUT(
  //,-----------------------------------------------------|   |--------------------------------------------------------------------------------.
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, JP_ASTR, XXXXXXX, XXXXXXX,     XXXXXXX,   KC_P7,   KC_P8,   KC_P9, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, JP_PLUS,  KC_TAB, XXXXXXX,     JP_SLSH,   KC_P4,   KC_P5,   KC_P6, JP_MINS,  JP_EQL, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       KC_P0,   KC_P1,   KC_P2,   KC_P3, XXXXXXX, _______, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
               _______, _______, _______, _______,              _______, _______,          _______, _______ 
          //`---------------------------------------------|   |--------------------------------------------'
  ),

  // 記号レイヤー。
  /*　|------------------------------------------------------------------------------------------------------------------------------------------|
      |Esc |   |   |   |   |   |                          |   |   |   |   |   | - | = | \ | ` |
      | Tab | ! | ? | $ | % | & |                           |   |   | @ |   |   |   |   | BSpace |
  | MO(_UNIX)| [ | { | ( | _ | \ |                            |   | ` | \ |   | ; | ' |   Enter   |
      | Shift | ] | } | ) | # | | |                             | ~ |   | , | . | / | Shift | Mo(_FN) |
      | Mo(_FN) | Alt | RCTL_T(英数) | LT(_NUMPAD, Space) |       | LT(_SYMBOL, Enter) | RCTL_T(かな) | ALt | Windows
  */

  [_SYMBOL] = LAYOUT(
  //,-----------------------------------------------------|   |--------------------------------------------------------------------------------.
      _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
      _______, JP_EXLM, JP_QUES,  JP_DLR, JP_PERC, JP_AMPR,     _______, _______,   JP_AT, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------|
      _______, JP_LBRC, JP_LCBR, JP_LPRN, JP_UNDS,  JP_YEN,     _______,  JP_GRV,  JP_YEN, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
      _______, JP_RBRC, JP_RCBR, JP_RPRN, JP_HASH, JP_PIPE,     JP_TILD, _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
               _______, _______, _______, _______,              _______, _______,          _______, _______ 
          //`---------------------------------------------|   |--------------------------------------------'
  ),

  // UNIXキーバインドを再現するレイヤー
  /*
  a: home
  e: end
  f: →
  b: ←
  p: ↑
  n: ↓
  h: backspace
  d: delete
  k: 1行削除
  */ 
  [_UNIX] = LAYOUT(
  //,-----------------------------------------------------|   |--------------------------------------------------------------------------------.
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX,  KC_END, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_UP, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------|
      _______, KC_HOME, XXXXXXX,  KC_DEL,KC_RIGHT, XXXXXXX,     KC_BSPC, XXXXXXX,CK_CTROW, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT,     KC_DOWN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
               XXXXXXX, _______, _______, JP_ZKHK,              _______, _______,          _______, _______ 
          //`---------------------------------------------|   |--------------------------------------------'
  ),

  // ゲーミング用レイヤー。
  // 基本的なキーボード、右上で元に戻す
  // LCTLはLALT

  [_GAMING] = LAYOUT(
  //,-----------------------------------------------------|   |--------------------------------------------------------------------------------.
       KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,        KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL, KC_BSLS,TG(_GAMING),
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC, KC_RBRC,KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------|
      KC_LALT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,        KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT, MO(_FN),
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
               XXXXXXX, KC_LALT, KC_LCTL,  KC_SPC,               KC_ENT, KC_RCTL,          KC_RALT, KC_RGUI 
          //`---------------------------------------------|   |--------------------------------------------'
  ),

  // FN layer. DとFに仮想デスクトップのL, Rを配置
  // ]でCapsLock(Shift+LCtrl)
  // \で_MACレイヤー, `で_GAMINGレイヤーのON/OFF切り替え
  [_FN] = LAYOUT(
  //,-----------------------------------------------------|   |--------------------------------------------------------------------------------.
  TG(_ADJUST),   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,TG(_MAC),TG(_GAMING),
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
      _______,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,     _______, _______, KC_PSCR, KC_SLCK,KC_PAUSE,   KC_UP, CK_CAPS, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------|
      _______,  KC_F11,  KC_F12, KC_VD_L, KC_VD_R, _______,     _______, _______, KC_HOME, KC_PGUP, KC_LEFT,KC_RIGHT, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,     _______, _______,  KC_END, KC_PGDN, KC_DOWN, _______, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
               _______, _______, _______, _______,              _______, _______,          _______, _______ 
          //`---------------------------------------------|   |--------------------------------------------'
  ),

  [_ADJUST] = LAYOUT( /* Base */
  //,-----------------------------------------------------|   |--------------------------------------------------------------------------------.
  TG(_ADJUST), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   RESET,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     RGB_RST, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     RGB_TOG, RGB_MOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     RGB_VAD, RGB_VAI, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,              XXXXXXX, XXXXXXX,          KC_STOP, XXXXXXX 
          //`---------------------------------------------|   |--------------------------------------------'
  )
};

//A description for expressing the layer position in LED mode.
layer_state_t layer_state_set_user(layer_state_t state) {
#ifdef RGBLIGHT_ENABLE
    switch (get_highest_layer(state)) {
    case _FN:
      rgblight_sethsv_at(HSV_BLUE, 0);
      break;
    case _ADJUST:
      rgblight_sethsv_at(HSV_PURPLE, 0);
      break;
    default: //  for any other layers, or the default layer
      rgblight_sethsv_at( 0, 0, 0, 0);
      break;
    }
    rgblight_set_effect_range( 1, 4);
#endif
return state;
}

int RGB_current_mode;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  bool continue_process = process_record_user_jtu(keycode, record);
  if (continue_process == false) {
    return false;
  }
  bool result = false;
  switch (keycode) {
    #ifdef RGBLIGHT_ENABLE
      case RGB_MOD:
          if (record->event.pressed) {
            rgblight_mode(RGB_current_mode);
            rgblight_step();
            RGB_current_mode = rgblight_config.mode;
          }
        break;
      case RGB_RST:
          if (record->event.pressed) {
            eeconfig_update_rgblight_default();
            rgblight_enable();
            RGB_current_mode = rgblight_config.mode;
          }
        break;
    #endif

    case CK_CTROW:
      if (record->event.pressed) {
        // shift+end
        // down
        register_code(KC_LSFT);
        register_code(KC_END);
        // up
        unregister_code(KC_END);
        unregister_code(KC_LSFT);

        // delete
        register_code(KC_DEL);
        unregister_code(KC_DEL);
      }
      return false;
    
    default:
      result = true;
      break;
  }

  return result;
}
