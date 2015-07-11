#include<iostream>
#include<list>

using namespace std;

class Graph
{
	int numNodes,count;
	struct node
	{
		int value;
	}*temp,*nptr;
	
	node **addr;
	list<int> *adj;		//for storing adjacency list
	bool *visited;
	public:
	Graph(int numNodes)
	{
		count=0;
		this->numNodes=numNodes;
		addr=new node*[numNodes];
		adj=new list<int>[numNodes];
		visited=new bool[numNodes];
		for (int i=0;i<numNodes;i++)
			visited[i]=false;
	}
	
	void addNode(int val);
	void addEdge(int u,int v);
	void doDFS(int);
	//void printAdjacency();
};

void Graph::addNode(int val)
{
	nptr=new node;
	nptr->value=val;
	addr[count++]=nptr;
}

void Graph::addEdge(int u,int v)
{
	adj[u].push_back(v);
}

void Graph::doDFS(int s)
{
	cout<<"Node "<<s<<" Value="<<addr[s]->value<<"\n";
	visited[s]=true;

	for (auto n=adj[s].begin();n!=adj[s].end();n++)
	{
		if (!visited[*n])
			doDFS(*n);
	}
	
}
/*
void Graph::printAdjacency()
{
	for (int i=0;i<numNodes;i++)
	{
		for (auto j=adj[i].begin();j
*/
int main()
{
	Graph g(6);
	g.addNode(100);
	g.addNode(200);
	g.addNode(300);
	g.addNode(400);
	g.addNode(500);
	g.addNode(600);
	g.addEdge(0,1);
	g.addEdge(0,3);
	g.addEdge(1,2);
	g.addEdge(3,1);
	g.addEdge(2,3);
	g.addEdge(4,2);
	g.addEdge(4,5);
	g.addEdge(5,5);
	g.doDFS(4);
	return 0;
}			
