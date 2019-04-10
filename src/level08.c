#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "magic.c"

char *SECRET="\x59\x54\x0e\x0d\x65\x50\x0a\x65\x5f\x0a\x5b\x65\x53\x0e\x48\x48\x65\x0e\x65\x52\x0a\x0a\x49\x09\x42\x0e\x4e\x0c\x65\x0d\x54\x0e\x0d\x65\x50\x0a\x09\x0f\x4e\x0d\x65\x53\x0a\x49\x09\x65\x52\x0e\x53\x4b\x05\x0e\x65\x0f\x0d\x0b\x53\x4b";

void feedMe(char *str);
void winner();
void mathIsHard(char *c);
int changeMe;


int main(int argc, char *argv[])
{
	char buffer[100];
	printf("> %s - Format String <\nHint: Overwrite changeMe with 512\n", argv[0]);
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
	if(changeMe == 512) 
		winner();
	else 
		printf("changeMe is: %d\n", changeMe);
	return;
}

void winner() {
	mathIsHard(SECRET);
	exit(0);
}
