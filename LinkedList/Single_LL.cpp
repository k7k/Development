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

void insert_at_pos(NODE *head,int pos,int val)
{
	NODE tmp = getNode();
        tmp->info = val;
        tmp->link = NULL;
	NODE cur;
	NODE prev=NULL;
	int count = 1;

	if(pos <= 0)
	{
		cout<<"Invalid position\n";
		return;
	}
	if(pos == 1)
	{
		tmp->link=(*head)->link;
		*head=tmp;
		return;
	}
	cur=*head;
	while(cur->link != NULL && count != pos)
	{
		prev = cur;
		cur=cur->link;
		count++;
	}
	cout<<"count: "<<count<<"\n";
	/* to insert at position after last node*/
	if(count == pos-1)
	{
		cur->link = tmp;
		return;
	}

	if(cur == NULL || count != pos)
	{
		cout<<"position beyond the total number of nodes\n";
		return;
	}
	prev->link = tmp;
	tmp->link = cur;
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
	cout<<"---------inserting at postion--------\n";
	insert_at_pos(&head,1,99);
	insert_at_pos(&head,5,88);
	insert_at_pos(&head,10,77);
	insert_at_pos(&head,13,66);
	print(head);	
	return 0;
}
