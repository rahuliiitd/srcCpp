#include<iostream>
#include<list>
#include<string>

using namespace std;

int main()
{
	int T;
	cin>>T;
	int i;
	string temp="";
	list<string> l;
	cin.ignore();
	for (i=0;i<T;i++)
	{
		string s;
		getline(cin,s);
		for (string::iterator it=s.begin();it!=s.end();it++)
		{
			if (*it==' ')
				continue;

			temp+=*it;
			if (*it=='>')		// tag complete
			{
				if (!l.empty() && (l.back()).length()==3 && temp[2]==(l.back())[1] && temp[1]=='/')
				{
					l.pop_back();
				}
				else
				{
					l.push_back(temp);
				}
				temp="";
			}
		}
		if (l.empty())
		{
			cout<<"TRUE\n";
		}
		else
		{
			cout<<"FALSE\n";
		}
		l.clear();
	}
	return 0;
}
	
