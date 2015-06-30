#include<string.h>
#include<stdio.h>

#define LEN 20

int main()
{
	char c[LEN],temp;
	printf("Enter String ");
	scanf("%s",c);
	int len=strlen(c);
	int i=0,hlen=len/2;
	
	for(;i<hlen;i++)
	{
		temp=c[i];
		c[i]=c[--len];
		c[len]=temp;
	}

	printf("\n%s",c);
	return 0;
}
