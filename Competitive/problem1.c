#include<stdio.h>

int main()
{
    int x,copy,rem=0;
    printf("Enter a number: ");
    scanf("%d",&x);
    copy=x;
    while(copy)
    {
        rem = rem*10 + copy%10;
        copy = copy/10;
    }
    if(x<0 || x!=rem)
        printf("False");
    else
        printf("True");
    return 0;
}