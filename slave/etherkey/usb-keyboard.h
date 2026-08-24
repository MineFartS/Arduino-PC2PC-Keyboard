#pragma once

#define HWSERIAL Serial1
#include "Keyboard.h"
#include "utils.h"

#define KEY_UP          KEY_UP_ARROW
#define KEY_DOWN        KEY_DOWN_ARROW
#define KEY_RIGHT       KEY_RIGHT_ARROW
#define KEY_LEFT        KEY_LEFT_ARROW

#define KEYPAD_PLUS     KEY_KP_PLUS
#define KEYPAD_0        KEY_KP_0

#define KEY_ENTER       KEY_RETURN
#define KEY_SPACE       ' '

#define MODIFIERKEY_CTRL  KEY_LEFT_CTRL
#define MODIFIERKEY_ALT   KEY_LEFT_ALT
#define MODIFIERKEY_SHIFT KEY_LEFT_SHIFT
#define MODIFIERKEY_GUI   KEY_LEFT_GUI

#define keyboard_leds   0

#define MYDEBUG
#define KBD_BUFFSZ 200
#define KEYNAME_BUFFSZ 25
#define PREFIX 17 // CTRL-Q

// Util functions
int mode_select(char in_ascii, int oldmode);
uint16_t escape_sequence_to_keycode(char in_ascii);
uint16_t special_char_to_keycode(char in_ascii);
uint16_t keyname_to_keycode(const char* keyname);
void usb_send_key(uint16_t key, uint16_t mod=0);

// Interactive mode functions
void interactive_mode(char in_ascii);

// Command mode functions
void command_mode(char in_ascii);
void c_parse(char* str);
bool c_parse_ext(char* str, bool send_single, int modifier);
void c_sendraw(char* pch);
void c_send(char* pch);
void c_unicode(char* pch, bool linux);
void c_sleep(int ms);

// Debug mode functions
void debug_mode(char in_ascii);
