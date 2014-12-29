#pragma once

extern int mystrlen(const char* str1)
{
	int i=0;
	while(str1[i] != '\0')
	{
		i++;
	}
	return i;
}

extern int mystrcmp(const char* str1, const char* str2)
{
	int i=0;
	while(str1[i]!='\0' && str2[i] != '\0' && str1[i] == str2[i])
	{
		i++;
	}
	if(str1[i] == '\0' && str2[i] == '\0')
	{
		return 0;
	}
	return str1[i] < str2[i] ? -1 : 1;
}



extern char* mystrcat(char* dst,const char* src)
{
	int len;
	int i;
	len = mystrlen(dst);
	for (i=0;i<mystrlen(src);i++)
	{
		dst[len+i] = src[i];
	}
	return dst;
}



