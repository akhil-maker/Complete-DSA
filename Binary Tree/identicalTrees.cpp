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
bool areIdentical(Node* root1, Node* root2){
    if(root1==NULL && root2==NULL)
        return true;
    else if(root1!=NULL && root2!=NULL && root1->data==root2->data)
        return areIdentical(root1->left, root2->left) && areIdentical(root1->right, root2->right);
    else
        return false;
}
int main(){
    Node* root1 = newNode(10);
    root1->left = newNode(5);
    root1->right = newNode(13);
    root1->left->left = newNode(3);
    root1->left->right = newNode(6);
    root1->right->left = newNode(11);
    root1->right->right = newNode(15);
    Node* root2 = newNode(10);
    root2->left = newNode(5);
    root2->right = newNode(13);
    root2->left->left = newNode(3);
    root2->left->right = newNode(6);
    root2->right->left = newNode(11);
    root2->right->right = newNode(15);
    cout<<areIdentical(root1, root2);
}