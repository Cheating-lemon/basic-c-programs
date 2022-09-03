#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void sort(float num[]);

void main()
{
    float num[30];
    srand(time(0));
    for (int i = 0; i < 20; i++)
    {
        num[i] = 1 + rand()%10000;
        num[i] = num[i]/100;
    }
    sort(num);
    for(int i = 0; i < 20; i++)
    {
        printf("%.2f\t",num[i]);        
    }
}

void sort(float num[])
{
    float temp;
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 19; j++)
        {
            if (num[j] < num[j+1])
            {
                temp = num[j];
                num[j] = num[j+1];
                num[j+1] = temp;
            }
        }   
    }
}
