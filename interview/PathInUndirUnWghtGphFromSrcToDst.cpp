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

bool BFS(vector<int> (&adj)[V], int (&dist)[V], int (&parent)[V], int src,int dst)
{
	bool visit[V] = {false};

	queue<int> q;
	q.push(src);
	dist[src] = 0;
	visit[src] = true;

	while(!q.empty())
	{	
		int cur = q.front();
		q.pop();
		for(vector<int>::iterator it = adj[cur].begin(); it != adj[cur].end(); ++it)
		{
			if(visit[*it] == false)
			{
				//cout<<*it<<" " <<cur<<endl;
				visit[*it] = true;
				q.push(*it);

				parent[*it] = cur;
				dist[*it] = dist[cur]+1;
				if(*it == dst)
					return true;
			}
		}
	}
	return false;
}

void printPathFromSrcToDst(vector<int> (&adj)[V], int src, int dst)
{
	int dist[V];
	int parent[V];

	for(int i=0;i<V;++i)
	{
		dist[i] = MAX;
		parent[i] = -1;
	}

	if(BFS(adj, dist, parent, src, dst) == false) {
		cout<<"no path from " <<src<< " to "<<dst<<"\n";
		return;
	}
	
	cout<<"path dist "<<dist[dst]<<endl;
	vector<int> v;
	v.push_back(dst);
	int cur = dst;
	while(parent[cur] != -1)
	{
		v.push_back(parent[cur]);
		cur = parent[cur];
	}
	cout<<"paths from: "<<src <<" to: "<<dst<<" is - ";
	for(int i=0; i<v.size(); ++i)
	{
		cout<<v[i]<<" " ;
	}
	cout<<endl;; 
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

	int src = 0;
	int dst = 4;
	printPathFromSrcToDst(adj, src, dst);
	return 0;
}
