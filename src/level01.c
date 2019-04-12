#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "magic.c"

char *SECRET="\x60\x7e\x71\x70\x73\x72\x75\x74\x77\x76\x79\x78\x0f\x0e\x11\x10\x13\x12\x15\x14\x17\x16\x19\x18\x1b\x00\x03\x02\x05\x04\x07\x06\x09\x08\x0b\x0a\x0d\x0c\x1e\x2f\x2e\x31\x30\x33\x32\x35\x34\x37\x36\x39\x38\x3b\x20\x23\x22\x25\x24\x27\x26\x29\x28\x2b\x2a\x2d\x2c";

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


