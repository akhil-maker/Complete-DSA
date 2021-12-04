#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};

bool detectLoop(Node* head){
    Node* p = head;
    Node* q = head->next->next;
    if(p==NULL || p->next==NULL)
        return false;
    while(q && q->next){
        if(p==q)
            break;
        p = p->next;
        q = q->next->next;
    }
    if(p==q)
        return true;
    return false;
}
int main(){
    Node* first1 = (struct Node*)malloc(sizeof(struct Node));
    first1->data = 12;
    Node* second1 = (struct Node*)malloc(sizeof(struct Node));
    second1->data = 13;
    first1->next = second1;
    Node* third1 = (struct Node*)malloc(sizeof(struct Node));
    third1->data = 14;
    second1->next = third1;
    third1->next = second1;
    cout<<detectLoop(first1);
}