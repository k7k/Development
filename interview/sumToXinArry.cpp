#include <iostream>
#include <map>
#include <list>
#include <utility>

using namespace std;

void printList(list<pair<int,int> > &list)
{
	pair<int,int> p;
	std::list<std::pair<int,int> >::iterator it;
	for(it = list.begin(); it!=list.end();++it)
	{
		cout<<(*it).first<<" ";
		//list.pop_front();
	}
	cout<<endl;
}

void getSumXelements(int a[],int sz, int X)
{
	map<int,int> m;
	list<pair<int,int> > l;

	int value = -1;

	for(int i=0;i<sz;++i)
		m[a[i]] = i;

	for(int i=0;i<sz;++i)
	{
		l.clear();
		int j=i;
		value = X - a[j];

		if(value == 0 ) {
			l.push_back(make_pair(a[i],value));
			printList(l);
			l.clear();
		}

		pair<int,int> p;
		while(j<sz)
		{
			if(value > 0 && j<sz) {
				l.push_back(make_pair(a[j],value));
				j++;
				value = value - a[j];
			 }
			else if(value < 0 ){
				p = l.back();
				l.pop_back();
				//cout<<p.first<<" "<<p.second<<endl;
				j = m[p.first]+1; // get index
				p = l.back();
				//cout<<p.first<<" "<<p.second<<endl;
				value = p.second; // get intermidiate X value
				while((value = value - a[j]) < 0 & j<sz) {
					p = l.back();
					l.pop_back();
					j = m[p.first]+1;
					p = l.back();
					value = p.second;
					value = value - a[j];
				}
				
			}
			else if(value == 0) {
				l.push_back(make_pair(a[j],0));
				printList(l);
				p = l.back();
				l.pop_back();
				j = m[p.first]+1;
				p = l.back();
				value = p.second;
				value = value - a[j];
			}
		}
		if(value >0 && (m.find(value) != m.end()))
		{
			cout<<value<<" ";
			printList(l);
		}
	}
}

int main()
{
	int a[]={2,3,6,4,8,11,9,7};
	int n = sizeof(a)/sizeof(a[0]);
	int x = 13;
	cout<<"given array: \n";
	for(int i=0;i<n;++i)
		cout<<a[i]<<" ";
	cout<<"\n--------------------------"<<endl;
	getSumXelements(a,n,x);
	return 0;
}
