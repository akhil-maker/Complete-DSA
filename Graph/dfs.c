#include<stdio.h>
#include<stdlib.h>
struct stack{
    int size;
    int top;
    int *arr;
};
int isEmpty(struct stack* ptr){
    if(ptr->top==-1)
        return 1;
    else    
        return 0;
}
int isFull(struct stack* ptr){
    if(ptr->top==ptr->size-1)
        return 1;
    else
        return 0;
}
int visited[7] = {0, 0, 0, 0, 0, 0, 0};
int a[7][7] = {
    {0, 1, 1, 1, 0, 0, 0},
    {1, 0, 0, 1, 0, 0, 0},
    {1, 0, 0, 1, 1, 0, 0},
    {1, 1, 1, 0, 1, 0, 0},
    {0, 0, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0}
};
void DFS(int i){
    printf("%d ", i);
    visited[i] = 1;
    for(int j=0; j<7; j++){
        if(a[i][j]==1 && visited[j]==0){
            DFS(j);
        }
    }
}
int main(){
    struct stack* s;
    s->size = 100;
    s->top = -1;
    s->arr = (int*)malloc(s->size*(sizeof(int)));
    DFS(1);
}