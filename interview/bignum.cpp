#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int count(0);

int getNumDigits(int a)
{
	extern int count;
	if(0 != a/10) {
		count++;
		getNumDigits(a/10);
	}
	else
		count++;// single digit
	return count;
}

void getExtendedArry(int *arr,multimap<int, int> &exArr,int maxDigit,int size)
{
	extern int count;
	char str[maxDigit];
	int n =0;
	for(int i=0;i<size;++i)
	{
		snprintf(str,maxDigit,"%d",arr[i]);
		//cout<<str<<endl;
		string s(str);
		//cout<<"---- "<<s<<endl;
		count=0;
		getNumDigits(arr[i]);
		//cout<<"digit "<<count<<endl;
		if(count < maxDigit)
		{
 			s.append(s.substr(0,maxDigit-count)); 
			//cout<<s<<endl;
			while(strlen(s.c_str()) < maxDigit) {
 				s.append(s.substr(0,maxDigit-strlen(s.c_str()))); 
			}
			//cout<<s<<endl;
			exArr.insert(make_pair(atoi(s.c_str()), arr[i]));
		}
	}
}

/* big number formed from an array of numbers */
int main()
{
	int arr[] = {33,35,99,9,2,190}; //9 99 35 33 2 190
	//int arr[] = {3,5,89889,79,21,8989}; //8989 89889 79 5 3 21
	int sz = sizeof(arr)/sizeof(arr[0]);
	extern int count;
	int exArr[sz];

	// get number of digits in max number
	vector<int> v(arr,arr+sz);
	sort(v.begin(),v.end(),greater<int>());

#if 0	
	for(int i=0;i<v.size();++i)
		cout<<v[i]<<" ";
#endif

	getNumDigits(v[0]); //after sort v[0] is max number
	cout<<endl<<count<<endl;

	multimap<int,int> mp;
	//count+1 is because if 998 is max digit then take 4 digit numbers
	getExtendedArry(arr, mp, count+1, sz);
	for(multimap<int,int>::reverse_iterator rit=mp.rbegin(); rit!=mp.rend(); ++rit)
		cout<<"first: " << rit->first<<" second "<<rit->second<<" \n";

	cout<<endl;
	return 0;
}
