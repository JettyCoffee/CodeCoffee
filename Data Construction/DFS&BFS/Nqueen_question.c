/*N皇后问题
描述

如何在N*N的棋盘上放置N枚棋子，使得任意两个棋子不出现在同一直线上？一共有多少种方法


输入
1个整数，放置棋子个数N


输出
1*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXSIZE 36
#define element_type int

typedef struct Maze{
    int Map[MAXSIZE][MAXSIZE];
    int n,count;
}JettyMaze;

int check(JettyMaze *maze,int row, int column){
    for(int i=0; i<row; i++){
        if(maze->Map[i][column] == 1){
            return -1;
        }
    }
    for(int i=row,j=column;i>=0 && j>=0; i--, j--){
        if(maze->Map[i][j] == 1){
            return -1;
        }
    }
    for(int i=row,j=column;i>=0 && j<maze->n; i--, j++){
        if(maze->Map[i][j] == 1){
            return -1;
        }
    }
    return 1;
}

void DFSPathFinder(JettyMaze *maze, int row){
    if(row == maze->n){
        maze->count++;
        return;
    }
    for(int column = 0;column<maze->n;column++){
        if(check(maze,row,column) == 1){
            maze->Map[row][column] = 1;
            DFSPathFinder(maze,row+1);
            maze->Map[row][column] = 0;
        }
    }
}

int main(){
    JettyMaze maze;
    scanf("%d",&maze.n);
    maze.count = 0;
    for(int i=0;i<maze.n;i++){
        for(int j=0;j<maze.n;j++){
            maze.Map[i][j] = 0;
        }
    }
    DFSPathFinder(&maze,0);
    printf("%d",maze.count);
    return 0;
}