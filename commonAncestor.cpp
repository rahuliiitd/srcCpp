#include<iostream>
#include<list>
using namespace std;

class BinaryTree
{
	
	int numNodes;
	struct node
	{
		int value;
		node *left,*right;
	}*nptr,*root,*temp;
	
	//node **addr;
	public:

	BinaryTree(int numNodes)
	{
		root=nullptr;
		this->numNodes=numNodes;
		//addr=new node*[numNodes];
	}
	
	void addNode(int val,int parentVal,int leftOrRight);	//1 for left, 2 for right
	node* findParent(int,node*);	//return 1 if parent present, else 0
	void doBFS();
};

void BinaryTree::addNode(int val,int parentVal,int leftOrRight)	
{
	nptr=new node;
	nptr->value=val;
	nptr->left=nullptr;
	nptr->right=nullptr;
	if (root==nullptr)
	{
		root=nptr;
		return;
	}
	
	temp=findParent(parentVal,root);
	if (temp==nullptr)
	{
		cout<<"Node with value "<<parentVal<<" not present\n";
		return;
	}
	
	if ((leftOrRight==1 && temp->left!=nullptr) || (leftOrRight==2 && temp->right!=nullptr))
	{
		cout<<"Cannot insert node as the requested position is full\n";
		return;
	}
	
	if (leftOrRight==1)
		temp->left=nptr;
	else
		temp->right=nptr;	
}

BinaryTree::node* BinaryTree::findParent(int val,BinaryTree::node *start)
{
	cout<<"Node value="<<start->value<<"\n";
	node *statL,*statR;
	if (start->value==val)
	{
		return start;
	}
	
	if (start->left!=nullptr) 
		statL=findParent(val,start->left);
	
	if (start->right!=nullptr)
		statR=findParent(val,start->right);
	
	if (statL!=nullptr)
		return statL;
	else
		return statR;
}

void BinaryTree::doBFS()
{	
	cout<<"\nBFS OUPTPUT\n";
	list<node*> queue;
	queue.push_back(root);
	while (!queue.empty())
	{
		nptr=queue.front();
		queue.pop_front();
		cout<<nptr->value<<" ";
		if (nptr->left!=nullptr)
			queue.push_back(nptr->left);
		if (nptr->right!=nullptr)
			queue.push_back(nptr->right);
	}
}
		
int main()
{
	BinaryTree b(8);
	b.addNode(1,0,0);
	b.addNode(2,1,1);	
	b.addNode(3,1,2);
	//cout<<"ROOT-----------------\n";
	//cout<<(b.root->left)->value<<" "<<(b.root->right)->value;
	b.addNode(4,2,1);
	b.addNode(5,2,2);
	b.addNode(6,3,1);
	b.addNode(7,4,1);
	b.addNode(8,6,2);
	b.doBFS();
	return 0;
}
			
		
