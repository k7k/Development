#include<iostream>
using namespace std;

int bioCoe(int n, int k)
{
    int res = 1;
    if(k>n-k)
        k=n-k;
    for(int i=0;i<k;i++)
    {
        res = res*(n-i);
        res = res/(i+1);
    }
    return res;
}

int main()
{
    cout<<bioCoe(7,2)<<endl;
    cout<<bioCoe(5,2)<<endl;
    return 0;
}
