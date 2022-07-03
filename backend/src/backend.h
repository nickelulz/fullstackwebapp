#pragma once

// Frontend API URL
#define FRONTEND_API_URL "http://localhost:3000"

// Standard Project Vars
#define BUFFER_SIZE_SMALL 50
#define BUFFER_SIZE_MED   300
#define BUFFER_SIZE_LARGE 1000

// Frontend API interaction functions
int http_get(char* endpoint);
int http_post(char* endpoint, char* json);
size_t output_data(char* buffer, size_t itemsize, size_t nitems, void* ignore);
