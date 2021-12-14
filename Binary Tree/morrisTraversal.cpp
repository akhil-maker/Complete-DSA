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
void morrisTraversal(Node* root){
    Node* curr, *pre;
    if(root==NULL)
        return;
    curr = root;
    while(curr!=NULL){
        if(curr->left==NULL){
            cout<<curr->data<<" ";
            curr = curr->right;
        }
        else{
            pre = curr->left;
            while(pre->right!=NULL && pre->right!=curr)
                pre = pre->right;
            if(pre->right==NULL){
                pre->right = curr;
                curr = curr->left;
            }
            else{
                pre->right = NULL;
                cout<<curr->data<<" ";
                curr = curr->right;
            }
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
    root->left->left->left = newNode(16);
    root->left->left->right = newNode(17);
    root->left->right->left = newNode(18);
    root->left->right->right = newNode(19);
    root->right->left->left = newNode(20);
    root->right->left->right = newNode(21);
    root->right->right->left = newNode(22);
    root->right->right->right = newNode(23);
    morrisTraversal(root);
}