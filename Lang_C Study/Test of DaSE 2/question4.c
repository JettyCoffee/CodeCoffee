/*合并字符串
给定两个字符串，轮流从中取出一个字符，拼接起来，最终合并为一个字符串。
比如str1=“qwe”，str2="asd"，
先从str1中取出‘q’，再从str2中取出'a'，
再从str1中取出'w'，...最终得到"qawsed"
当然，如果其中一个字符串已经遍历完了，
就直接把另一个字符串的剩余部分全部接上：

输入
输入有2行，分别表示要合并的两个字符串，
从第一行的第一个字符开始轮流合并

输出
输出一行，表示合并后的字符串*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

char Jetty(char *a,char* b){
    char str[200001];
    int count = 0;
    for(int i=0;i<200000;i++){
        if(a[i] != '\0'){
            str[count++]=a[i];
        }
        if(b[i] != '\0'){
            str[count++]=b[i];
        }
        if(a[i] == '\0' && b[i] == '\0'){
            break;
        }
    }
    printf("%s",str);
}

int main(){
    char a[100001], b[100001];
    scanf("%s%s", &a,&b);
    Jetty(&a,&b);
}