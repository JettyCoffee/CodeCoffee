/*字典序最小字符串（指针）
输入两个包含空格的字符串a和b，输出拼接后字典序最小字符串。
字符串a和b拼接：要么a拼接到b后面，要么b拼接到a后面。

输入
第一行一个字符串a。（1<=len(a)<=100000）
第二行一个字符串b。（1<=len(b)<=100000）

输出
输出一行a和b拼接后字典序最小字符串。*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

char Jetty(char *a,char* b){
    if(compareStrings(a,b) < 0){
        printf("%s%s",a,b);
    }
    else{
        printf("%s%s",b,a);
    }
}

int compareStrings(char *str1, char *str2) {
    while (*str1 != '\0' && *str2 != '\0') {
        if (*str1 < *str2)
            return -1;
        else if (*str1 > *str2)
            return 1;
        
        str1++;
        str2++;
    }

    if (*str1 == '\0' && *str2 != '\0')
        return -1;
    else if (*str1 != '\0' && *str2 == '\0')
        return 1;
    
    return 0;
}

int main(){
    char a[100001], b[100001];
    scanf("%s%s", &a,&b);
    Jetty(&a,&b);
}