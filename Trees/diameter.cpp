#include "Tree.h"

int max(int a,int b)
{
	return (a>b)?a:b;
}

int getHeight(struct Tree *root)
{
	if(root == NULL)
		return 0;
	else {
		return (1+ max(getHeight(root->left),getHeight(root->right)));
	}
}

int diameter(struct Tree* tree)
{
	if(tree == NULL)
		return 0;

	int lht=getHeight(tree->left);
	int rht=getHeight(tree->right);

	int ldia=diameter(tree->left);
	int rdia=diameter(tree->right);

	return max(lht+rht+1,max(ldia,rdia));
}

int main()
{

	//tree:	10<--15-->20-->30
	struct Tree* root=getNode(15);
	root->left = getNode(10);
	root->right = getNode(20);

	root->right->right = getNode(30);
	//root->left->right = getNode(8);
	root->right->left = getNode(21);
	root->right->left->left =getNode(22);
	root->right->left->left->right = getNode(23);
	root->right->left->left->right->left = getNode(24);
	root->right->left->left->right->right = getNode(26);

	root->right->right->left = getNode(13);
	root->right->right->left->right = getNode(21);
	
	cout<<"diameter :"<<diameter(root)<<endl;
	return 0;
}
