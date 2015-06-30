#include<iostream>
#include<string>

using namespace std;

int main()
{
	string s;
	cin>>s;
	int len=s.length(),i;
	for (i=0;i<len;i++)
		cout<<(int)s[i]<<" ";
	return 0;
}		
