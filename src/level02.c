#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "magic.c"

char *SECRET="\x2a\x76\x29\x2a\x42\x67\x29\x28\x6c\x2a\x42\x28\x2d\x42\x78\x29\x7a\x42\x6c\x2d\x67\x42\x67\x29\x28\x42\x2c\x2a\x22";

void winner(void);
void mathIsHard(char *secret);
void feedMe(char *c);

int main(int argc, char *argv[])
{
	char buffer[100];
	printf("> %s - Stack Overflow <\nHint: Feed Me DEADBEEF\n", argv[0]);
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
