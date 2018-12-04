#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

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
	printf("Welcome to %s\n\nFeed Me\n", argv[0]);
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

void mathIsHard(char *secret)
{
	int i;
	int key = strlen(secret);
	char flag[255] = {0x20};
	printf("\nYou win! Decrypting...\n");
	for (i = 0; secret[i] != '\0'; i++) {
		char ch;
		ch = secret[i]  ^ key;
		if (ch >= 97 && ch <= 122) {
			ch = ch - (key%26);
			if (ch < 97) 
				ch = ch + 122 - 97 + 1;
		} else if (ch >= 65 && ch <= 90) {
			ch = ch - (key%26);
			if(ch < 65) 
				ch = ch + 90 - 65 + 1;
		}
		flag[i] = ch;
		printf("\rFLAG{%s}", flag);
		fflush(stdout);
		usleep(100000);
	}
	printf("\n");
	fflush(stdout);
	return;
}
