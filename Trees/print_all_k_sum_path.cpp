#include "Tree.h"
#include <vector>


void printVec(vector<int> &path,int i)
{
	for(int j=i;j<path.size();++j)
		cout<<path[j]<<" ";
	
	cout <<endl;
}
void printPathUtil(Tree *root,vector<int> &path,int sum)
{
	if(!root)
		return;

	path.push_back(root->data);

	printPathUtil(root->left,path,sum);
	printPathUtil(root->right,path,sum);
	
	int tmp = 0;
	for(int i=path.size()-1;i>=0;--i)
	{	
		tmp += path[i];
		if(tmp == sum)
			printVec(path,i);
	}

	path.pop_back();
}

void printPath(Tree *root,int sum)
{
	vector<int> path;
	printPathUtil(root,path,sum);
}

int main()
{
	Tree *root = getNode(1);
	root->left = getNode(3);
	root->right = getNode(-1);	
	root->left->left = getNode(2);	
	root->left->right = getNode(1);	
	root->left->right->left = getNode(1);	
	root->right->left = getNode(4);	
	root->right->right = getNode(5);	
	root->right->left->left = getNode(1);	
	root->right->left->right = getNode(2);	
	root->right->right->right = getNode(6);

	//int reqSum = 5;
	int reqSum = 6;
	printPath(root,reqSum);

	return 0;	
}
