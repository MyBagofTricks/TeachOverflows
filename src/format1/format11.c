#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

char *SECRET = "\x4c\x5b\x5e\x1d\x71\x5d\x1e\x41\x71\x4c\x1d\x5b\x42\x56\x71\x40\x4c\x1d\x71\x41\x56\x44\x71\x4a\x1e\x4b\x1d\x11\x1f\x56\x4b\x71\x1f\x54\x71\x5d\x1e\x41\x56\x71\x4f\x1d\x19\x71\x1f\x19";

void feedMe(char *str);
void winner();
void mathIsHard(char *c);
int changeMe;


int main(int argc, char *argv[])
{
	char buffer[100];
	printf("Welcome to %s\n\nFeed Me\n", argv[0]);
	fflush(stdout);
	fgets(buffer, sizeof(buffer), stdin);
	feedMe(buffer);
	printf("Try again\n");
	fflush(stdout);
	return 0;
}

void feedMe(char *string)
{
	printf(string);
	if(changeMe == 512) 
		winner();
	else 
		printf("changeMe is: %d\n", changeMe);
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
