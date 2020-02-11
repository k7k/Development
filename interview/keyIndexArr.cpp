#include <iostream>
#include <cmath>
using namespace std;

void getIndex(int *a, int l,int h, int key, int &finalIndex)
{
    int absKey;
    int negateKey = (-(key));
    int mid;
    int ret;

    if(l<=h)
    {
        mid = (l+h)/2;
        if(key == a[mid] || negateKey == a[mid] )
        {
            //cout<<"came here "<< mid<<" "<<a[mid]<<" "<<negateKey<<endl<<l<<" "<<h<<endl;
            if(key == a[mid])
            {
                finalIndex = mid; // if mid matches, save idex but still search in left of mid
            }
            getIndex(a, l, mid-1, key, finalIndex); //search in left of mid element
            if(finalIndex == -1) //search in right only when mid and left of mid is not found
               getIndex(a, mid+1, h, key, finalIndex); //search in right of mid element 
        }
        else if(key > 0) // ex: key= 20, mid = -30, 20>-30 but we need to check left of mid not right
        {
            absKey = abs(a[mid]);
            //cout<<"pos "<<absKey <<" "<<key<<endl<<l<<" "<<h<<endl;
            if(key < absKey)
                 getIndex(a, l, mid-1, key, finalIndex);
            else
                getIndex(a, mid+1, h, key, finalIndex);
        }
        else if(key < 0) //ex: mid = -20, key = -30 ; -30<-20 but we need to search right side not left
        {
            absKey = abs(key);
            //cout<<"neg "<<absKey <<" "<<a[mid]<<endl<<l<<" "<<h<<endl;;
            if(absKey < a[mid])
               getIndex(a, l, mid-1, key, finalIndex);
            else
                getIndex(a, mid+1, h, key, finalIndex);
        }
    }
}

int main()
{
    /*search a given key first index in an array which is having signed values but are sorted without sign */
    int a[]={10,-20,20,-20,-20,30,-30,30,-30,40};
    int len =sizeof(a)/sizeof(a[0]);
    for(int i=0;i<len; ++i)
        cout<<a[i]<<" ";
    cout<<endl;

    int key1 = 30;
    int key2 = -20;
    int key3 = 20;
    int key4 = 40;
    int key5 = -30;
    int finalIndex = -1;

    cout<<"Key :" <<key1<<" ";
    getIndex(a, 0, len-1, key1, finalIndex);
    cout<<finalIndex<<endl;
    finalIndex =-1;
    cout<<"Key :" <<key2<<" ";
    getIndex(a, 0, len-1, key2, finalIndex);
    cout<<finalIndex<<endl;

    finalIndex =-1;
    cout<<"Key :" <<key3<<" ";
    getIndex(a, 0, len-1, key3, finalIndex);
    cout<<finalIndex<<endl;

    finalIndex =-1;
    cout<<"Key :" <<key4<<" ";
    getIndex(a, 0, len-1, key4, finalIndex);
    cout<<finalIndex<<endl;

    finalIndex =-1;
    cout<<"Key :" <<key5<<" ";
    getIndex(a, 0, len-1, key5, finalIndex);
    cout<<finalIndex<<endl;

    finalIndex =-1;
    getIndex(a, 0, len-1, -25, finalIndex);
    cout<<"Key : -25 "<<finalIndex<<endl; //not found in array

    finalIndex =-1;
    getIndex(a, 0, len-1, 50, finalIndex);
    cout<<"Key : 50 "<<finalIndex<<endl; //not found in array

    return 0;
}
