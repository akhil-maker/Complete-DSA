#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* newNode(int data){
    struct Node* t = (struct Node*)malloc(sizeof(int));
    t->data = data;
    t->next = NULL;
    return t;
};
void LLtraversal(struct Node* head){
    struct Node* p = head;
    while(p!=NULL){
        printf("%d ", p->data);
        p = p->next;
    }
}
int main(){
    struct Node* head = (struct Node*)malloc(sizeof(int));
    head->data = 2;
    struct Node* f = (struct Node*)malloc(sizeof(int));
    f->data = 3;
    head->next = f;
    struct Node* s = (struct Node*)malloc(sizeof(int));
    s->data = 4;
    f->next = s;
    struct Node* t = newNode(5);
    s->next = t;
    LLtraversal(head);
}