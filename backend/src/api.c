#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <json-c/json.h>
#include <curl/curl.h>
#include "logger.h"
#include "backend.h"

void API_ENDPOINT(char* endpoint) {
	char* buffer = FRONTEND_API_URL;
	strcat(buffer, endpoint);
	endpoint = buffer;
}

int http_post(char* endpoint, char* json) {
    CURL* curl = curl_easy_init();

    if (!curl) {
        LOG_ERROR("Could not init curl to endpoint %s\n", endpoint);
		return EXIT_FAILURE;
    }

    char* data_recieved;
	API_ENDPOINT(endpoint);

    curl_easy_setopt(curl, CURLOPT_URL, endpoint);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, 10L);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, output_data);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data_recieved);
    CURLcode result = curl_easy_perform(curl);
    curl_easy_cleanup(curl);

    if (result != CURLE_OK) {
        LOG_ERROR("POST Request Error: %s\n", curl_easy_strerror(result));
		return EXIT_FAILURE;
	}

    return EXIT_SUCCESS;
}

int http_get(char* endpoint) {
	CURL* curl = curl_easy_init();

	if (!curl) {
        LOG_ERROR("Could not init curl to endpoint %s\n", endpoint);
		return EXIT_FAILURE;
	}

    char* data_recieved;
	API_ENDPOINT(endpoint);

	// LibCurl Configuration
	curl_easy_setopt(curl, CURLOPT_URL, endpoint);
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, output_data);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data_recieved);
    CURLcode result = curl_easy_perform(curl);
    curl_easy_cleanup(curl);

	// Action
	if (result != CURLE_OK) {
        LOG_ERROR("GET Request Error: %s\n", curl_easy_strerror(result));
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

size_t output_data(char* buffer, size_t itemsize, size_t nitems, void* data) {
	size_t bytes = itemsize * nitems;
	// int line_number = 1;
	// printf("Chunk recieved: (%zu bytes)\n", bytes);
	// printf("%d:\t", line_number);
	// for (size_t i = 0; i < bytes; i++) {
	// 	printf("%c", buffer[i]);
	// 	if (buffer[i] == '\n') {
	// 		line_number++;
	// 	}
	// }
	// printf("\n\n");

    // Copy data from buffer to data object
    strncat((char*) data, buffer, bytes);

	return bytes;
}
