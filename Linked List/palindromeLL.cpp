#include<iostream>
#include<stack>
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
bool palindrome(Node* head){
    Node* slow = head;
    stack<Node*> s;
    while(slow!=NULL){
        s.push(slow);
        slow = slow->next;
    }
    Node* p = head;
    while(!s.empty()){
        Node* temp = s.top();
        s.pop();
        if(temp->data!=p->data)
            return false;
        p = p->next;
    }
    return true;
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
    four->data = 3;
    third->next = four;
    Node* five = (struct Node*)malloc(sizeof(struct Node));
    five->data = 2;
    four->next = five;
    Node* six = (struct Node*)malloc(sizeof(struct Node));
    six->data = 1;
    five->next = six;
    Node* seven = (struct Node*)malloc(sizeof(struct Node));
    seven->data = 1;
    six->next = seven;
    seven->next = NULL;
    LLtraversal(root);
    cout<<palindrome(root);
}