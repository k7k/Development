#include <iostream>
#include <vector>
using namespace std;

struct Node
{
	int data;
	struct Node *llink;
	struct Node *rlink;
};

typedef struct Node NODE;

NODE* getNode(int val)
{
	NODE *p = new NODE;
	p->data = val;
	p->llink = NULL;
	p->rlink = NULL;
	return p;
}

NODE* SortedArrToBST(vector<NODE*> arr, int s, int e)
{
	if(s>e)
		return NULL;

	int mid = (s+e)/2;
	NODE *root = arr[mid];

	root->llink = SortedArrToBST(arr, s, mid-1);
	root->rlink = SortedArrToBST(arr, mid+1, e);
	return root;
}

void getBSTnodes(NODE *root, vector<NODE*> &v)
{
	if(root == NULL)
		return;
	getBSTnodes(root->llink,v);
	v.push_back(root);
	getBSTnodes(root->rlink,v);
}

NODE* BST(NODE *root)
{
	vector<NODE*> v;
	getBSTnodes(root, v);
	NODE *bbst = SortedArrToBST(v, 0, v.size()-1);
	return bbst;
}

void preOrder(NODE *root)
{
	if(root == NULL)
		return;

	cout<<root->data<<" ";
	preOrder(root->llink);
	preOrder(root->rlink);
}

int main()
{
	NODE *root = getNode(10);
	root->llink = getNode(8);
	root->llink->llink = getNode(7);
	root->llink->llink->llink = getNode(6);
	root->llink->llink->llink->llink = getNode(5);
	
	preOrder(root);
	cout<<endl;
	root = BST(root);
	preOrder(root);
	cout<<endl;
	return 0;
}
