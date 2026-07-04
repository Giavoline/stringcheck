CC      = gcc
CFLAGS  = -std=c17 -Wall -Wextra -Wpedantic \
	  -Iinclude \
	  -Isrc
LDFLAGS =

TARGET  = stringcheck

SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

test: $(TARGET)
	./tests/test.sh


.PHONY: all clean test
