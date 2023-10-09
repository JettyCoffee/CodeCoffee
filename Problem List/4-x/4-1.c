#include <stdio.h>

int main(){
    int num,input,o;
    num = 0;
    while (1)
    {
        scanf("%d", &input);
        if(input % 2 == 1){
            num += input;
        }
        if(input <= 0){
            break;
        }
    }
    printf("%d",num);
    return 0;
}