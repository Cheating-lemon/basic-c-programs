#include<stdio.h>
#include<stdlib.h>

float num;
float f(float x)
{
    return x*x - num;
}

void main()
{
    float a,b,mid,accuracy;
    printf("Enter the number of which sqrt has to be found: ");
    scanf("%f",&num);
    printf("Enter the initial guess values: ");
    scanf("%f,%f",&a,&b);
    printf("Enter the desired accuracy: ");
    scanf("%f",&accuracy);

    if (f(a)*f(b) > 0)
    {
        printf("The guesses are not suitable.\n");
        exit(0);
    }
    mid = (a+b)/2;
    while ( abs(mid-a) >= accuracy )
    {
        if ( f(mid)==0 )
        {
            break;
        }
        
        if (f(a)*f(mid) > 0)
        {
            a = mid;
        }
        else b = mid;
        
        mid = (a+b)/2;
    }
    printf("\nThe sqrt is: %f",mid);
}