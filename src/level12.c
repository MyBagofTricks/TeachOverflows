#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include "magic.c"

char *SECRET="\x02\x07\x42\x06\x00\x04\x02\x68\x44\x03\x42\x03\x50\x07\x56\x68\x4d\x03\x02\x68\x03\x68\x5e\x03\x06\x58\x4f\x42\x04\x68\x00\x07\x68\x52\x42\x04\x03\x59\x68\x50\x07\x4d\x46\x68\x00\x5c\x04\x68\x44\x42\x07\x52\x58\x04\x47";

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
