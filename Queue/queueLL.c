#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct queueLL{
    struct Node* f;
    struct Node* r;
};
void enqueue(struct queueLL* q, int val){
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    if(p==NULL){
        printf("Queue overflow\n");
        return;
    }
    p->data = val;
    p->next = NULL;
    if(q->r!=NULL)
        q->r->next = p;
    else
        q->f = q->r = p;
    if(q->f==NULL)
        q->f = p;
    q->r = p;
}
int dequeue(struct queueLL* q){
    if(q->f==NULL){
        printf("Queue underflow\n");
        return -1;
    }
    struct Node* p = q->f;
    q->f = q->f->next;
    return p->data;
}
void printLL(struct queueLL* q){
    struct Node* p = q->f;
    while(p!=NULL){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
int main(){
    struct queueLL* q;
    q->f = NULL;
    q->r = NULL;
    dequeue(q);
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    printf("Dequeued element: %d\n", dequeue(q));
    printf("Dequeued element: %d\n", dequeue(q));
    printf("Dequeued element: %d\n", dequeue(q));
    dequeue(q);
    enqueue(q, 50);
    printLL(q);
    printf("Dequeued element: %d\n", dequeue(q));
    printf("Dequeued element: %d\n", dequeue(q));
    enqueue(q, 0);
    enqueue(q, 20);
    enqueue(q, 10);
    printLL(q);
    printf("Dequeued element: %d\n", dequeue(q));
}