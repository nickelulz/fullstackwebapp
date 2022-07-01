#pragma once

int http_get(char* endpoint);
size_t output_data(char* buffer, size_t itemsize, size_t nitems, void* ignore);
