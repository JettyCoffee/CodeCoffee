#include <stdio.h>



int main()
{
    char op;
    int num1,num2;
    scanf("%d",&num1);
    while(1)
    {
        scanf("%c",&op);
        if(op == '=')
        {
            double result = num1;
            printf("%.2f",result);
            break;
        }
        if(op != '+' && op!='-' && op != '*' && op != '/')
        {
            printf("ERROR");
            return 0;
        }
        scanf("%d",&num2);
        if(num2 == 0)
        {
            printf("ERROR");
            return 0;
        }
        switch(op)
        {
            case '+':
            num1 = num1 + num2;
            break;
            case '-':
            num1 = num1 - num2;
            break;
            case '*':
            num1 = num1 * num2;
            break;
            case '/':
            num1 = num1 / num2;
            break;
        }
    }
}