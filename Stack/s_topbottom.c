#include<stdio.h>
#include<stdlib.h>
struct stack{
    int *a;
    int size;
    int top;
};
int isEmpty(struct stack* s){
    if(s->top==-1)
        return 1;
    else
        return 0;
}
int isFull(struct stack* s){
    if(s->top==s->size-1)
        return 1;
    else
        return 0;
}
void push(struct stack* s, int val){
    if(isFull(s))
        printf("Stack is full");
    else{
        s->top++;
        s->a[s->top] = val;
    }
}
int pop(struct stack* s){
    if(isEmpty(s)){
        printf("Stack is empty");
        return -1;
    }
    else{
        int val = s->a[s->top];
        s->top--;
        return val;
    }
}
int stackTop(struct stack* s){
    if(isEmpty(s)){
        printf("Stack is empty");
        return -1;
    }
    else
        return s->a[s->top];
}
int stackBottom(struct stack* s){
    if(isEmpty(s)){
        printf("Stack is full");
        return -1;
    }
    else
        return s->a[0];
}
int main(){
    struct stack* s = (struct stack*)malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
    s->a = (int *)malloc(s->size*sizeof(int));
    push(s, 56);
    push(s, 46);
    push(s, 23);
    push(s, 89);
    push(s, 78);
    push(s, 67);
    printf("Topmost value of stack is %d\n", stackTop(s));
    printf("Bottommost value of stack is %d\n", stackBottom(s));
    return 0;
}