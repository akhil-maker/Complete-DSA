#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
Node* newNode(int val){
    Node* t = (struct Node*)malloc(sizeof(struct Node));
    t->data = val;
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
Node* enqueue(Node* head, int val){
    if(head==NULL)
        return newNode(val);
    Node* t = newNode(val);
    t->next = head;
    head = t;
    return head;
}
int dequeue(Node* head){
    Node* p = head;
    head = p->next;
    int x = p->data;
    free(p);
    return x;
}
int main(){
    Node* root = (struct Node*)malloc(sizeof(struct Node));
    root->data = 1;
    Node* first = (struct Node*)malloc(sizeof(struct Node));
    first->data = 2;
    root->next = first;
    Node* second = (struct Node*)malloc(sizeof(struct Node));
    second->data = 3;
    first->next = second;
    Node* third = (struct Node*)malloc(sizeof(struct Node));
    third->data = 4;
    second->next = third;
    Node* four = (struct Node*)malloc(sizeof(struct Node));
    four->data = 5;
    third->next = four;
    Node* five = (struct Node*)malloc(sizeof(struct Node));
    five->data = 6;
    four->next = five;
    Node* six = (struct Node*)malloc(sizeof(struct Node));
    six->data = 7;
    five->next = six;
    Node* seven = (struct Node*)malloc(sizeof(struct Node));
    seven->data = 8;
    six->next = seven;
    seven->next = NULL;
    cout<<dequeue(root)<<endl;
    LLtraversal(first);
}