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
void lOrder2DirChange(Node* root){
    if(root==NULL)
        return;
    if(root->left==NULL && root->right==NULL){
        cout<<root->data;
        return;
    }
    queue<Node*> q;
    stack<Node*> s;
    int ct = 0, sz;
    bool rTol = false;
    q.push(root);
    Node* p;
    while(!q.empty()){
        ct++;
        sz = q.size();
        for(int i=0; i<sz; i++){
            p = q.front();
            q.pop();
            if(rTol==false)
                cout<<p->data<<" ";
            else
                s.push(p);
            if(p->left)
                q.push(p->left);
            if(p->right)
                q.push(p->right);
        }
    }
    if(rTol==true){
        while(!s.empty()){
            p = s.top();
            s.pop();
            cout<<p->data<<" ";
        }
    }
    if(ct==2){
        rTol = !rTol;
        ct = 0;
    }
    cout<<endl;
}
int main(){
    Node* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(13);
    root->left->left = newNode(3);
    root->left->right = newNode(6);
    root->right->left = newNode(11);
    root->right->right = newNode(15);
    lOrder2DirChange(root);
}