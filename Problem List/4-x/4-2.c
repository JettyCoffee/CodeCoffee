#include <stdio.h>
#include <math.h>

double fact(int n){
    double result = 1.0;
    for(int a=2;a<=n;a++){
        result *= a;
    }
    return result;
}

int main(){
    double x,s,i;
    i=0.0;
    x=0.0;
    s=1.0;
    int n=1;
    scanf("%lf",&x);
    do
    {
        i = pow(x,n) / (double)fact(n);
        s += i;
        n++;
    }while (fabs(i) >= 0.00001);
    printf("%.4lf",s);
    return 0;
}
