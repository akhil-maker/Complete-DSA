#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};

void LLtraversal(Node* head){
    Node* p = head;
    while(p!=NULL){
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

int intersection(Node* a, Node* b){
    Node* p = a;
    Node* q = b;
    if(p==NULL || q==NULL)
        return -1;
    while(p!=NULL || q!=NULL){
        p = p->next;
        q = q->next;
        if(p==q)
            return p->data;
        if(p==NULL)
            p = b;
        if(q==NULL)
            q = a;
    }
    return p->data;
}
int main(){
    Node* root = (struct Node*)malloc(sizeof(struct Node));
    root->data = 1;
    Node* first = (struct Node*)malloc(sizeof(struct Node));
    first->data = 2;
    root->next = first;
    Node* second = (struct Node*)malloc(sizeof(struct Node));
    second->data = 8;
    first->next = second;
    Node* third = (struct Node*)malloc(sizeof(struct Node));
    third->data = 19;
    second->next = third;
    Node* four = (struct Node*)malloc(sizeof(struct Node));
    four->data = 34;
    third->next = four;
    Node* five = (struct Node*)malloc(sizeof(struct Node));
    five->data = 46;
    four->next = five;
    Node* six = (struct Node*)malloc(sizeof(struct Node));
    six->data = 57;
    five->next = six;
    Node* seven = (struct Node*)malloc(sizeof(struct Node));
    seven->data = 68;
    six->next = seven;
    seven->next = NULL;
    Node* first1 = (struct Node*)malloc(sizeof(struct Node));
    first1->data = 42;
    Node* second1 = (struct Node*)malloc(sizeof(struct Node));
    second1->data = 53;
    first1->next = second1;
    Node* third1 = (struct Node*)malloc(sizeof(struct Node));
    third1->data = 64;
    second1->next = third1;
    third1->next = six;
    cout<<intersection(root, first1);
}