#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left, *right;
};
Node* newNode(int data){
    Node* p = new Node;
    p->data = data;
    p->left = NULL;
    p->right = NULL;
    return p;
}
void lOrderSpiral(Node* root){
    Node* p = root;
    stack<Node*> s1;
    stack<Node*> s2;
    s1.push(root);
    while(!s1.empty() || !s2.empty()){
        while(!s1.empty()){
            p = s1.top();
            s1.pop();
            cout<<p->data<<" ";
            if(p->right) s2.push(p->right);
            if(p->left) s2.push(p->left);
        }
        while(!s2.empty()){
            p = s2.top();
            s2.pop();
            cout<<p->data<<" ";
            if(p->left) s1.push(p->left);
            if(p->right) s1.push(p->right);
        }
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
    lOrderSpiral(root);
}