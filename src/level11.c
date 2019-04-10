#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "magic.c"

char *SECRET="\x54\x14\x46\x7b\x13\x56\x14\x11\x17\x7b\x10\x48\x14\x41\x13\x7b\x13\x14\x7b\x46\x14\x5e\x7b\x43\x17\x7b\x11\x10\x52\x41\x13\x17\x7b\x4d\x14\x41";
char string[64];

void feedMe(char *str);
void feedMe2(int password, int password2);
void winner();
void mathIsHard(char *c);

int main(int argc, char *argv[])
{
	char buffer[100];
	printf("> %s - ROP <\nHint: Build the string and call winner\n", argv[0]);
        fflush(stdout);
	fgets(buffer, sizeof(buffer), stdin);
	string[0] = 0;
	feedMe(buffer);
	printf("Try again\n");
        fflush(stdout);
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
	if (!strcmp(string, "magic!"))
		mathIsHard(SECRET);
	return;
}
