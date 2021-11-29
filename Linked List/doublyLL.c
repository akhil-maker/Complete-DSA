#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* newNode(int data){
    struct Node* p = (struct Node*)malloc(sizeof(int));
    p->data = data;
    p->prev = NULL;
    p->next = NULL;
    return p;
}

void DLLtraversal(struct Node* head){
    struct Node* p = head;
    printf("LL traversal: ");
    while(p!=NULL){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void RevDLLtraversal(struct Node* head){
    struct Node* p = head;
    while(p->next!=NULL){
        p = p->next;
    }
    printf("LL traversal:");
    while(p!=NULL){
        printf("%d ", p->data);
        p = p->prev;
    }
    printf("\n");
}
int main(){
    struct Node* head = newNode(1);
    struct Node* f = newNode(2);
    head->next = f;
    f->prev = head;
    struct Node* sec = newNode(3);
    sec->prev = f;
    f->next = sec;
    struct Node* t = newNode(5);
    sec->next = t;
    t->prev = sec;
    struct Node* fo = newNode(4);
    t->next = fo;
    fo->prev = t;  
    printf("%d", head->data);
    DLLtraversal(head);
    RevDLLtraversal(head);
}