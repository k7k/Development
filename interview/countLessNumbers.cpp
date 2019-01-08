#include <iostream>

using namespace std;
#define MAX 999

void countLessDigits(int a[],int m,int b[],int n)
{
	int hash[MAX]={0}; //you can also take map<int,int>

	cout <<"b : ";
	for(int i=0;i<n;i++) {
		cout <<b[i]<<" ";
		hash[b[i]]++;
	}
	cout<<endl;

#if 0 // this other way of counting
	for(int i=0;i<MAX;++i)
		hash[i] += hash[i-1];
#endif

	for(int i=0;i<m;++i) {
		cout<< a[i]<<" : ";
		int tmp = 0;
		while(a[i] >= 0) {
			tmp += hash[a[i]--];
			//cout <<"tmp: "<<tmp<<endl;
		}
		cout<<tmp<<endl;
	}
}

int main()
{
	/* couting number of digits in 'b' lesser than the each digit in 'a' */
	int a[]={23,14,6,38,7,1};
	int b[]={33,11,22,5,61};
#if 0
	int a[]={2,4,6,8,9,1};
	int b[]={3,1,2,5,11};
#endif 
	int sz1 = sizeof(a)/sizeof(a[0]);
	int sz2 = sizeof(b)/sizeof(b[0]);

	countLessDigits(a,sz1,b,sz2);

	return 0;
}
