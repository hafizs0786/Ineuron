#include<stdio.h>
#include"library.h"
#include"library.c"

int main()
{    
    double angle_at_chowk;

    // Given Linear equation is in format ax+by+c=0;
    // To find intersection angle between both line we need value of a and b only
    double a1 = 5, b1 = 1; //5x+y-3=0
    double a2 = 2, b2 = 3; //2x+3y+1=0

    angle_at_chowk = find_angle(a1,b1,a2,b2);

    printf("Angle at which these roads meet at 123 Chowk: %.2f\n",angle_at_chowk);
    return 0;
}