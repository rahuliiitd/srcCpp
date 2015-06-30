#include<iostream>
#include<string>
#include<iterator>

using namespace std;

int main()
{
	string s,st1,st2;
	cout<<"Enter String ";
	getline(cin,s);
	int len=s.length(),i,j;
	for (i=0;i<s.length()-1;i++)
	{
		if (s[i]==' ')
			continue;
		for (j=i+1;j<s.length();j++)
		{
			if (s[i]==s[j] && j!=s.length()-1)
			{
				st1=s.substr(0,j);
				st2=s.substr(j+1,s.length());
				//cout<<"\ni="<<i<<" j="<<j<<" str1="<<st1<<" ste2="<<st2<<"\n";
				s=st1+st2;
			}
			else if (s[i]==s[j] && j==s.length()-1)
				s=s.substr(0,j);
		}
	}
	
	cout<<"\n"<<s;

	/*
	string::iterator i=s.begin();
	string::iterator j;
	int ci=0,cj=0;
	while (i!=s.begin()+s.length()-1)		//skip the last character
	{
		j=i+1;
		while (j!=s.end())
		{
			if (*i==*j)
			{	
				s.erase(j);
				if (j==s.end())
					break;
			}
			cj++;
			j=s.begin()+1+cj;
		}
		cj=0;
		ci++;
		i=s.begin()+ci;
	}
	cout<<"\n"<<s;*/

	
	return 0;
}
