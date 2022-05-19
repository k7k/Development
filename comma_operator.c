#include <stdio.h>

int main()
{
   int x = 10;
   int y = 15;
  
   printf("X: %d  Y:%d\n", x,y);

   /* comma as operator:
   
      The comma operator (represented by the token, ) is a binary operator that evaluates its first operand and discards the result, 
      it then evaluates the second operand and returns this value (and type).
      The comma operator has the lowest precedence of any C operator, and acts as a sequence point. 
      
      int i = (5, 10); 10 is assigned to i
      int j = (f1(), f2()); f1() is called (evaluated) first followed by f2().The returned value of f2() is assigned to j 

      comma as a separator
      int a = 1, b = 2;
      
      Comma acts as a separator here and doesn't enforce any sequence.
       Therefore, either f1() or f2() can be called first 
        void fun(f1(), f2());
   */
   printf("comma operation effected value %d\n",(x,y));
   int z=(++x,y++);
   printf("Z: %d  X: %d Y: %d\n",z,x,y);
  
   int z1=(x++,++y);
   printf("Z1: %d  X: %d Y: %d\n",z1,x,y);
   return 0;
}
