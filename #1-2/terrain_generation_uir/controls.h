#pragma once
#include <Windows.h>
#include <stdio.h>
#include <string.h>
#include <CommCtrl.h>

extern HFONT controls_font;

// 
// set_controls_default_font
// 
// Set default font to all controls
// 
void set_controls_default_font(HFONT h_font);

HWND add_label(HWND parent, INT x, INT y, INT width, INT height, LPCSTR text);

HWND add_button(HWND parent, INT x, INT y, INT width, INT height, LPCSTR button_name, INT id);
HWND add_checkbox(HWND parent, INT x, INT y, INT width, INT height, LPCSTR button_name, BOOL initstate, INT id);
HWND add_togglebutton(HWND parent, INT x, INT y, INT width, INT height, LPCSTR button_name, BOOL initstate, INT id);

HWND add_gropbox(HWND parent, INT x, INT y, INT width, INT height, LPCSTR group_name, INT id);
HWND add_trackbar(HWND parent, INT x, INT y, INT width, INT height, INT min, INT max, INT current, INT id, BOOL bhorz);

HWND add_editbox(HWND parent, INT x, INT y, INT width, INT height, INT id, LPCSTR inittext);

HWND add_trackbar_with_description_autoheight(HWND parent, LONG x, LONG *p_y, INT width, INT height, INT up_padding, INT id, LPCSTR description);