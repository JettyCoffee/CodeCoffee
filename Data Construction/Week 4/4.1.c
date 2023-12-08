//给1-n， n个元素的集合，
//写递归程序实现求子集合大小
//（元素个数）为K的子集合个数。
#include <stdio.h>

typedef struct Set{
    int set_size;
    int target_size;
    int count;
}JettySet;

void initializeSet(JettySet *set,int n,int K){
    set->set_size = n;
    set->count = 0;
    set->target_size = K;
}

void DFS(JettySet *set, int cur_dep, int subset_size){
    if(cur_dep == set->set_size){
        if(subset_size == set->target_size){
            set->count++;
        }
        return;
    }
    DFS(set, cur_dep+1, subset_size+1);//当前元素计入子集
    DFS(set, cur_dep+1, subset_size);//当前元素不计入子集
}

int main(){
    JettySet set;
    int n,K;
    scanf("%d%d",&n,&K);
    initializeSet(&set,n,K);
    int deep = 0;
    int subset_size = 0;
    DFS(&set,deep,subset_size);
    printf("%d",set.count);
}