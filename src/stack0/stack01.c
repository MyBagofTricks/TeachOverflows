#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char *SECRET = "\x46\x17\x78\x48\x14\x14\x54\x78\x4d\x49\x41\x78\x52\x49\x42\x5d\x14\x56\x78\x56\x4f\x42\x16\x46\x53\x78\x10\x52\x16\x41\x78\x17\x4e\x14\x42\x54\x16\x17\x4d";

void winner(void);
void mathIsHard(char *secret);
void feedMe(char *c);

int main(int argc, char *argv[])
{
	char buffer[100];
	printf("Welcome to %s\n\nFeed Me DEADBEEF\n", argv[0]);
        fflush(stdout);
	fgets(buffer, sizeof(buffer), stdin);
	feedMe(buffer);
	printf("Try again\n");
        fflush(stdout);
	return 0;
}

void feedMe(char *c)
{
	char buffer[100];
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
                        if (ch < 97) {
                                ch = ch + 122 - 97 + 1;
                        }
                } else if (ch >= 65 && ch <= 90) {
                        ch = ch - (key%26);
                        if(ch < 65) {
                                ch = ch + 90 - 65 + 1;
                        }
                }
		flag[i] = ch;
                printf("\rFLAG{%s}", flag);
                fflush(stdout);
                usleep(100000);
        }
        printf("\n");
        return;
}
