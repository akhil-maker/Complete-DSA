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
Node* merge(Node* a, Node* b){
    Node* res;
    if(a==NULL)
        return b;
    if(b==NULL)
        return a;
    if(a->data<b->data){
        res = a;
        res->next = merge(a->next, b);
    }
    else{
        res = b;
        res->next = merge(a, b->next);
    }
    return res;
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
    third1->next = NULL;
    LLtraversal(root);
    LLtraversal(first1);
    Node* meroot = merge(root, first1);
    LLtraversal(meroot);
}