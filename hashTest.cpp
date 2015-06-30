#include<iostream>
#include<iterator>
#include<map>
#include<string>

using namespace std;

class nametest
{
	public:
	string name;
	bool eligible;
	nametest(string n,bool e);
	~nametest();
};	

nametest::nametest(string n,bool e)
{
	name=n;
	eligible=e;
}

nametest::~nametest()
{
//	cout<<"Destructor Called";
}
	
int main()
{
	/*map<int,string> M;
	M.insert(make_pair(1,"Rahul"));
	M.insert(make_pair(0,"Richa"));
	for (auto i=M.begin();i!=M.end();i++)
	{
		cout<<"\n"<<(*i).first<<" "<<(*i).second;
	}*/

	map<int,nametest> M;
	map<int,string> N;
	nametest a("Rahul Sharma",true);
	nametest b("Richa Sharma",false);
	N.insert(make_pair(1,"Rahul"));
	N.insert(make_pair(2,"Richa"));
	M.insert(make_pair(1,a));
	M.insert(make_pair(2,b));
	auto c=M.find(2);			//iterators needed with arbitrary objects
	string i=N[1];
	cout<<(*c).first<<" Name:"<<(*c).second.name;
	if (M.count(2))
	{
		cout<<"Element with key 3 present";
	}
	else
	{
		cout<<"Element not present";
	}

	return 0;
}
	
