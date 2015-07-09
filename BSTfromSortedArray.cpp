#include<iostream>

using namespace std;

class Tree
{
	struct node
	{
		int value;
		node *left,*right;
	}*nptr,*root;
	
	void inorderTraversal(node*) const;
	void makeTree(node**,int*,int,int);
	public:
	Tree(int*,int,int);
	void printTree() const;
};

Tree::Tree(int *ar,int start,int end)	
{
	makeTree(&root,ar,start,end);
//	cout<<"Root : "<<root->value<<"\n";
}

void Tree::makeTree(Tree::node **n,int *ar,int start,int end)		//pointers have an address too!!
{
//	cout<<"("<<start<<","<<end<<")"<<"\n";
	int m=(start+end)/2;
	cout<<"m="<<m<<"\n";
	*n=new node;
	(*n)->value=ar[m];
	
	if (start==end)
	{
		(*n)->left=nullptr;
		(*n)->right=nullptr;
		return;
	}

	makeTree(&((*n)->left),ar,start,m-1);
	makeTree(&((*n)->right),ar,m+1,end);
}

void Tree::printTree() const	//doing inorder traversal
{
	inorderTraversal(root);
}

void Tree::inorderTraversal(Tree::node* n) const
{
	if (n==nullptr)
		return;
	inorderTraversal(n->left);
	cout<<n->value<<" ";
	inorderTraversal(n->right);
}
	
int main()
{
	int a[]={1,2,3,4,5,6,7};
	Tree t(a,0,6);
	t.printTree();
	return 0;
}
