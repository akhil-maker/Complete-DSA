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

void removeLoop(Node* head){
    Node* slow = head;
    Node* fast = head->next->next;
    while(fast && fast->next){
        if(slow==fast)
            break;
        slow = slow->next;
        fast = fast->next->next;
    }
    if(slow==fast){
        slow = head;
        if(slow==fast){
            while(fast->next!=slow) fast = fast->next;
        }
        else{
            while(slow->next!=fast->next){
                slow = slow->next;
                fast = fast->next;
            }
        }
        fast->next = NULL;
    }
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
    removeLoop(first1);
    LLtraversal(first1);
}