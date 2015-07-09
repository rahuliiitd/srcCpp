#include<iostream>
#include<list>

using namespace std;

class Graph
{
	int numNodes,*nodeDepth,*parent;
	list<int> *adj;
	bool *visited;
	int dmax,dmin;
	public:
	Graph(int);
	void addEdge(int,int);
	void runBFS(int);
	void returndmindmax(int*,int*) const;
	int returnDepth(int) const;
};

Graph::Graph(int x)
{
	numNodes=x;
	adj=new list<int>[numNodes];
	visited=new bool[numNodes];
	nodeDepth=new int[numNodes];
	parent=new int[numNodes];
	for (int i=0;i<numNodes;i++)
	{
		visited[i]=false;
		nodeDepth[i]=-1;
		parent[i]=-1;
	}
	dmax=-1;
	dmin=x+1;
}

void Graph::addEdge(int u,int v)
{
	adj[u].push_back(v);
}

void Graph::runBFS(int s)
{
	list<int> queue;
	nodeDepth[s]=0;			//root node has 0 depth
	queue.push_back(s);
	int i,d=0;

	bool isleaf;
	visited[s]=true;
	nodeDepth[s]=0;
	
	while (!queue.empty())
	{
		i=queue.front();
		//cout<<"i="<<i<<"\n";
		queue.pop_front();
		isleaf=true;
		for (auto k=adj[i].begin();k!=adj[i].end();k++)
		{
			if (!visited[*k])
			{
				isleaf=false;
				visited[*k]=true;
				parent[*k]=i;
				nodeDepth[*k]=nodeDepth[i]+1;
				queue.push_back(*k);
			}
		}
		
		if (isleaf)
		{
			if (nodeDepth[i]>dmax)
				dmax=nodeDepth[i];
			if (nodeDepth[i]<dmin)
				dmin=nodeDepth[i];
		}	
	}	
}

void Graph::returndmindmax(int *a,int *b) const
{
	*a=dmin;
	*b=dmax;
}

int Graph::returnDepth(int a) const
{
	return nodeDepth[a];
}

int main()
{
	Graph g(10);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(1,3);
	g.addEdge(1,4);
	g.addEdge(2,5);
	g.addEdge(2,6);
	g.addEdge(2,7);
	g.addEdge(5,8);
	g.addEdge(8,9);
	g.runBFS(0);
	cout<<"Depth of each node :\n";
	for (int i=0;i<9;i++)
	{
		cout<<"Depth of Node "<<i<<"="<<g.returnDepth(i)<<"\n";
	}
	
	int min,max;
	g.returndmindmax(&min,&max);
	if ((max-min)>1)
		cout<<"Tree Not Balanced\n";
	else
		cout<<"Tree Balanced\n";
				
	return 0;
}

