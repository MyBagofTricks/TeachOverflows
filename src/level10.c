#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "magic.c"

int SECRET[36] = {0x56,0x17,0x46,0x17,0x7b,0x15,0x7b,0x10,0x53,0xa,0xa,0xa,0x46,0x14,0x5e,0x7b,0x4d,0x14,0x41,0x7b,0x52,0x15,0x51,0x17,0x7b,0x10,0x7b,0x56,0x41,0x46,0x46,0x15,0x49,0x10,0x5c,0x17};

void mathIsHard(int *secret, int key);
void feedMe(char *str);
void winner(int input);

int main(int argc, char *argv[])
{
	char buffer[64];
	printf("> %s - ROP <\nHint: Call winner with the correct password\n", argv[0]);
        fflush(stdout);
	fgets(buffer, sizeof(buffer), stdin);
	feedMe(buffer);
	printf("Try again\n");
        fflush(stdout);
	return 0;
}

void feedMe(char *input)
{
	char buffer[16];
	strcpy(buffer, input);
	return;
}

void winner(int password)
{
	if (password == 0xCAFEF00D) {
		size_t key = sizeof(SECRET)/sizeof(SECRET[0]);
		mathIsHard(SECRET, key);
	} else {
		printf("Not quite\n");
	}
	exit(0);
}
