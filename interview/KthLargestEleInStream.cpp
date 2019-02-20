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
	int getParent(int i) { return (i-1)/2;}
	int getLeft(int i) { return 2*i+1;}
	int getRight(int i) { return 2*i+2;}
	void replaceMin(int x) {
		harr[0] = x; 
		MiniHeapify(0); 
	}
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

void KthLargestEle(int k)
{
	int *arr = new int[k];
	MiniHeap mh(arr, k);

	int val;
	int count = 0;

	while(1)
	{
		cout<<"enter element\n";
		cin>>val;

		if(count<k-1)
		{
			arr[count] = val;
			count++;
		}		
		else
		{
			if(count == k-1)
			{
				arr[count] = val;
				mh.buildHeap();
			}

			else
			{
				if(val > mh.getMin())
					mh.replaceMin(val);
			}
			cout<<k<<"th Largest Element in stream: "<<mh.getMin()<<endl;
			count++;
		}
	}
}

int main()
{
	int k;
	cout<<"Enter K vlaue, so that you will get Kth largest element\n";
	cin>>k;
	KthLargestEle(k);
	return 0;
}


