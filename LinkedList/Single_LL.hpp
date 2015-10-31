#include <malloc.h>
#include <stdlib.h>
#include "Node.hpp"

NODE getNode();
void print(NODE head);
void insert_front(NODE *head);
void insert_rear(NODE *head);
void insert_after_node(NODE *head);
void insert_at_pos(NODE *head,int pos,int val);
void delete_all(NODE *head);
void delete_front(NODE *head,int val);
/*Node delete_rear(NODE first);
Node delete_at_pos(NODE first,int pos);
Node delete_key(NODE first,int key);*/

