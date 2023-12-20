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
    int out_x,out_y;
}JettyMaze;

typedef struct Stack{
    int data[MAXSIZE];
    int x[MAXSIZE],y[MAXSIZE];
    int top;
}JettyStack;

//初始化栈
void initStack(JettyStack *stack){
    stack->top = -1;
}

//入栈
void push(JettyStack *stack, element_type element, int x, int y){
    if(stack->top < MAXSIZE - 1){
        stack->data[++stack->top] = element;
        stack->x[stack->top] = x;
        stack->y[stack->top] = y;
    }
}//MAXSIZE - 1是因为top初始为-1

//出栈
element_type pop(JettyStack *stack, int *x, int *y){
    if(stack->top >= 0){
        *x = stack->x[stack->top];
        *y = stack->y[stack->top];
        return stack->data[stack->top--];
    }
    return 0;
}

//检测栈是否为空
int isEmpty(JettyStack *stack){
    return stack->top == -1;
}

void DFSPathFinder(JettyStack *stack, JettyMaze *maze, int x, int y){
    /*if(x == 1 && y == 1){
        maze->MazeMap[maze->m][maze->n] = 0;
    }*/
    if(x == maze->out_x && y == maze->out_y){
        /*while(stack->top != -1){
            printf("%d '('%d %d')'\n",stack->top,stack->x[stack->top],stack->y[stack->top]);
            pop(stack,&x,&y);
        }*/
        for(int i=1;i<=8;i++){
            for(int j=1;j<=8;j++){
                if(j != 8){
                    printf("%d ",maze->MazeMap[i][j]);
                }
                if(j == 8){
                    if(i==8){
                        printf("%d",maze->MazeMap[i][j]);
                    }
                    else{
                        printf("%d\n",maze->MazeMap[i][j]);
                    }
                }
            }
        }
        exit(0);
    }
    if(maze->MazeMap[x+1][y] == 0){
        maze->MazeMap[x+1][y] = 2;
        push(stack,maze->MazeMap[x+1][y],x+1,y);
        DFSPathFinder(stack,maze,x+1,y);
    }
    if(maze->MazeMap[x][y+1] == 0){
        maze->MazeMap[x][y+1] = 2;
        push(stack,maze->MazeMap[x][y+1],x,y+1);
        DFSPathFinder(stack,maze,x,y+1);
    }
    if(maze->MazeMap[x-1][y] == 0){
        maze->MazeMap[x-1][y] = 2;
        push(stack,maze->MazeMap[x-1][y],x-1,y);
        DFSPathFinder(stack,maze,x-1,y);
    }
    if(maze->MazeMap[x][y-1] == 0){
        maze->MazeMap[x][y-1] = 2;
        push(stack,maze->MazeMap[x][y-1],x,y-1);
        DFSPathFinder(stack,maze,x,y-1);
    }
    /*for(int i=-1;i<=1;i++){
        for(int j=-1;j<=1;j++){
            if(maze->MazeMap[x+i][y+j] == 0 && ( i == 0 || j == 0 ) ){
                maze->MazeMap[x+i][y+j] = 2;
                push(stack,maze->MazeMap[x+i][y+j],x+i,y+j);
                DFSPathFinder(stack,maze,x+i,y+j);
            } //对当前node的东南西北进行dfs访问
        }
    }*/
    pop(stack,&x,&y);//当前元素所有路径可能性均不存在，删除该元素在队列中的
    maze->MazeMap[x][y] = 0;
}

int main(){
    JettyMaze maze;
    JettyStack stack;
    initStack(&stack);
    //int m,n;
    //scanf("%d%d",&m,&n);
    maze.m = 8;
    maze.n = 8;
    for(int i=0;i<=8+1;i++){
        for(int j=0;j<=8+1;j++){
            if(i==0 || i==8+1 || j==0 || j==8+1){
                maze.MazeMap[i][j] = 1; //为maze加上墙(假设1为墙)
            }
            else{
                scanf("%d",&maze.MazeMap[i][j]);
            }
        }
    }
    int in_x, in_y;
    scanf("%d%d%d%d",&in_x,&in_y,&maze.out_x,&maze.out_y);
    in_x += 1;
    in_y += 1;
    maze.out_x += 1;
    maze.out_y += 1;
    maze.MazeMap[in_x][in_y] = 2;
    DFSPathFinder(&stack,&maze,in_x,in_y);
    return 0;
}