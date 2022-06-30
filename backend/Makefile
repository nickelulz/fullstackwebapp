CC = gcc
CFLAGS = -std=c99 -O3 -g -Wall -Wextra
CFLAGS += -I include -L lib/libhttp/include -llibhttp -ljson-c 
LDFLAGS := -llibhttp -ljson-c 

SRC_DIR := src
BIN_DIR := bin
SOURCES := $(shell find $(SRC_DIR) -type f -name *.c)
OBJECTS := $(patsubst $(SRC_DIR)/%,$(BIN_DIR)/%,$(SOURCES:.c=.o))
TARGET := $(BIN_DIR)/backend-main

.PHONY: all clean
all: dirs $(TARGET)

dirs: 
	mkdir -p ./$(BIN_DIR)

run: all
	$(BIN_DIR)/build

$(TARGET): $(OBJECTS)
	$(CC) $^ -o $< $(LDFLAGS)

$(OBJECTS): $(SOURCES)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(BIN_DIR)/* $(OBJECTS)