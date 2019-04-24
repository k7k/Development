#include <iostream>
using namespace std;

struct A{
	int a;
};
void fun(int &ref)
{
	cout<<"in fun \n";
	cout<<"&ref :"<<&ref<<endl;
	cout<<"ref :"<<ref<<endl;
}
int main()
{
	struct A ob;
	struct A *ptr;
	ptr=0;
	if(ptr)
		cout<<"I'm coming though null\n";
	if(ptr=&ob)//assignment is done first then if condition evaluation
	{
		cout<<"no crash\n";
		cout<<ptr->a<<endl;
	}

	int a =10;
	int *p = &a;
	cout<<"&p: "<<&p<<" p: "<<p<<" &a: "<<&a<<" *p: "<<*p<<" a: "<<a<<endl; 
	fun(*p);
	return 0;
}
