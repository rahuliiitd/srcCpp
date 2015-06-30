#include<iostream>
#include<omp.h>
using namespace std;
class matrix
{
	struct node
	{
		bool wallR,wallD;
		char color;
	};
	node *n;
	int N,M,rowSize;
	public:
	matrix(int,int);
	void buildWall(int,int,int);
	bool isReachable(int,int,int,int);
	bool canMove(int,int,int,int);		//Moving to adjacent cells
};

matrix::matrix(int x,int y)
{
	N=x;M=y;
	n=new node[x*y];
	rowSize=sizeof(node)*M;
	for (int i=0;i<x;i++)
	{
		for (int j=0;j<y;j++)
		{
			n[i*sizeof(node)+j].wallR=false;
			n[i*sizeof(node)+j].wallD=false;
			n[i*sizeof(node)+j].color='w';
		}
	}
}

void matrix::buildWall(int op,int x,int y)
{
	x--;y--;
	if (op==1)
	{
		n[x*M+y].wallR=true;
	}
	else
	{
		n[x*M+y].wallD=true;
	}
}

bool matrix::canMove(int x1,int y1,int x2,int y2)	//checks for walls
{
	if (y1<y2 && n[(x1*rowSize)+y1].wallR==false)// && n[(x1*rowSize)+y1])	//moving right
		return true;
	else if (y1>y2 && n[(x1*rowSize)+y2].wallR==false)	//moving left
		return true;
	else if (x1<x2 && n[(x1*rowSize)+y1].wallD==false)	//moving down
		return true;
	else if (x1>x2 && n[(x2*rowSize)+y1].wallD==false)	//moving up
		return true;
	else
		return false;
}
	
bool matrix::isReachable(int x1,int y1,int x2,int y2)
{
	
	x1--;x2--;y1--;y2--;
//	if (x1==0 && y1==0)
//	{
		
		
}


	
int main()
{
	matrix m(3,4);
	return 0;
}	
