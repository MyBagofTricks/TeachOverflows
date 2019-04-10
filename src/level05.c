#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "magic.c"

char *SECRET="\x4e\x1b\x45\x74\x45\x18\x42\x18\x74\x1e\x1c\x1f\x42\x1c\x1a\x4e\x1d\x74\x1c\x1b\x74\x1d\x18\x1c\x74\x1a\x4e\x1c\x1b\x74\x1c\x52\x18\x74\x5c\x47\x4e\x74\x1e\x1c\x47\x5c\x5c";

void mathIsHard(char *c);
void feedMe(char *str);
void winner(void);

int main(int argc, char *argv[])
{
        char buffer[200];
	printf("> %s - Stack Overflow < \nHint: Feed Me and call winner()\n", argv[0]);
        fflush(stdout);
	fgets(buffer, sizeof(buffer), stdin);
	feedMe(buffer);
	printf("Try again\n");
        fflush(stdout);
	return 0;
}

void feedMe(char *c)
{
	char buffer[100];
	strcpy(buffer, c);
	return;
}

void winner(void)
{
	mathIsHard(SECRET);
	exit(0);
}

