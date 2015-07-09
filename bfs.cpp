#include<iostream>

using namespace std;

class graph
{
	struct node
	{
		int num;
	}**listPtr,*root;
	
	int numNodes;
	
	public:
	graph()
	{
		numNodes=0;
		root=nullptr;
	}
	
	void createGraph(int);
};

void graph::createGraph(int n)
{
	numNodes=n;
	listPtr=new node*[numNodes*2];

	int i;
	for (i=0;i<numNodes;i++)
	{
		if (i==1)
		{


int main()
{
	return 0;
}			
