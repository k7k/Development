#include<iostream>
using namespace std;

void swap(int *a,int *b)
{
        int tmp=*a;
        *a=*b;
        *b=tmp;
}

/* not working for all cases, needs fix */
int partition(int arr[],int l,int r)
{
	int i,j,p;
	p=arr[l];
	i=l;
	j=r;

	//while(i<j) {
			
		while(arr[i] < p){
			cout<<arr[i]<<"  " <<p<<"\n";
			i++;
		}
		while(arr[j] > p)
			j--;
		if(i<j)	
		swap(&arr[i],&arr[j]);
	//}
	if(i>=j)
		swap(&arr[l],&arr[j]);

	//swap(&arr[l],&arr[j]);
	return j;		
}


void quicksort(int arr[], int l, int r)
{
	if(l<=r)
	{
		int p=partition(arr,l,r);
		//cout<<"P is: " <<p<<"\n";
		quicksort(arr,l,p-1);
		quicksort(arr,p+1,r);
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
	quicksort(a,0,len-1);
	cout<<"after: ";
	for(int i=0;i<len;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<"\n";
	return 0;
}
