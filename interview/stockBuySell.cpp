#include <iostream>

using namespace std;

struct interval
{
    int buy;
    int sell;
};

void stockBuySell(int price[], int n)
{
    interval sol[n/2 + 1];
    int count = 0;
    
    int i=0;
    if( n == 1)
        return;
        
    while(i<n)
    {
        while( i<n && price[i+1] <= price[i])
            i++;
        
        if(i == n-1)
            break;
            
        sol[count].buy = i++;
        
        while( i<n && price[i]>=price[i-1])
            i++;
            
        sol[count].sell = i-1;
        count++;
    }
    if(count == 0)
        cout<<"No profit can be made\n";
    else {
        for(int k=0;k<count;k++)
        {
            cout<<sol[k].buy<<" "<<sol[k].sell<<endl;
        }
    }
    return;
}

int main()
{
    int price[] = {100, 180, 260, 310, 40, 535, 695}; 
    int n = sizeof(price)/sizeof(price[0]); 
  
    stockBuySell(price, n); 
  
    return 0; 
}