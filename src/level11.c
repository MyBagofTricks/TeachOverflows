#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "magic.c"
#define BUF_SIZE 64
#define GET_SIZE 100

int SECRET[36] = {0x54,0x14,0x46,0x7b,0x13,0x56,0x14,0x11,0x17,0x7b,0x10,0x48,0x14,0x41,0x13,0x7b,0x13,0x14,0x7b,0x46,0x14,0x5e,0x7b,0x43,0x17,0x7b,0x11,0x10,0x52,0x41,0x13,0x17,0x7b,0x4d,0x14,0x41};
char string[64];

void mathIsHard(int *secret, int key);
void feedMe();
void feedMe2(int password, int password2);
void winner();

int main(int argc, char *argv[])
{
	printf("> %s - ROP <\n", argv[0]);
	feedMe();
	printf("Try again\n");
	return 0;
}

void feedMe(char *input)
{
	printf("Build the string and call winner\n> ");
	char buffer[BUF_SIZE];
	memset(buffer, 0, BUF_SIZE);
	fgets(buffer, GET_SIZE, stdin);
	return;
}

void feedMe2(int password, int password2)
{
	if ((password == 0xCAFEF00D) && (password2 == 0xDEADBEEF))
		strncat(string, "magic!", 6);
	return;
}

void winner() {
	if (!strcmp(string, "magic!")) {
		size_t key = sizeof(SECRET)/sizeof(SECRET[0]);
		mathIsHard(SECRET, key);
	}
	exit(0);
}
