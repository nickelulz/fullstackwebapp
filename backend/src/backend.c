#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <json-c/json.h>
#include <curl/curl.h>
#include "backend.h"

#define FRONTEND_API_URL "http://localhost:3000"

int main(int argc, char* argv[]) {
	return http_get("/server/");
}

int http_get(char* endpoint) {
	CURL* curl = curl_easy_init();

	if (!curl) {
		fprintf(stderr, "LibCurl Initialization failed. Exiting...\n");
		return EXIT_FAILURE;
	}

	// LibCurl Configuration
	char buf[30];
	strcpy(buf, FRONTEND_API_URL);
	strcat(buf, endpoint);
	curl_easy_setopt(curl, CURLOPT_URL, buf);
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, output_data);

	// Action
	CURLcode result = curl_easy_perform(curl);
	if (result != CURLE_OK) {
		fprintf(stderr, "Download Error: %s\n", curl_easy_strerror(result));
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

size_t output_data(char* buffer, size_t itemsize, size_t nitems, void* ignore) {
	size_t bytes = itemsize * nitems;
	int line_number = 1;
	printf("Chunk recieved: (%zu bytes)\n", bytes);
	printf("%d:\t", line_number);
	for (int i = 0; i < bytes; i++) {
		printf("%c", buffer[i]);
		if (buffer[i] == '\n') {
			line_number++;
		}
	}
	printf("\n\n");
	return bytes;
}
