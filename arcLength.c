#include<stdio.h>
#include<math.h>

void main()
{
    float x,y,z, x1,y1,z1, x2,y2,z2, radius,distance,theta,arcLength;
    printf("Enter the co-ordinates of the center of the sphere(x,y,z): ");
    scanf("%f,%f,%f",&x,&y,&z);

    printf("Enter the co-ordinates of the 1st point(x,y,z): ");
    scanf("%f,%f,%f",&x1,&y1,&z1);

    printf("Enter the co-ordinates of the 2nd point(x,y,z): ");
    scanf("%f,%f,%f",&x2,&y2,&z2);

    radius = sqrt( pow(x-x1,2) + pow(y-y1,2) + pow(z-z1,2) );
    distance = sqrt( pow(x2-x1,2) + pow(y2-y1,2) + pow(z2-z1,2) );
    theta = 2*asin( distance/(2*radius) );

    arcLength = radius*theta;
    printf("The smallest arc length between the two points on the sphere is %.2f units.",arcLength);
}