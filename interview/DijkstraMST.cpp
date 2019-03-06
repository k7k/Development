#include <iostream>
#include <map>
#include <list>
using namespace std;
#define V 5
#define MAX 9999

int getminKey(int dist[V], bool visited[V])
{
	int key = MAX;
	int minKeyIndex = -1;
	for(int i=0;i<V;++i)
	{
		if(visited[i] == false && dist[i]< key)
		{
			key = dist[i];
			minKeyIndex = i;
		}
	}
	return minKeyIndex;
}

void printPath(int parent[V],int i)
{
	if(parent[i] == -1)
		return;

	printPath(parent, parent[i]);
	cout<<i<<" ";
}

void printMST(int dist[V],int parent[V])
{
	cout<<"dest : weight : Path\n";
	for(int i=0;i<V;++i) {
			cout<<i<<" : "<<dist[i]<<" : ";
			printPath(parent, i);
			cout<<endl;
	}
}

void printMST(int graph[V][V], int src)
{
	bool visited[V];
	int dist[V];
	int parent[V];

	for(int i=0;i<V;++i)
	{
		visited[i]=false;
		dist[i]=MAX;
	}

	dist[src] = 0;
	parent[src] = -1;

	for(int i =0;i<V-1;++i)
	{
		int index = getminKey(dist,visited);
		
		visited[index] = true;
		for(int i =0;i<V;++i) 
		{
			if(visited[i] == false && graph[index][i] && 
				graph[index][i] < dist[index] + dist[i])
			{
				dist[i] = graph[index][i] + dist[index];
				parent[i] = index;
			}
		}
	}	
	cout<<"source is : "<<src<<endl;
	printMST(dist,parent);
}


int main()
{
	// graph nodes 0,1,2,3,4
	int graph[V][V] = {
						{0,4,0,0,7},
						{4,0,0,0,2},
						{0,0,0,5,3},
						{0,0,5,0,9},
						{7,2,3,9,0},
					  };

	int src = 0;
	printMST(graph, src);
	return 0;
}
