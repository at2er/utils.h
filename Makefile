CC = cc
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c99 -D_DEFAULT_SOURCE \
	 -g3

.PHONY: test-darr2 test-str
test-darr2: test/darr2
test-str: test/str

test/darr2: test/darr2.c darr2.h
	$(CC) $(CFLAGS) -o $@ $<
test/str: test/str.c str.h
	$(CC) $(CFLAGS) -o $@ $<

.PHONY: all clean
all: test-darr2 test-str

clean:
	rm -f test/darr2 test/str
