#include "Tree.h"

void InOrder(struct Tree *root)
{
	if(root == NULL) return;
	InOrder(root->left);
	cout <<root->data <<" ";
	InOrder(root->right);
}
void PreOrder(struct Tree *root)
{
	if(root == NULL) return;

	cout <<root->data <<" ";
	PreOrder(root->left);
	PreOrder(root->right);
}
void PostOrder(struct Tree *root)
{
	if(root == NULL) return;
	PostOrder(root->left);
	PostOrder(root->right);
	cout <<root->data <<" ";

}

int main()
{

	//tree:	10<--15-->20-->30
	struct Tree* root=getNode(15);
	root->left = getNode(10);
	root->right = getNode(20);
	root->right->right = getNode(30);
	cout<<"Inoreder: \n";
	InOrder(root);
	cout<<"\nPreOrder: \n";
	PreOrder(root);
	cout<<"\n PostOrder: \n";
	PostOrder(root);
	cout<<"\n";
	
	return 0;
}
