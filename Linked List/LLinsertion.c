#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* newNode(int data){
    struct Node* p = (struct Node*)malloc(sizeof(int));
    p->data = data;
    p->next = NULL;
    return p;
};
void LLtraversal(struct Node* head){
    struct Node* p = head;
    while(p!=NULL){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
struct Node* insertAtFirst(struct Node* head, int data){
    struct Node* p = newNode(data);
    p->next = head;
    head = p;
    return head;
}
struct Node* insertAtEnd(struct Node* head, int data){
    struct Node* p = newNode(data);
    struct Node* ptr = head;
    while(ptr->next!=NULL)
        ptr = ptr->next;
    ptr->next = p;
    return head;
}
struct Node* insertAtIndex(struct Node* head, int data, int index){
    struct Node* p = head;
    struct Node* ptr = newNode(data);
    for(int i=0; i<index-1; i++)
        p = p->next;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}
int main(){
    struct Node* head = newNode(1);
    struct Node* f = newNode(2);
    head->next = f;
    struct Node* s = newNode(3);
    f->next = s;
    struct Node* t = newNode(4);
    s->next = t;
    LLtraversal(head);
    head = insertAtFirst(head, 5);
    LLtraversal(head);
    head = insertAtEnd(head, 6);
    LLtraversal(head);
    head = insertAtIndex(head, 7, 2);
    LLtraversal(head);
}