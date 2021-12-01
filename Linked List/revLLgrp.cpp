#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

struct Node* newNode(int data){
    Node* p = (struct Node*)malloc(sizeof(struct Node));
    p->data = data;
    p->next = NULL;
    return p;
}

Node* revLLgrp(Node* head, int k){
    
}

void LLtraversal(Node* head){
    Node* p = head;
    while(p!=NULL){
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}
int main(){
    struct Node* head = newNode(1);
    struct Node* f = newNode(2);
    head->next = f;
    struct Node* s = newNode(3);
    f->next = s;
    struct Node* t = newNode(4);
    s->next = t;
    struct Node* fo = newNode(5);
    t->next = fo;
    struct Node* fi = newNode(6);
    fo->next = fi;
    struct Node* si = newNode(7);
    fi->next = si;
    LLtraversal(head);
}