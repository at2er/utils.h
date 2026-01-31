CC = cc
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c99 -D_DEFAULT_SOURCE \
	 -g3

.PHONY: test-str
test-str: test/str

test/str: test/str.c str.h
	$(CC) $(CFLAGS) -o $@ $<

.PHONY: all clean
all: test-str

clean:
	rm -f test/str
