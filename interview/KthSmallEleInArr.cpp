#include <iostream>
using namespace std;

void swap(int *a,int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

class MiniHeap
{
	int *harr;
	int hSize;

	public:
	MiniHeap(int arr[],int size);
	void buildHeap();
	void MiniHeapify(int );
	void getMinimum(){

		if(hSize >1) {
			harr[0] = harr[hSize-1];
			MiniHeapify(0);
		}
		hSize--;
	}
	int getParent(int i) { return (i-1)/2;}
	int getLeft(int i) { return 2*i+1;}
	int getRight(int i) { return 2*i+2;}
	int getMin() { return harr[0];}	
};

MiniHeap::MiniHeap(int arr[],int size)
{
	harr = arr;
	hSize = size;
}

void MiniHeap::buildHeap()
{
	int i = hSize/2 - 1;
	while(i>=0)
	{
		MiniHeapify(i);
		i--;
	}
}

void MiniHeap::MiniHeapify(int i)
{
	int small = i;
	int left = getLeft(i);
	int right = getRight(i);

	if(left<hSize && harr[left]< harr[i])
		small = left;
	if(right<hSize && harr[right] < harr[small])
		small = right;
	if(small != i)
	{
		swap(&harr[small], &harr[i]);
		MiniHeapify(small);
	}
}

void KthSmallestEle(int arr[],int s, int k)
{
	MiniHeap mh(arr, s);
	mh.buildHeap();

	for(int i=0;i<k-1;++i){
		mh.getMinimum();
	}
	cout<<"Minimum ele: "<<mh.getMin()<<endl;
}

void printArr(int arr[],int s)
{
	for(int i=0;i<s;++i)
		cout<<arr[i]<<" ";
	cout<<endl;
}
int main()
{
	int k;
	cout<<"enter K value, so you will see Kth smallest element\n";
	cin>>k;
	int a[]={12,34,66,33,22,76,8};
	int size = sizeof(a)/sizeof(a[0]);
	printArr(a,size);
	KthSmallestEle(a,size,k);
	return 0;
}


