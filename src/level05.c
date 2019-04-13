#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "magic.c"

int SECRET[43] = {0x4e,0x1b,0x45,0x74,0x45,0x18,0x42,0x18,0x74,0x1e,0x1c,0x1f,0x42,0x1c,0x1a,0x4e,0x1d,0x74,0x1c,0x1b,0x74,0x1d,0x18,0x1c,0x74,0x1a,0x4e,0x1c,0x1b,0x74,0x1c,0x52,0x18,0x74,0x5c,0x47,0x4e,0x74,0x1e,0x1c,0x47,0x5c,0x5c};

void mathIsHard(int *secret, int key);
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
        size_t key = sizeof(SECRET)/sizeof(SECRET[0]);
        mathIsHard(SECRET, key);
        exit(0);
}
