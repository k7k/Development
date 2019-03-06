#include <iostream>
#include <string>
using namespace std;


void perm(string str, string out)
{
	if(str.size() == 0) {
		cout<<out<<endl;
		return;
	}

	for(int i=0;i<str.size();++i)
	{
		//cout<<str<<endl;
		perm(str.substr(1), out+str[0]);
		rotate(str.begin(), str.begin()+1,str.end());
	}
}

int main()
{
	string str="abc";
	perm(str,"");
	return 0;
}
