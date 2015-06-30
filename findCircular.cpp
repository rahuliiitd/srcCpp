#include<iostream>
#include<unordered_set>

using namespace std;

struct node
{
	int value;
	node *next;
};

int main()
{
	node a,b,c,d,*start,*temp;
	a.value=1;
	b.value=2;
	c.value=3;
	d.value=4;
	a.next=&b;
	b.next=&c;
	c.next=&d;
	d.next=&b;
	start=&a;

	unordered_set<node*> addr;
	temp=start;
	while (true)
	{
		if (addr.count(temp)==0)
			addr.insert(temp);
		else
			break;
		temp=temp->next;
	}
	
	cout<<"Node contains "<<temp->value<<"\n";
		
	return 0;
}
