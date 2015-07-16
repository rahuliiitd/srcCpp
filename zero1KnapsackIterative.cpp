#include<iostream>

using namespace std;

void fillBag(int**,int,int,int *,int *,bool**);

int main()
{
	int N,W;
	int i,j;
	cin>>N>>W;
	
	int *Wa=new int[N];
	int *Va=new int[N];
	
	for (i=0;i<N;i++)
	{
		cin>>Wa[i]>>Va[i];
	}
	
	bool **taken=new bool*[N];
	int **res=new int*[N];
	for (i=0;i<N;i++)
	{
		res[i]=new int[W];
		taken[i]=new bool[W];
	}
	
	for (i=0;i<N;i++)
	{
		for (j=0;j<W;j++)
			taken[i][j]=false;
	}
	
	fillBag(res,N,W,Wa,Va,taken);
	return 0;
}

void fillBag(int **res,int N,int W,int *Wa,int *Va,bool **taken)
{
	int i,j,temp;
	for (i=0;i<N;i++)
	{
		for (j=0;j<W;j++)
		{
			if (i==0 || j==0)
				res[i][j]=0;

			else if (Wa[i]<=W && (res[i-1][j]<res[i-1][j-Wa[i]]+Va[i]))
			{
				res[i][j]=res[i-1][j-Wa[i]]+Va[i];
				taken[i][j]=true;
			}			
			else
			{
				res[i][j]=res[i-1][j];
			}
		}
	}
	
	cout<<"\n"<<res[N-1][W-1]<<"\n";
	cout<<"Items Taken :\n";
	temp=W-1;
	for (i=N-1;i>=0;i--)
	{
		if (taken[i][temp])
		{
			cout<<i+1<<" taken\n";
			temp-=Wa[i];
		}
	}	
}
		
		
	
