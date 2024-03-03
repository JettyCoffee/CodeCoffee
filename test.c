#include <stdio.h>


void main(){
    int *p;
    void pp(int a, int *b,int *p);
    int a=1,b=2,c=3;
    p=&a;
    pp(a+b,p,p);
    printf("1:%d %d %d",a,b,p);
    pp(a-c,p,p);
}

void pp(int a, int *b, int *p){
    static int c=4;
    c++;
    *p=*b+c;
    a=*p-c;
    printf("2:%d %d %d",a,*b,*p);
}