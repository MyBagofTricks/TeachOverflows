#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "magic.c"

char *SECRET = "\x46\x17\x78\x48\x14\x14\x54\x78\x4d\x49\x41\x78\x52\x49\x42\x5d\x14\x56\x78\x56\x4f\x42\x16\x46\x53\x78\x10\x52\x16\x41\x78\x17\x4e\x14\x42\x54\x16\x17\x4d";

void winner(void);
void mathIsHard(char *secret);
void feedMe(char *c);

int main(int argc, char *argv[])
{
	char buffer[100];
	printf("Welcome to %s\n\nFeed Me DEADBEEF\n", argv[0]);
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
        char buf[9] = "\0";
	if (strlen(c) < 64) {
		printf("Not enough letters\n");
	} else {
		strncpy(buf, c+(64*sizeof(char)), sizeof(buf)-1);
	        if (!strcmp(buf, food))
	                winner();
	        else
	                printf("Sorry, %s doesn't taste like %s.\n", buf, food);
	}
        return;
}

void winner(void)
{
	mathIsHard(SECRET);
	exit(0);
}
