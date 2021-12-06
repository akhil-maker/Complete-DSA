#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
Node* newNode(int data){
    Node* p = (struct Node*)malloc(sizeof(struct Node));
    p->data = data;
    p->next = NULL;
    return p;
}
void LLtraversal(Node* head){
    Node* p = head;
    while(p!=NULL){
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}
Node* sumLL(Node* a, Node* b){
    int sum = 0, carry = 0;
    Node* res = NULL;
    Node* p = a, *q = b;
    Node* prev = NULL;
    while(p!=NULL || q!=NULL){
        sum = carry + (p?p->data:0) + (q?q->data:0);
        carry = (sum>=10)?1:0;
        sum = sum%10;
        Node* temp = newNode(sum);
        if(res==NULL)
            res = temp;
        else
            prev->next = temp;
        prev = temp;
        if(p) p = p->next;
        if(q) q = q->next;
    }
    if(carry>0)
        prev->next = newNode(carry);
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
    Node* swaroot = sumLL(root, first1);
    LLtraversal(swaroot);
}