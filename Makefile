#!/bin/sh

CC=gcc
CFLAGS= -Wall -Wno-implicit-function-declaration
CLIBS= -lncurses
EXEC=2048

build: display.o game_logic.o map.o movement.o utils.o main.o
	$(CC) $^ $(CFLAGS) -o $(EXEC) $(CLIBS)

display.o: display.c
	$(CC) -c $(CFLAGS) $^

game_logic.o: game_logic.c
	$(CC) -c $(CFLAGS) $^

map.o: map.c
	$(CC) -c $(CFLAGS) $^

movement.o: movement.c
	$(CC) -c $(CFLAGS) $^

utils.o: utils.c
	$(CC) -c $(CFLAGS) $^

main.o: main.c
	$(CC) -c $(CFLAGS) $^

run:
	./$(EXEC)

clean:
	rm -rf *.o $(EXEC)