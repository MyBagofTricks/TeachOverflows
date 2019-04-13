#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "magic.c"

int SECRET[58] = {0x59,0x54,0xe,0xd,0x65,0x50,0xa,0x65,0x5f,0xa,0x5b,0x65,0x53,0xe,0x48,0x48,0x65,0xe,0x65,0x52,0xa,0xa,0x49,0x9,0x42,0xe,0x4e,0xc,0x65,0xd,0x54,0xe,0xd,0x65,0x50,0xa,0x9,0xf,0x4e,0xd,0x65,0x53,0xa,0x49,0x9,0x65,0x52,0xe,0x53,0x4b,0x5,0xe,0x65,0xf,0xd,0xb,0x53,0x4b};

void mathIsHard(int *secret, int key);
void feedMe(char *str);
void winner();
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

void winner(void)
{
        size_t key = sizeof(SECRET)/sizeof(SECRET[0]);
        mathIsHard(SECRET, key);
        exit(0);
}
