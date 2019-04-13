#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "magic.c"


char *SECRET="\x58\x41\x1f\x1f\x1b\x4e\x77\x18\x42\x1b\x4e\x5c\x19\x18\x43\x4f\x77\x68\x4e\x5b\x77\x7c\x41\x6a\x77\x68\x4a\x5a\x77\x1b\x5a\x41\x59\x68\x40\x19\x18\x4a\x68\x52";



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


