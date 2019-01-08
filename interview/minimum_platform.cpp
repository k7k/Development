#include <iostream>
#include <map>

using namespace std;

void getMinimumPlatform(float a[],float d[],int n)
{
	multimap<float,char> mp;
	int platform_req = 0;
	int result = 0;
	for(int i=0;i<n;++i)
	{
		mp.insert(make_pair(a[i],'a'));
		mp.insert(make_pair(d[i],'d'));
	}

	for(multimap<float, char>::iterator it = mp.begin();it != mp.end();++it)
	{
		if(it->second == 'a')
			platform_req++;
		else platform_req--;

		if(platform_req > result)
			result = platform_req;
	}
	cout<<"platform_req: "<<result<<endl;
}

int main()
{
	float arr[]={9.00, 9.40, 9.50, 11.00, 15.00, 18.00};
	float dep[]={9.10, 10.00, 11.20, 11.30, 19.00, 20.00};
	int sz = sizeof(arr)/sizeof(arr[0]);
	getMinimumPlatform(arr,dep,sz);		
	return 0;
}
