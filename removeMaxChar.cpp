#include<iostream>
#include<string>
#include<vector>

using namespace std;

int findMax(vector<string>);
bool foundCommon(string,vector<string>);

int main()
{
	vector<string> v;
	string s;
	while (true)
	{	
		cin>>s;
		if (s=="end")
			break;
		v.push_back(s);
	}
	
	int max=findMax(v);
	cout<<"Maximum deletion possible = "<<max<<"\n";
	return 0;
}

/*
int findMax(vector<string> v)
{
	vector<string> cpy=v;
	string word;
	int max=0,count;
	for (vector<string>::iterator i1=cpy.begin();i1!=cpy.end();i1++)
	{
		word=*i1;
		count=0;
		for (string::iterator i2=word.begin();i2!=word.end();i2++)
		{
			word.erase(i2);
			if (foundCommon(word,v))
			{
				count++;
			}
		}
		if (count>max)
			max=count;
	}
	
	return max;
}
*/

int findMax(vector<string> v)
{
	vector<string> cpy=v;
	string word;
	int max=0,count;
	for (vector<string>::iterator i1=cpy.begin();i1!=cpy.end();i1++)
	{
		word=*i1;
		count=0;
		for (int i2=0;i2<word.length();i2++)
		{
			eraseit(&word,i2);
			if (foundCommon(word,v))
			{
				count++;
			}
		}
		if (count>max)
			max=count;
	}
	
	return max;
}

bool foundCommon(string word,vector<string> vec)
{
	for (vector<string>::iterator i1=vec.begin();i1!=vec.end();i1++)
	{
		if (word==(*i1))
			return true;
	}

	return false;
}

void eraseit(string *s,int pos)
{
	string temp;
	int slen=(*s).length();
	if (
