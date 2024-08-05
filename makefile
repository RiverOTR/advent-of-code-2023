# J.Med, mr.rivertimmothyotter@gmail.com

.PHONY: clean

CC = gcc
CFLAGS = -g
CPPFLAGS = -std=gnu90 -Wall -Wextra -pedantic

calibrationCalc: calibrationCalc.o
	$(CC) -o calibrationCalc calibrationCalc.o

calibrationCalc.o: calibrationCalc.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -o calibrationCalc.o -c calibrationCalc.c

clean:
	rm -f calibrationCalc.o
