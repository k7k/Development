#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
	int tmp;
	if(*a != *b)
	{
		tmp = *a;
		*a = *b;
		*b = tmp;
	}
}

void printArr(int a[],int sz)
{
	for(int i=0;i<sz;++i)
		cout<<a[i]<<" ";
	cout<<endl;
}

int main()
{
	int a[]={1,0,0,1,1};
	//int a[]={1,1,1,1,1};
	int sz = sizeof(a)/sizeof(a[0]);

	printArr(a,sz);

	int low=0;
	int hg = sz-1;
	while(low <= hg)
	{
		if(a[low] == 0) low++;
		else{ 
			swap(&a[low],&a[hg--]);
		}
	}
	
	printArr(a,sz);
	return 0;
}
