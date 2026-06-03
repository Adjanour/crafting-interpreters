CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g -D_POSIX_C_SOURCE=200809L
VALGRIND = valgrind --leak-check=full --error-exitcode=1

all: test_list

test_list: test_list.c list.c list.h
	$(CC) $(CFLAGS) -o test_list test_list.c list.c

run: test_list
	./test_list

valgrind: test_list
	$(VALGRIND) ./test_list

clean:
	rm -f test_list
