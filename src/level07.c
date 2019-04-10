#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "magic.c"

char *SECRET="\x5a\x1c\x5a\x72\x5f\x1d\x43\x72\x4c\x1e\x19\x46\x72\x1a\x4c\x1e\x72\x4e\x1d\x49\x1e\x72\x19\x58\x1d\x43\x1a\x72\x43\x5a\x44\x12\x4a\x42\x4b\x72\x5a\x1d\x4a\x1a\x72\x5b\x19\x46\x1e";

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
