#include<iostream>

using namespace std;

int findKnapsackSol(int N,int W,int *Wa,int *Va)
{
	if (N==0 || W==0)
	{
		return 0;
	}
	
	int val1=findKnapsackSol(N-1,W,Wa,Va);
	int val2=findKnapsackSol(N-1,W-Wa[N],Wa,Va)+Va[N];
	
	if (val1>val2)
		return val1;

	return val2;
}

int main()
{
	int N,W,i,sol;		// N = Number of Items		W = Maximum allowed weight
	cin>>N>>W;
	int *Wa=new int[N];
	int *Va=new int[N];
	
	for (i=0;i<N;i++)
	{
		cin>>Wa[i]>>Va[i];
	}
	
	sol=findKnapsackSol(N-1,W,Wa,Va);
		
	cout<<"\nSolution = "<<sol<<"\n";
	
	return 0;
}


