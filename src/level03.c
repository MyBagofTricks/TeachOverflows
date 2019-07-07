#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "magic.c"
#define BUF_SIZE 100
#define GET_SIZE 100

int SECRET[58] = {0x4e,0xa,0x65,0x53,0xa,0x59,0xf,0x65,0xa,0x42,0x65,0x53,0xa,0x53,0xa,0x65,0x59,0x9,0x42,0x9,0x65,0x54,0xe,0x42,0x49,0x9,0x50,0x65,0xb,0x4e,0x65,0xd,0x54,0x9,0x65,0x49,0xe,0x4b,0xb,0x4e,0xc,0x65,0xa,0x56,0x65,0xd,0x54,0xb,0xf,0x65,0x9,0x5e,0x9,0x42,0x53,0xb,0xf,0x9};

void winner();
void mathIsHard(int *secret, int key);
void feedMe();

int main(int argc, char *argv[])
{
	printf("> %s - Stack Overflow <\n", argv[0]);
	feedMe();
	printf("Try again\n");
	return 0;
}

void feedMe()
{
        char buffer[BUF_SIZE];
	printf("Feed Me DEADBEEF & 1CEDC0C0\n> ");
	fgets(buffer, GET_SIZE, stdin);
	char *food = "DEADBEEF";
	char *drink = "1CEDC0C0";
	char buf[9] = "\0";
	if (strlen(buffer) < 88) {
                printf("Not enough characters\n");
	} else {
		strncpy(buf, buffer+(64*sizeof(char)), sizeof(buf)-1);
		if (!strcmp(buf, food)) {
			strncpy(buf, buffer+(80*sizeof(char)), sizeof(buf)-1);
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

void winner()
{
        size_t key = sizeof(SECRET)/sizeof(SECRET[0]);
        mathIsHard(SECRET, key);
        exit(0);
}
