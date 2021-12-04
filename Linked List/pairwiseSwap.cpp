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
Node* pairSwap(Node* head){
    Node* p = head;
    Node* q;
    Node* n = NULL;
    Node* start = NULL;
    while(p!=NULL && p->next!=NULL){
        q = p->next;
        p->next = q->next;
        q->next = p;
        if(start==NULL)
            head = q;
        else
            start->next = q;        
        start = p;
        p = p->next;
    }
    return head;
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
    LLtraversal(root);
    Node* swaroot = pairSwap(root);
    LLtraversal(swaroot);
}