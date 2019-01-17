#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "magic.c"

char *SECRET = "\x4f\x13\x54\x53\x42\x49\x40\x47\x56\x63\x40\x12\x13\x54\x41\x7c\x5b\x54\x7c\x4b\x13\x47\x42\x7c\x4c\x12\x42\x41\x40\x7c\x41\x40\x10\x5a\x02";

void winner(void);
void mathIsHard(char *secret);
void feedMe(char *c);

int main(int argc, char *argv[])
{
       	char buffer[100];
	printf("Welcome to %s\n\nFeed Me 60+ of anything\n", argv[0]);
	fflush(stdout);
	fgets(buffer, sizeof(buffer), stdin);
	feedMe(buffer);
	printf("Try again\n");
        fflush(stdout);
	return 0;
}

void feedMe(char *c)
{
	if (strlen(c) < 64)
		printf("Not enough letters\n");
	else
		winner();
        return;
}

void winner(void)
{
	mathIsHard(SECRET);
	exit(0);
}


