#pragma once

#include <stdarg.h>

// CLI Coloring
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

char* ansi_wrapf(const char* code, const char* format, va_list args);
char* ansi_color(const char* color, const char* format, ...);

#define ansi_green(text, ...)   ansi_color(ANSI_COLOR_GREEN,    text, ##__VA_ARGS__)
#define ansi_red(text, ...)     ansi_color(ANSI_COLOR_RED,      text, ##__VA_ARGS__)
#define ansi_yellow(text, ...)  ansi_color(ANSI_COLOR_YELLOW,   text, ##__VA_ARGS__)
#define ansi_blue(text, ...)    ansi_color(ANSI_COLOR_BLUE,     text, ##__VA_ARGS__)
#define ansi_magenta(text, ...) ansi_color(ANSI_COLOR_MAGENTA,  text, ##__VA_ARGS__)
#define ansi_cyan(text, ...)    ansi_color(ANSI_COLOR_CYAN,     text, ##__VA_ARGS__)
