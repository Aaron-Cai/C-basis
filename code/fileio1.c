#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int main(int argc, char* argv[])
{
	if(argc != 3)
	{
		printf("usage: %s plaintext outfile\n",argv[0]);
	}
	else
	{
		FILE *plaintext		= fopen(argv[1],"r");
		FILE *ciphertext	= fopen(argv[2],"w");
		char str[100];
		int x;
		char key = 't';
		if(plaintext == 0)
		{
			printf("The input file does not exist, please check the file name of plaintext file\n");
			return -1;
		}
		printf("encrypting...\n");
		while((x = fgetc(plaintext)) != EOF)
		{
			if(x - 'a' >=0 && x - 'a'<26)
			{
				int x1 = (x - 'a' +  key - 'a' ) % 26 + 'a';
				fputc(x1,ciphertext);
			}
			else if(x - 'A'>=0 && x - 'A'<26)
			{
				int x1 = (x - 'A' +  key - 'A' ) % 26 + 'A';
				fputc(x1,ciphertext);
			}
			else
			{
				fputc(x,ciphertext);
			}
		}
		printf("encrypting done.\n");
		fclose(plaintext);
		fclose(ciphertext);
	}
	return 0;
}