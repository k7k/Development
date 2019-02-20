#include <iostream>
using namespace std;

//iterative
bool isMaxHeap(int a[], int n)
{
	// till last internal node
	for(int i=0; i<= (n-2)/2;++i)
	{
		if(a[i] < a[2*i+1] || ( (2*i+2) < n && a[i] < a[2*i+2]))
			return false;
	}
	return true;
}

int main()
{
	int a[]={90,15,10,7,12,2,7,3};
	int l =sizeof(a)/sizeof(a[0]);

	if(isMaxHeap(a,l ))
		cout<<"true\n";
	else 
		cout<<"false\n";

	return 0;

}
