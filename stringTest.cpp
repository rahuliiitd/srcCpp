#include<iostream>
#include<string>
#include<vector>
#include<iterator>
#include<typeinfo>

using namespace std;

int main()
{
	string a="Rahul";
	//vector<string>::iterator i;
	cout<<"Space used by a="<<a.capacity();
	for (auto i=a.begin();i!=a.end();i++)
	{
		cout<<*i;
	}
	a.clear();
	cout<<"\nModified a length="<<a.length();
	//cout<<a;
	cout<<"Is a empty "<<a.empty();
	return 0;
}

