/**特别的素数

素数又称质数。指一个大于1的自然数，除了1和此整数自身外，不能被其他自然数整除的数。
可莉喜欢特别的素数，特别的素数是指一个素数它的每一位数字之和也是一个素数，
但是可莉不会编程。可莉想请你帮她计算出从n到m范围内所有的特别的素数之和。

输入一行两个由空格分隔的整数n,m。（1<=n<=m<=1000）

输出一个整数，即从n到m范围内所有的特别的素数之和。**/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int sum = 0;
    for(int i=n;i<=m;i++){
        if(i == 1){
        }
        if(i == 2){
            sum = sum + 2;
        }
        if(i > 2){
            int flag1 = 0;
            int flag2 = 0;
            for(int j=2;j<i;j++){
                if(i % j == 0){
                    flag1 = 1;
                }
            }
            int temp = i;
            if(flag1 == 0){
                int temp3=0;
                while(temp != 0){
                    temp3 += temp%10;
                    temp/=10;
                }
                for(int j=2;j<temp3;j++){
                    if(temp3 % j == 0){
                        flag2 = 1;
                    }
                }
            }
            if(flag2 == 0 && flag1 == 0){
                sum += i;
            }
        }
    }
    printf("%d\n",sum);
}