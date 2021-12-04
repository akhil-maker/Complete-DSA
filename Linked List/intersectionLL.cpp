#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
Node* intersection(Node* a, Node* b){
    Node* p = a;
    Node* q = b;
    while(p!=q){
        p = p->next;
        q = q->next;
        if(p==q)
            return p;
        if(p==NULL)
            p = b;
        if(q==NULL)
            q = a;
    }
    return p;
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
    Node* root1 = (struct Node*)malloc(sizeof(struct Node));
    root1->data = 11;
    Node* first1 = (struct Node*)malloc(sizeof(struct Node));
    first1->data = 12;
    root1->next = first1;
    Node* second1 = (struct Node*)malloc(sizeof(struct Node));
    second1->data = 13;
    first1->next = second1;
    Node* third1 = (struct Node*)malloc(sizeof(struct Node));
    third1->data = 14;
    second1->next = third1;
    third1->next = four;
    Node* res = intersection(root, root1);
    cout<<res->data;
}