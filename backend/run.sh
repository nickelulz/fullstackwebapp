# remove prev builds
rm -rf bin/*

# build
# -std=c99 -O3 -g -Wall -Wextra
gcc src/main.c -lcurl -ljson-c -o bin/main.o

# run
./bin/main.o
