#include<iostream>
#include<string.h>
using namespace std;

#define ROW 5
#define COL 5

int IsValid(int a[][COL],int r,int c,bool visited[][COL])
{
	return (r<ROW && r>=0 && c<COL && c>=0 & a[r][c] && !visited[r][c] );
}

void DFS(int a[][COL],int r,int c,bool visited[][COL])
{
	int rn[]={-1,-1,-1,0,0,1,1,1};
	int cn[]={-1,0,1,-1,1,-1,0,1};
	visited[r][c] =true;
	for (int i=0;i<8;++i){
		if(IsValid(a,r+rn[i],c+cn[i],visited))
			DFS(a,r+rn[i],c+cn[i],visited);
	}
}

int numberOfIslands(int a[][COL])
{

	bool visited[ROW][COL];
	memset(visited,0,sizeof(visited));
	int count=0;
	for(int i=0;i<ROW;++i)
	{
		for(int j=0;j<COL;++j)
		{
			if(a[i][j] && !visited[i][j]) {
				DFS(a,i,j,visited);
				++count;
			}
		}
	}
	return count;
}

int main()
{
	int a[][COL]={{1,1,0,0,0},
			{0,1,0,0,1},
			{1,0,0,1,1},
			{0,0,0,0,0},
			{1,0,1,0,1}

			};
	cout<< "number of Islands are: " << numberOfIslands(a) << endl;
	return 0;
}
