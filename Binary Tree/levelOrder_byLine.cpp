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
void levelByLine(Node* root){
    Node* p = root;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(q.size()>1){
        p = q.front();
        q.pop();
        if(p==NULL){
            q.push(NULL);
            cout<<endl;
        }
        else{
            if(p->left) 
                q.push(p->left);
            if(p->right)
                q.push(p->right);
            cout<<p->data<<" ";
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
    levelByLine(root);
}