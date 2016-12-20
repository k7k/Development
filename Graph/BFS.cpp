#include "Graph.h"
#define V 5

void BFS(class Graph &g,int s)
{
	bool *visited = new bool[V];
	for(int i=0;i<V;++i)
	{
		visited[i]=false;
	}
	
	list<int> queue;
	visited[s]=true;
	queue.push_back(s);

	list<int>::iterator i;

	while(!queue.empty())
	{
		s = queue.front();
		cout << s << " ";
		queue.pop_front();
		for(i=g.adj[s].begin();i!=g.adj[s].end();++i)
		{
			if(!visited[*i])
			{
				visited[*i]=true;
				queue.push_back(*i);
			}

		}
	}
	cout <<endl;
}

int main()
{
	Graph g(V);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(1,2);
	g.addEdge(2,0);
	g.addEdge(2,3);
	g.addEdge(3,3);
	g.addEdge(2,4);

	BFS(g,2);
	return 0;
}
