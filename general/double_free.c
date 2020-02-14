#include <stdio.h>
#include <stdlib.h>

struct A{
	int a;
	int b;
};

int main()
{
	int *p = NULL;
	//free(p); // freeing null ptr , nothing happened libc dependent
	p = (int*)malloc(sizeof(int));
	if(p!=NULL)
	{
		printf("double free here\n");
		free(p);
		//free(p); //double free cause sigabrt
		
	}
	int *ptr;
	//free(ptr); // freeing invalid pointer causes seg fault

	struct A *ptr1=NULL;
	//ptr1->a=10; trying write only will cause seg fault
	free(ptr1); // freeing NULL has no issue



	//freeing static memory
	int a=10;
	int *q = &a;
	printf("*q: %d\n", *q);
	//free(q);//freeing static memory cause ABRT

	int b=10;
	int *bptr = &b;
	//int **dbptr;
	//*dbptr = bptr;
	printf("&b is: %p\n",&b);
	printf("bptr is: %p\n",bptr);
	printf("bptr is: %d\n",*bptr);
	return 0;
}
