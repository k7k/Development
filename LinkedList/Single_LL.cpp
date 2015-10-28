#include "Single_LL.hpp"

NODE getNode()
{
	NODE x;
	x= (NODE)malloc(sizeof(struct Node));
	if(x == NULL)
	{
		cout<<"out of memory\n";
		exit(1);
	}
	return x;
}

void print(NODE head)
{
	for(NODE tmp = head; tmp != NULL; tmp = tmp->link)
	{
		cout<<tmp->info<<" "<<std::endl;
	}
}

void insert_front(NODE *head,int val)
{
        NODE tmp = getNode();
        tmp->info = val;
        tmp->link = *head;
        *head = tmp;
}

void insert_rear(NODE *head,int val)
{
	NODE tmp = getNode();
	tmp->info = val;
	tmp->link = NULL;
        NODE cur=*head;
	
	/*inserting first node */
	if (cur == NULL)
	{
		*head = tmp;
		return;
	}
	while(cur->link != NULL)
	{
		cur=cur->link;
	}
	cur->link = tmp;
	return;
}

void insert_after_node(NODE prev,int val)
{
	NODE tmp = getNode();
        tmp->info = val;
        tmp->link = NULL;
	if(prev == NULL)
	{
		cout<<"given previous node can't be NULL\n";
		return;
	}
	tmp->link=prev->link;
	prev->link=tmp;
	return;
}

int main()
{
	NODE head=NULL;
	cout<<"---------inserting front---------\n";
	insert_front(&head,10);
	insert_front(&head,20);
	insert_front(&head,30);
	print(head);
	cout<<"----------inserting rear ------------\n";
	insert_rear(&head,40);
        insert_rear(&head,50);
	print(head);
	cout<<"----------inserting after given node-----\n";
	insert_after_node(head,111);
	insert_after_node(head->link->link,222);
	insert_after_node(head->link->link->link->link,333);
	print(head);
	return 0;
}
