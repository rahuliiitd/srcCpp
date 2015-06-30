#include<iostream>
using namespace std;

int *createMatrix(int,int);
int pathPresent(int*,int,int,int,int);
void insertWall(int *,int,int,int);
int maxCells(int *);

struct node
{
	bool wallL,wallR,wallU,wallD;
	char color;
}

void resetColor(node**);
void insertWall(node**,int,int);
int maxCell(node**);

int main()
{
	int N,M,Q,T,i,j,queryType,x1,x2,y1,y2,sum=0;
	cin>>T;
	for (i=0;i<T;i++)
	{	
		cin>>N>>M>>Q;
		int *a=createMatrix(N,M);
		sum=0;
		for (j=0;j<Q;j++)
		{
			cin>>queryType;
			if (queryType==1 || queryType==2)
			{
				cin>>x1>>y1;
				insertWall(a,queryType,x1,y1);
			}
			else if (queryType==3)
			{
				cin>>x1>>y1>>x2>>y2;
				if (pathPresent(a,x1,y1,x2,y2))
                        	        sum++;
			}
			else
			{
				sum+=maxCells(a);
			}
		}
		cout<<sum;
	}
	return 0;
}

int *createMatrix(int p,int q)
{
	int *k=new int[p*q];
	return k;
}

void insertWall(int *m,int queryType,int x,int y)
{
	if (queryType==1)
	{
		m[x][y]=1;
	}
	else
	{
		m[x][y]=2;
	}
}

int pathPresent(int *m,int x1,int y1,int x2,int y2)
{
	if (x1
}		
