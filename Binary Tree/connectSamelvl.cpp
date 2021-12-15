#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left, *right;
    Node* nextRight;
};
Node* newNode(int data){
    Node* p = new Node;
    p->data = data;
    p->left = NULL;
    p->right = NULL;
    p->nextRight = NULL;
    return p;
}
void connect(Node* root){
    queue<Node*> q;
    q.push(root);
    Node* p;
    while(!q.empty()){
        int sz = q.size();
        Node* prev = NULL;
        while(sz--){
            p = q.front();
            q.pop();
            if(p->left)
                q.push(p->left);
            if(p->right)
                q.push(p->right);
            if(prev!=NULL)
                prev->nextRight = p;
            prev = p;
        }
        prev->nextRight = NULL;
    }
}
int main(){
    Node* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(13);
    root->left->left = newNode(3);
    root->left->right = newNode(6);
    root->right->left = newNode(11);
    root->right->right = newNode(15);
    connect(root);
    cout<<"next right of "<<root->data<<" is "<<(root->nextRight?root->nextRight->data:-1)<<endl;
    cout<<"next right of "<<root->left->data<<" is "<<(root->left->nextRight?root->left->nextRight->data:-1)<<endl;
    cout<<"next right of "<<root->right->data<<" is "<<(root->right->nextRight?root->right->nextRight->data:-1)<<endl;
    cout<<"next right of "<<root->left->left->data<<" is "<<(root->left->left->nextRight?root->left->left->nextRight->data:-1)<<endl;
    cout<<"next right of "<<root->left->right->data<<" is "<<(root->left->right->nextRight?root->left->right->nextRight->data:-1)<<endl;
    cout<<"next right of "<<root->right->left->data<<" is "<<(root->right->left->nextRight?root->right->left->nextRight->data:-1)<<endl;
}