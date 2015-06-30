#include<iostream>
#include<string>

using namespace std;

class List
{
	struct node
	{
		int value;
		node *next;
	}*front,*rear,*p,*k,*prev;
	int nodeCount;
	public:
	List()
	{
		front=rear=nullptr;
		nodeCount=0;
	}
	void insert(int);
	void deleteDuplicates();
	void printList();
};

void List::insert(int x)
{
	p=new node;
	p->value=x;
	p->next=nullptr;
	if (front==nullptr)
	{
		front=rear=p;
	}
	else
	{
		rear->next=p;
		rear=p;
	}
	nodeCount++;
}

void List::deleteDuplicates()
{
	if (nodeCount==0)
	{
		cerr<<"Cannot remove duplicates from an empty list";
		return;
	}
	int i,j;
	node *temp;
	p=front;
	while (p!=rear)
	{
		prev=p;
		k=p->next;
		while (k!=nullptr)
		{
			if (p->value==k->value)
			{	
				prev->next=k->next;
				nodeCount--;
				if (k==rear)
					rear=prev;
			}
			else
			{
				prev=k;
			}
			k=k->next;
		}
		p=p->next;
	}
}				
		
void List::printList()
{	
	int i;
	cout<<"Number of Nodes="<<nodeCount<<"\n";
	for (i=1,p=front;p!=nullptr;p=p->next,i++)
	{
		cout<<"Node "<<i<<" Value="<<p->value<<"\n";
	}
}		
int main()
{
	List a;
	a.insert(5);
	a.insert(3);
	a.insert(5);
	a.insert(5);
	a.insert(8);
	cout<<"Before\n";
	a.printList();
	a.deleteDuplicates();
	cout<<"After\n";
	a.printList();
	return 0;
}
