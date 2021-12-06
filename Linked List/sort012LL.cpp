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
Node* sort012(Node* head){
    Node* p = head;
    int cnt[3] = {0, 0, 0};
    while(p!=NULL){
        cnt[p->data]++;
        p = p->next;
    }
    int i = 0;
    p = head;
    while(p!=NULL){
        if(cnt[i]==0)
            i++;
        p->data = i;
        cnt[i]--;
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
    second->data = 0;
    first->next = second;
    Node* third = (struct Node*)malloc(sizeof(struct Node));
    third->data = 0;
    second->next = third;
    Node* four = (struct Node*)malloc(sizeof(struct Node));
    four->data = 2;
    third->next = four;
    Node* five = (struct Node*)malloc(sizeof(struct Node));
    five->data = 1;
    four->next = five;
    Node* six = (struct Node*)malloc(sizeof(struct Node));
    six->data = 2;
    five->next = six;
    six->next = NULL;
    LLtraversal(root);
    root = sort012(root);
    LLtraversal(root);
}