#include <iostream>
using namespace std;

bool powerOf2(int n)
{
	if(n == 1)
		return true;
	if( n == 0 )
		return false;

	if(n%2 == 0)
		return powerOf2(n/2);
	else return false;
}

bool powerOF2(int n)
{
	// power 2 means 1 bit is set, if n is power of 2 doing n-1 set all other bits to 1 expect original set bit
	// first n is for 0
	return n && (!(n & (n-1)));
}

int main()
{
	int n = 255;
	//int n = 0;
	if(powerOf2(n))
		cout<<n<<" is power of 2\n";
	else
		cout<<n<<" is not power of 2\n";	

	if(powerOF2(n))
		cout<<n<<" is power of 2\n";
	else
		cout<<n<<" is not power of 2\n";

	return 0;	
}
