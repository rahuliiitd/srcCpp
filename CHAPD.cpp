#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

void printResult(long long,long long);
vector<long long> first1000Primes();

int main()
{
	int T,i;
	long long A,B;
	cin>>T;
	for (i=0;i<T;i++)
	{
		cin>>A>>B;
		printResult(A,B);
	}
	return 0;
}

vector<long long> first1000Primes()
{ 	
void printResult(long long A,long long B)
{
	long long i,prev=0,b=B;
	vector<long long> pfactors;
	cout<<b;
	if (b%2==0)
	{
		pfactors.push_back(2);
		
		while (b%2==0)
		{
			b=b/2;
		}
//		cout<<"tempB="<<tempB<<"\n";
	}
	
	i=3;
	while (b!=1)
	{		//cout<<"b="<<b<<"\n";
			while (b%i==0)
			{
				cout<<i<<"\n";
				b=b/i;
			//	cout<<"\ni="<<i;
				if (prev!=i)
					pfactors.push_back(i);
				prev=i;
			}
	//	cout<<"Check i="<<i<<"\n";
		
		i+=2;
	}
//	cout<<"check 0\n";	
	
	if (pfactors.empty())
	{
	//	cout<<"B is prime\n";
	
		if (A%B==0)
			cout<<"Yes\n";
		else
			cout<<"No\n";
		return;
	}
	
	//cout<<"\n";
	for (vector<long long>::iterator k=pfactors.begin();k!=pfactors.end();k++)
	{
		//cout<<(*k)<<" ";
		if (A%(*k)!=0)
		{
			cout<<"No\n";
			return;
		}
	}		
		
	cout<<"Yes\n";
		
}		
