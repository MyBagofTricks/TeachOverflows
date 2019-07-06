#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "magic.c"

int SECRET[36] = {0x54,0x14,0x46,0x7b,0x13,0x56,0x14,0x11,0x17,0x7b,0x10,0x48,0x14,0x41,0x13,0x7b,0x13,0x14,0x7b,0x46,0x14,0x5e,0x7b,0x43,0x17,0x7b,0x11,0x10,0x52,0x41,0x13,0x17,0x7b,0x4d,0x14,0x41};
char string[64];

void mathIsHard(int *secret, int key);
void feedMe(char *str);
void feedMe2(int password, int password2);
void winner();

int main(int argc, char *argv[])
{
	char buffer[100];
	printf("> %s - ROP <\nHint: Build the string and call winner\n", argv[0]);
	fgets(buffer, sizeof(buffer), stdin);
	string[0] = 0;
	feedMe(buffer);
	printf("Try again\n");
	return 0;
}

void feedMe(char *input)
{
	char buffer[64];
	strcpy(buffer, input);
	return;
}

void feedMe2(int password, int password2)
{
	if ((password == 0xCAFEF00D) && (password2 == 0xDEADBEEF))
		strncat(string, "magic!", 6);
}

void winner() {
	if (!strcmp(string, "magic!")) {
		size_t key = sizeof(SECRET)/sizeof(SECRET[0]);
		mathIsHard(SECRET, key);
	}
	exit(0);
}
