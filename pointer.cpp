#include<iostream>

using namespace std;

int main()
{
	int a=10;
	int b=20;
	int c=30;
	int *p;
	const int* p1=&a;
	int *const p2=&b; //constant pointer so needs to initialize

	a++;   //actual var is not constant
	*p1++;  
	//p2=&c;      //constant pointer can't be changed
	b++;
	//*p2++;  //modifying read-only pointer
	cout<<*p1<<" " << *p2 <<endl;

	const int d=40;   //const var must be initialized
	const int *p3=&d;
	//d++;  // modifying read-only var
	//p=&d; //assigning const var to non-const pointer
	*p3++;  //non-const pointer so allowed
	//int const e;	 same as 'const int e'

	const int *const p4 = &d;
	//*p4++;  //modifying read-only pointer
	return 0;
}
