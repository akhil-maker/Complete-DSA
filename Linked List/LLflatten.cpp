#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* right, *down;
};

void LLtraversal(Node* head){
    Node* p = head;
    while(p!=NULL){
        cout<<p->data<<" ";
        Node* r = p->down;
        while(r!=NULL){
            cout<<r->data<<" ";
            r = r->down;
        }
        cout<<endl;
        p = p->right;
    }
    cout<<endl;
}
Node* merge(Node* a, Node* b){
    if(a==NULL)
        return b;
    if(b==NULL)
        return a;
    Node* res;
    if(a->data<b->data){
        res = a;
        res->down = merge(a->down, b);
    }
    else{
        res = b;
        res->down = merge(a, b->down);
    }
    res->right = NULL;
    return res;
}
Node* flatten(Node* head){
    if(head==NULL || head->right==NULL)
        return head;
    return merge(head, flatten(head->right));
}
int main(){
    Node* root = (struct Node*)malloc(sizeof(struct Node));
    root->data = 1;
    Node* first = (struct Node*)malloc(sizeof(struct Node));
    first->data = 2;
    root->down = first;
    Node* second = (struct Node*)malloc(sizeof(struct Node));
    second->data = 3;
    first->down = second;
    Node* third = (struct Node*)malloc(sizeof(struct Node));
    third->data = 4;
    second->down = third;
    Node* four = (struct Node*)malloc(sizeof(struct Node));
    four->data = 5;
    third->down = NULL;
    root->right = four;
    Node* five = (struct Node*)malloc(sizeof(struct Node));
    five->data = 6;
    four->down = five;
    Node* six = (struct Node*)malloc(sizeof(struct Node));
    six->data = 7;
    five->down = six;
    Node* seven = (struct Node*)malloc(sizeof(struct Node));
    seven->data = 8;
    six->down = NULL;
    root->right->right = seven;
    seven->down = NULL;
    seven->right = NULL;
    LLtraversal(root);
    root = flatten(root);
    LLtraversal(root);
}