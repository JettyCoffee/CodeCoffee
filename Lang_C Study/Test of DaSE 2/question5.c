/*植物大战僵尸（递归）
僵尸入侵了你的后院！为了抵御僵尸的入侵，
坚果老师需要从n个身高不同的植物中挑选出k个按从矮到高的顺序排成队列守护后院，为了达到最好的效果，老师想把所有可能的布阵方案都试一遍。现在坚果老师把这个任务交给了你，
给你植物们的身高数据heights，请你帮他找出所有可能的排队方案。
注意每行末尾无空格！注意每行末尾无空格！注意每行末尾无空格！

输入
第一行两个自然数n表示植物总数，
k表示队列人数 (1 < n < 21, 1 <= k <= n)。
第二行n个自然数表示植物的身高。植物身高范围1 <= height <= 300，
保证没有相同身高的植物且身高从低到高给出。

输出
所有可能的排队方案，每个方案占一行且身高从矮到高排列，所有排队方案按字典顺序输出。*/
#include <stdio.h>

typedef struct Set{
    int set_size;
    int target_size;
    int count;
}JettySet;

typedef struct subset{
    int subset[21];
    int oriset[21];
}JettySubset;

void initializeSet(JettySet *set,int n,int K){
    set->set_size = n;
    set->count = 0;
    set->target_size = K;
}

int DFS(JettySet *set,JettySubset *subset, int cur_dep, int subset_size){
    subset->subset[subset_size] = subset->oriset[cur_dep];
    if(cur_dep == set->set_size){
        if(subset_size == set->target_size){
            set->count++;
            for(int i=0;i<set->target_size;i++){
                printf("%d",subset->subset[i]);
                if(i != set->target_size-1){
                    printf(" ");
                }
                if(i == set->target_size-1){
                    printf("\n");
                }
            }
        }
        return;
    }
    DFS(set,subset, cur_dep+1, subset_size+1);//当前元素计入子集
    DFS(set,subset, cur_dep+1, subset_size);//当前元素不计入子集
}

int main(){
    JettySet set;
    JettySubset subset;
    int n,K;
    scanf("%d%d",&n,&K);
    int height[n];
    for(int i=0;i<n;i++)
        {
            scanf("%d",&subset.oriset[i]);
        }
    initializeSet(&set,n,K);
    int deep = 0;
    int subset_size = 0;
    DFS(&set,&subset,deep,subset_size);
}