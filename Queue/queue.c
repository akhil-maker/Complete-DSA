#include<stdio.h>
#include<stdlib.h>
struct queue{
    int size;
    int f, r;
    int *a;
};
int isFull(struct queue* q){
    if(q->r==q->size-1)
        return 1;
    else
        return 0;
}
int isEmpty(struct queue* q){
    if(q->f==q->r)
        return 1;
    else
        return 0;
}
void enqueue(struct queue* q, int val){
    if(isFull(q))
        printf("Queue is full");
    else{
        q->r++;
        q->a[q->r] = val;
    }
}
int dequeue(struct queue* q){
    int a = -1;
    if(isEmpty(q))
        printf("Queue is empty");
    else{
        q->f++;
        int val = q->a[q->f];
        return val;
    }
}
void printQueue(struct queue* q){
    for(int i=q->r; i>q->f; i--)
        printf("%d ", q->a[i]);
    printf("\n");
}
int main(){
    struct queue* q;
    q->size = 100;
    q->f = q->r = -1;
    q->a = (int*)malloc(q->size*sizeof(int));
    enqueue(q, 12);
    enqueue(q, 23);
    enqueue(q, 34);
    enqueue(q, 45);
    enqueue(q, 56);
    enqueue(q, 67);
    printQueue(q);
    printf("%d\n", dequeue(q));
    enqueue(q, 89);
    printf("%d\n", dequeue(q));
    printQueue(q);
}