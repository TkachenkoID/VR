#pragma once
#include <Windows.h>
#include <tchar.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#include <CommCtrl.h>
#pragma comment(lib, "comctl32.lib")

#include "resource.h"

#define PADDING_PX 2
#define UP_PADDING_PX 10

#define CONTROLS_WINDOW_CLASS "ControlsWindow"
#define VIEWPORT_WINDOW_CLASS "ViewportWindow"

#define PERCENTOF(x, p) ((INT)(x / 100 * p))

#define IDC_SETSEED 1000
#define IDC_SEEDEDIT 1001
#define IDC_FREQTRACK 1002
#define IDC_AMPLITUDE 1003
#define IDC_VERTSDIST 1004
#define IDC_WIDTHTRACK 1005
#define IDC_SMALLNOISE 1006
#define IDC_NOISEMULTIPLIER 1007
#define IDC_STARTGENERATION 1008

#include <gl/GL.h>

//typedef uint16_t GLhalf;
//typedef uint16_t GLhalfARB;
//typedef int32_t GLfixed;
//typedef intptr_t GLintptr;
//typedef intptr_t GLintptrARB;
//typedef size_t GLsizeiptr;
//typedef size_t GLsizeiptrARB;
//typedef int64_t GLint64;
//typedef int64_t GLint64EXT;
//typedef uint64_t GLuint64;
//typedef uint64_t GLuint64EXT;
//
///* OpenGL extensions */
//#define FCC __stdcall
//typedef void (FCC *PFNGLGENBUFFERSPROC)(GLsizei n, GLuint *buffers);
//typedef void (FCC *PFNGLBINDBUFFERPROC)(GLenum target, GLuint buffer);
//typedef void (FCC *PFNGLBUFFERDATAPROC)(GLenum target, GLsizeiptr size, const void *data, GLenum usage);
//typedef void (FCC *PFNGLDELETEBUFFERSPROC)(GLsizei n, const GLuint *buffers);
//extern PFNGLGENBUFFERSPROC glGenBuffers;
//extern PFNGLBINDBUFFERPROC glBindBuffer;
//extern PFNGLBUFFERDATAPROC glBufferData;
//extern PFNGLDELETEBUFFERSPROC glDeleteBuffers;
//
//bool load_gl_extension(LPVOID *ppfuncptr, LPCSTR procname);
//#define LOAD_GL_EXTENSION(fptr, proc) load_gl_extension((LPVOID *)fptr, proc)