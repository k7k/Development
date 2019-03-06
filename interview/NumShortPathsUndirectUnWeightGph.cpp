#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define V 8
#define MAX 999

//using extended BFS, timecomplexity O(V+E)
void addEdge(vector<int> (&adj)[V], int src, int dst)
{
	adj[src].push_back(dst);
	adj[dst].push_back(src);
}

void BFS(vector<int> (&adj)[V], int (&dist)[V], int (&path)[V], int src)
{
	dist[src] = 0;
	path[src] = 1;
	bool visit[V] = {false};

	queue<int> q;
	q.push(src);
	visit[src] = true;

	while(!q.empty())
	{	
		int cur = q.front();
		q.pop();
		for(vector<int>::iterator it = adj[cur].begin(); it != adj[cur].end(); ++it)
		{
			if(visit[*it] == false)
			{
				visit[*it] = true;
				q.push(*it);
			}
			if(dist[*it] > dist[cur]+ 1)
			{
				dist[*it] = dist[cur] + 1;
				path[*it] = path[cur];
			}
			else if(dist[*it] == dist[cur]+1) {
				path[*it] += path[cur];
			}
		}

	}
}

void printShortPaths(vector<int> (&adj)[V], int src)
{
	int dist[V];
	int path[V];

	for(int i=0;i<V;++i)
	{
		dist[i] = MAX;
		path[i] = 0;
	}

	BFS(adj, dist, path, src);
	for(int i=0; i<V; ++i)
	{
		cout<<"Num short paths from: "<<src <<" to: "<<i<<" is - "<<path[i]<<endl;; 
	}
}

int main()
{

	// add edges in both direction
	vector<int> adj[V];
	addEdge(adj,0,1);
	addEdge(adj,1,2);
	addEdge(adj,1,3);
	addEdge(adj,2,3);
	addEdge(adj,2,4);
	addEdge(adj,2,5);
	addEdge(adj,3,4);
	addEdge(adj,4,5);
	addEdge(adj,4,7);
	addEdge(adj,5,6);

	int src = 4;
	printShortPaths(adj, src);
	return 0;
}
