#include <stdio.h>

int main(){
    int a,n,out,mid;
    mid = 0;
    scanf("%d %d",&a,&n);
    for(int i=1;i<=n;i++){
        mid = mid *10 +a;
        out += mid; 
    }
    printf("%d\n",out);
    return 0;
}