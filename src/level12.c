#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include "magic.c"

char *SECRET="\x7c\x2f\x2a\x76\x6d\x68\x28\x44\x2a\x2e\x44\x2f\x76\x63\x2f\x61\x2e\x44\x2f\x74\x44\x2b\x6a\x2c\x2a\x2b\x74";


void feedMe(char *str);
void winner();
void fail();
void mathIsHard(char *c);

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
	fflush(stdout);
	fgets(buffer, sizeof(buffer), stdin);
	feedMe(buffer);
	fflush(stdout);
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

void winner() {
	mathIsHard(SECRET);
	exit(0);
}
