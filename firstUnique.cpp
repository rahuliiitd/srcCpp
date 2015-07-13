#include<iostream>
#include<set>

using namespace std;

string findUnique(string);

int main()
{
	string str;
	getline(cin,str);
	string res=findUnique(str);
	cout<<res<<"\n";
	return 0;
}

string findUnique(string str)
{
	int len=str.length();
	int i,j;
	string ret="NULL";
	multiset<char> cset;
	for (i=0;i<len;i++)
	{
		if (str[i]==' ')
			continue;
		
		cset.insert(str[i]);

	}
	
	for (i=0;i<len;i++)
	{
		if (str[i]==' ')
			continue;
		
		if (cset.count(str[i])==1)
		{
			ret=str[i];
			break;
		}
	}

	return ret;
}

				
