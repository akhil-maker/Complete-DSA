#include<stdio.h>
#include<stdlib.h>
struct stack{
    char *a;
    int top;
    int size;
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
int multiParenMatch(char* exp){
    struct stack* s = (struct stack*)malloc(sizeof(struct stack));
    s->top = -1;
    s->size = 80;
    s->a = (char*)malloc(s->size*sizeof(char));
    for(int i=0; exp[i]!='\0'; i++){
        if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{')
            push(s, exp[i]);
        else if(exp[i]==')' || exp[i]==']' || exp[i]=='}'){
            if(isEmpty(s))
                return 0;
            else{
                char r = s->a[s->top];
                switch (exp[i])
                {
                case ')':
                    if(r=='(')
                        pop(s);
                    else
                        return 0;
                    break;
                case ']':
                    if(r=='[')
                        pop(s);
                    else
                        return 0;
                    break;
                case '}':
                    if(r=='{')
                        pop(s);
                    else
                        return 0;
                }
            }
        }
    }
    if(isEmpty(s))
        return 1;
    else
        return 0;
}
int main(){
    char *exp = "[{(89-(879*9))}]";
    if(multiParenMatch(exp)){
        printf("The expression is balanced");
    }
    else{
        printf("The expression is not balanced");
    }
    return 0;
}