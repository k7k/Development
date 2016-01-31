#include <iostream>
#include <stdlib.h>
using namespace std;

struct Tree {

	int data;
	struct Tree *left;
	struct Tree *right;
};


struct Tree* getNode(int info)
{
	struct Tree *tmp=(struct Tree*)malloc(sizeof(struct Tree));
	tmp->data = info;
	tmp->left=NULL;
	tmp->right=NULL;
	return tmp;
}
