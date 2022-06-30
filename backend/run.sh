# remove prev builds
rm -rf bin/*

# build
gcc -std=c99 -O3 -g -Wall -Wextra src/main.c -llibhttp -I include -L lib/libhttp/include -ljson-c -o bin/main.o

# run
./bin/main.o