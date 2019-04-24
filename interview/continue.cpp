#include <iostream>
using namespace std;

int main()
{

	for(int i=0;i<3;i++)
	{
		cout<<"outer loop------\n";
		for(int j=0;j<3;++j)
		{
			if(j == 1)continue; //go back to last loop (i.e j loop not i loop)
			cout<<"j: "<<j<<" inner loop\n";
		}
	}
	return 0;
}
