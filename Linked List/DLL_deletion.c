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

struct Node* deleteAtFirst(struct Node* head){
    struct Node* ptr = head;
    struct Node* p = head->next;
    p->prev = NULL;
    ptr->next = NULL;
    free(ptr);
    head = p;
    return head;
}

struct Node* deleteAtEnd(struct Node* head){
    struct Node* q = head;
    struct Node* p = head->next;
    while(p->next!=NULL){
        p = p->next;
        q = q->next;
    }
    q->next = NULL;
    p->prev = NULL;
    free(p);
    return head;
}

struct Node* deleteAtIndex(struct Node* head, int index){
    struct Node* p = head;
    int i = 0;
    while(i<index-1 && p!=NULL){
        p = p->next;
        i++;
    }
    struct Node* q = p->next;
    p->next = q->next;
    q->next->prev = p;
    q->prev = NULL;
    q->next = NULL;
    free(q);
    return head;
}

void LLtraversal(struct Node* head){
    struct Node* p = head;
    while(p!=NULL){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main(){
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    struct Node* third = (struct Node*)malloc(sizeof(struct Node));
    struct Node* fourth = (struct Node*)malloc(sizeof(struct Node));

    head->data = 12;
    head->prev = NULL;
    head->next = second;

    second->data = 23;
    second->prev = head;
    second->next = third;

    third->data = 34;
    third->prev = second;
    third->next = fourth;

    fourth->data = 45;
    fourth->prev = third;

    struct Node* fifth = newNode(89);
    fifth->prev = fourth;
    fourth->next = fifth;

    LLtraversal(head);
    head = deleteAtFirst(head);
    LLtraversal(head);
    head = deleteAtEnd(head);
    LLtraversal(head);
    head = deleteAtIndex(head, 1);
    LLtraversal(head);
}