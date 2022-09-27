#include<stdio.h>
#include"library.h"
#include"library.c"

int main()
{
    double area;

    double x1 = 20.077, y1 = 11.598; //1st coordinate
    double x2 = 26.526, y2 = 90.138; //2nd coordinate
    double x3 = 23.674, y3 = 32.579; //3st coordinate

    double area_under_A = find_area(x1,y1,x2,y2,x3,y3);
    printf("Area to be coloured black: %.2f square unit\n",area_under_A);
    return 0;
}