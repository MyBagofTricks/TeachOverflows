#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "magic.c"

// replace the value for SECRET with the output from the python script
char *SECRET = "\x07\x59\x4b\x07\x54\x03\x5e\x57\x6d\x5a\x02\x48\x6d\x43\x02\x6d\x56\x4b\x42\x6d\x48\x41\x40\x6d\x47\x01\x42\x01\x6d\x5a\x41\x43\x05\x6d\x57\x01\x40\x40\x03\x5e\x57\x6d\x43\x05\x4b\x42\x05\x01\x50\x13";

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

