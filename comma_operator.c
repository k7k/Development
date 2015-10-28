#include <stdio.h>

int main()
{
   int x = 10;
   int y = 15;
  
   printf("X: %d  Y:%d\n", x,y);

   printf("comma operation effected value %d\n",(x,y));
   int z=(++x,y++);
   printf("Z: %d  X: %d Y: %d\n",z,x,y);
  
   int z1=(x++,++y);
   printf("Z1: %d  X: %d Y: %d\n",z1,x,y);
   return 0;
}
