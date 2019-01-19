#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "magic.c"

char *SECRET = "\x4d\x1c\x40\x70\x4c\x5f\x46\x4d\x42\x5b\x70\x1b\x46\x56\x70\x4d\x1c\x18\x70\x59\x18\x70\x1e\x18\x70\x58\x1c\x57\x1b\x5f\x41\x1a\x1c\x70\x48\x1e\x4e\x1c\x70\x1e\x1a\x70\x1a\x4c\x1f\x42\x18";
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
