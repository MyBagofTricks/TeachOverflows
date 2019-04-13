#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "magic.c"

int SECRET[58] = {0x4e,0xa,0x65,0x53,0xa,0x59,0xf,0x65,0xa,0x42,0x65,0x53,0xa,0x53,0xa,0x65,0x59,0x9,0x42,0x9,0x65,0x54,0xe,0x42,0x49,0x9,0x50,0x65,0xb,0x4e,0x65,0xd,0x54,0x9,0x65,0x49,0xe,0x4b,0xb,0x4e,0xc,0x65,0xa,0x56,0x65,0xd,0x54,0xb,0xf,0x65,0x9,0x5e,0x9,0x42,0x53,0xb,0xf,0x9};

void winner(void);
void mathIsHard(int *secret, int key);
void feedMe(char *c);

int main(int argc, char *argv[])
{
        char buffer[100];
	printf("> %s - Stack Overflow <\nHint: Feed Me DEADBEEF & 1CEDC0C0\n", argv[0]);
        fflush(stdout);
	fgets(buffer, sizeof(buffer), stdin);
	feedMe(buffer);
	printf("Try again\n");
        fflush(stdout);
	return 0;
}

void feedMe(char *c)
{
	char *food = "DEADBEEF";
	char *drink = "1CEDC0C0";
	char buf[9] = "\0";
	if (strlen(c) < 88) {
                printf("Not enough letters\n");
		exit(0);
	} else {
		strncpy(buf, c+(64*sizeof(char)), sizeof(buf)-1);
		if (!strcmp(buf, food)) {
			strncpy(buf, c+(80*sizeof(char)), sizeof(buf)-1);
			if (!strcmp(buf, drink)) {
					winner();
			} else {
				printf("I'm thirsty, but %s tastes nothing like %s\n", buf, drink);
			}
		} else {
			printf("Sorry, %s doesn't taste like %s.\n", buf, food);
		}
	}
	return;
}

void winner(void)
{
        size_t key = sizeof(SECRET)/sizeof(SECRET[0]);
        mathIsHard(SECRET, key);
        exit(0);
}
