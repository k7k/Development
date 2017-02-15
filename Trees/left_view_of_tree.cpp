#include "Tree.h"

void printViewUtil(Tree *root,int level,int *max_level)
{
	if(!root)
		return;

	if(*max_level < level)
	{
		cout<< root->data << " ";
		*max_level = level; 
	}

	printViewUtil(root->left,level+1,max_level);
	printViewUtil(root->right,level+1,max_level);
}

void printLeftView(Tree *root)
{
	int max_level = 0;
	printViewUtil(root,1,&max_level);
}

int main()
{

	/* left view 10,28,14,21 */
	Tree *root = getNode(10);
	root->left = getNode(28);
	root->right = getNode(13);	
	root->right->left = getNode(14);	
	root->right->right = getNode(15);	
	root->right->left->left = getNode(21);	
	root->right->left->right = getNode(22);	
	root->right->right->left = getNode(23);	
	root->right->right->right = getNode(24);

	printLeftView(root);

	return 0;	
}
