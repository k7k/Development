#include <iostream>
using namespace std;

void printMax(int *arr, int len)
{
    int max1, max2;

    if(len <2){
        cout<<"Error: no sufficent elements\n";
        return;
    }

    if(arr[0] > arr[1]) {
        max1 = arr[0];
        max2 = arr[1];
    }
    else {
        max1 = arr[1];
        max2 = arr[0];
    }

    for(int i=2; i<len-1; ++i)
    {
        if(arr[i] > max1) {
            max2 = max1;
            max1 = arr[i];
        }
        else if(arr[i] > max2)
            max2 = arr[i];
    }
    cout<<"Max "<<max1<<" "<<max2<<endl;
}

/* print 2 largest elements in an unsorted array */
int main()
{
    //int a[]={2,9,34,22,89,21,75,33,69,93,54};
    int a[]={2,99,34,22,21,75,33,169,93,54};
    int len = sizeof(a)/sizeof(a[0]);
    for(int i=0;i<len;++i) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    printMax(a, len);
    return 0;
}
