#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "magic.c"

char *SECRET="\x4e\x0a\x65\x53\x0a\x59\x0f\x65\x0a\x42\x65\x53\x0a\x48\x0e\x65\x59\x09\x42\x09\x65\x54\x0e\x42\x49\x09\x50\x65\x0b\x4e\x65\x0d\x54\x09\x65\x49\x0e\x4b\x0b\x4e\x0c\x65\x0a\x56\x65\x0d\x54\x0b\x0f\x65\x09\x5e\x09\x42\x53\x0b\x0f\x09";

void winner(void);
void mathIsHard(char *c);
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
	mathIsHard(SECRET);
	return;
}

