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
void maxMin(int &mx, int &mn, Node* root){
    if(root==NULL)
        return;
    if(root->data>mx)
        mx = root->data;
    if(root->data<mn)
        mn = root->data;
    maxMin(mx, mn, root->left);
    maxMin(mx, mn, root->right);
}
int maxMinDiff(Node* root){
    int mx = root->data, mn = root->data;
    maxMin(mx, mn, root);
    return mx-mn;
}
int main(){
    Node* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(13);
    root->left->left = newNode(3);
    root->left->right = newNode(6);
    root->right->left = newNode(11);
    root->right->right = newNode(15);
    cout<<maxMinDiff(root);
}