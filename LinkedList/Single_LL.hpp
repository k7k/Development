#include <malloc.h>
#include <stdlib.h>
#include "Node.hpp"

NODE getNode();
void print(NODE head);
void insert_front(NODE *head,int val);
void insert_rear(NODE *head,int val);
void insert_after_node(NODE prev,int val);
void insert_at_pos(NODE *head,int pos,int val);
void delete_all(NODE *head);
void delete_key(NODE *head,int val);
//Node delete_at_pos(NODE first,int pos);

