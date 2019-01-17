#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "magic.c"

char *SECRET = "\x61\x44\x58\x5f\x5a\x40\x53\x46\x7f\x40\x7f\x5a\x40\x45\x77\x60\x5c\x45\x43\x41\x57\x5a\x50\x64\x5f\x53\x51\x53\x41\x77\x5a\x50\x61\x51\x57\x40\x40\x53\x46\x7f\x40\x7f\x5a\x40\x45\x60\x5c\x53\x6d\x5f\x5a\x50\x41";

void feedMe(char *str);
void winner();
void mathIsHard(char *c);
int changeMe;


int main(int argc, char *argv[])
{
	char buffer[100];
	printf("Welcome to %s\n\nFeed Me\n", argv[0]);
	fflush(stdout);
	fgets(buffer, sizeof(buffer), stdin);
	feedMe(buffer);
	printf("Try again\n");
	fflush(stdout);
	return 0;
}

void feedMe(char *string)
{
	printf(string);
	if(changeMe == 0xcafef00d)
		winner();
	else
		printf("changeMe is: %d\n", changeMe);
	return;
}

void winner() {
	mathIsHard(SECRET);
	exit(0);
}
