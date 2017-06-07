#include <iostream>
using namespace std;

void findAvg(int a[],int n)
{
	static float avg = 0;
	for(int i=0;i<n;++i) {
		avg = (avg*i+a[i])/(i+1); //prev_avg*n+new_num/n+1
		cout <<avg <<" ";
	}
	cout<<endl;
}

int main()
{
	int a[] = {10,20,30,40,50,60};
	/* 1 -- 10
	   2 -- 10,20 = 15
           3 -- 10,20,30 = 20
	   4 -- 10,20,30,40 = 25
	*/

 	int numElements = sizeof(a)/sizeof(a[0]);
	findAvg(a,numElements);
	return 0;
}
