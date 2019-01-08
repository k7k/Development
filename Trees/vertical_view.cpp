#include <iostream>
#include <queue>
#include <map>
#include <vector>

using namespace std;

struct Node{
	int data;
	struct Node* left;
	struct Node* right;
};

typedef struct Node NODE;

NODE* getNode(int val)
{
	NODE *obj= new NODE();
	obj->data = val;
	obj->left = NULL;
	obj->right = NULL;
	return obj;
}

void printVertical(NODE *root)
{
	if(!root)
		return;

	queue<pair<NODE*,int> > q;
	map<int,vector<int> > m;

	NODE *tmp = root;
	int dp =0;
	

	q.push(make_pair(root, 0));
	while(!q.empty())
	{
		pair<NODE*,int> t = q.front();
		dp = t.second;
		tmp = t.first;
		m[dp].push_back(tmp->data);

		q.pop();

		if(tmp->left != NULL)
			q.push(make_pair(tmp->left, dp-1));
		if(tmp->right != NULL)
			q.push(make_pair(tmp->right, dp+1));
	}

	map<int, vector<int> >::iterator it;
	for(it = m.begin(); it != m.end(); ++it) {
		cout<<endl<<it->first<< " : "<<endl;
		for(int i=0;i<it->second.size();++i) {
			cout<<it->second[i]<<"  ";
		}
	}
	cout<<endl;
}

int main()
{
	NODE *root = getNode(1);
	root->left = getNode(2);
	root->right = getNode(3);
	root->left->left = getNode(4);
	root->left->right = getNode(5);
	root->right->left = getNode(6);
	root->right->right = getNode(7);
	root->right->left->right = getNode(8);
	root->right->right->right = getNode(9);
	root->right->right->left = getNode(10);
	root->right->right->left->right = getNode(11);
	root->right->right->left->right->right = getNode(12);

	printVertical(root);
	return 0;
}
