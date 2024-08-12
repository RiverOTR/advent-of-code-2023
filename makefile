# J.Med, mr.rivertimmothyotter@gmail.com

.PHONY: clean

CC = gcc
CFLAGS = -g
CPPFLAGS = -std=gnu90 -Wall -Wextra -pedantic
BUILD_DIR = ./build

problem2: problem2.o
	$(CC) $(CFLAGS) -o problem2 $(BUILD_DIR)/problem2.o

problem2.o: problem2.c
	$(CC) $(CPPFLAGS) -o $(BUILD_DIR)/problem2.o -c problem2.c

problem1: problem1.o
	$(CC) $(CFLAGS) -o problem1 $(BUILD_DIR)/problem1.o

problem1.o: problem1.c
	$(CC) $(CPPFLAGS) -o $(BUILD_DIR)/problem1.o -c problem1.c

clean:
	rm -f $(BUILD_DIR)/* problem?[123456789]
