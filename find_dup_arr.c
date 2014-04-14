#include<stdio.h>
 

void find_dup(int a[],int size)
{
	int i,j;
	for(i=0;i<size-1;i++){
		for(j=i+1;j<size;j++){
			if(a[j]==a[i]){
				printf("duplicate is present\n");
				break;
			}
		}
	}
} 

int main()
{
    int a[] = {1, 2,3, 4, 5, 6,7,8,10,11};
    find_dup(a,10 );
    return 0;
}
