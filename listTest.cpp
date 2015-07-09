#include<iostream>
#include<list>

using namespace std;

int main()
{
	list<int> l;
	l.push_back(1);
	l.push_back(2);
	for (auto a =l.begin();a!=l.end();a++)
	{
		cout<<*a<<" ";
		*a=*a+10;
		cout<<*a<<" ";
	}
	cout<<endl;
	return 0;
}

