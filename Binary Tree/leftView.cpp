#include<iostream>
#include<queue>
using namespace std;
struct Node{
    int data;
    struct Node* left, *right;
};
struct Node* newNode(int val){
    struct Node* node = new Node;
    node->data = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}
void leftView(Node* root){
    if(root==NULL)
        return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        for(int i=1; i<=n; i++){
            Node* t = q.front();
            q.pop();
            if(i==1)
                cout<<t->data<<" ";
            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
        }
    }
}
int main(){
    Node* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(2);
    root->left->left = newNode(9);
    root->left->right = newNode(8);
    root->right->left = newNode(1);
    root->right->right = newNode(3);
    root->left->right->right = newNode(7);
    leftView(root);
}