#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "magic.c"

char *SECRET = "\x03\x59\x5c\x42\x02\x5c\x01\x42\x6d\x03\x5e\x5c\x41\x05\x6d\x54\x4b\x5e\x50\x58\x03\x5e\x57\x6d\x03\x43\x6d\x53\x02\x59\x59\x02\x5e\x6d\x4b\x5e\x50\x6d\x50\x01\x46\x4b\x07\x05\x4b\x05\x03\x5e\x57\x13";

void feedMe(char *str);
void winner();
void mathIsHard(char *c);

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

void winner() {
	mathIsHard(SECRET);
	exit(0);
}
