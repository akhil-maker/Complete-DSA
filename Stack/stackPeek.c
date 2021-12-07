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
        printf("Stack overflow\n");
    else{
        s->top++;
        s->a[s->top] = val;
    }
}
int pop(struct stack* s){
    if(isEmpty(s)){
        printf("Stack underflow\n");
        return -1;
    }
    else{
        int val = s->a[s->top];
        s->top--;
        return val;
    }
}
int peek(struct stack* s, int i){
    int arrind = s->top-i+1;
    if(arrind<0){
        printf("Invalid position for the stack\n");
        return -1;
    }
    else
        return s->a[arrind];
}
int main(){
    struct stack* s = (struct stack*)malloc(sizeof(struct stack*));
    s->size = 80;
    s->top = -1;
    s->a = (int *)malloc(s->size*sizeof(int));
    push(s, 56);
    push(s, 46);
    push(s, 23);
    push(s, 89);
    push(s, 78);
    push(s, 67);
    for(int j=1; j<=s->top+1; j++){
        printf("Value at %d position is %d\n", j, peek(s, j));
    }
    return 0;
}