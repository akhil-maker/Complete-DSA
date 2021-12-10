#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* left, *right;
};
struct Node* newNode(int val){
    struct Node* node = new Node;
    node->data = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}
bool isBSTUtil(Node* root, int min, int max){
    if(root==NULL)
        return 1;
    if(root->data<min || root->data>max)
        return 0;
    return isBSTUtil(root->left, min, root->data) && isBSTUtil(root->right, root->data, max);
}
bool isBST(struct Node* root){
    return isBSTUtil(root, INT_MIN, INT_MAX);
}
int main(){
    Node* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(13);
    root->left->left = newNode(3);
    root->left->right = newNode(6);
    root->right->left = newNode(11);
    root->right->right = newNode(15);
    cout<<isBST(root);
}