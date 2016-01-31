#include<iostream>
using namespace std;

int sort(int a[],int n)
{
	int key;
	int i,j;
	for(i=0;i<n;i++)
	{
		key=a[i];
		j=i-1;	
		while(j>=0 && a[j]>key)
		{
			a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=key;
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
