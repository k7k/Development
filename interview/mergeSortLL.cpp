#include <iostream>
using namespace std;

struct list{
	int data;
	struct list *link;
};
typedef struct list node;

void printLL(node* head)
{
	node *cur = head;
	while(cur != NULL)
	{
		cout<<cur->data<<" ";
		cur = cur->link;
	}
	cout<<endl;

}

node* getNode(int val)
{
	node* tmp =new node;
	tmp->data = val;
	tmp->link = NULL;
	return tmp;
}

class LL{

	public:
	node *head;
	LL(){
		head = NULL;
	}

	void push(int val)
	{
		node *tmp = getNode(val);
		if(head == NULL){
			head = tmp;
			return;
		}

		node *cur = head;
		tmp->link = head;
		head = tmp;
	}

	void printList()
	{
		node *cur = head;
		while(cur != NULL)
		{
			cout<<cur->data<<" ";
			cur = cur->link;
		}
		cout<<endl;
	}

	void mergeSort(node **headRef)
	{
		node *f, *b;
		if(*headRef == NULL || (*headRef)->link == NULL)
			return;
		splitLL(f,b, *headRef);
		mergeSort(&f);
		mergeSort(&b);
		*headRef = merge(f,b);	
	}

	void splitLL(node *&front, node *&back, node *headRef)
	{
		if(headRef == NULL)
			return;

		node *s = headRef;
		node *f = headRef->link;

		while(f != NULL && f->link != NULL)
		{
			s = s->link;
			f = f->link->link;
		}
		front = headRef;
		back = s->link;
		s->link = NULL;
	}

	node* merge(node *f, node *b)
	{
		node *result;

		//cout<<"front: ";printLL(f);
		//cout<<"back: ";printLL(b);
		if(f == NULL)
			return b;

		else if(b == NULL)
			return f;

		if(f->data <= b->data)
		{
			result = f;
			result->link = merge(f->link, b);
		}
		else
		{
			result = b;
			result->link = merge(f, b->link);
		}

		//cout<<"result: ";printLL(result);
		return result;
	}

	node** getHead() { return &head;}
};



int main()
{
	class LL llist;
	llist.push(20);
	llist.push(30);
	llist.push(60);
	llist.push(10);
	llist.push(50);
	llist.push(90);
	
	llist.printList();
	cout<<endl;
	llist.mergeSort(llist.getHead());

	llist.printList();
	cout<<endl;
	return 0;
}
