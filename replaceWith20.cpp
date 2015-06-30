#include<iostream>
#include<string>

using namespace std;

int main()
{
	string s;
	cout<<"Enter String ";
	getline(cin,s);
	for (int i=0;i<s.length();i++)
	{
		if (s[i]==' ')
		{
			if (i==0)
			{
				s="%20"+s.substr(1,s.length());
			}
			else if (i==s.length()-1)
			{
				s=s.substr(0,s.length()-1)+"%20";
			}
			else
			{
				s=s.substr(0,i)+"%20"+s.substr(i+1,s.length());
			}
		}
	}
	
	cout<<"\n"<<s;
	return 0;
}
