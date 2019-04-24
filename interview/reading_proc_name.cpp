#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int agrc, char **argv[])
{
	ifstream comm("/proc/self/comm");
    	string name;
    	getline(comm, name);
	extern char *__progname;
	if(strcmp("proc" /*binary name -o proc */,__progname) == 0) {
    		cout << "name is " << name <<"prog: "<<__progname<<endl;
    		printf("name is %s\n" ,__progname);
	}
    		cout <<"prog: "<<__progname<<endl;
	return 0;
}
