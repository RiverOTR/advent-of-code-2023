# J.Med, mr.rivertimmothyotter@gmail.com

.PHONY: clean

CC = gcc
CFLAGS = -g
CPPFLAGS = -std=gnu90 -Wall -Wextra -pedantic
BUILD_DIR = ./build

day2problem1: day2problem1.o
	$(CC) $(CFLAGS) -o day2problem1 $(BUILD_DIR)/day2problem1.o

day2problem1.o: day2problem1.c
	$(CC) $(CPPFLAGS) -o $(BUILD_DIR)/day2problem1.o -c day2problem1.c

day1problem2: day1problem2.o
	$(CC) $(CFLAGS) -o day1problem2 $(BUILD_DIR)/day1problem2.o

day1problem2.o: day1problem2.c
	$(CC) $(CPPFLAGS) -o $(BUILD_DIR)/day1problem2.o -c day1problem2.c

clean:
	rm -f $(BUILD_DIR)/* day*[123456789]problem*[123456789]
