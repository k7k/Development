#include <iostream>
using namespace std;

struct Node{
	int data;
	struct Node *link;
};

class LL{

	struct Node *head;
	public:
	LL(){
		head = NULL;
	}

	void push(int val)
	{
		struct Node *tmp = new struct Node;
		tmp->data = val;
		tmp->link = head;
		head = tmp;
	}

	void print()
	{
		struct Node *tmp = head;
		while(tmp != NULL)
		{
			cout<<tmp->data<<" ";
			tmp = tmp->link;
		}
		cout<<endl;
	}

	void reverse()
	{
		struct Node *cur = head;
		struct Node *prev = NULL;
		struct Node *next = NULL;

		while(cur != NULL)
		{
			next = cur->link;
			cur->link = prev;
			prev = cur;
			cur = next;	
		}
		head = prev;
	}
};

int main()
{
	class LL ll;
	ll.push(50);
	ll.push(40);
	ll.push(30);
	ll.push(20);
	ll.push(10);

	ll.print();

	ll.reverse();

	ll.print();
}
