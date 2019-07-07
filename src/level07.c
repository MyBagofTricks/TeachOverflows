#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "magic.c"
#define BUF_SIZE 16
#define GET_SIZE 10 


int SECRET[47] = {0x1e,0x5e,0x55,0x70,0x19,0x1f,0x18,0x70,0x1b,0x70,0x70,0x5f,0x56,0x44,0x70,0x4a,0x1f,0x49,0x55,0x70,0x58,0x5f,0x18,0x70,0x1e,0x47,0x70,0x46,0x1f,0x18,0x70,0x1a,0x5f,0x42,0x1c,0x70,0x5b,0x1f,0x5f,0x56,0x70,0x19,0x1c,0x18,0x70,0x1e,0x18};

void mathIsHard(int *secret, int key);
void feedMe();
void winner();

int main(int argc, char *argv[])
{
	printf("> %s - Format String <\n", argv[0]);
	feedMe();
	printf("Try again\n");
	return 0;
}

void feedMe()
{
	printf("Overwrite changeMe with 0xcafef00d.\nKeep the payload under 9 bytes\n> ");
	volatile int changeMe;
	char buffer[BUF_SIZE];
	char getBuffer[GET_SIZE];
	fgets(getBuffer, GET_SIZE, stdin);
	changeMe = 0;
	sprintf(buffer, getBuffer);
	puts(buffer);
	if(changeMe == 0xcafef00d)
		winner();
}

void winner(void)
{
        size_t key = sizeof(SECRET)/sizeof(SECRET[0]);
        mathIsHard(SECRET, key);
        exit(0);
}
