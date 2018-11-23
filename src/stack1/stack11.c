#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// replace the value for SECRET with the output from the python script
char *SECRET = "\x62\x6b\x2f\x2f\x2b\x68\x47\x28\x6c\x2b\x68\x7c\x29\x28\x6d\x69\x47\x58\x68\x7b\x47\x5c\x6b\x54";

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
	char buffer[100];
	strcpy(buffer, c);
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
