#include <iostream>
using namespace std;

struct TNode
{
	int data;
	struct TNode *llink;
	struct TNode *rlink;
};

struct LNode
{
	int data;
	struct LNode *link;
};

typedef struct TNode TNODE;
typedef struct LNode LNODE;

TNODE* getTNode(int val)
{
	TNODE *p = new TNODE();
	p->data = val;
	p->llink = NULL;
	p->rlink = NULL;
	return p;
}

void push(LNODE **head, int val)
{
	LNODE *tmp = new LNODE();
	tmp->data = val;
	tmp->link = *head;
	(*head) = tmp;
}

int countNodes(LNODE *head)
{
	int count =0;

	LNODE *tmp = head;
	while(tmp != NULL)
	{
		count++;
		tmp = tmp->link;
	}
	return count;
}

/* bottom up construction */
TNODE* SortedLLToBSTrec(LNODE **head, int n)
{
	if(n<= 0)
		return NULL;

	TNODE *left = SortedLLToBSTrec(head, n/2);
	TNODE *root = getTNode((*head)->data);
	*head = (*head)->link;
	root->llink = left;

	TNODE *right = SortedLLToBSTrec(head,n-n/2-1);
	root->rlink = right;
	return root;
}

TNODE* SortedLLToBST(LNODE *head)
{
	int n = countNodes(head);
	cout<<"node count :"<<n<<endl;

	return SortedLLToBSTrec(&head, n);
}

void preOrder(TNODE *root)
{
	if(root == NULL)
		return;

	cout<<root->data<<" ";
	preOrder(root->llink);
	preOrder(root->rlink);
}

void printL(LNODE *head)
{
	cout<<"List is: \n";
	while(head != NULL)
	{
		cout<<head->data<<" ";
		head =head->link;
	}
	cout<<endl;
}

int main()
{
	LNODE *head = NULL;
	push(&head, 7);
	push(&head, 6);
	push(&head, 5);
	push(&head, 4);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);
	
	printL(head);
	TNODE *root = SortedLLToBST(head);

	cout<<"PreOrder is:"<<endl;
	preOrder(root);
	cout<<endl;
	return 0;
}
