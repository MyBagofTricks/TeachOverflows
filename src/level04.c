#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "magic.c"
#define BUF_SIZE 100 
#define GET_SIZE 120

int SECRET[45] = {0x1e,0x42,0x1e,0x46,0x5f,0x1a,0x4c,0x1c,0x4a,0x1b,0x72,0x1c,0x4a,0x72,0x4b,0x1d,0x5a,0x1e,0x46,0x19,0x1a,0x1c,0x1d,0x4a,0x72,0x1c,0x4a,0x5b,0x48,0x43,0x5a,0x1c,0x4a,0x1b,0x72,0x4b,0x1d,0x5a,0x1e,0x46,0x19,0x1a,0x1c,0x1d,0x4a};

void mathIsHard(int *secret, int key);
void feedMe();
void winner();

int main(int argc, char *argv[])
{
	printf("> %s - Stack Overflow <\n", argv[0]);
	feedMe();
	printf("Try again\n");
	return 0;
}

void feedMe()
{
	printf("Feed Me and overflow the variable\n> ");
	volatile int (*changeMe)() = 0;
        char buffer[BUF_SIZE];
	memset(buffer, 0, BUF_SIZE);
	fgets(buffer, GET_SIZE, stdin);
	char *food = "DEADBEEF";
        char buf[9] = "\0";
        strncpy(buf, buffer+(64*sizeof(char)), sizeof(buf)-1);
        if (strcmp(buf, food)) {
		printf("Sorry, %s doesn't taste like %s.\n", buf, food);
		exit(0);
	} else {
		if (changeMe) {
			winner();
			exit(0);
		} else {
			printf("Close, but you didn't overwrite the variable. ");
		}
	}
}

void winner(void)
{
        size_t key = sizeof(SECRET)/sizeof(SECRET[0]);
        mathIsHard(SECRET, key);
        exit(0);
}
