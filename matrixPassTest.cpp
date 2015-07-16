#include<iostream>

using namespace std;

void changeToFive(int **,int,int);

int main()
{
	int **ar,i;
	ar=new int*[5];
	for (i=0;i<5;i++)
		ar[i]=new int[5];
	
	changeToFive(ar,5,5);
	
	ar[3][4]=10;
	for (int i=0;i<5;i++)
	{
		for (int j=0;j<5;j++)
		{
			cout<<ar[i][j]<<" ";
		}
		cout<<"\n";
	}

		
	return 0;
}

void changeToFive(int **ar,int r,int c)
{
	for (int i=0;i<r;i++)
	{
		for (int j=0;j<c;j++)
			ar[i][j]=5;
	}
}
