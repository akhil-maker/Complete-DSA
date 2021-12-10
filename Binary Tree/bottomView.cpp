#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    int hd;
    Node* left, *right;
};
Node* newNode(int data){
    Node* node = new Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->hd = INT_MAX;
    return node;
}
void bottomView(Node* root){
    if(root==NULL)
        return;
    int hd = 0;
    map<int, int> m;
    queue<Node*> q;
    root->hd = hd;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        hd = temp->hd;
        m[hd] = temp->data;
        if(temp->left!=NULL){
            temp->left->hd = hd-1;
            q.push(temp->left);
        }
        if(temp->right!=NULL){
            temp->right->hd = hd+1;
            q.push(temp->right);
        }
    }
    for(auto i=m.begin(); i!=m.end(); i++)
        cout<<i->second<<" ";
}
int main(){
    Node* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(13);
    root->left->left = newNode(3);
    root->left->right = newNode(6);
    root->right->left = newNode(11);
    root->right->right = newNode(15);
    bottomView(root);
}