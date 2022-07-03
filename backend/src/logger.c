#include <stdio.h>
#include <stdarg.h>
#include "color.h"

void log_format(const char* tag, const char* message, va_list args) {
    // time_t now;
    // time(&now);
    // char * date =ctime(&now);
    // date[strlen(date) - 1] = '\0';
    fprintf(stderr, "[%s] ", tag);
    vfprintf(stderr, message, args);
    fprintf(stderr, "\n");
}

void LOG_ERROR(const char* message, ...) {
    va_list args;
    va_start(args, message);
    log_format(ansi_red("ERROR"), ansi_red(message), args);
    va_end(args);
}

void LOG_INFO(const char* message, ...) {
    va_list args;
    va_start(args, message);
    log_format(ansi_green("INFO"), message, args);
    va_end(args);
}

void LOG_WARN(const char* message, ...) {
    va_list args;
    va_start(args, message);
    log_format(ansi_yellow("WARN"), ansi_yellow(message), args);
    va_end(args);
}

void LOG_DEBUG(const char* message, ...) {
    va_list args;
    va_start(args, message);
    log_format(ansi_yellow("DEBUG"), message, args);
    va_end(args);
}
