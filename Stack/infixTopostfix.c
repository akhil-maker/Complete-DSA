#include<stdio.h>
#include<stdlib.h>
struct stack{
    int size;
    int top;
    char *a;
};
int isFull(struct stack* s){
    if(s->top==s->size-1)
        return 1;
    else
        return 0;
}
int isEmpty(struct stack* s){
    if(s->top==-1)
        return 1;
    else
        return 0;
}
void push(struct stack* s, char val){
    if(isFull(s))
        printf("Stack overflow");
    else{
        s->top++;
        s->a[s->top] = val;
    }
}
char pop(struct stack* s){
    if(isEmpty(s))
        printf("Stack underflow");
    else{
        char val = s->a[s->top];
        s->top--;
        return val;
    }
}
int precedence(char ch){
    if(ch=='*' || ch=='/')
        return 3;
    else if(ch=='+' || ch=='-')
        return 2;
    else
        return 0;
}
int isOperator(char ch){
    if(ch=='+' || ch=='-' || ch=='*' ||ch=='/')
        return 1;
    else
        return 0;
}
int stackTop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Empty stack");
        return -1;
    }
    else{
        return ptr->a[ptr->top];
    }
}
char* infixTopostfix(char* infix){
    struct stack* s = (struct stack*)malloc(sizeof(struct stack));
    s->size = 100;
    s->top = -1;
    s->a = (char*)malloc(s->size*sizeof(char));
    char* postfix = (char*)malloc(sizeof(char));
    int i = 0;
    int j = 0;
    while(infix[i]!='\0'){
        if(!isOperator(infix[i])){
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else{
            if(precedence(infix[i])>precedence(stackTop(s))){
                push(s, infix[i]);
                i++;
            }
            else{
                postfix[j] = pop(s);
                j++;
            }
        }
    }
    while(!isEmpty(s)){
        postfix[j] = pop(s);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}
int main(){
    char* infix;
    scanf("%s", infix);
    printf("Infix to postfix: %s", infixTopostfix(infix));
    return 0;
}