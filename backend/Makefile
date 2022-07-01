CC = gcc
CFLAGS = -std=c99 -O3 -g -Wall
# EXTRA CFLAGS
#CFLAGS += -Wextra
CFLAGS += -lcurl -ljson-c
LDFLAGS :=

SRC_DIR := src
BIN_DIR := bin
SOURCES := $(shell find $(SRC_DIR) -type f -name *.c)
OBJECTS := $(patsubst $(SRC_DIR)/%,$(BIN_DIR)/%,$(SOURCES:.c=.o))
TARGET := $(BIN_DIR)/backend-main

.PHONY: all run clean

run: all
		./$(TARGET)

all: dirs $(TARGET)

dirs:
	mkdir -p $(BIN_DIR)

$(TARGET): $(OBJECTS)
	$(CC) $< $(CFLAGS) -o $@

$(OBJECTS): $(SOURCES)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BIN_DIR)/*
