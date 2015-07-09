#include<iostream>
#include<list>
#include<string>

using namespace std;

class Graph
{
	int numNodes;
	int num,maxDepth;
	int *nodeDepth;
	bool *visited;
	list<int> *adj;
	struct node
	{
		int rnum;
		string name;
	}*nptr,**naddr;
	
	list<node*> *ll;
	public:
	Graph(int n)
	{
		num=0;
		numNodes=n;
		maxDepth=-1;
		adj=new list<int>[numNodes];
		nodeDepth=new int[numNodes];
		visited=new bool[numNodes];
		naddr=new node*[numNodes];
		for (int i=0;i<numNodes;i++)
		{
			nodeDepth[i]=-1;
			visited[i]=false;
		}
	}
	
	void addNode(int,string);
	void addEdge(int,int);
	void doBFS(int);
	void makeLL();
	void printLists();
};

void Graph::addNode(int n,string s)
{
	nptr=new node;
	nptr->rnum=n;
	nptr->name=s;
	naddr[num++]=nptr;
}

void Graph::addEdge(int u,int v)
{
	adj[u].push_back(v);
}

void Graph::doBFS(int s)
{
	nodeDepth[s]=0;
	visited[s]=true;
	list<int> queue;
	int element;
	queue.push_back(s);
	while (!queue.empty())
	{
		element=queue.front();
	//	cout<<"Element "<<element<<"\n";
		queue.pop_front();
		if (nodeDepth[element]>maxDepth)
			maxDepth=nodeDepth[element];

		for (auto n=adj[element].begin();n!=adj[element].end();n++)
		{
			if (!visited[*n])
			{
				visited[*n]=true;
				nodeDepth[*n]=nodeDepth[element]+1;
				queue.push_back(*n);
			}
		}
	}
}	
	
void Graph::makeLL()
{
	ll=new list<node*>[maxDepth+1];
	for (int i=0;i<numNodes;i++)
	{
	//	cout<<"Node "<<i<<" Depth="<<nodeDepth[i]<<"\n";
		ll[nodeDepth[i]].push_back(naddr[i]);
	}
}

void Graph::printLists()
{
	for (int i=0;i<=maxDepth;i++)
	{
		cout<<"Nodes at Depth "<<i<<" :\n";
		for (auto it=ll[i].begin();it!=ll[i].end();it++)
		{
			cout<<(*it)->rnum<<" ";
		}
		cout<<"\n";
	}
}
			
int main()
{
	Graph g(8);
	g.addNode(130,"Rahul");		//0
	g.addNode(131,"Raj");		//1
	g.addNode(132,"Rajarshi");	//2
	g.addNode(133,"Rajeev");	//3
	g.addNode(134,"Rajnish");	//4
	g.addNode(135,"Ravinder");	//5
	g.addNode(136,"Richa");		//6
	g.addNode(137,"Resham");	//7
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(0,3);
	g.addEdge(1,4);
	g.addEdge(1,5);
	g.addEdge(4,7);
	g.addEdge(3,6);
	g.doBFS(0);
	g.makeLL();
	g.printLists();
	return 0;
}
	
