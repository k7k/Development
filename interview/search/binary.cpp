#include<iostream>
using namespace std;

int search(int a[],int l,int r, int val)
{
	while(l<=r)
	{
		int m=(l+r)/2;
		if(val == a[m])
			return m;
		if(val > a[m])
			l=m+1;
		else
			r=m-1;
	}
	return -1;
}

int main()
{
	int a[]={1,2,3,4,5,6,7,8,9,10};
	int len=sizeof(a)/sizeof(a[0]);
	cout<<"array: ";
	for(int i=0;i<len;++i) {
		cout<<a[i]<<"  ";
	}
	cout<<"\n";
	int val=12;
	int res=search(a,0,len-1,val);
	if(res == -1)
		cout<<"item not found\n";
	else
		cout<<"item: "<<val<<" found at: "<<res+1<<"\n";
	val=1;
	res=search(a,0,len-1,val);
	if(res == -1)
		cout<<"item not found\n";
	else
		cout<<"item: "<<val<<" found at: "<<res+1<<"\n";
	return 0;
}
