#include<stdio.h>
struct {
  int num1;
  float num2;
  char a;
  char b[10];
  short i;
  
}a[2];

void main()
{
  int start,last;
  start = &a[0].num1;
  last = &a[1].num1;
  printf("\nSize of Structure : %d Bytes",(last-start));
  printf("\n size from operator is %d Bytes\n", sizeof(a[0]));
}
