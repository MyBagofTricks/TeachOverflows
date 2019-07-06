#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "magic.c"

int SECRET[40] = {0x58,0x41,0x1f,0x1f,0x1b,0x4e,0x77,0x18,0x42,0x1b,0x4e,0x5c,0x19,0x18,0x43,0x4f,0x77,0x68,0x4e,0x5b,0x77,0x7c,0x41,0x6a,0x77,0x68,0x4a,0x5a,0x77,0x1b,0x5a,0x41,0x59,0x68,0x40,0x19,0x18,0x4a,0x68,0x52};

void winner(void);
void mathIsHard(int *secret, int key);
void feedMe(char *c);

int main(int argc, char *argv[])
{
       	char buffer[100];
	printf("> %s - Stack Overflow <\nHint: Feed Me 60 characters\n", argv[0]);
	fgets(buffer, sizeof(buffer), stdin);
	feedMe(buffer);
	printf("Try again\n");
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
	size_t key = sizeof(SECRET)/sizeof(SECRET[0]);
	mathIsHard(SECRET, key);
	exit(0);
}
