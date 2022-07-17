/* NOTE: Try using left & right shift operator to achieve same */
#include <iostream>

using namespace std;

void swap(int a[], int s, int e)
{
    int tmp;
    while(s<e) {
    tmp = a[s];
    a[s++] = a[e];
    a[e--] = tmp;
    }
}

void leftRorate(int a[], int n, int d)
{
    if (d == 0)
    return;
    
    if(d>n)
    d = n%d;
    
    swap(a, 0, d-1);
    swap(a, d, n-1);
    swap(a, 0, n-1);
}

void printArr(int a[], int n)
{
    for(int i=0;i<n;++i)
        cout<<a[i]<<" ,";
    cout<<endl;
}

int main()
{
    int a[]={1,2,3,4,5,6,7,8,9};
    int n = sizeof(a)/sizeof(a[0]);
    printArr(a, n);
    leftRorate(a, n, 4);
    cout<<"after rotate \n";
    printArr(a, n);
    
    return 0;
}
