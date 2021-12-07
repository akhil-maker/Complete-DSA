#include<stdio.h>
#include<stdlib.h>
struct stack{
    int size;
    int top;
    char* arr;
};
int isEmpty(struct stack* ptr){
    if(ptr->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(struct stack* ptr){
    if(ptr->top==ptr->size-1){
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(struct stack* ptr, int val){
    if(isFull(ptr)){
        printf("Stack Overflow");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
int pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow");
        return -1;
    }
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int parenthesisMatch(char* exp){
    struct stack* s = (struct stack*)malloc(sizeof(struct stack));
    s->top = -1;
    s->size = 1000;
    s->arr = (char*)malloc(s->size*sizeof(char));
    for(int i=0; (exp[i]!='\0'); i++){
        if(exp[i]=='(')
            push(s, '(');
        else if(exp[i]==')'){
            if(isEmpty(s))
                return 0;
            else
                pop(s);
        }
    }
    if(isEmpty(s))
        return 1;
    else
        return 0;
}
int main(){
    char *exp = "(2+(3*(6/5)-8))";
    if(parenthesisMatch(exp)){
        printf("The expression is balanced");
    }
    else{
        printf("The expression is not balanced");
    }
    return 0;
}