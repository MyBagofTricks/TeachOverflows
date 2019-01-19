#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "magic.c"

// replace the value for SECRET with the output from the python script
char *SECRET = "\x62\x6b\x2f\x2f\x2b\x68\x47\x28\x6c\x2b\x68\x7c\x29\x28\x6d\x69\x47\x58\x68\x7b\x47\x5c\x6b\x54";

void mathIsHard(char *c);
void feedMe(char *str);
void winner(void);

int main(int argc, char *argv[])
{
        char buffer[200];
	printf("> %s - Stack Overflow < \nHint: Feed Me and call winner()\n", argv[0]);
        fflush(stdout);
	fgets(buffer, sizeof(buffer), stdin);
	feedMe(buffer);
	printf("Try again\n");
        fflush(stdout);
	return 0;
}

void feedMe(char *c)
{
	char buffer[100];
	strcpy(buffer, c);
	return;
}

void winner(void)
{
	mathIsHard(SECRET);
	exit(0);
}

