#include <iostream>
#include <cmath>
using namespace std;


/*
Board row and column format
 .
 .
 r5
 r4
 r3
 r2
r1c1 c2 c3 c4 c5 . .

 .
 .
 r5    d21 ru d22
 r4     cl Q cr
 r3    d11 rd d12
 r2
r1c1 c2 c3 c4 c5 . .

*/

int min(int a, int b)
{
    return (a<b? a:b);
}

int getNumOfAttckPos(int n, int k, int x, int y, int *obX, int *obY)
{

    int rw_u = n-x; // row up
    int rw_d = x-1; // row down
    int cl_l = y-1; // column left
    int cl_r = n-y; // column right

    /*diagnoal distance */
    int d11 = min(x-1, y-1);
    int d21 = min(n-x, y-1);
    int d12 = min(x-1, n-y);
    int d22 = min(n-x, n-y);

    for(int i=0; i<k; ++i)
    {
        if(x>obX[i] && y>obY[i] && abs(x-obX[i]) == abs(y-obY[i]))
            d11 = min(d11, x-obX[i]-1);

        if(x<obX[i] && y>obY[i] && abs(x-obX[i]) == abs(y-obY[i]))
            d12 = min(d12, obX[i]-x-1);

        if(x>obX[i] && y<obY[i] && abs(x-obX[i]) == abs(y-obY[i]))
            d21 = min(d21, x-obX[i]-1);

        if(x<obX[i] && y<obY[i] && abs(x-obX[i]) == abs(y-obY[i]))
            d22 = min(d22, obX[i]-x-1);

        if(x == obX[i] && y>obY[i])
            cl_l = min(cl_l, y-obY[i]-1);

        if(x == obX[i] && y<obY[i])
            cl_r = min(cl_r, obY[i]-y-1);

        if(y == obY[i] && x>obX[i])
            rw_d = min(rw_d, x-obX[i]-1);

        if(y == obY[i] && x<obX[i])
            rw_u = min(rw_u, obX[i]-x-1);
    
        cout<<"rw_u :"<<rw_u<<" rw_d: "<<rw_d<<" cl_l: "<<cl_l<<" cl_r: "<<cl_r<<" d11: "<<d11<<" d12: "<<d12<<" d21: "<<d21<<" d22: "<<d22<<endl;    
    }
    return (rw_u + rw_d + cl_l + cl_r + d11 + d12 + d21 + d22);
}

int main()
{
    int x = 4,y=4; //queen position
    int numSize = 8; //board size 8*8 board
    /*array of obstacles positions */
    int obstacleXPosition[] = {6, 3, 4};
    int obstacleYPosition[] = {2, 5, 6};
    int numOfObstacles = sizeof(obstacleXPosition)/sizeof(obstacleXPosition[0]);

    cout<<getNumOfAttckPos(numSize, numOfObstacles, x, y, obstacleXPosition, obstacleYPosition)<<endl;
    return 0;
}
