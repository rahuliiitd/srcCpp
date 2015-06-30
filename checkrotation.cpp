#include<iostream>
#include<string>

using namespace std;

bool isSubstring(string,string);

int main()
{
	string s1,s2;
	cout<<"Enter String 1 ";
	getline(cin,s1);
	cout<<"\nEnter String 2 ";
	getline(cin,s2);
	if (s1.length()!=s2.length())
	{
		cout<<"String 2 not the rotation of 1";
		return 0;
	}
	
	if (isSubstring(s1+s1,s2))
		cout<<"String 2 is the rotation of 1";
	else
		cout<<"String 2 not the rotation of 1";
	
	return 0;
}

bool isSubstring(string s1,string s2)
{
	int loc=s1.find(s2);
	if (loc!=-1)
		return true;
	return false;
}
