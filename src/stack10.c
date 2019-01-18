#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "magic.c"

// replace the value for SECRET with the output from the python script
char *SECRET = "\x1e\x42\x1e\x46\x5f\x1a\x4c\x1c\x4a\x57\x72\x1c\x4a\x72\x4b\x1d\x5a\x1e\x46\x59\x1a\x1c\x1d\x4a\x72\x1c\x4a\x5b\x1c\x43\x5a\x1c\x4a\x57\x72\x4b\x1d\x5a\x1e\x46\x59\x1a\x1c\x1d\x4a";


void mathIsHard(char *c);
void feedMe(char *str);
void winner(void);

int main(int argc, char *argv[])
{
        char buffer[200];
	printf("Welcome to %s\n\nFeed Me\n", argv[0]);
	fflush(stdout);
	fgets(buffer, sizeof(buffer), stdin);
	feedMe(buffer);
	printf("Try again\n");
        fflush(stdout);
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
	mathIsHard(SECRET);
	exit(0);
}
