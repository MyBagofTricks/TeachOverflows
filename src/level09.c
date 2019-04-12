#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "magic.c"

char *SECRET="\x5f\x4c\x1e\x1d\x5e\x1d\x42\x71\x59\x1e\x46\x19\x42\x1e\x48\x1b\x71\x19\x4c\x1d\x71\x1b\x19\x1a\x59\x4b\x71\x59\x1e\x46\x19\x42\x1e\x48\x1b\x71\x19\x4c\x1d\x71\x54\x41\x19\x41\x42\x1d";

void feedMe(char *str);
void winner();
void mathIsHard(char *c);
int changeMe;


int main(int argc, char *argv[])
{
	char buffer[100];
	printf("%s - Format String <\nHint: Overwrite changeMe with 0xcafef00d\n", argv[0]);
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
		printf("changeMe is:0x%x\n", changeMe);
	return;
}

void winner() {
	mathIsHard(SECRET);
	exit(0);
}
