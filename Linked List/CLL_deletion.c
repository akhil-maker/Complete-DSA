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
    while (p!=head);
    printf("\n");
}

struct Node* deleteAtFirst(struct Node* head){
    struct Node* p = head->prev;
    p->next = head->next;
    head->next->prev = p;
    p = head;
    head = p->next;
    free(p);
    return head;
}

struct Node* deleteAtEnd(struct Node* head){
    struct Node* p = head->prev;
    p->prev->next = head;
    head->prev = p->prev;
    free(p);
    return head;
}

struct Node* deleteAtIndex(struct Node* head, int index){
    struct Node* p = head;
    for(int i=0; i<index; i++)
        p = p->next;
    p->prev->next = p->next;
    p->next->prev = p->prev;
    free(p);
    return head;
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
    head = deleteAtFirst(head);
    LLtraversal(head);
    head = deleteAtEnd(head);
    LLtraversal(head);
    head = deleteAtIndex(head, 1);
    LLtraversal(head);
}