#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "logger.h"
#include "backend.h"
#include "color.h"

char* ansi_wrapf(const char* code, const char* format, va_list args) {
    // Initial format buffer
    char* format_buf = malloc(sizeof(char) * strlen(format) + BUFFER_SIZE_MED);
    int format_status = vsprintf(format_buf, format, args);

    if (format_status != EXIT_SUCCESS) {
        // LOG_ERROR("Format failure!");
        // LOG_ERROR("Attempt to format string \"%s\" failed on exit code %d!", format, format_status);
        return NULL;
    }

    // Create
    char* buffer = malloc(sizeof(char) * strlen(format_buf) + BUFFER_SIZE_MED);
    strcpy(buffer, code);
    strcpy(buffer, format_buf);
    strcpy(buffer, ANSI_COLOR_RESET);

    // Free and return
    free(format_buf);
    return buffer;
}

char* ansi_color(const char* color, const char* format, ...) {
    va_list args;
    va_start(args, format);
    char* out = ansi_wrapf(color, format, args);
    va_end(args);
    return out;
}
