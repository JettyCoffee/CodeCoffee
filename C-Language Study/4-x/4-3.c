#include <stdio.h>
#include <math.h>

int main(){
    int n,fenzi,fenmu,mid;
    fenzi = 2;
    fenmu = 1;
    double out = 2.0;
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        mid = fenmu;
        fenmu = fenzi;
        fenzi = mid + fenzi;
        out += (double)fenzi / (double)fenmu;
    }
    printf("%.2lf", out);
    return 0;
}

