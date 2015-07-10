#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

class BST
{
	int numNodes;
	struct node
	{
		int rnum;
		string name;
		node *parent,*left,*right;
	}*nptr,*root,*temp;
	node* findSuccessor(int);
	int findLocation(int,node**);		//finds the place in BST where a node is present,or should be present 
	public:
	BST(int numNodes)
	{
		this->numNodes=numNodes;
		root=nullptr;
	}

	void addNode(int,string);
	void printSuccessor(int);
};

void BST::addNode(int a,string s)
{
	nptr=new node;
	nptr->rnum=a;
	nptr->name=s;
	if (root==nullptr)
	{
		root=nptr;
		return;
	}
	
	int stat=findLocation(a,&temp);
	if (stat==0)		//value not present in the BST
	{
		if (temp->rnum<a)
		{
			temp->right=nptr;
		}
		else
		{
			temp->left=nptr;
		}		
		nptr->parent=temp;
	}
	
	else if (stat==1)
	{
		cout<<"Node with the value "<<a<<" already present\n";
	}
}

int BST::findLocation(int val,BST::node **p)
{
	node *prev;
	prev=temp=root;
	
	while (temp!=nullptr)
	{
		if (temp->rnum==val)
		{
			*p=temp;
			return 1;
		}

		else if (temp->rnum<val)
		{
	 		if (temp->right!=nullptr)
			{
				temp=temp->right;
			}
			else
			{
				*p=temp;
				return 0;
			}
		}
		
		else if (temp->rnum>val)
		{
			if (temp->left!=nullptr)
			{
				temp=temp->left;
			}
			else
			{
				*p=temp;
				return 0;
			}
		}
	}
}

BST::node* BST::findSuccessor(int v)
{
	int stat=findLocation(v,&nptr);
	if (stat==0)
	{
		cout<<"Node with the given value not present\n";
		exit(1);
	}
	
	node* prev,*par;
	prev=nptr;
	par=nptr->parent;
	
	while (prev==par->right)
	{
		prev=par;
		par=par->parent;
	}
	
	return par;
}
	
void BST::printSuccessor(int v)
{
	nptr=findSuccessor(v);
	cout<<"Successor of the node with the value "<<v<<endl;
	cout<<nptr->rnum<<" "<<nptr->name<<endl;
}		


int main()
{
	BST g(8);	
	g.addNode(134,"Rajnish");	//4
	g.addNode(130,"Rahul");		//0
	g.addNode(132,"Rajarshi");	//2
	g.addNode(131,"Raj");		//1
	g.addNode(133,"Rajeev");	//3
	g.addNode(135,"Ravinder");	//5
	g.addNode(136,"Richa");		//6
	g.addNode(137,"Resham");	//7
	g.printSuccessor(133);
	return 0;
}
