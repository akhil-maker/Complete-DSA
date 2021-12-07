#include<stdio.h>
#include<stdlib.h>
struct stack{
    int *a;
    int size;
    int top;
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
void push(struct stack* s, int val){
    if(isFull(s))
        printf("Stack is full\n");
    else{
        s->top++;
        s->a[s->top] = val;
    }
}
int pop(struct stack* s){
    if(isEmpty(s))
        printf("Stack is empty\n");
    else{
        int val = s->a[s->top];
        s->top--;
        return val;
    }
}
void printStack(struct stack* s){
    for(int i=0; i<=s->top; i++)
        printf("%d ", s->a[i]);
    printf("\n");
}
int main(){
    struct stack* s = (struct stack*)malloc(sizeof(struct stack));
    s->size = 80;
    s->top = -1;
    s->a = (int*)malloc(s->size*sizeof(int));
    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    printf("%d\n", pop(s));
    push(s, 6);
    printStack(s);
}