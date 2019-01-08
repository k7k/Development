#include <iostream>

using namespace std;

int main()
{
	//int a[] ={2,-2,3,0,-3,-2,8};
	int a[] ={3,-2,3,2,-3,-2,8};

	int max=0;
	int max_so_far = 0;

	for(int i=0;i<7;++i)
	{
		max = max +a[i];

		if(max < 0)
			max = 0;

		if(max_so_far < max)
			max_so_far = max;
	}

	cout<<"max sum of continuous elements of array: "<< max_so_far<<endl;
	return 0;
}
