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
bool areIdentical(Node* t, Node* s){
    if(t==NULL && s==NULL)
        return true;
    else if(t!=NULL && s!=NULL && t->data==s->data)
        return areIdentical(t->left, s->left) && areIdentical(t->right, s->right);
    else 
        return false;
}
bool isSubtree(Node* t, Node* s){
    if(s==NULL)
        return true;
    if(t==NULL)
        return false;
    if(areIdentical(t, s))
        return true;
    return isSubtree(t->left, s) || isSubtree(t->right, s);
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
    Node* s = newNode(15);
    s->left = newNode(22);
    s->right = newNode(23);
    cout<<isSubtree(root, s);
}