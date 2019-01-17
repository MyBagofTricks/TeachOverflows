#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "magic.c"

char *SECRET = "\x58\x41\x1f\x1f\x1b\x4e\x77\x18\x42\x1b\x4e\x5c\x19\x18\x43\x4f\x77\x68\x4e\x5b\x77\x7c\x41\x6a\x77\x68\x4a\x5a\x77\x1b\x5a\x41\x59\x68\x40\x19\x18\x4a\x68\x52";

void winner(void);
void mathIsHard(char *c);
void feedMe(char *c);

int main(int argc, char *argv[])
{
        char buffer[100];
	printf("Welcome to %s\n\nFeed Me More DEADBEEF\n", argv[0]);
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

