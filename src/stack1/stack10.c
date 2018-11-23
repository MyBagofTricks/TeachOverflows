#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// replace the value for SECRET with the output from the python script
char *SECRET = "\x1e\x42\x1e\x46\x5f\x1a\x4c\x1c\x4a\x57\x72\x1c\x4a\x72\x4b\x1d\x5a\x1e\x46\x59\x1a\x1c\x1d\x4a\x72\x1c\x4a\x5b\x1c\x43\x5a\x1c\x4a\x57\x72\x4b\x1d\x5a\x1e\x46\x59\x1a\x1c\x1d\x4a";


void mathIsHard(char *c);
void feedMe(char *str);
void winner(void);

int main(int argc, char *argv[])
{
        char buffer[200];
	printf("Welcome to %s\n\nFeed Me\n", argv[0]);
	fflush(stdout);
	fgets(buffer, sizeof(buffer), stdin);
	feedMe(buffer);
	printf("Try again\n");
        fflush(stdout);
	return 0;
}

void feedMe(char *c)
{
	volatile int (*fp)();
	char buffer[100];
	char *food = "DEADBEEF";
        char buf[9] = "\0";
	fp = 0;
        strncpy(buf, c+(64*sizeof(char)), sizeof(buf)-1);
        if (strcmp(buf, food)) {
		printf("Sorry, %s doesn't taste like %s.\n", buf, food);
		exit(0);
	} else {
		strcpy(buffer, c);
		if (fp) {
			winner();
			exit(0);
		} else {
			printf("Close, but you didn't overwrite the variable. ");
		}
	}
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
        return;
}
