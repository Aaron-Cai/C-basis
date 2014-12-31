#include "mystrfunc.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	char mystr[100] = "Hello world!";
	char* str2 = "Weclome";
	printf("%d\n",mystrlen(mystr) );
	printf("%d\n",mystrlen(str2) );
	printf("%d\n",mystrcmp(mystr,str2) );
	printf("%s\n",mystrcat(mystr,str2) );
	return 0;
}

