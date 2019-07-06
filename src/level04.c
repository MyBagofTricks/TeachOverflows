#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "magic.c"

int SECRET[45] = {0x1e,0x42,0x1e,0x46,0x5f,0x1a,0x4c,0x1c,0x4a,0x1b,0x72,0x1c,0x4a,0x72,0x4b,0x1d,0x5a,0x1e,0x46,0x19,0x1a,0x1c,0x1d,0x4a,0x72,0x1c,0x4a,0x5b,0x48,0x43,0x5a,0x1c,0x4a,0x1b,0x72,0x4b,0x1d,0x5a,0x1e,0x46,0x19,0x1a,0x1c,0x1d,0x4a};

void mathIsHard(int *secret, int key);
void feedMe(char *str);
void winner(void);

int main(int argc, char *argv[])
{
        char buffer[200];
	printf("> %s - Stack Overflow <\nHint: Feed Me and overflow the variable\n", argv[0]);
	fgets(buffer, sizeof(buffer), stdin);
	feedMe(buffer);
	printf("Try again\n");
	return 0;
}

void feedMe(char *c)
{
	volatile int (*changeMe)() = 0;
	char buffer[100];
	char *food = "DEADBEEF";
        char buf[9] = "\0";
        strncpy(buf, c+(64*sizeof(char)), sizeof(buf)-1);
        if (strcmp(buf, food)) {
		printf("Sorry, %s doesn't taste like %s.\n", buf, food);
		exit(0);
	} else {
		strcpy(buffer, c);
		if (changeMe) {
			winner();
			exit(0);
		} else {
			printf("Close, but you didn't overwrite the variable. ");
		}
	}
}

void winner(void)
{
        size_t key = sizeof(SECRET)/sizeof(SECRET[0]);
        mathIsHard(SECRET, key);
        exit(0);
}
