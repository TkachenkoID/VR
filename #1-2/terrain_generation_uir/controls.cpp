#include "controls.h"

HFONT controls_font;

void set_controls_default_font(HFONT h_font)
{
	controls_font = h_font;
}

HWND add_label(HWND parent, INT x, INT y, INT width, INT height, LPCSTR text)
{
	HWND hbutton;
	hbutton = CreateWindowExA(0, "static", text, WS_VISIBLE | WS_CHILD/*|WS_TABSTOP*/, x, y, width, height, parent, (HMENU)0, NULL, NULL);
	SendMessageA(hbutton, WM_SETFONT, (WPARAM)controls_font, (LPARAM)TRUE);
	return hbutton;
}

HWND add_button(HWND parent, INT x, INT y, INT width, INT height, LPCSTR button_name, INT id)
{
	HWND hbutton;
	hbutton = CreateWindowExA(0, "button", button_name, WS_VISIBLE | WS_CHILD/*|WS_TABSTOP*/, x, y, width, height, parent, (HMENU)id, NULL, NULL);
	SendMessageA(hbutton, WM_SETFONT, (WPARAM)controls_font, (LPARAM)TRUE);
	return hbutton;
}

HWND add_checkbox(HWND parent, INT x, INT y, INT width, INT height, LPCSTR button_name, BOOL initstate, INT id)
{
	HWND hbutton;
	hbutton = CreateWindowExA(0, "button", button_name, WS_VISIBLE|WS_CHILD|BS_AUTOCHECKBOX, x, y, width, height, parent, (HMENU)id, NULL, NULL);
	SendMessageA(hbutton, WM_SETFONT, (WPARAM)controls_font, (LPARAM)TRUE);
	return hbutton;
}

HWND add_togglebutton(HWND parent, INT x, INT y, INT width, INT height, LPCSTR button_name, BOOL initstate, INT id)
{
	HWND hbutton;
	hbutton = CreateWindowExA(0, "button", button_name, WS_VISIBLE|WS_CHILD|BS_AUTO3STATE, x, y, width, height, parent, (HMENU)id, NULL, NULL);
	SendMessageA(hbutton, WM_SETFONT, (WPARAM)controls_font, (LPARAM)TRUE);
	return hbutton;
}

HWND add_gropbox(HWND parent, INT x, INT y, INT width, INT height, LPCSTR group_name, INT id)
{
	HWND hgroup;
	hgroup = CreateWindowExA(0, "button", group_name, WS_VISIBLE|WS_CHILD|BS_GROUPBOX, x, y, width, height, parent, (HMENU)id, NULL, NULL);
	SendMessageA(hgroup, WM_SETFONT, (WPARAM)controls_font, (LPARAM)TRUE);
	return hgroup;
}

HWND add_trackbar(HWND parent, INT x, INT y, INT width, INT height, INT min, INT max, INT current, INT id, BOOL bhorz)
{
	HWND htrackbar;
	DWORD dw_style = WS_VISIBLE | WS_CHILD;
	dw_style |= bhorz ? TBS_HORZ : TBS_VERT;
	htrackbar = CreateWindowExA(0, TRACKBAR_CLASSA, "", dw_style, x, y, width, height, parent, (HMENU)id, NULL, NULL);
	SendMessageA(htrackbar, WM_SETFONT, (WPARAM)controls_font, (LPARAM)TRUE);
	return htrackbar;
}

HWND add_editbox(HWND parent, INT x, INT y, INT width, INT height, INT id, LPCSTR inittext)
{
	HWND hgroup;
	hgroup = CreateWindowExA(WS_EX_CLIENTEDGE, WC_EDITA, inittext, WS_VISIBLE|WS_CHILD, x, y, width, height, parent, (HMENU)id, NULL, NULL);
	SendMessageA(hgroup, WM_SETFONT, (WPARAM)controls_font, (LPARAM)TRUE);
	return hgroup;
}

HWND add_trackbar_with_description_autoheight(HWND parent, LONG x, LONG *p_y, INT width, INT height, INT up_padding, INT id, LPCSTR description)
{
	add_label(parent, x, *p_y, width, 20, description);
	*p_y += 20;
	HWND htrack = add_trackbar(parent, x, *p_y, width, height, 0, 0, 0, id, TRUE);
	*p_y += height + up_padding;
	return htrack;
}