#include <iostream>

using namespace std;

int main()
{
	int r=3;
	int c=4;
	// row and colum increasing matrix

#if 0
	int a[4][4] = {
					{1,2,3,4},
					{5,6,7,8},
					{9,10,11,12},
					{13,14,15,16},
				};
#endif

	int a[r][c];
	int count = 0;
	for(int i=0;i<r;++i)
	{
		for(int j=0;j<c;++j)
		{
			a[i][j] = ++count; 
		}
	}

	cout <<"Array is: \n";
	for(int i=0;i<r;++i)
	{
		cout<<"{ ";
		for(int j=0;j<c;++j)
		{
			cout<< a[i][j]<<" "; 
		}
		cout<<"}"<<endl;
	}
	int X = 5; //key to find in matrix
	int i=0; //row
	int j = c-1;

	while(i<r && j>=0)
	{
		if(a[i][j] == X) {
			cout<<"found @:( "<<i<<" , "<<j<<" )"<<endl;
			return 0;
		}
		else if(a[i][j] > X)
			j--;
		else i++;
	}
	cout<<"Not found\n";
	return 0;
}
