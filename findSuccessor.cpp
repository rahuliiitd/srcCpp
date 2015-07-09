#include<iostream>
#include<string>

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
	//node* findSuccessor(int);
	int findLocation(int,node*);		//finds the place in BST where a node is present,or should be present 
	public:
	BST(int numNodes)
	{
		this->numNodes=numNodes;
		root=nullptr;
	}

	void createNode(int,string);
//	void printSuccessor(int);
};

void BST::createNode(int a,string s)
{
	nptr=new node;
	nptr->rnum=a;
	nptr->name=s;
	if (root==nullptr)
	{
		root=nptr;
		return;
	}
	
	int stat=findLocation(a,temp);
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

int BST::findLocation(int val,BST::node *p)
{
	node *prev;
	prev=temp=root;
	
	while (temp!=nullptr)
	{
		if (temp->rnum==val)
		{
			p=temp;
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
				p=temp;
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
				p=temp;
				return 0;
			}
		}
	}
}

int main()
{
	return 0;
}
