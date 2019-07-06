#include <stdio.h>
#include <string.h>
#include <unistd.h>

void mathIsHard(int *secret, int key)
{
	char flag[255] = {0x20};
        printf("\nYou win! Decrypting...\n");
        for (int i = 0; secret[i] != '\0'; i++) {
                char ch;
                ch = secret[i]  ^ key;
                if (ch >= 97 && ch <= 122) {
                        ch = ch - (key%26);
                        if (ch < 97) {
                                ch = ch + 122 - 97 + 1;
                        }
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
