#include "Tree.h"

void printKdown(Tree* node,int k)
{
	if(node == NULL || k<0)
		return;

	if(k == 0)
	{
		cout<<node->data<<endl;
		return;
	}

	printKdown(node->left,k-1);
	printKdown(node->right,k-1);
}

int printKnodes(Tree* root,int target,int dist)
{
	if(root == NULL)
		return -1;

	if(root->data == target)
	{
		printKdown(root,dist);
		return 0;
	}

	int d1 = printKnodes(root->left,target,dist);
	if(d1 != -1)
	{
		if(d1+1 == dist)
			cout<<root->data<<endl;
		else
			printKdown(root->right,dist-d1-2); //right child 2 edges away from left child

		return d1+1;
	}

	int d2 = printKnodes(root->right,target,dist);
	if(d2 != -1)
	{
		if(d2+1 == dist)
			cout<<root->data<<endl;
		else
			printKdown(root->left,dist-d2-2);
		return d2+1;
	}
	return -1;
}

int main()
{
	Tree *root = getNode(10);
	root->left = getNode(7);
	root->right = getNode(15);
	root->left->left = getNode(5);
	root->left->right = getNode(9);
	root->left->left->left = getNode(3);
	root->left->left->right = getNode(6);
	root->right->left = getNode(14);
	root->right->right = getNode(20);

	int dist = 2;
	printKnodes(root,15,2);

	return 0;
}
