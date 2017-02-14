#include "Tree.h"
#include <vector>


void printPathUtil(Tree *root,vector<int> &path,int tmpSum,int sum)
{
	if(!root)
		return;

	tmpSum += root->data;
	path.push_back(root->data);

	if(tmpSum == sum)
	{
		cout<<"Path found: ";
		for(int i=0;i<path.size();++i)
			cout <<path[i]<<" " ;

		cout <<endl;
	}

	if(root->left)
		printPathUtil(root->left,path,tmpSum,sum);
	if(root->right)
		printPathUtil(root->right,path,tmpSum,sum);

	path.pop_back();
}

void printPath(Tree *root,int sum)
{
	vector<int> path;
	printPathUtil(root,path,0,sum);
}

int main()
{
	Tree *root = getNode(10);
	root->left = getNode(28);
	root->right = getNode(13);	
	root->right->left = getNode(14);	
	root->right->right = getNode(15);	
	root->right->left->left = getNode(21);	
	root->right->left->right = getNode(22);	
	root->right->right->left = getNode(23);	
	root->right->right->right = getNode(24);

	//int reqSum = 38;
	int reqSum = 59;
	printPath(root,reqSum);

	return 0;	
}
