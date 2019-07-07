#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "magic.c"
#define BUF_SIZE 100
#define GET_SIZE 100

int SECRET[40] = {0x58,0x41,0x1f,0x1f,0x1b,0x4e,0x77,0x18,0x42,0x1b,0x4e,0x5c,0x19,0x18,0x43,0x4f,0x77,0x68,0x4e,0x5b,0x77,0x7c,0x41,0x6a,0x77,0x68,0x4a,0x5a,0x77,0x1b,0x5a,0x41,0x59,0x68,0x40,0x19,0x18,0x4a,0x68,0x52};

void winner();
void mathIsHard(int *secret, int key);
void feedMe();

int main(int argc, char *argv[])
{
	printf("> %s - Stack Overflow <\n", argv[0]);
	feedMe();
	printf("Try again\n");
	return 0;
}

void feedMe()
{
       	char buffer[BUF_SIZE];
	printf("Feed Me 60 characters\n> ");
	memset(buffer, 0, BUF_SIZE);
	fgets(buffer, GET_SIZE, stdin);
	int z = strlen(buffer);
	if (z >= BUF_SIZE-1) 
		printf("Too many characters\n");
	else if (z == 60)
		winner();
	else
		printf("You entered %d characters\n", z);
        return;
}

void winner()
{
	size_t key = sizeof(SECRET)/sizeof(SECRET[0]);
	mathIsHard(SECRET, key);
	exit(0);
}
