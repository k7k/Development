#include <iostream>
#include <execinfo.h>
using namespace std;

int main()
{
	cout<<"starting here";
	int a =1;
	cout<<"a "<<a<<endl;
	cout<<"long way to go";
	int b = 2;
	cout<<"b "<<b<<endl;;
	cout<<"now call stack trace";
	void* addrlist[64];

	int addrlen = backtrace(addrlist, sizeof(addrlist) / sizeof(void*));
	if (addrlen == 0) {
		cout<<"no trace\n";
		return -1;
	}

	char** symbollist = backtrace_symbols(addrlist, addrlen);
	cout<<"Trace: \n";
	for(int i=0;i<addrlen;++i)
	{
		cout<<addrlist[i]<<": "<<symbollist[i]<<endl;
		printf("0x%x : %s\n",addrlist[i],symbollist[i]);
	}
	free(symbollist);	
	return 0;
}
