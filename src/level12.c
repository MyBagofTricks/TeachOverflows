#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include "magic.c"

int SECRET[27] = {0x7c,0x2f,0x2a,0x76,0x6d,0x68,0x28,0x44,0x2a,0x2e,0x44,0x2f,0x76,0x63,0x2f,0x61,0x2e,0x44,0x2f,0x74,0x44,0x2b,0x6a,0x2c,0x2a,0x2b,0x74};

void mathIsHard(int *secret, int key);
void feedMe(char *str);
void winner();
void fail();

struct data {
	char name[64];
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
	char buffer[100];
	printf("%s - Heap Overflow <\nHint: Overflow the heap\n", argv[0]);
	fgets(buffer, sizeof(buffer), stdin);
	feedMe(buffer);
	return 0;
}

void feedMe(char *string)
{	
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
