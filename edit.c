#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

//C语言下的队列基础模型
#define MAXSIZE 36
#define element_type char

typedef struct Finder{
    double distance[MAXSIZE];
    char letter[MAXSIZE];
}Finder;

typedef struct Location{
    int x,y;
}LetterLocation;

//队列结构体
typedef struct Queue{
    char data[MAXSIZE];
    int x[MAXSIZE],y[MAXSIZE];
    int rear, front, count;
}JettyQueue;
//初始化队列
void initQueue(JettyQueue *queue){
    queue->rear = -1;
    queue->front = 0;
    queue->count = 0;
}
//判断队列是否为空
int isEmpty(JettyQueue *queue){
    return queue->count == 0;
}
//入队
void enqueue(JettyQueue *queue, char element, int x , int y){
    //queue->data[((queue->rear++) == MAXSIZE) ? 0 : (queue->rear++)] = element;
    if(queue->count == MAXSIZE) {return;}
    queue->data[(queue->rear++) % MAXSIZE] = element;
    queue->x[(queue->rear++) % MAXSIZE] = x;
    queue->y[(queue->rear++) % MAXSIZE] = y;
    queue->count++;
}
//出队
char dequeue(JettyQueue *queue, int *x , int *y){
    if(queue->count == 0) {return;}
    return queue->data[queue->front % MAXSIZE];
    *x = queue->x[queue->front % MAXSIZE];
    *y = queue->y[queue->front % MAXSIZE];
    queue->front++;
    queue->count--;
}

int main(){
    JettyQueue jettyqueue;
    LetterLocation letterlo;
    Finder jettyfinder;
    initQueue(&jettyqueue);
    
    int m,n;
    scanf("%d %d",&m,&n);
    char input[m][n];
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            scanf(" %c", &input[i][j]);
        }
    }
    int count = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            letterlo.x = i;
            letterlo.y = j;
            int visited[MAXSIZE][MAXSIZE];
            int ori_x = letterlo.x, ori_y = letterlo.y, flag=0;
            int row = m, column = n;
            char ori_letter = input[letterlo.x][letterlo.y];
            visited[letterlo.x][letterlo.y] = 1;
            //enqueue(jettyqueue, input[letterlo->x][letterlo->y],letterlo->x, letterlo->y);
            for(int i=-1; i<=1; i++){
                for(int j=-1; j<=1; j++){
                    int newrow = letterlo.x + i, newcolumn = letterlo.x + j;
                    if(newrow >= 0 && newrow <= row && newcolumn >= 0 && newcolumn <= column && newcolumn != letterlo.x && newrow != letterlo.x){
                        enqueue(&jettyqueue,input[newrow][newcolumn],newrow,newcolumn);
                        visited[newrow][newcolumn] = 1;
                    }
                }
            }
            while(isEmpty(&jettyqueue) != 0){
                char comparer = dequeue(&jettyqueue, letterlo.x, letterlo.y);
                if(comparer == ori_letter){
                    jettyfinder.distance[count] = abs(ori_x - letterlo.x) + abs(ori_y - letterlo.y);
                    jettyfinder.letter[count] = ori_letter;
                    count++;
                    break;
                }
                for(int i=-1; i<=1; i++){
                    for(int j=-1; j<=1; j++){
                        int newrow = letterlo.x + i, newcolumn = letterlo.y + j;
                        if(visited[newrow][newcolumn] != 1 && newrow >= 0 && newrow <= row && newcolumn >= 0 && newcolumn <= column){
                            enqueue(&jettyqueue,input[newrow][newcolumn],newrow,newcolumn);
                            visited[newrow][newcolumn] = 1;
                        }
                    }
                }
            }
        }
    }
    struct result{
        char letter;
        int distance;
    }result;
    result.distance = 6;
    for(int i=0;i<count;i++){
        if(result.distance >= jettyfinder.distance[i])
        {
            result.distance = jettyfinder.distance[i];
            result.letter = jettyfinder.letter[i];
        }
    }

    printf("%c",result.letter);

    return 0;
}