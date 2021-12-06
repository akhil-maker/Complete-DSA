#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
void deleteNode(Node* p){
    if(p==NULL)
        return;
    else{
        if(p->next==NULL)
            return;
    }
    Node* temp = p->next;
    p->data = temp->data;
    p->next = p->next->next;
    free(temp);
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
    third1->next = NULL;
    deleteNode(second1);
    Node* p = first1;
    while(p!=NULL){
        cout<<p->data<<" ";
        p = p->next;
    }
}