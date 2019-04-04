#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "magic.c"

char *SECRET="\x06\x68\x4d\x07\x4f\x58\x50\x68\x47\x03\x59\x04\x68\x03\x68\x4f\x50\x44\x68\x5a\x07\x59\x04\x68\x52\x4f\x00\x68\x06\x68\x50\x07\x46\x00\x68\x59\x46\x07\x4d\x68\x06\x5e\x68\x55\x07\x4f\x58\x58\x68\x01\x04\x00\x68\x06\x00";

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
