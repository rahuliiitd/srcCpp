#include<CL/cl.h>
#include<iostream>
#include<string>
using namespace std;

struct node
{
	int num;
	string name;
	node *next;
};

typedef struct node node;

void addNode(node**,int,string);
void printList(node*);
node* findName(node*);
void traverse(node*);
 
int main()
{
	node *head=NULL;
	addNode(&head,1,"Rahul");
	traverse(head);
	addNode(&head,2,"Raj");
	traverse(head);
	printList(head);
	
	return 0;
}

void traverse(node *x)
{
	node *p,*i;
	for (p=x;p!=NULL;p=p->next)
	{
		cout<<p->num;
	}
}
void addNode(node **head,int num,string name)
{
	node *x;
	x=new node;
	x->num=num;
	x->name=name;
	if (*head==NULL)
	{
		x->next=NULL;
		*head=x;
	}
	else
	{
		x->next=*head;
		*head=x;
	}
}

void printList(node *x)
{
	if (x==NULL)
	{
		cout<<"\nEmpty List";
		return;
	}
	int c=1;
	for (node *p=x;p!=NULL;p=p->next,c++)	
	{
		cout<<"-------------------------\nNode"<<c<<"\n";
		cout<<"Number : "<<p->num;
		cout<<"\nName : "<<p->name<<"\n";
	}
}

		
