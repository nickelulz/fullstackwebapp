# remove prev builds
rm -rf bin/*

# build
# -std=c99 -O3 -g -Wall -Wextra
gcc -std=c99 -O3 -g -Wall -Wextra -lcurl -ljson-c -o bin/backend-main src/color.c src/api.c src/server.c src/logger.c src/httpd.c

# run
./bin/main.o

# clean
rm -rf bin/*
