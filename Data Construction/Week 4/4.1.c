//给1-n， n个元素的集合，
//写递归程序实现求子集合大小
//（元素个数）为K的子集合个数。
#include <stdio.h>

typedef struct Set{
    int set_size;
    int subset_size;
    int target_size;
    int count;
}JettySet;

void initializeSet(JettySet *set,int n,int K){
    set->set_size = n;
    set->count = 0;
    set->target_size = K;
}

void DFS(JettySet *set, int cur_dep, int cur_size){
    if(cur_dep > set->set_size){
        set->count++;
    }
    for(int i=set->target_size;i<)
}