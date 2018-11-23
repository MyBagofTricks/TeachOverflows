#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

char *SECRET = "\x56\x17\x46\x17\x7b\x15\x7b\x4f\x7b\x4f\x53\x7b\x46\x14\x5e\x7b\x4d\x14\x41\x7b\x52\x15\x51\x17\x7b\x4f\x7b\x56\x41\x46\x46\x15\x49\x4f\x5c\x17";

void feedMe(char *str);
void winner(int input);
void mathIsHard(char *c);

int main(int argc, char *argv[])
{
	char buffer[64];
	printf("Welcome to %s\n\nFeed Me\n", argv[0]);
        fflush(stdout);
	fgets(buffer, sizeof(buffer), stdin);
	feedMe(buffer);
	printf("Try again\n");
        fflush(stdout);
	return 0;
}

void feedMe(char *input)
{
	char buffer[16];
	strcpy(buffer, input);
	return;
}

void winner(int password)
{
	if (password == 0xCAFEF00D) mathIsHard(SECRET);
	else printf("Not quite\n");
	return;
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
