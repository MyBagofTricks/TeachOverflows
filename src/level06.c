#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "magic.c"

char *SECRET="\x04\x5b\x05\x04\x54\x00\x5a\x07\x6e\x56\x01\x48\x6e\x04\x01\x6e\x52\x05\x5e\x6e\x48\x43\x06\x6e\x45\x02\x5e\x02\x6e\x56\x43\x04\x06\x6e\x07\x02\x06\x06\x00\x5a\x07\x6e\x04\x06\x05\x5e\x06\x02\x50";

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

