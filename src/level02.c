#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "magic.c"

int SECRET[29] = {0x2a,0x76,0x29,0x2a,0x42,0x67,0x29,0x28,0x6c,0x2a,0x42,0x28,0x2d,0x42,0x78,0x29,0x7a,0x42,0x6c,0x2d,0x67,0x42,0x67,0x29,0x28,0x42,0x2c,0x2a,0x22};

void mathIsHard(int *secret, int key);
void winner(void);
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
        size_t key = sizeof(SECRET)/sizeof(SECRET[0]);
        mathIsHard(SECRET, key);
        exit(0);
}
