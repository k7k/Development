#include <iostream>
#include <string>
using namespace std;

void addBinaryStr(string str1, string str2)
{
	string res="";
	int sum = 0;

	int i=str1.size()-1;
	int j=str2.size()-1;

	while(i>=0 || j>=0 || sum==1)
	{
		sum += (i>=0 ? str1[i]-'0':0);
		sum += (j>=0 ? str2[j]-'0':0);

		res = char(sum%2 + '0') + res;
		sum /=2;
		i--;
		j--;
	}
	cout<<"Result string "<<res<<endl;
}

int main()
{
	string str1 = "1001";
	string str2 = "1101";
	cout<<"str1: "<<str1<<" str2: "<<str2<<endl;
	addBinaryStr(str1,str2);
	return 0;
}
