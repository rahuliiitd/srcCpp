#include<iostream>
#include<vector>
#include<iterator>

using namespace std;
int main()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(5);
	vector<int>::iterator i;
	cout<<"\n";
	v.pop_back();		//deletes the last element
	for (i=v.begin();i!=v.end();i++)
		cout<<*i<<" ";
	return 0;
}
	
