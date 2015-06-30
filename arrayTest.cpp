#include<iostream>
#include<array>
#include<string>

using namespace std;

int main()
{
	string s;
	cout<<"Enter String ";
	cin>>s;
	array<bool,128> b;
	b.fill(false);
	bool found=false;
	for (auto i=s.begin();i!=s.end();i++)
	{
		if (*i==' ')
			continue;

		if (b[int(*i)]!=false)
		{
			found=true;
			break;
		}
		else
			b[int(*i)]=true;
	}
	/*for (auto i=b.begin();i!=b.end();i++)
	cout<<*i<<" ";*/
	if (found)
		cout<<"Duplicate Present";
	else
		cout<<"No Duplicate Present";
	return 0;
}	
