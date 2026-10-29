CC      = gcc
CFLAGS  = -Wall -Wextra -O2 -pthread
TARGET  = portscan
SRC     = src/main.c src/scanner.c

all: $(TARGET)

$(TARGET): $(SRC) src/scanner.h
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

# Build with AddressSanitizer to catch memory bugs while developing
debug: $(SRC) src/scanner.h
	$(CC) -Wall -Wextra -g -fsanitize=address,undefined -pthread -o $(TARGET)_debug $(SRC)

clean:
	rm -f $(TARGET) $(TARGET)_debug

.PHONY: all debug clean
