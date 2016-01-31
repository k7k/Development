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
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[min])
				min=j;
		}		
		swap(&a[min],&a[i]);
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
