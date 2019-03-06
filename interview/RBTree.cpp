#include <iostream>
#include <queue>
using namespace std;



/**
RED-BLACK tree rules:
- each node has red/black color
- root node is always black
- there are no two adjacent red nodes
- every path from a node to NULL node has same number of black nodes
- NULL node color is black

RBtree with n nodes has height <= 2log(n+1)

most BST operations search/min/max/insert/del take O(height) time.
if we make sure height is remains Log(n) after every insertion/del then above operations take Log(n) time.

AVL tree is more balanced than RB but needs more rotations during insert/del
if less insert/del and more search use AVL
if more insert/del then use RB tree

Alg for Insert:

- make new node color red
- if new node x is root mark color black
- if new node x parent sibling is red then do re-coloring
- if new node x parent sibling is black then do rotation and/or recoloring
*/

enum COLR{
	BLACK,
	RED
};

struct Node
{
	int data;
	bool color;
	struct Node *left;
	struct Node *right;
	struct Node *parent;

	Node(int val)
	{
		data = val;
		color = RED;
		left = right = parent = NULL;
	}
};
typedef struct Node NODE;

NODE* getNode(int val)
{
	struct Node *tmp = new Node(val);
	return tmp;
}


class RBTree
{
	NODE *root;
	protected:

	NODE* insert(NODE *root, NODE *cur);
	void rotateLeft(NODE *&root, NODE *&cur);
	void rotateRight(NODE *&root, NODE *&cur);
	void balanceRBTree(NODE *&root, NODE *&cur);

	public:
	RBTree()
	{
		root = NULL;
	}

	NODE *getRoot() {return root;}
	void RBInsert(int val);
};
void inOrderPrint(NODE *root);
void levelOrderPrint(NODE *root);

void inOrderPrint(NODE *root)
{
	if(root == NULL)
		return;

	inOrderPrint(root->left);
	cout<<root->data<<" ";
	inOrderPrint(root->right);
}

void levelOrderPrint(NODE *root)
{
	if(root == NULL)
		return;

	queue<NODE*> q;
	q.push(root);

	while(!q.empty())
	{
		NODE *tmp = q.front();
		cout<<tmp->data<<" ";
		q.pop();

		if(tmp->left)
			q.push(tmp->left);
		if(tmp->right)
			q.push(tmp->right);
	}
}

NODE* RBTree::insert(NODE *root, NODE *cur)
{
	if(root == NULL)
		return cur;

	if(cur->data < root->data) {
		root->left = insert(root->left, cur);
		root->left->parent = root;
	}

	else if(cur->data > root->data) {
		root->right = insert(root->right, cur);
		root->right->parent = root;
	}
	return root;
}

void RBTree::RBInsert(int val)
{
	NODE *node = getNode(val);
	root = insert(root, node);
	balanceRBTree(root, node);
}

void RBTree::rotateLeft(NODE *&root, NODE *&cur)
{
	NODE *cur_right = cur->right;

	cur->right = cur_right->left;

	if(cur->right != NULL)
		cur->right->parent = cur;

	cur_right->parent = cur->parent;
	
	if(cur->parent == NULL)
		root = cur_right; //if rotated one is root

	else if(cur->parent->left == cur)
		cur->parent->left = cur_right; // update parent childs

	else cur->parent->right = cur_right;

	cur_right->left = cur; //update rotated node
	cur->parent = cur_right;
}

void RBTree::rotateRight(NODE *&root, NODE *&cur)
{
	NODE *cur_left = cur->left;

	cur->left = cur_left->right;

	if(cur->left != NULL)
		cur->left->parent = cur;

	cur_left->parent = cur->parent;

	if(cur->parent == NULL)
		root = cur_left;
	else if(cur == cur->parent->left)
		cur->parent->left = cur_left;
	else
		cur->parent->right = cur_left;

	cur_left->right = cur;
	cur->parent = cur_left;
}

void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void RBTree::balanceRBTree(NODE *&root, NODE *&cur)
{
	cout<<"inside \n";
	NODE *parent = NULL;
	NODE *g_parent = NULL;

	while(root != cur && cur->color != BLACK  && cur->parent->color == RED)
	{
		parent = cur->parent;
		g_parent = cur->parent->parent;

		if(g_parent != NULL && parent == g_parent->left)
		{
			NODE *parent_sibling = g_parent->right; 
			if(parent_sibling != NULL && parent_sibling->color == RED)
			{
				parent->color = BLACK;
				parent_sibling->color = BLACK;
				g_parent->color = RED;
				cur = g_parent;
			}
			else {
				if(cur == parent->right)
				{
					rotateLeft(root, parent);
					cur = parent;
					parent = cur->parent;
				}
				{
					rotateRight(root, g_parent);
					swap(g_parent->color, parent->color);
					cur = parent;
				}
			}
		}
		else //if(g_parent != NULL && parent == g_parent->right)
		{
			NODE *parent_sibling = g_parent->left;
			if(parent_sibling != NULL && parent_sibling->color == RED)
			{
				parent->color = BLACK;
				parent_sibling->color = BLACK;
				g_parent->color = RED;
				cur = g_parent;
			}
			else {
				if(cur == parent->left)
				{
					rotateRight(root, parent);
					cur = parent;
					parent = cur->parent;
				}
				{
					rotateLeft(root, g_parent);
					swap(g_parent->color, parent->color);
					cur = parent;
				}
			}
		}
	}
	root->color = BLACK;
}

int main()
{
	RBTree rbTree;

	rbTree.RBInsert(7);
	rbTree.RBInsert(6);
	rbTree.RBInsert(5);
	rbTree.RBInsert(4);
	rbTree.RBInsert(3);
	rbTree.RBInsert(2);
	rbTree.RBInsert(1);

	cout<<"In order traversal\n";
	inOrderPrint(rbTree.getRoot());
	cout<<endl;
	cout<<"Level order traversal\n";
	levelOrderPrint(rbTree.getRoot());
	cout<<endl;
	return 0;
}
