#include "Tree.h"
#include <vector>

bool printPathUtil(Tree *root,vector<int> &path,int sum)
{
	if(!root)
	{
		return (sum == 0);
	}
	else {
		bool ret = false;
		path.push_back(root->data);
		int tmp = sum-root->data;

		if(root->left == NULL & root->right == NULL & tmp == 0)
			return true;

		if(root->left)
			ret = ret || printPathUtil(root->left,path,tmp);
		if(root->right)
			ret = ret || printPathUtil(root->right,path,tmp);

		if(!ret)
			path.pop_back();

		return ret;
	}
}

void printPath(Tree *root,int sum)
{
	vector<int> path;
	if(printPathUtil(root,path,sum))
	{
		cout<<"Path exist\n";
		for(int i=0;i<path.size();++i)
			cout<<path[i] << " ";

		cout<<endl;
	}
	else{
		cout<<"No such path\n";
	}
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

	int reqSum = 5;
	//int reqSum = 11;
	printPath(root,reqSum);

	return 0;	
}
