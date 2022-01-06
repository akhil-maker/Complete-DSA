#include<stdio.h>
#include<stdlib.h>
struct queue{
    int f;
    int r;
    int* arr;
    int size;
};
void enqueue(struct queue* q, int val){
    if(q->r==q->size-1){
        printf("Queue is full\n");
        return;
    }
    q->r++;
    q->arr[q->r] = val;
}
int dequeue(struct queue* q){
    if(q->f==q->r){
        printf("Queue is empty\n");
        return -1;
    }
    q->f++;
    int val = q->arr[q->f];
    return val;
}
int main(){
    struct queue* q;
    q->size = 100;
    q->f = q->r = -1;
    q->arr = (int*)malloc(q->size*sizeof(int));

    //bfs implementation
    int u;
    int i = 0;
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
    printf("%d ", i);
    visited[i] = 1;
    enqueue(q, i); //enqueue i for exploration
    while(q->f!=q->r){ //queue is not empty
        u = dequeue(q);
        for(int j=0; j<7; j++){
            if(a[u][j]==1 && visited[j]==0){
                printf("%d ", j);
                visited[j] = 1;
                enqueue(q, j);
            }
        }
    }
}