#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

struct student
{
	int regno;
	string name;
	int marks;
};

bool multiSort(student s1,student s2)
{
	if (s1.marks>s2.marks)
		return true;
	else if (s1.marks<s2.marks)
		return false;
	
	if (s1.name<s2.name)
		return true;
	else
		return false;
}

int main()
{
	vector<student> Vec;
	student s;
	for (int i=0;i<5;i++)
	{
		cin>>s.regno>>s.name>>s.marks;
		Vec.push_back(s);
	}
	
	sort(Vec.begin(),Vec.end(),multiSort);
	
	for (auto i=Vec.begin();i!=Vec.end();i++)
	{
		cout<<i->regno<<" "<<i->name<<" "<<i->marks<<"\n";
	}
	
	return 0;
}
