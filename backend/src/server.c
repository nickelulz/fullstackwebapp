#include <unistd.h>
#include <sys/stat.h>
#include "backend.h"
#include "logger.h"
#include "color.h"
#include "httpd.h"

#define DEFAULT_PORT 3001
#define CHUNK_SIZE 1024 // read 1024 bytes at a time
#define SERVER_PORT "3001"

int main(int argc, char* argv[]) {
	LOG_INFO("This should be colored %s and this should be colored %s", ansi_green("green"), ansi_red("red"));
	initialize_httpserver(argc > 1 ? argv[1] : SERVER_PORT);
	return 0;
}

void route() {
	ROUTE_START()

	GET("/") {
		HTTP_200;
		printf("List of request headers:\n\n");
		header_t* h = request_headers();
		while (h->name) {
			printf("%s: %s\n", h->name, h->value);
			h++;
		}
	}

	POST("/") {
		HTTP_201;
		printf("You posted %d bytes! \r\n", payload_size);
		if (payload_size > 0)
			printf("Request body: %s", payload);
	}


	GET(uri) {
		HTTP_500;
		printf("No route!\n");
	}

	ROUTE_END()
}
