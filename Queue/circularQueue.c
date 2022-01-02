#include<stdio.h>
#include<stdlib.h>
struct Cqueue{
    int size;
    int f;
    int r;
    int *arr;
};
int isEmpty(struct Cqueue* q){
    if(q->f==q->r)
        return 1;
    return 0;
}
int isFull(struct Cqueue* q){
    if((q->r+1)%q->size==q->f)
        return 1;
    return 0;
}
void enqueue(struct Cqueue* q, int val){
    if(isFull(q)){
        printf("Queue overflow\n");
        return;
    }
    printf("Enqueued element: %d\n", val);
    q->r = (q->r+1)%q->size;
    q->arr[q->r] = val;
}
int dequeue(struct Cqueue* q){
    if(isEmpty(q)){
        printf("Queue underflow\n");
        return -1;
    }
    q->f = (q->f+1)%q->size;
    int x = q->arr[q->f];
    return x;
}
int main(){
    struct Cqueue* q;
    q->size = 4;
    q->f = q->r = 0;
    q->arr = (int*)malloc(q->size*sizeof(int));
    enqueue(q, 12);
    enqueue(q, 15);
    enqueue(q, 1);
    printf("Dequeue element: %d\n", dequeue(q));
    printf("Dequeue element: %d\n", dequeue(q));
    printf("Dequeue element: %d\n", dequeue(q));
    enqueue(q, 45);
    printf("Dequeue element: %d\n", dequeue(q));
}