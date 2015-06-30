#include<iostream>
#include<array>

#define M 10
#define N 20

using namespace std;

int main()
{
	int *A=new int[M*N];
	array<bool,M> row;
	array<bool,N> col;
	row.fill(false);
	col.fill(false);
	for (int i=0;i<M;i++)
	{
		for (int j=0;j<N;j++)
		{	
			if (A[i*N+j]==0)
			{
				row[i]=true;
				col[j]=true;
			}
		}
	}
	for (int i=0;i<M;i++)
	{
		for (int j=0;j<N;j++)
		{
			if (row[i]==true || col[j]==true)
				A[i*N+j]=0;
		}
	}
	
	delete[] A;
	return 0;
}	
