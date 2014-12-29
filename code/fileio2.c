#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS

int main(int argc, char *argv[])
{
	FILE *file4read		= fopen("test1.txt","r");
	FILE *file4write	= fopen("out.txt","w");
	char str[100];
	char str2[100];
	int x;

	if(file4read != 0)
	{
		while(fscanf(file4read,"%s %d%s",str,&x,str2)!=EOF)
			printf("%s %d%s\n",str,x,str2);
		fclose(file4read);
	}
	else
	{
		printf("file does not exist\n");
	}
	return 0;
}