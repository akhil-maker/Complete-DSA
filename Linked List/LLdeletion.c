#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
void LLtraversal(struct Node* head){
    struct Node* p = head;
    while(p!=NULL){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
struct Node* newNode(int data){
    struct Node* t = (struct Node*)malloc(sizeof(int));
    t->data = data;
    t->next = NULL;
    return t;
}
struct Node* deleteAtFirst(struct Node* head){
    struct Node* ptr = head;
    head = head->next;
    free(ptr);
    return head;
}
struct Node* deleteAtEnd(struct Node* head){
    struct Node* ptr = head;
    struct Node* p = head->next;
    while(p->next!=NULL){
        ptr = ptr->next;
        p = p->next;
    }
    ptr->next = NULL;
    free(p);
    return head;
}
struct Node* deleteAtValue(struct Node* head, int value){
    struct Node* ptr = head;
    struct Node* p = head->next;
    while(p->data!=value && p!=NULL){
        p = p->next;
        ptr = ptr->next;
    }
    if(p->data==value){
        ptr->next = p->next;
        free(p);
    }
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
    head = deleteAtFirst(head);
    LLtraversal(head);
    head = deleteAtEnd(head);
    LLtraversal(head);
    head = deleteAtValue(head, 3);
    LLtraversal(head);
}