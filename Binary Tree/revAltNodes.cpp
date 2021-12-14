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
void preorder(Node* root1, Node* root2, int lvl){
    if(root1==NULL || root2==NULL)
        return;
    if(lvl%2==0)
        swap(root1->data, root2->data);
    preorder(root1->left, root2->right, lvl+1);
    preorder(root1->right, root2->left, lvl+1);
}
void revAlter(Node* root){
    preorder(root->left, root->right, 0);
}
void lorder(Node* root){
    Node* p;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        p = q.front();
        q.pop();
        cout<<p->data<<" ";
        if(p->left) q.push(p->left);
        if(p->right) q.push(p->right);
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
    root->left->left->left = newNode(16);
    root->left->left->right = newNode(17);
    root->left->right->left = newNode(18);
    root->left->right->right = newNode(19);
    root->right->left->left = newNode(20);
    root->right->left->right = newNode(21);
    root->right->right->left = newNode(22);
    root->right->right->right = newNode(23);
    lorder(root);
    revAlter(root);
    lorder(root);
}