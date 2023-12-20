#include <stdio.h>

#define MAXSIZE 100
#define element_type int

typedef struct Map{
    int Map[MAXSIZE][MAXSIZE];
    int row,column;
    int counter,longest[MAXSIZE][MAXSIZE];
}JettyMap;

void BFS_Snowing(JettyMap *map, int x,int y){
    for(int i=-1;i<=1;i++){
        for(int j=-1;j<=1;j++){
            if(map->Map[x+i][y+j] < map->Map[x][y] && ( i == 0 || j == 0 ) ){
                map->counter++;
                BFS_Snowing(map,x+i,y+j);
            } //对当前node的东南西北入队
        }
    }
    if(map->counter > map->longest[map->row][map->column]){
        map->longest[map->row][map->column] = map->counter;
    }
    map->counter--;
}

int main(){
    JettyMap map;
    map.counter = 0;
    int m,n,longcounters;
    longcounters = 0;
    scanf("%d%d", &m, &n);
    for(int i=0; i<=m+1; i++){
        for(int j=0;j<=n+1; j++){
            if(i==0 || i==m+1 || j==0 || j==n+1){
                map.Map[i][j] = 10001; //为map加上墙(假设1为墙)
            }
            else{
                scanf("%d",&map.Map[i][j]);
            }
        }
    }
    for(int i=1; i<=m; i++){
        for(int j=1;j<=n; j++){
            map.row = i;
            map.column = j;
            map.longest[i][j] = 0;
            map.counter++;
            BFS_Snowing(&map,i,j);
            longcounters = (map.longest[i][j] > longcounters) ? map.longest[i][j] : longcounters;
        }
    }
    printf("%d",longcounters);
    return 0;
}