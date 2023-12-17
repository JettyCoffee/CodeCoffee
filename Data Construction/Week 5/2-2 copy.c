//求解迷宫问题， 并打印出一条迷宫问题从入口到出口的路径
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

//C语言下的队列基础模型
#define MAXSIZE 36
#define element_type int

typedef struct Maze{
    int MazeMap[MAXSIZE][MAXSIZE];
    int m,n;
    int dir_x[1][1];
    int dir_y[1][1];
}JettyMaze;

typedef struct MazeStack{
    int data[MAXSIZE];
    int x[MAXSIZE],y[MAXSIZE];
    int top;
}JettyStack;

//初始化栈
void initStack(JettyStack *stack){
    stack->top = -1;
}

//入栈
void push(JettyStack *stack, element_type element, int *x, int *y){
    if(stack->top < MAXSIZE - 1){
        stack->data[++stack->top] = element;
        stack->x[stack->top] = x;
        stack->y[stack->top] = y;
    }
}//MAXSIZE - 1是因为top初始为-1

//出栈
element_type pop(JettyStack *stack, int *x, int *y){
    if(stack->top >= 0){
        return stack->data[stack->top--];
        *x = stack->x[stack->top];
        *y = stack->y[stack->top];
    }
    return 0;
}

//检测栈是否为空
int isEmpty(JettyStack *stack){
    return stack->top == -1;
}

void DFSPathFinder(JettyStack *stack, JettyMaze *maze, int x, int y){
    if(x == maze->m || y == maze->n){
        while(stack->top != -1){
            pop(stack,x,y);
            printf("%d '('%d %d')'\n",stack->top,x,y);
        }
        return;
    }
    for(int i=0;i<=1;i++){
        for(int j=0;j<=1;j++){
            if(maze->MazeMap[x+i][y+j] == 0){
                maze->MazeMap[x+i][y+j] = 2;
                push(stack,maze->MazeMap[x+i][y+j],x+i,y+j);
                DFSPathFinder(stack,maze,x+i,y+j);
            } //对当前node的东南西北进行dfs访问
        }
    }
    pop(stack,x,y);//当前元素所有路径可能性均不存在，删除该元素在队列中的
    maze->MazeMap[x][y] = 0;
}

int main(){
    JettyMaze maze;
    JettyStack stack;
    initStack(&stack);
    int m,n;
    scanf("%d%d",&m,&n);
    maze.m = m;
    maze.n = n;
    for(int i=0;i<=m+1;i++){
        for(int j=0;j<=n+1;j++){
            if(i==0 || i==m+1 || j==0 || j==n+1){
                maze.MazeMap[i][j] = 1; //为maze加上墙(假设1为墙)
            }
            else{
                scanf("%d",&maze.MazeMap[i][j]);
            }
        }
    }
    int ini_x=1, ini_y=1;
    DFSPathFinder(&stack,&maze,ini_x,ini_y);
    return 0;
}