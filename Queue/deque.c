#include<stdio.h>
#include<stdlib.h>
struct deque{
    int f;
    int r;
    int size;
    int *arr;
};
void enqueueR(struct deque* q, int val){
    if(q->size-1==q->r){
        printf("Deque is full\n");
        return;
    }
    q->r++;
    q->arr[q->r] = val;
    printf("Enqueued element at %d index: %d\n", q->r, q->arr[q->r]);
}
int dequeueF(struct deque* q){
    if(q->r==q->f){
        printf("Deque is empty\n");
        return -1;
    }
    q->f++;
    int x = q->arr[q->f];
    printf("Dequeued element: %d\n", x);
    return x;
}
void enqueueF(struct deque* q, int val){
    if(q->f==-1){
        printf("Deque is full\n");
        return;
    }
    q->arr[q->f] = val;
    printf("Enqueued element at %d index: %d\n", q->f, q->arr[q->f]);
    q->f--;
}
int dequeueR(struct deque* q){
    if(q->r==-1){
        printf("Deque is empty\n");
        return -1;
    }
    int val = q->arr[q->r];
    printf("Dequeued element: %d\n", val);
    q->r--;
    return val;
}
int main(){
    struct deque* q;
    q->f = q->r = -1;
    q->size = 4;
    q->arr = (int*)malloc(sizeof(q->size));
    enqueueR(q, 10);
    enqueueR(q, 20);
    enqueueR(q, 30);
    enqueueR(q, 40);
    enqueueR(q, 10);
    enqueueR(q, 50);
    dequeueF(q);
    dequeueF(q);
    enqueueF(q, 50);
    enqueueF(q, 50);
    enqueueF(q, 70);
    dequeueR(q);
    dequeueR(q);
}