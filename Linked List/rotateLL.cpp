#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

struct Node* newNode(int data){
    Node* p = (struct Node*)malloc(sizeof(struct Node));
    p->data = data;
    p->next = NULL;
    return p;
}

void LLtraversal(Node* root){
    Node* p = root;
    while(p!=NULL){
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

Node* rotateLL(Node* root, int k){
    if(k==0)
        return root;
    Node* p = root;
    int i = 0;
    Node* q = root;
    while(p->next!=NULL){
        if(i==k-1){
            q = p->next;
            p->next = NULL;
            p = q;
        }
        p = p->next;
        i++;
    }
    p->next = root;
    root = q;
    return root;
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
    head = rotateLL(head, 5);
    LLtraversal(head);
}