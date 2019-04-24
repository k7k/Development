#include <iostream>
using namespace std;

class A{
	int a;
public:
	A(){
		a=0;
	}
	void show() //this ptr is passed as NULL
	{
	cout <<"show\n"; // no crash
	//	cout<<a<<endl; //crash
	}
};

int main()
{
	A *ptr = NULL;
	ptr->show();
	return 0;
}
