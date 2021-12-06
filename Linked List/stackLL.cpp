#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
Node* newNode(int data){
    Node* t = (struct Node*)malloc(sizeof(struct Node));
    t->data = data;
    t->next = NULL;
    return t;
}
void LLtraversal(Node* head){
    Node* p = head;
    while(p!=NULL){
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}
void push(Node* head, int val){
    if(head==NULL)
        head = newNode(val);
    else{
        Node* t = newNode(val);
        Node* p = head;
        while(p->next!=NULL)
            p = p->next;
        p->next = t;
    }
}
int pop(Node* head){
    if(head->next==NULL){
        Node* p = head;
        int x = p->data;
        free(p);
        return x;
    }
    Node* p = head;
    while(p->next->next!=NULL)
        p = p->next;
    Node* q = p->next;
    int x = q->data;
    free(q);
    p->next = NULL;
    return x;
}
int main(){
    Node* s = newNode(5);
    push(s, 56);
    push(s, 24);
    push(s, 26);
    push(s, 27);
    push(s, 28);
    push(s, 29);
    push(s, 21);
    push(s, 20);
    push(s, 43);
    push(s, 53);
    push(s, 46);
    pop(s);
    pop(s);
    LLtraversal(s);
}