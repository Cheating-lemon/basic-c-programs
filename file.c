#include<stdio.h>
#include<math.h>
//#include<stdlib.h>

void main()
{
    FILE *fp;
    int n,sum=0,num,count = 0;
    float mean,sd,sumsd;
    fp = fopen("mean.dat","w");
    /*if (fp == NULL)
    {
        printf("Can't open the file.");
        exit(0);
    }*/
    
    
    //writing to the file
    printf("Enter some numbers(to stop use ctrl+Z):\n");
    while (scanf("%d",&n) != EOF)
    {
        fprintf(fp,"%d ",n);
    }
    fclose(fp);

    //reading the file
    fp = fopen("mean.dat","r");
    printf("\nThe numbers stored in the file are: ");
    while (fscanf(fp,"%d ",&num) != EOF)
    {
        printf("%d ",num);
        sum += num;
        sumsd += num*num;
        count++;
    }
    fclose(fp);
    mean = sum/count;
    sd = sqrt( (sumsd/count)-(mean*mean) );
    printf("\nMean = %.2f\n",mean);
    printf("Standard Deviation = %.2f",sd);
}