#include<iostream>
#include<vector>

void minimum_coins(int *arr,int n,int val)
{
	std::vector<int> tmp;
	std::vector<int> res;
	int min_itr=999;
	int itr=0;
	for(int i= n-1;i>=0;--i)
	{
		int j=i;
		while(j>=0 && val > 0){
			if(val >= arr[i])
			{
				val=val-arr[i];
				itr++;
				tmp.push_back(arr[i]);
			}
			else
				j--;
		}
		
		if(val == 0)
		{
			if(min_itr > itr)
			{
				min_itr = itr;
				res = tmp;
				tmp.clear();
			}
		}
	}
	
	std::cout<<"number of coins requied: " << itr<<std::endl;
	for(int i=0;i < res.size();++i)
	{
		
		std::cout<< res[i]<<" ";
	}
	std::cout<<"\n";
}

int main()
{
	int arr[]={1,2,3,10,20,50,100,500};
	int n = sizeof(arr)/sizeof(arr[0]);
	std::cout<<"6 change\n";
	minimum_coins(arr,n,6);
	std::cout<<"434 change\n";
	minimum_coins(arr,n,434);
	std::cout<<"500 change\n";
	minimum_coins(arr,n,500);
	
	std::cout<<"612 change\n";
	minimum_coins(arr,n,612);
	return 0;
}
