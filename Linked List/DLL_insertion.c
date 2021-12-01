#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* insertAtFirst(struct Node* head, int data){
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    p->data = data;
    p->prev = NULL;
    p->next = head;
    head->prev = p;
    head = p;
    return head;
}

struct Node* insertAtEnd(struct Node* head, int data){
    struct Node* p = head;
    while(p->next!=NULL){
        p = p->next;
    }
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->prev = p;
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

struct Node* insertAtIndex(struct Node* head, int data, int index){
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    int i = 0;
    struct Node* p = head;
    while(i<index-1 && p!=NULL){
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next->prev = ptr;
    p->next = ptr;
    ptr->prev = p;
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
    fourth->next = NULL;
    
    LLtraversal(head);
    head = insertAtFirst(head, 90);
    LLtraversal(head);
    head = insertAtEnd(head, 80);
    LLtraversal(head);
    head = insertAtIndex(head, 70, 2);
    LLtraversal(head);
}