#include<iostream>
using namespace std;
#define MAX 99999;

int getMax(int a, int b)
{
	return (a>b)?a:b;
}

int getNumEggDrop(int e,int f)
{
	int dp[e+1][f+1];
	int tmp;

	for(int i=1;i<=e;i++) {
		dp[i][0] = 0;
		dp[i][1] = 1;
	}

	for(int i=1;i<=f;i++) {
		dp[1][i] = i;
	}

	for(int i=2; i<=e ;i++) {
		for(int j=2;j<=f;j++) {
			dp[i][j] = MAX;
			for (int x=1;x<=j;x++) {
				tmp = 1 + getMax(dp[i-1][j-1],dp[i][j-x]);
				if(tmp < dp[i][j])
					dp[i][j] = tmp;
			}
		}
	}
	return dp[e][f];
}

int main()
{
	int eggs = 4;
	int floors = 10;//36;
	int res = getNumEggDrop(eggs, floors);

	
	cout<<"NumEggDrops: "<<res<<endl;
	return 0;
}
