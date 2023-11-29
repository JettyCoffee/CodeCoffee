#include <stdio.h>

double dist(double x1, double y1, double x2, double y2);

int main(){
    double x1,y1,x2,y2;
    scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
    double diameter = dist(x1,y1,x2,y2);
    printf("%.2lf",diameter);
    return 0;
}

#include <math.h>
double dist(double x1, double y1, double x2, double y2)
{
    double diameter = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
    return diameter;
}