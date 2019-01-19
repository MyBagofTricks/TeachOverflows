#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include "magic.c"

char *SECRET = "\x59\x54\x0c\x0f\x67\x50\x08\x67\x5b\x08\x41\x67\x5f\x0c\x48\x48\x67\x0c\x67\x5e\x08\x08\x49\x0b\x4e\x0c\x4a\x0e\x67\x0f\x54\x0c\x0f\x67\x50\x08\x0b\x0d\x4a\x0f\x67\x4e\x0b\x0f\x41\x4e\x4a\x07\x67\x0c\x67\x0d\x0f\x09\x5f\x57";

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
