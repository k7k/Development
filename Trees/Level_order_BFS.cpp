#include "Tree.h"

int getHeight(struct Tree *root)
{
	if(root == NULL)
		return 0;
	else {
		int lht=getHeight(root->left);
		int rht=getHeight(root->right);

		if(lht >rht)
			return (lht+1);
		else return (rht +1);
	}
}

void printLevelNodes(struct Tree* node,int ht)
{
	if(node == NULL)
		return;
	if(ht == 1)
		cout<<node->data<<" ";
	else if(ht >1){
		printLevelNodes(node->left,ht-1);
		printLevelNodes(node->right,ht-1);
	}
}

void printLevelOrder(struct Tree *root)
{
	int h=getHeight(root);
	for(int i=1;i<=h;i++)
		printLevelNodes(root,i);
}

int main()
{

	//tree:	10<--15-->20-->30
	struct Tree* root=getNode(15);
	root->left = getNode(10);
	root->right = getNode(20);
	root->right->right = getNode(30);
	cout<<"\n";
	printLevelOrder(root);	
	return 0;
}
