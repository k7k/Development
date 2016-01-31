#include<iostream>
using namespace std;

void swap(int *a,int *b)
{
	int tmp=*a;
	*a=*b;
	*b=tmp;
}

int sort(int a[],int n)
{
	int i,j,min;
	bool swapped;
	for(i=0;i<n-1;i++)
	{
		swapped=false;
		for(int j=0;j<n-i-1;j++)
		{
			if(a[j] > a[j+1]) {
				swap(&a[j],&a[j+1]);
				swapped=true;
			}
		}
		if(swapped == false)
			break;
	}
}


int main()
{
	int a[]={2,43,4,12,33,54,32,76,56,86};
	int len=sizeof(a)/sizeof(a[0]);
	cout<<"before: ";
	for(int i=0;i<len;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<"\n";
	sort(a,len);
	cout<<"after: ";
	for(int i=0;i<len;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<"\n";
	return 0;
}
