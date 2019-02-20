#include <iostream>
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

NODE* SortedArrToBST(int arr[], int s, int e)
{
	if(s>e)
		return NULL;

	int mid = (s+e)/2;
	NODE *root = getNode(arr[mid]);

	root->llink = SortedArrToBST(arr, s, mid-1);
	root->rlink = SortedArrToBST(arr, mid+1, e);
	return root;
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
	//int a[]={3,14,22,35,48,79,80};
	//int a[]={3,14,22,35,48,79,80,96};
	int a[]={1,2,3,4,5,6,7};
	int len = sizeof(a)/sizeof(a[0]);
	NODE *root = SortedArrToBST(a, 0, len-1);

	preOrder(root);
	cout<<endl;
	return 0;
}
