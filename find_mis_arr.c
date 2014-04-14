#include<stdio.h>
 
/* getMissingNo takes array and size of array as arguments*/
int getMissingNo(int a[], int n)
{
    int i;
    int x1 = a[0]; /* For xor of all the elemets in arary */
    int x2 = 1; /* For xor of all the elemets from 1 to n+1 */
     
    for (i = 1; i< n; i++)
        x1 = x1^a[i];
            
    for ( i = 2; i <= n+1; i++)
        x2 = x2^i;        
    
    return (x1^x2);
}
 
/*program to test above function */
int main()
{
    int a[] = {1, 2,3, 4, 5, 6,7,9,10,11};
    int miss = getMissingNo(a,10 );
    printf("%d\n", miss);
    return 0;
}
