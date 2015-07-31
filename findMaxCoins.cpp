#include <iostream>
#include<vector>
using namespace std;

long max(long a,long b)
{
	if (a>b)
		return a;
	return b;
}

int main() 
{
	long T,N,i,j,val;
	vector<long> numCoins;
	vector<long> maxCoins;
	cin>>T;
	for (i=0;i<T;i++)
	{
		cin>>N;
		
		for (j=0;j<N;j++)
		{
			cin>>val;
			numCoins.push_back(val);
		}
		
		for (j=0;j<N;j++)
		{
			if (j==0)
			{
				maxCoins.push_back(numCoins[0]);
			}
			else if (j==1)
			{
				maxCoins.push_back(max(maxCoins[0],numCoins[1]));
			}
			else
			{
				maxCoins.push_back(max(maxCoins[j-2]+numCoins[j],maxCoins[j-1]));
			}
		}
		j--;
		cout<<"Case "<<i+1<<": "<<maxCoins[j]<<"\n";
		numCoins.clear();
		maxCoins.clear();
	}
	return 0;
}
