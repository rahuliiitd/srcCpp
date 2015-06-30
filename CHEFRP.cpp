#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void produceOutput(int*,int);

int main()
{
        int T,N,*A,i,j;
        cin>>T;
        for (i=0;i<T;i++)
        {
                cin>>N;
                A=new int[N];

                for (j=0;j<N;j++)       //Taking input of A array
                        cin>>A[j];
		
              	produceOutput(A,N);
		cout<<"\n";
		delete A;
		
        }
	return 0;
}

void produceOutput(int *A,int N)
{
	int sum=0,j;
	if (N==1)
	{
		if (A[0]>=2)
			cout<<"2";
		else
			cout<<"-1";
		return;
	}
	
	vector<int> a(A,A+N);
	sort(a.begin(),a.end());
	A=&a[0];
	
	if (A[0]<2)
	{
		cout<<"-1";
		return;
	}
	
	for (j=(N-1);j>0;j--)
		sum+=A[j];
	
	sum+=2;
	cout<<sum;
	return;
}	
