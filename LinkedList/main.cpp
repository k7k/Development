#include<iostream>
#include "Single_LL.hpp"

using namespace std;

int main()
{
        NODE head=NULL;
	int ch,val;

	for(;;){
	cout<<"Select choice:\n";
	cout<<" \ 
		1. insert_front\n\
		2. insert_rear\n \
		3. insert_after_node\n\
		4. insert_at_pos\n\
		5. delete_key \n\
		6. delete all\n\
		7. print list\n\
		8. exit\n";
	cin>>ch;
	switch(ch)
	{
		char ch;
		case 1:
			cout<<"---------inserting front---------\n";
			do{
			    cout<<"enter value\n";
			    cin>>val;
			    insert_front(&head,val);
			    print(head);
			    cout<<"want to continue y/n:";
			    cin>>ch;
			}while(ch == 'y');
			break;
		case 2:
    			cout<<"----------inserting rear ------------\n";
			do{
			    cout<<"enter value\n";
			    cin>>val;
			    insert_rear(&head,val);
                            print(head);
			    cout<<"want to continue y/n:";
			    cin>>ch;
			}while(ch == 'y');
			break;
		case 3:
        		cout<<"----------inserting after given node-----\n";
			do{
			    cout<<"enter value\n";
			    cin>>val;
			    insert_after_node(head,val);
			    print(head);
			    cout<<"want to continue y/n:";
			    cin>>ch;
			}while(ch == 'y');
			break;
		case 4:
			int pos;
        		cout<<"---------inserting at postion--------\n";
			do{
			    cout<<"enter value\n";
			    cin>>val;
			    cout<<"enter position\n";
			    cin>>pos;
			    insert_at_pos(&head,pos,val);
			    print(head);
			    cout<<"want to continue y/n:";
			    cin>>ch;
			}while(ch == 'y');
			break;
		case 5:
			do{
				int val;
				cout<<"Enter the item to be deleted\n";
				cin >> val;
				delete_key(&head,val);
				cout<<"After deletion items are:\n";
				print(head);
				cout<<"want delete more:y/n ?\n";
				cin>>ch;
			}while(ch == 'y');
			break;
		case 6:
			cout<<"deleting all nodes\n";
			delete_all(&head);
			break;
		case 7:
			cout<<"listing all nodes:\n";
       			print(head);
			break;
		case 8:
			return 0;
		default:
			break;
	}
	}
        return 0;
}
