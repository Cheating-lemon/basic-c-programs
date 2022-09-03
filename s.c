#include<stdio.h>

void swap(int a, int b)
{
    int temp;
    temp=a;
    a=b;
    b=temp;
}
int main()
{
    int a=2,b=3;
    swap(2,3);
    printf("%d,%d",a,b);
    return 0;
}