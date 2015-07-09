#include<stdio.h>

int add(int x,int y)
{
	return x+y;
}

int main()
{
	const int k=10;
	int *s=&k;
	int a=add(5,3);
	printf("%d",a);
}

