#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
void nthEnd(Node* head, int k){
    Node* main = head;
    Node* ref = head;
    int cnt = 0;
    if(head!=NULL){
        while(cnt<k){
            if(ref==NULL){
                cout<<main->data<<endl;
                return;
            }
            ref = ref->next;
            cnt++;
        }
        if(ref==NULL){
            head = head->next;
            if(head!=NULL)
                cout<<main->data<<endl;
        }
        else{
            while(ref!=NULL){
                main = main->next;
                ref = ref->next;
            }
            cout<<main->data<<endl;
        }
    }
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
    nthEnd(root, 2);
}