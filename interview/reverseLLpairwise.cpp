#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

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

		while(cur != NULL && cur->link != NULL)
		{
			swap(&cur->data, &cur->link->data);
			cur = cur->link->link;
		}
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
	//ll.push(05);

	ll.print();

	ll.reverse();

	ll.print();
}
