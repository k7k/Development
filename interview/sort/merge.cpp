#include<iostream>
using namespace std;

int merge(int arr[],int l,int mid,int r)
{
	int i,j,k;
	
	int n1=mid-l+1;
	int n2=r-mid;

	int L[n1],R[n2];
	for(i=0;i<n1;i++)
		L[i]=arr[l+i];
	for(j=0;j<n2;j++)
		R[j]=arr[mid+1+j];
	
	i=j=0;
	k=l;
	while(i < n1 && j < n2)
	{
		if(L[i] <= R[j]) {
			arr[k]=L[i];
			i++;
		}
		else{
			arr[k]=R[j];
			j++;	
		}
		k++;
	}

	while(i<n1)
	{
		arr[k++]=L[i++];
	}
	while(j<n2)
	{
		arr[k++]=R[j++];
	}
}

void mergesort(int arr[], int l, int r)
{
	if(l<r)
	{
		int mid=l+(r-l)/2;
		mergesort(arr,l,mid);
		mergesort(arr,mid+1,r);
		merge(arr,l,mid,r);
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
	mergesort(a,0,len-1);
	cout<<"after: ";
	for(int i=0;i<len;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<"\n";
	return 0;
}
