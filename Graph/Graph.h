#include<iostream>
#include<list>
using namespace std;

class Graph
{
public:
	int V;
	list<int> *adj;
	Graph(int V)
	{
		this->V = V;
		adj= new list<int>[V];
	}
	void addEdge(int v,int w)
	{
		adj[v].push_back(w);
	}
	~Graph(){}	
};
