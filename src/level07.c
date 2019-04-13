#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "magic.c"

int SECRET[45] = {0x5a,0x1c,0x5a,0x72,0x5f,0x1d,0x43,0x72,0x4c,0x1e,0x19,0x46,0x72,0x1a,0x4c,0x1e,0x72,0x4e,0x1d,0x49,0x1e,0x72,0x19,0x58,0x1d,0x43,0x1a,0x72,0x43,0x5a,0x44,0x12,0x4a,0x42,0x4b,0x72,0x5a,0x1d,0x4a,0x1a,0x72,0x5b,0x19,0x46,0x1e};

void mathIsHard(int *secret, int key);
void feedMe(char *str);
void winner();

int main(int argc, char *argv[])
{
	char buffer[10];
	printf("> %s - Format String <\nHint: Overwrite changeMe with 0xcafef00d\n", argv[0]);
	fflush(stdout);
	fgets(buffer, sizeof(buffer), stdin);
	feedMe(buffer);
	printf("Try again\n");
	fflush(stdout);
	return 0;
}

void feedMe(char *string)
{
	volatile int changeMe;
	char buffer[16];
	changeMe = 0;
	sprintf(buffer, string);
	puts(buffer);
	if(changeMe == 0xcafef00d)
		winner();
}

void winner(void)
{
        size_t key = sizeof(SECRET)/sizeof(SECRET[0]);
        mathIsHard(SECRET, key);
        exit(0);
}
