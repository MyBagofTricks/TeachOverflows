#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "magic.c"

int SECRET[47] = {0x1a,0x47,0x1b,0x1a,0x4c,0x46,0x70,0x4a,0x1f,0x58,0x70,0x1a,0x1f,0x70,0x4e,0x1b,0x42,0x70,0x58,0x5f,0x18,0x70,0x5d,0x1c,0x42,0x1c,0x70,0x4a,0x5f,0x1a,0x18,0x70,0x19,0x1c,0x18,0x18,0x1e,0x46,0x19,0x70,0x1a,0x18,0x1b,0x42,0x18,0x1c,0x56};

void mathIsHard(int *secret, int key);
void feedMe(char *str);
void winner(void);

int main(int argc, char *argv[])
{
	char buffer[200];
	printf("> %s - Stack Overflow <\nHint: Feed Me and call winner()\n", argv[0]);
	fgets(buffer, sizeof(buffer), stdin);
	feedMe(buffer);
	printf("Try again\n");
	return 0;
}

void feedMe(char *str)
{	
	char buffer[80];
	strcpy(buffer, str);
	return;
}

void winner(void)
{
        size_t key = sizeof(SECRET)/sizeof(SECRET[0]);
        mathIsHard(SECRET, key);
        exit(0);
}
