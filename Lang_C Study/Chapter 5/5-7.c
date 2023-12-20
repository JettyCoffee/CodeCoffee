#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double funcos(double e,double x);

int main(){
    double e,x;
    scanf("%lf %lf",&e,&x);
    printf("%.6lf",funcos(e,x));
    return 0;
}

double pp(double x,int y){
  	double sum = 1;
    for(int i=1;i<=y;i++){
        sum *= x/i;
    }
    return sum;
}

double funcos(double e,double x)
{
    double cos=0;
    for(int i=0;;i++)
    {
        double temp = pp(x,2*i);
        if(i%2 == 0)
        {
            cos += temp;
        }
        else
        {
            cos -= temp;
        }
        if(temp < e)
        {
            return cos;
        }
    }
}