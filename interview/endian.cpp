#include <iostream>
using namespace std;

int main()
{
	unsigned int i = 1;
	char *p = (char*)&i;
	
	if(*p)
		cout<<"Little endian\n";
	else cout <<"Big endian\n";

	return 0;
}
