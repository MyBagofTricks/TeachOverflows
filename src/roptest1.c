#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void feedMe(void);

int main(int argc, char *argv[])
{
	printf("%s\nROP ME > ", argv[0]);
	feedMe();
	return 0;
}

void feedMe(void)
{
	char buffer[120];
	fgets(buffer, 0x220, stdin);
	printf("Thanks!\n");
	return;
}

