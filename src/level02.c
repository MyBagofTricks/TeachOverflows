#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "magic.c"
#define BUF_SIZE 100
#define GET_SIZE 100

int SECRET[29] = {0x2a,0x76,0x29,0x2a,0x42,0x67,0x29,0x28,0x6c,0x2a,0x42,0x28,0x2d,0x42,0x78,0x29,0x7a,0x42,0x6c,0x2d,0x67,0x42,0x67,0x29,0x28,0x42,0x2c,0x2a,0x22};

void mathIsHard(int *secret, int key);
void winner();
void feedMe();

int main(int argc, char *argv[])
{
	printf("> %s - Stack Overflow <\n", argv[0]);
	feedMe();
	printf("Try again\n");
	return 0;
}

void feedMe()
{
	printf("Feed me DEADBEEF\n> ");
	char buffer[BUF_SIZE];
	memset(buffer, 0, BUF_SIZE);
	fgets(buffer, GET_SIZE, stdin);
        char *food = "DEADBEEF";
        char buf[9] = "\0";
	if (strlen(buffer) < 64) {
		printf("Not enough letters\n");
	} else {
		strncpy(buf, buffer+(64*sizeof(char)), sizeof(buf)-1);
	        if (!strcmp(buf, food))
	                winner();
	        else
	                printf("Sorry, %s doesn't taste like %s.\n", buf, food);
	}
        return;
}

void winner()
{
        size_t key = sizeof(SECRET)/sizeof(SECRET[0]);
        mathIsHard(SECRET, key);
        exit(0);
}
