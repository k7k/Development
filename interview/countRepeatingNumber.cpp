#include <iostream>
#include <map>

using namespace std;

int main()
{
	int arr[] ={1,2,3,2,2,4,5,4,6,7,1,3,1,8,5,9,6};
	int len = sizeof(arr)/sizeof(arr[0]);

	map<int,int> mp;
	map<int,int>::iterator it;
	for(int i=0;i<len;++i)
	{
		it = mp.find(arr[i]);
		if(it == mp.end())
		{
			mp[arr[i]] = 1;
		}
		else {
			mp[arr[i]] = (it->second)++;
		}
	}
	cout<<"repeated count:"<<endl;
	for(it = mp.begin();it != mp.end();++it)
	{
		cout<<it->first<<" : "<<it->second<<endl;
	}
	return 0;
}
