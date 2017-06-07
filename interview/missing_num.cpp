#include <iostream>
using namespace std;

int getMissingNum(int a[],int n)
{
	int sum = (n+1)*(n+1+1)/2;
	for(int i=0;i<n;++i)
		sum -= a[i];

	return sum;
}

int getMissNum(int x[],int n)
{
	int a = x[0];
	int b = 1;

	for(int i=1;i<n;++i)
		a = a^x[i];

	for(int i=2;i<=n+1;++i)
		b = b^i;

	return a^b;
}

int main()
{
	int a[] = {1,2,4,5,6,7};
	int b[] = {1,2,3,4,6,7};
	cout <<"Missing num: "<<getMissingNum(a,sizeof(a)/sizeof(a[0]))<<endl;
	cout <<"Missing num: "<<getMissNum(b,sizeof(b)/sizeof(b[0]))<<endl;
	return 0;
}
