#include <iostream>
using namespace std;

void swap(int *a,int *b)
{
	int temp;
	if(*a != *b)
	{
		temp = *a;
		*a = *b;
		*b = temp;
	}
}

void sortArray(int a[], int sz)
{
	int low=0;
	int mid=0;
	int high=sz-1;

	while(mid <= high) {
		switch(a[mid])
		{
		case 0:
			swap(&a[low++],&a[mid++]);
			break;
		case 1:
			mid++;
			break;
		case 2:
			swap(&a[mid],&a[high--]);
			break;
		}
	}
}

void printArr(int a[], int sz)
{
	for(int i=0;i<sz;++i)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	int a[]={1,0,2,1,1,0,0,2,0,0,2,1};
	//int a[]={1,2,2,1,1,2,1,2,1,1,2,1};
	int len =sizeof(a)/sizeof(a[0]);

	printArr(a,len);
	sortArray(a,len);
	printArr(a,len);
	return 0;
}
