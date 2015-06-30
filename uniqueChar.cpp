#include<iostream>
#include<map>
#include<vector>
#include<iterator>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<cstring>
#include<ctype.h>

using namespace std;

struct func
{
	bool operator() (char x,char y)
	{
		return (((int)x)>((int)y));
	}
}ob;

int main()
{

	/*unordered_multimap<int,string> m;
	m.insert(make_pair(1,"Rahul"));
	m.insert(make_pair(2,"Richa"));
	m.insert(make_pair(2,"Paree"));
	pair<unordered_multimap<int,string>::iterator,unordered_multimap<int,string>::iterator> p;
	p=m.equal_range(2);
	for (auto i=p.first;i!=p.second;i++)
	{
		cout<<"\n"<<i->first<<" "<<i->second;
	}*/
	
	/*
	string a("Rahul");
	//int ar[]={5,4,3,2,1};
	int ar[]={1,2,3,4,5};
	vector<int> v(ar,ar+5);
	sort(v.rbegin(),v.rend());
	for (auto i=v.begin();i!=v.end();i++)
		cout<<*i<<" ";
	*/
	
	string a;
	bool allGood=true;
	cout<<"Enter String ";
	getline(cin,a);
	
	////////////////////////////////////
	///Without Hashing
	///////////////////////////////////
	/*
	sort(a.begin(),a.end());
	for (string::iterator i=a.begin();i!=a.end();i++)
	{
		if ((*i)==(*(i+1)))
		{
			allGood=false;
			break;
		}
	}
	
	if (!allGood)
		cout<<"Duplicates Found";
	else
		cout<<"No Duplicates";
	*/
	

	//////////////////////////////////
	///With Hashing
	/////////////////////////////////
	
	unordered_set<char> s;
	for (string::iterator i=a.begin();i!=a.end();i++)
	{
		char c=*i;
		if (s.count(c)!=0)
		{
			allGood=false;
			break;
		}
		else if (c!=' ')
		{
			s.insert(c);
		}
	}
	
	if (!allGood)
		cout<<"Duplicates Found";
	else
		cout<<"No Duplicates";
	
	return 0;
}

