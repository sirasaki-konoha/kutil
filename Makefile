CC     := gcc
CFLAGS := -Wall -Wextra -std=c99 -O2 -I. -g
LDLIBS := 

.PHONY: all clean

all: bin/example


bin/example: bin/
	$(CC) $(CFLAGS) $(LDLIBS) example/test.c -o bin/example

bin/:
	mkdir -p bin

clean:
	rm -rf bin

