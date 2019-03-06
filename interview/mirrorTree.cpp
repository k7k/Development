#include <iostream>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};
typedef struct Node NODE;

NODE* getNode(int val)
{
	NODE *tmp = new NODE;
	tmp->data = val;
	tmp->left = tmp->right = NULL;
	return tmp;
}

void mirror(NODE *&root)
{
	if(root == NULL)
		return;

	if(root->left)
		mirror(root->left);
	if(root->right)
		mirror(root->right);

	if(root->left == NULL && root->right == NULL)
		return;

	NODE *tmp = root->left;
	root->left = root->right;
	root->right = tmp;
}

void inOrder(NODE *root)
{
	if(root == NULL)
		return;

	if(root->left)
		inOrder(root->left);
	cout<<root->data<<" ";
	if(root->right)
		inOrder(root->right);
}

int main()
{
	NODE *root = getNode(20);
	root->left = getNode(10);
	root->left->left  = getNode(5);
	root->left->right  = getNode(15);
	root->right = getNode(30);
	root->right->left = getNode(25);
	root->right->right = getNode(35);

	inOrder(root);
	cout<<endl;
	mirror(root);
	inOrder(root);
	cout<<endl;
	return 0;
}
