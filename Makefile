# ==============================================================================
# Makefile: Stack String Reverser (C Implementation)
# ==============================================================================

CC = gcc
CFLAGS = -Wall -Wextra -O2 -std=c99
TARGET = stack_reverse
SRC = stack_reverse.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

run: $(TARGET)
	./$(TARGET)

test: $(TARGET)
	@echo "--- Testing with sample word: 'ALGORITHM' ---"
	./$(TARGET) "ALGORITHM"
	@echo "--- Testing with sample word: 'RADAR' ---"
	./$(TARGET) "RADAR"

clean:
	rm -f $(TARGET)

.PHONY: all run test clean
