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
	cout<<"Items in List are:\n";
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

void delete_front(NODE *head,int val)
{
	
	NODE cur=*head;
	if(*head == NULL)
	{
		cout<<"no nodes present\n";
		return;
	}
	if((*head) != NULL && (*head)->info == val)
	{
		*head = (*head)->link;
		free(cur);
		return;
	}
	NODE prev = NULL;
	while(cur != NULL && cur->info != val)
	{
		prev = cur;
		cur = cur->link;
	}
	if(cur == NULL)
	{
		cout<<"item not found\n";
		return;
	}
	prev->link = cur->link;
	free(cur);
	return;
}

void delete_all(NODE *head)
{
	if(*head == NULL)
	{
		cout<<"No items in the list\n";
		return;
	}
	NODE cur = *head;
	while(cur != NULL)
	{
		cout<<"deleting :"<<cur->info<<"\n";
		
		*head = (*head)->link;
		free(cur);
		cur = *head;
	}
	return;
}
