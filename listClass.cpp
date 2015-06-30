#include<iostream>
#include<string>

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
	int getLength();
	int getNodeValue(int);
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
		std::cerr<<"Cannot remove duplicates from an empty list";
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
	std::cout<<"Number of Nodes="<<nodeCount<<"\n";
	for (i=1,p=front;p!=nullptr;p=p->next,i++)
	{
		std::cout<<"Node "<<i<<" Value="<<p->value<<"\n";
	}
}		

int List::getLength()
{
	return nodeCount;
}

int List::getNodeValue(int loc)
{
	int i=1;
	p=front;
	while (i<loc)
	{
		p=p->next;
		i++;
	}
	return (p->value);
}



