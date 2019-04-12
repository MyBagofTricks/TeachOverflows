CC = gcc
CFLAGS = -fno-stack-protector -no-pie -m32 -Wall -Wformat=0

all: level01 level02 level03 level04 level05 level06 level07 level08 level09 level10 level11 level12

level01: src/level01.c 	
	$(CC) $(CFLAGS) src/level01.c -o bin/level01
	
level02: src/level02.c
	$(CC) $(CFLAGS) src/level02.c -o bin/level02

level03: src/level03.c
	$(CC) $(CFLAGS) src/level03.c -o bin/level03

level04: src/level04.c
	$(CC) $(CFLAGS) src/level04.c -o bin/level04

level05: src/level05.c 	
	$(CC) $(CFLAGS) src/level05.c -o bin/level05
	
level06: src/level06.c
	$(CC) $(CFLAGS) -s src/level06.c -o bin/level06

level07: src/level07.c
	$(CC) $(CFLAGS) src/level07.c -o bin/level07

level08: src/level08.c
	$(CC) $(CFLAGS) src/level08.c -o bin/level08

level09: src/level09.c 	
	$(CC) $(CFLAGS) src/level09.c -o bin/level09

level10: src/level10.c
	$(CC) $(CFLAGS) src/level10.c -o bin/level10

level11: src/level11.c
	$(CC) $(CFLAGS) src/level11.c -o bin/level11

level12: src/level12.c
	$(CC) $(CFLAGS) src/level12.c -o bin/level12 -Wno-incompatible-pointer-types


${shell mkdir -p bin}
