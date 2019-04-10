#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "magic.c"

char *SECRET="\x1a\x47\x1b\x1a\x4c\x46\x70\x4a\x1f\x58\x70\x1a\x1f\x70\x4e\x1b\x42\x70\x58\x5f\x18\x70\x5d\x1c\x42\x1c\x70\x4a\x5f\x1a\x18\x70\x19\x1c\x18\x18\x1e\x46\x19\x70\x1a\x18\x1b\x42\x18\x1c\x56";

void mathIsHard(char *c);
void feedMe(char *str);
void winner(void);

int main(int argc, char *argv[])
{
	char buffer[200];
	printf("> %s - Stack Overflow <\nHint: Feed Me and call winner()\n", argv[0]);
        fflush(stdout);
	fgets(buffer, sizeof(buffer), stdin);
	feedMe(buffer);
	printf("Try again\n");
        fflush(stdout);
	return 0;
}

void feedMe(char *str)
{	
	char buffer[80];
	if(strchr(str, 0x41) != NULL) {
			printf("Denied! Don't be so predictable\n");
			exit(0);
	}
	strcpy(buffer, str);
	return;
}

void winner(void)
{
	mathIsHard(SECRET);
	exit(0);
}

