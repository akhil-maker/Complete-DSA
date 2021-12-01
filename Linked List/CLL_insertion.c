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

struct Node* insertAtFirst(struct Node* head, int data){
    struct Node* ptr = newNode(data);
    struct Node* p = head->prev;
    p->next->prev = ptr;
    ptr->next = p->next;
    p->next = ptr;
    ptr->prev = p;
    head = ptr;
    return head;
}

struct Node* insertAtEnd(struct Node* head, int data){
    struct Node* p = head->prev;
    struct Node* ptr = newNode(data);
    p->next = ptr;
    head->prev = ptr;
    ptr->prev = p;
    ptr->next = head;
    return head;
}

struct Node* insertAtIndex(struct Node* head, int data, int index){
    struct Node* p = head;
    struct Node* ptr = newNode(data);
    for(int i=0; i<index-1; i++)
        p = p->next;
    ptr->next = p->next;
    ptr->prev = p;
    p->next->prev = ptr;
    p->next = ptr;
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
    head = insertAtFirst(head, 67);
    LLtraversal(head);
    head = insertAtEnd(head, 78);
    LLtraversal(head);
    head = insertAtIndex(head, 89, 3);
    LLtraversal(head);
}