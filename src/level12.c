#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include "magic.c"
#define BUF_SIZE 64
#define GET_SIZE 100

int SECRET[27] = {0x7c,0x2f,0x2a,0x76,0x6d,0x68,0x28,0x44,0x2a,0x2e,0x44,0x2f,0x76,0x63,0x2f,0x61,0x2e,0x44,0x2f,0x74,0x44,0x2b,0x6a,0x2c,0x2a,0x2b,0x74};

void mathIsHard(int *secret, int key);
void feedMe();
void winner();
void fail();

struct data {
	char name[BUF_SIZE];
};

struct ptr {
	int (*fp)();
};


void fail() {
	printf("Try again\n");
	return;
}

int main(int argc, char *argv[])
{
	printf("%s - Heap Overflow <\n", argv[0]);
	feedMe();
	return 0;
}

void feedMe(char *string)
{	
	printf("Overflow the heap\n> ");
	char buffer[BUF_SIZE];
	memset(buffer, 0, BUF_SIZE); 
	fgets(buffer, GET_SIZE, stdin);
	struct data *d;
	struct ptr *f;
	d = malloc(sizeof(struct data));
	f = malloc(sizeof(struct ptr));
	f->fp = fail;
	strcpy(d->name, string);
	f->fp();
	return;
}

void winner(void)
{
        size_t key = sizeof(SECRET)/sizeof(SECRET[0]);
        mathIsHard(SECRET, key);
        exit(0);
}
