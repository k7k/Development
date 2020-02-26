#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node* link;
};
typedef struct Node NODE;

NODE* getNode(int val)
{
    NODE *tmp = new NODE;
    tmp->data = val;
    tmp->link = NULL;
    return tmp;
}

class LL {

public:
    NODE *head;
    
    LL()
    {
        head = NULL;
    }
    ~LL()
    {
        cout<<"Destructor called\n";
        NODE *tmp;
        while(head != NULL)
        {
            tmp = head;
            head = head->link;
            delete(tmp);
        }
    }
    NODE* getHead() { return head;}

    void addNode(int val)
    {
        if(head == NULL)
            head = getNode(val);
        else {
            NODE *tmp = head;
            while(tmp->link != NULL)
            {
                tmp= tmp->link;
            }
            tmp->link = getNode(val);
        }
    }

    void printLL()
    {
        NODE* tmp = head;
        while(tmp!=NULL)
        {
            cout<<tmp->data<<" ";
            tmp = tmp->link;
        }
        cout<<endl;
    }

    void deleteNodes(int sum)
    {
        NODE *cur = head;
        NODE *prev = NULL; //previous to first ptr
        NODE *first = NULL; // start of sequence node summing to "sum"
        NODE *last = NULL; //end of sequence node summing to "sum"

        int remSum;
        for(;cur != NULL;cur=cur->link)
        {
            remSum = sum;
            if(cur->data <= remSum) {
                first = cur;
                last = cur;
                remSum -=cur->data;
                if(remSum >0)
                {
                    NODE *tmp = cur->link;
                    while(remSum >0 && tmp != NULL)
                    {
                        last = tmp;
                        remSum -=tmp->data;
                        tmp =tmp->link;
                    }
                }
            }
            if(remSum == 0) break;
            prev = cur;
        }

        if(remSum != 0)
            cout<<"No Node Found for given sum\n";
        else if(prev == NULL) //first node or removal required from head
        {
            cur = head;
            head = last->link;
            delete cur;            
        }
        else if(first != NULL && last != NULL){
            prev->link = last->link;
            while(first != last->link)
            {
                //cout<<first->data<<endl;
                cur = first;
                first = first->link;
                delete cur;
            }
        }
    }
};

int main()
{
    LL objLL;
    objLL.addNode(20);
    objLL.addNode(10);
    objLL.addNode(15);
    objLL.addNode(25);
    objLL.addNode(30);
    objLL.addNode(20);

    objLL.printLL();
    int sum=123;//120;//100;//15;//20;//45;//55;//40,75,50
    cout<<"Sum: "<<sum<<endl;
    objLL.deleteNodes(sum);
    objLL.printLL();
    return 0;
}

