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

testlev: src/levenshtein.c tests/test_levenshtein.c
	$(CC) $(CFLAGS) -Isrc \
	    tests/test_levenshtein.c \
	    src/levenshtein.c \
	    -o test_levenshtein
	./test_levenshtein

.PHONY: testlev
