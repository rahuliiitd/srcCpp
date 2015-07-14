#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char *str=malloc(sizeof(char));		//even int was working
	strcpy(str,"My name is Rahul Sharma. I am a student at IIIT-Delhi");
	printf("%s",str);
	return 0;
}

