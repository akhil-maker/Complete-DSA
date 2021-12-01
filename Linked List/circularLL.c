#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* newNode(int data){
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    p->data = data;
    p->prev = NULL;
    p->next = NULL;
    return p;
}

void LLtraversal(struct Node* head){
    struct Node* p = head;
    do{
        printf("%d ", p->data);
        p = p->next;
    }
    while(p!=head);
    printf("\n");
}

int main(){
    struct Node* head = newNode(12);
    struct Node* f = newNode(23);
    struct Node* s = newNode(34);
    struct Node* t = newNode(45);
    struct Node* fo = newNode(56);
    head->next = f;
    f->prev = head;
    f->next = s;
    s->prev = f;
    s->next = t;
    t->prev = s;
    t->next = fo;
    fo->prev = t;
    fo->next = head;
    head->prev = fo;
    LLtraversal(head);
}