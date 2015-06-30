#include<iostream>
#include<unordered_map>
#include<string>
#include<algorithm>

using namespace std;
string erasespace(string);
int main()
{
	string s1,s2;
	bool anagram=true;
	cout<<"Enter String1 ";
	getline(cin,s1);
	cout<<"\nEnter String2 ";
	getline(cin,s2);
	
	////////////////////////////////////////////////
	///Using character count method
	///////////////////////////////////////////////
	/*
	unordered_map<char,int> cset;
	for (auto i=s1.begin();i!=s1.end();i++)
	{
		if (*i==' ')
			continue;

		if (cset.count(*i)==0)
			cset.insert(make_pair(*i,1));
		else
			cset[*i]++;
	}
	for (auto i=s2.begin();i!=s2.end();i++)
	{
		if (*i==' ')
			continue;

		if (cset.count(*i)==0)
		{
			anagram=false;
			break;
		}
		else
		{
			cset[*i]--;
		}
	}
	
	for (auto i=cset.begin();i!=cset.end();i++)
	{
		if (i->second!=0)
		{
			anagram=false;
			break;
		}
	}
	
	if (anagram)
		cout<<"Are Anagram";
	else
		cout<<"Not Anagram";
	*/

	/////////////////////////////////////////
	////Sort the string
	////////////////////////////////////////	
	s1=erasespace(s1);
	s2=erasespace(s2);
	cout<<"s1="<<s1<<" s2="<<s2<<"\n";
	sort(s1.begin(),s1.end());
	sort(s2.begin(),s2.end());
	if (s1==s2)
		cout<<"Anagram";
	else
		cout<<"Not Anagram";
	
	return 0;
}

string erasespace(string x)
{
	for (auto i=x.begin();i!=x.begin()+x.length()-1;i++)
	{
		if (*i==' ')
			x.erase(i);
	}
	return x;
}
