#include<iostream>
using namespace std;
static int minEle;
struct stack{
    int size;
    int top;
    int *a;
    int minEle;
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
    else if(isEmpty(s)){
        s->minEle = val;
        s->top++;
        s->a[s->top] = val;
    }
    else if(s->minEle>val){
        s->top++;
        s->a[s->top] = 2*val-s->minEle;
        s->minEle = val;
    }
    else{
        s->top++;
        s->a[s->top] = val;
    }
}
int pop(struct stack* s){
    if(isEmpty(s))
        return 1;
    else{
        int t = s->a[s->top];
        s->top--;
        if(t<s->minEle){
            int val = s->minEle;
            s->minEle = 2*s->minEle - t;
            return val;
        }
        else
            return t;
    }
}
int getMin(stack* s){
    if(isEmpty(s)){
        printf("Stack is empty\n");
        return INT_MIN;
    }
    else
        return s->minEle;
}
int main(){
    struct stack* s = (struct stack*)malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
    s->a = (int *)malloc(s->size*sizeof(int));
    s->minEle = INT_MIN;
    push(s, 56);
    push(s, 46);
    push(s, 23);
    push(s, 89);
    push(s, 78);
    push(s, 67);
    printf("%d\n", getMin(s));
}