#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "magic.c"

char *SECRET="\x58\x41\x5c\x5c\x1b\x4e\x77\x18\x42\x1b\x4e\x5c\x52\x18\x43\x1d\x77\x1c\x4e\x1b\x77\x5c\x41\x4a\x77\x1c\x4a\x5a\x77\x1b\x5a\x41\x59\x1c\x1f\x19\x18\x4a\x1c\x52";

void winner(void);
void mathIsHard(char *secret);
void feedMe(char *c);

int main(int argc, char *argv[])
{
       	char buffer[100];
	printf("> %s - Stack Overflow <\nHint: Feed Me 60 characters\n", argv[0]);
	fflush(stdout);
	fgets(buffer, sizeof(buffer), stdin);
	feedMe(buffer);
	printf("Try again\n");
        fflush(stdout);
	return 0;
}

void feedMe(char *c)
{
	int z = strlen(c);
	if (z != 60)
		printf("You entered %d characters\n", z);
	else
		winner();
        return;
}

void winner(void)
{
	mathIsHard(SECRET);
	exit(0);
}


