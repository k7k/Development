#include "Graph.h"
#define V 5

void DFSUtil(class Graph &g,int s,bool visited[])
{
	visited[s]=true;
	cout << s << " ";

	list<int>::iterator i;
	for(i = g.adj[s].begin(); i != g.adj[s].end(); ++i)
	{
		if(!visited[*i])
			DFSUtil(g,*i,visited);
	}
}

void DFS(class Graph &g,int s)
{
	bool *visited = new bool[V];
	for (int i=0;i<V;++i)
		visited[i]=false;
	DFSUtil(g,s,visited);
	cout<<endl;
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
        g.addEdge(1,4);

        DFS(g,2);
        return 0;
}
