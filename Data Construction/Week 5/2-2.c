//求解迷宫问题， 并打印出一条迷宫问题从入口到出口的路径
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

//C语言下的队列基础模型
#define MAXSIZE 36
#define element_type int

typedef struct Maze{
    char MazeMap[MAXSIZE][MAXSIZE];
    char visited[MAXSIZE][MAXSIZE];
    int m,n;
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

//取top元素
element_type top(JettyStack *stack){
    return stack->data[stack->top];
}

//检测栈是否为空
int isEmpty(JettyStack *stack){
    return stack->top == -1;
}

void DFSPathFinder(JettyStack *stack, JettyMaze *maze, int x, int y){
    if(x == maze->m || y == maze->n){
        //表示已经找到了了终点
        return;
    }
    for(int i=-1;i<=1;i+2){
        for(int j=-1;j<=1;j+2){
            if(maze->MazeMap[x+i][y+j] == 0){
                maze->MazeMap[x+i][y+j] == 2;
                DFSPathFinder(stack,maze->MazeMap[x+i][y+j],x+i,y+j);
            } //对当前node的东南西北进行dfs访问
        }
    }
    dequeue(stack,x,y);//当前元素所有路径可能性均不存在，删除该元素在队列中的
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
            scanf("%d",&maze.MazeMap[i][j]);
        }
    }
    int ini_x=1, ini_y=1;
    DFSPathFinder(&stack,&maze,ini_x,ini_y);

    return 0;
}